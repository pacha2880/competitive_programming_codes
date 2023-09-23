#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
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

// #pragma GCC optimization ("O2")
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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[tam];
int ar[tam];
int sub[tam], tot[tam];
vi vis;
void dfs1(int node, int par = -1)
{
    sub[node] = ar[node];
    // cout<<'@'<<node<<' '<<sub[node]<<'\n';;
    vis[node] = 1;
    for(int x : g[node])
    {
        if(x != par)
        {
            dfs1(x, node);
            sub[node] += max(0ll, sub[x]);
            // cout<<'@'<<node<<' '<<sub[node]<<'\n';;
        }
    }
    // cout<<'@'<<node<<' '<<sub[node]<<'\n';
}
void dfs2(int node, int par = -1)
{
    for(int x : g[node])
    {
        if(x != par)
        {
            if(sub[x] > 0)
                tot[node] -= sub[x];
            if(tot[node] > 0)
                tot[x] = sub[x] + tot[node];
            else
                tot[x] = sub[x];
            if(sub[x] > 0)
                tot[node] += sub[x];
            dfs2(x, node);
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    while(true)
    {
        int n, m;
        cin>>n>>m;
        if(n == 0 && m == 0) break;
        vis.assign(n, 0);
        fore(i, 0, m)
        {
            int a, b;
            cin>>a>>b;
            a--, b--;
            // cout<<'$'<<a<<' '<<b<<'\n';
            g[a].pb(b);
            g[b].pb(a);
        }
        fore(i, 0, n) cin>>ar[i];
        // cout<<"$$$$\n";
        vi roots;
        fore(i, 0, n)
        {
            if(!vis[i])
                roots.pb(i), dfs1(i);
        }
        // cout<<"$$$$\n";
        for(int x : roots)
        {
            tot[x] = sub[x];
            dfs2(x);
        }
        // cout<<"$$$$\n";
        fore(i, 0, n)
        {
            if(i > 0) cout<<' ';
            cout<<tot[i];
        }
        cout<<'\n';
        fore(i, 0, n) g[i].clear();
        fore(i, 0, n) sub[i] = 0, tot[i] = 0, ar[i] = 0;
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

