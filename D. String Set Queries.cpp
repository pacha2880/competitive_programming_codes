#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int alpha = 26;
int node[20][tam][alpha];
struct ahoCorasick
{
    int root, nnode;
    int link[tam], cnt[tam], id;
    bool dead;

    void init(int idx)
    {
        dead = false; id = idx; root = 0; nnode = 0;
        mem(node[id][root], 0);
        fore(i, 0, nnode + 1) cnt[i] = 0;
    }
    void clear()
    {
        dead = true;
    }
    void insert(string &s, int val)
    {
        int len = s.size();
        int now = root;

        fore(i, 0, len)
        {
            int nxt = s[i] - 'a';
            if(!node[id][now][nxt])
            {
                node[id][now][nxt] = ++nnode;
                mem(node[id][nnode],0);
                cnt[nnode] = 0;
            }

            now=node[id][now][nxt];
        }
        cnt[now] += val;
    }
    void insertdict(vector<string> &dict, vector<int> &vals)
    {
        fore(i, 0, sz(dict)) insert(dict[i], vals[i]);
    }
    void pushLinks()
    {
        queue<int> Q; link[root]=-1;
        Q.push(root);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();

            fore(i, 0, alpha)
            {
                if(!node[id][u][i]) continue;
                int v = node[id][u][i];
                int l = link[u];

                while(l != -1 && !node[id][l][i]) l = link[l];
                if(l!=-1) link[v] = node[id][l][i];
                else link[v] = 0;
                cnt[v] += cnt[link[v]];
                Q.push(v);
            }
        }
    }
    int query(string &p)
    {
        int u = root, ret = 0;
        for(char ch : p)
        {
            int nxt = ch - 'a';
            while(u != -1 && !node[id][u][nxt]) u = link[u];
            if(u == -1) u = 0;
            else u = node[id][u][nxt];
            ret += cnt[u];
        }
        return ret;
    }
} aho[20];

vector<string> dict[20];
vector<int> vals[20];

void add(string &s, int val)
{
    dict[0].pb(s);
    vals[0].pb(val);
    fore(i, 0, 20)
    {
        if(sz(dict[i]) > (1<<i))
        {
            for(auto it : dict[i]) dict[i + 1].pb(it);
            for(auto it : vals[i]) vals[i + 1].pb(it);
            dict[i].clear();
            vals[i].clear();
            aho[i].clear();
        }
        else
        {
            aho[i].init(i);
            aho[i].insertdict(dict[i], vals[i]);
            aho[i].pushLinks();
            break;
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    fore(i, 0, 20) aho[i].clear();
    while(n--)
    {
        int a;
        string b;
        cin>>a>>b;
        if(a == 1)
            add(b, 1);
        else if(a == 2)
            add(b, -1);
        else
        {
            int res = 0;
            fore(i, 0, 20) if(!aho[i].dead) res += aho[i].query(b);
            cout<<res<<endl;
        }
    }
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
