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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vii dp(tam);
vi vis;
vi gg[tam], g[tam], gr[tam];
vi oro;
int id[tam];
int ar[tam], ara[tam];
int cano[tam];
ii f(int node)
{
    if(vis[node]) return dp[node];
    vis[node] = 1;
    ii res(0, 0);
    // cout<node<<' '<<cano[]
    for(int x : g[node])
        res = max(res, f(x));
    return dp[node] = {res.f + cano[node], res.s - ar[node]};
}
void dfs(int node)
{
    vis[node] = 1;
    for(int x : gg[node])
        if(!vis[x])
            dfs(x);
    oro.pb(node);
}
void dfs1(int node, int nodus)
{
    // cout<<'$'<<node<<' '<<nodus<<'\n';
    cano[nodus]++;
    id[node] = nodus;
    vis[node] = 1;
    ar[nodus] += ara[node];
    for(int x : gr[node])
        if(!vis[x])
            dfs1(x, nodus);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    while(t--)
    {
        // cout<<t<<'\n';
        int n, m;
        cin>>n>>m;
        vis.assign(n, 0);
        fore(i, 0, n)
            cin>>ara[i];
        fore(i, 0, m)
        {
            int a, b;
            cin>>a>>b;
            gg[a - 1].pb(b - 1); 
            gr[b - 1].pb(a - 1);
        }
        oro.clear();
        fore(i, 0, n)
            if(!vis[i])
                dfs(i);
        int nodus = 0;
        fore(i, 0, n) vis[i] = 0;
        // cout<<"%%%\n";
        reverse(all(oro));
        // fore(i, 0, n) cout<<ar[i]<<' '<<cano[i]<<'\n';
        fore(i, 0, n)
        {
            if(!vis[oro[i]])
                dfs1(oro[i], nodus++);
            // cout<<i<<' '<<oro[i]<<' ';
            // cout<<id[i]<<'\n';
        }
        // cout<<"###\n";
        fore(i, 0, n)
        {
            vis[i] = 0;
            for(int x : gg[i])
                if(id[i] != id[x])
                    g[id[i]].pb(id[x]);
        }

        ii res(0, 0);
        // fore(i, 0, n)
        //     cout<<i + 1<<' '<<id[i] + 1<<'\n';
        // cout<<nodus<<'\n';
        fore(i, 0, nodus)
        {
            // cout<<ar[i]<<' '<<cano[i]<<'\n';
            // cout<<"#"<<i + 1<<'\n';
            // cout<<cano[i]<<' '<<ar[i]<<'\n';
            // for(int x : g[i])
            //     cout<<x + 1<<' ';
            res = max(res, f(i));
        }
        cout<<res.f<<' '<<-res.s<<'\n';
        fore(i, 0, n) g[i].clear(), gg[i].clear(), gr[i].clear(), ar[i] = 0, cano[i] = 0;
    }
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
