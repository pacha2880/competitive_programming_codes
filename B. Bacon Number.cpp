#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int 			long long
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
bitset<100> haypan[1000010];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m;
    cin>>n>>m;
    vector<vi> cines(m);
    fore(i, 0, n)
    {
        int x;
        cin>>x;
        while(x--)
        {
            int y;
            cin>>y;
            cines[y - 1].pb(i);
        }
    }
    vector<vi> caca(n, vi(n, MOD)), quien(n, vi(n)), par(n, vi(n, -1));
    fore(i, 0, n) caca[i][i] = 0;
    fore(i, 0, m)
    {
        fore(j, 0, sz(cines[i]))
        {
            haypan[i][cines[i][j]] = 1;
            fore(k, j + 1, sz(cines[i]))
            {
                caca[cines[i][j]][cines[i][k]] = 1;
                caca[cines[i][k]][cines[i][j]] = 1;
                quien[cines[i][j]][cines[i][k]] = i;
                quien[cines[i][k]][cines[i][j]] = i;
                par[cines[i][j]][cines[i][k]] = cines[i][j];
                par[cines[i][k]][cines[i][j]] = cines[i][k];
            }
        }
    }
    fore(k, 0, n)
        fore(i, 0, n)
            fore(j, 0, n)
            {
                if(caca[i][k] + caca[k][j] < caca[i][j])
                {
                    caca[i][j] = caca[i][k] + caca[k][j];
                    par[i][j] = par[k][j];
                }
            }
    // fore(i, 0, m)
    // {
    //     cout<<i<<'\n';
    //     fore(j, 0, n)cout<<haypan[i][j];
    //     cout<<'\n';
    // }
    int q;
    cin>>q;
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        int fro, to, mimo = MOD;
        fore(i, 0, n)
            if(haypan[b][i])
            fore(j, 0, n)
                if(haypan[a][j] && caca[i][j] < mimo)
                {
                    fro = i, to = j;
                    mimo = caca[i][j];
                }
        vi res;
        // cout<<mimo<<'\n';
        // cout<<fro<<' '<<to<<'\n';
        // cout<<a<<' '<<b<<'\n';
        // continue;
        if(mimo == MOD)
        {
            cout<<-1<<'\n';
            continue;
        }
        res.pb(a+1);
        res.pb(to + 1);
        while(fro != to)
        {
            res.pb(quien[par[fro][to]][to] + 1);
            to = par[fro][to];
            res.pb(to + 1);
        }
        res.pb(b+1);
        cout<<(sz(res) + 1) / 2<<'\n';
        for(int x : res)
            cout<<x<<' ';
        cout<<'\n';
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
// Ya que no se tiene información perfecta, tomar riesgos.
// Si se decide trabajar en un problema grande, empezar a hacerlo lo antes posible.
// La suerte siempre tiene su rol en las competencias y hay que vivir con eso.
