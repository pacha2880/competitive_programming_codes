#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int 			long long
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
#define forev(i, e, b) for(int i = e; i > b; i--)
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
// template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;

signed main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    while(t--)
    {
        int n, m, q;
        cin>>n>>m>>q;
        vector<vector<multiset<int>>> g(n, vector<multiset<int>>(n, multiset<int>()));
        fore(i, 0, m)
        {
            int a, b, c;
            cin>>a>>b>>c;
            a--, b--;
            g[a][b].insert(c);
            g[b][a].insert(c);
        }
        fore(k, 0, n)
            fore(i, 0, n)
                fore(j, 0, n)
                {
                    if(k == i || k == j) continue;
                    for(int x : g[i][k])
                        g[i][j].insert(x);
                    for(int x : g[k][j])
                        g[i][j].insert(x);
                    while(sz(g[i][j]) > n) g[i][j].erase(g[i][j].begin());
                }
        vector<vector<vi>> res(n, vector<vi>(n));
        fore(i, 0, n)
            fore(j, 0, n)
            {
                res[i][j] = vi(all(g[i][j]));
                cout<<i<<' '<<j<<'\n';
                for(int x : res[i][j])
                    cout<<x<<' ';
                cout<<'\n';
                reverse(all(res[i][j]));
            }
        // continue;
        while(q--)
        {
            int a, b, k;
            cin>>a>>b>>k;
            // cout<<a<<' '<<b<<' '<<k<<'\n';
            // cout<<sz(res)<<' '<<sz(res[a - 1])<<'\n';
            cout<<res[a - 1][b - 1][k - 1]<<' ';
        }
        cout<<'\n';

    }
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
// Ya que no se tiene información perfecta, tomar riesgos.
// Si se decide trabajar en un problema grande, empezar a hacerlo lo antes posible.
// La suerte siempre tiene su rol en las competencias y hay que vivir con eso.
