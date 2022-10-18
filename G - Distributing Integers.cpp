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
vi g[2 * tam];
ll res[2 * tam];
ll pot(ll b, ll e)
{
    ll res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
ll fac[2 * tam], facin[2 * tam];
int n;
pair<ll, ll> ras[2 * tam];
pair<ll, ll> dufs(int node, int par)
{
    if(ras[node].f != -1) return ras[node];
    ras[node] = {1, 0};
    for(int x : g[node])
    {
        if(x != par)
        {
            auto cat = dufs(x, node);
            ras[node].s += cat.s;
            ras[node].f = ras[node].f * facin[cat.s] % MOD * cat.f % MOD;
        }
    }
    ras[node].f = ras[node].f * fac[ras[node].s] % MOD;
    ras[node].s++;
    return ras[node];
}
void dfs(int node, int par, ll god, ll father)
{
    res[node] = fac[n - 1] * facin[father] % MOD * god % MOD;
    for(int x : g[node])
    {
        if(x != par)
        {
            auto cat = dufs(x, node);
            res[node] = res[node] * facin[cat.s] % MOD * cat.f % MOD;
        }
    }
    for(int x : g[node])
        if(x != par)
        {
            auto cat = dufs(x, node);
            dfs(x, node, res[node] * fac[n - 1 - cat.s] % MOD * fac[cat.s] % MOD * facin[n - 1] % MOD * pot(cat.f, MOD - 2) % MOD, n - cat.s);
        }
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    cin>>n;
    fore(i, 0, n) ras[i].f = -1;
    fac[0] = facin[0] = 1;
    fore(i, 1, 2 * tam)
    {
        fac[i] = fac[i - 1] * i % MOD;
        facin[i] = pot(fac[i], MOD -2);
    }
    fore(i, 0, n - 1)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1, 1, 0);
    fore(i, 0, n)
        cout<<res[i]<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
