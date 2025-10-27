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
typedef vector<vector<int>> mat;
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
vector<vi> niveles;
int prof[tam];
int par[19][tam];
void dfs(int node, int pa = -1, int nivel = 0)
{
    if(pa != -1)
        par[0][node] = pa;
    prof[node] = nivel;
    if(nivel == sz(niveles))
        niveles.pb(vi());
    // cout<<nivel<<' '<<node + 1<<'\n';
    niveles[nivel].pb(node);
    for(int x : g[node])
        if(x != pa)
            dfs(x, node, nivel + 1);
}


signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 

    int n;
    cin>>n;
    vi val(n);
    fore(i, 1, n) cin>>val[i];
    fore(i, 0, n - 1)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    fore(i, 0, 18)
        fore(j, 0, n)
            par[i + 1][j] = par[i][par[i][j]];
    auto cal_lca = [&](int a, int b){
        if(prof[a] > prof[b]) swap(a, b);
        for(int i = 18; i > -1; i--)
            if(prof[b] - prof[a] >= (1<<i))
                b = par[i][b];
        if(b == a)
            return b;
        for(int i = 18; i > -1; i--)
            if(par[i][b] != par[i][a])
                a = par[i][a], b = par[i][b];
        return par[0][b];
    };

    ii res{0, -1};
    for(int x : g[0])
    {
        niveles.clear();
        dfs(x, 0);
        for(vi nivel: niveles){
            vi level;
            int suma = 0;
            for(int x : nivel)
            {
                // cout<<x + 1<<' '<<val[x]<<' '<<prof[x]<<'\n';
                if(val[x] != 0)
                    level.pb(x), suma += val[x];
            }
            // cout<<suma<<'\n';
            if(level.empty()) continue;
            int lca = level[0];
            
            for(int x : level)
                lca = cal_lca(lca, x);//,cout<<lca<<' ';
            // cout<<lca<<'\n';
            if(lca == 0) continue;
            res = max(res, {suma, -(prof[level[0]] - prof[lca] + 1)});
        }
    }
    cout<<res.f<<' '<<-res.s<<'\n';
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
