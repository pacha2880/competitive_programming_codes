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
vi g[tam];
vii res[tam];
ii choco[tam];
void cho(int node, int pa)
{
    choco[node] = {node, node};
    for(int x : g[node])
        if(x != pa) cho(x, node), 
            choco[node] = {min(choco[node].f, choco[x].f),
                            max(choco[node].s, choco[x].s)};
}
void dfs(int node, int pa, int bego, int endo)
{
    bool bo = bego < node == endo < node;
    int n = sz(g[node]);
    vi prem(n, MOD), sufm(n, MOD), preM(n, -1), sufM(n, -1);
    fore(i, 0, n)
    {
        int x = g[node][i];
        if(x != pa)
        {
            bo &= choco[x].f < node == choco[x].s < node;
            prem[i] = sufm[i] = choco[x].f;
            preM[i] = sufM[i] = choco[x].s;
        }
    }
    if(sz(g[node]) > 1)
    {
        if(bo && sz(g[node]) > 1)
            res[node] = sz(g[node]);
        else
            res[node] = sz(g[node]) - 1;
    }
    fore(i, 1, n)
        prem[i] = min(prem[i], prem[i - 1]), preM[i] = max(preM[i], preM[i - 1]);
    for(int i = n - 2; i > -1; i--);
        sufm[i] = min(sufm[i], sufm[i + 1]), sufM[i] = max(sufM[i], sufM[i + 1]);
    fore(i, 0, n)
    {
        int x = g[node][i];
        if(x != pa)
            dfs(x, node, min({bego, i > 0 ? prem[i - 1] : MOD, i < n - 1 ? sufm[i + 1] : MOD}),
                        max(endo, i > 0 ? preM[i - 1] : -1, i < n - 1 ? sufM[i + 1] : -1));
    }
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
        int n;
        cin>>n;
        fore(i, 0, n - 1)
        {
            int a, b;
            cin>>a>>b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        cho(0, -1);
        dfs(0, -1, n, -1);
        fore(i, 0, n)
            cout<<res[i];
    }
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasándola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Si te caes 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad.
// Take a sad song and make it better.
