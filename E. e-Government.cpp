#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct vertex {
    int go[26];
    int pch, par, link;
    vertex(): link(0) {
        mem(go, 0);
    }
    vertex(int ch, int from): pch(ch), par(from), link(-1){
        mem(go, 0);
    }
};
vi g[10 * tam];
vertex t[10 * tam];
int siz = 2;
int can[10 * tam], nodus[tam];
void add(string s, int pos)
{
    int node = 1;
    for(char ch : s)
    {
        ch -= 'a';
        int &to = t[node].go[ch];
        if(to == 0)
        {
            to = siz;
            t[siz++] = {ch, node};
        }
        node = to;
    }
    nodus[pos] = node;
    can[node]++;
}
int go(int node, char ch);
    // cout<<s[0]<<'\n';
    // cout<<"#####\n";
    // cout<<s.size()<<'\n';
    // fore(i, 0, (int)s.size())
    //     cout<<s[i]<
int suff(int node)
{
    int &link = t[node].link;
    if(link == -1)
    {
        link = t[node].par == 1 ? 1 : go(suff(t[node].par), t[node].pch);
        g[link].pb(node);
    }
    return link;
}
int go(int node, char ch)
{
    int &to = t[node].go[ch];
    // cout<<'\n'<<node<<' '<<to<<'\n';
    if(to == 0)
        to = node == 1 ? 1: go(suff(node), ch);
    return to;
}
int po[10 * tam], re[10 * tam];
int colocado[10 * tam];
int ta = 0;
ll tr[20 * tam];
void update(int pos, ll val)
{
    pos++;
    for(;pos<20*tam;pos+=pos&-pos)
        tr[pos] += val;
}
ll query(int pos)
{
    pos++;
    ll res = 0;
    for(;pos;pos-=pos&-pos)
        res += tr[pos];
    return res;
}
void dfs(int node)
{
    // if(can[node])
    po[node] = ta++;
    for(int x : g[node])
        dfs(x);
    // if(can[node])
    re[node] = ta++;
}
void poner(int node)
{
    // cout<<'{'<<node<<' '<<colocado[node]<<'\n';
    if(!colocado[node])
    {
        // cout<<'+'<<node<<'\n';
        colocado[node] = 1;
        update(po[node], can[node]);
        update(re[node], -can[node]);
    }
}
void remove(int node)
{
    if(colocado[node])
    {
        // cout<<"->"<<node<<' '<<po[node]<<' '<<re[node]<<'\n';
        colocado[node] = 0;
        update(po[node], -can[node]);
        update(re[node], can[node]);
    }
}
ll matching(string s)
{
    ll res = 0;
    int node = 1;
    // cout<<s<<"s\n";
    // cout<<s[0]<<'\n';
    // cout<<"#####\n";
    // cout<<s.size()<<'\n';
    // fore(i, 0, (int)s.size())
    //     cout<<s[i]<<' ';
    // cout<<"####$$$%%%\n";
    for(char ch : s)
    {
        // cout<<"!";
        ch -= 'a';
        // cout<<'@';
        // cout<<node<<' '<<(char)(ch + 'a')<<endl;
        node = go(node, ch);
        // cout<<"*"<<endl;
        // cout<<'$';
        // cout<<can[node]<<' '<<node<<' '<<po[node]<<'\n';
        // cout<<"@"<<query(0, ta - 1, 0, 0, po[node])<<'\n';
        res += query(po[node]);
        // cout<<'#';
    }
    return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int q, n;
    cin>>q>>n;
    fore(i, 0, n)
    {
        string s;
        cin>>s;
        add(s, i + 1);
        // cout<<nodus[i + 1]<<'\n';
    }
    fore(i, 2, siz) suff(i);
    dfs(1);
    fore(i, 1, n + 1) poner(nodus[i]);
    // fore(i, 0, t.size())
    // {
    //     cout<<'$'<<i<<'\n';
    //     for(int x : g[i])
    //         cout<<x<<' ';
    //     cout<<'\n';
    // }
    // fore(i, 0, n) cout<<nodus[i+1]<<' '<<po[nodus[i + 1]]<<' '<<re[nodus[i + 1]]<<'\n';
    while(q--)
    {
        char ch;
        cin>>ch;
        // cout<<ch<<'\n';
        if(ch == '?')
        {
            string s;
            cin>>s;
            cout<<matching(s)<<'\n';
        }
        else
        {
            int pos;
            cin>>pos;
            if(ch == '-')
                remove(nodus[pos]);
            else
                poner(nodus[pos]);
        }
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
