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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;

vector<vi> g;
vi sis;
int dfs(int node)
{
    int sus = 1;
    for(int x : g[node])
        sus += dfs(x);
    return sis[node] = sus;
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
        int n, q;
        cin>>n>>q;
        vi par(n, -1);
        g.assign(n, vi());
        sis.assign(n, 0);
        vector<set<int>> sut(n);
        fore(i, 1, n)
        {
            int x;
            cin>>x;
            x--;
            g[x].pb(i);
            par[i] = x;
        }
        vi oliver(n), quien(n);
        vi ar(n);
        fore(i, 0, n)
        {
            cin>>ar[i];
            ar[i]--;
            if(ar[i] != 0)
                sut[par[ar[i]]].insert(i);
            oliver[ar[i]] = i;
        }
        int x = dfs(0);
        auto nico = [&](int micky)
        {
            // cout<<'#'<<micky<<'\n';
            if(micky == -1 || g[micky].empty())
                return 1;
            int pozo = oliver[micky];
            if(*sut[micky].begin() > pozo && *--sut[micky].end() < pozo + sis[micky])
                return 1;
            return 0;
            // return ans == sz(g[micky]);
        };
        int mateo = 0;
        // cout<<"hola\n";
        fore(i, 0, n)
            mateo += nico(i);
        // cout<<mateo<<'\n';
        // continue;
        while(q--)
        {
            int a, b;
            cin>>a>>b;
            // cout<<a<<' '<<b<<'\n';
            a--, b--;
            swap(ar[a], ar[b]);
            a = ar[a], b = ar[b];
            // c
            set<int> st({a, b, par[a], par[b]});
            for(int x : st)
                cout<<x<<' '<<nico(x)<<'\n',
                mateo -= nico(x);
            // mateo -= nico(a) + nico(b);
            // cout<<"papis"<<par[a]<<' '<<par[b]<<'\n';
            // mateo -= nico(par[a]) + nico(par[b]);
            // cout<<mateo<<'\n';
            if(a != 0)
            sut[par[a]].erase(oliver[a]);
            if(b != 0)
            sut[par[b]].erase(oliver[b]);
            swap(oliver[a], oliver[b]);
            if(a != 0)
            sut[par[a]].insert(oliver[a]);
            if(b != 0)
            sut[par[b]].insert(oliver[b]);
            // mateo += nico(a) + nico(b);
            // cout<<mateo<<'\n';
            // mateo += nico(par[a]) + nico(par[b]);
            for(int x : st)
                cout<<x<<' '<<nico(x)<<'\n',
                mateo += nico(x);
            int susu = 0;
            fore(i, 0, n) cout<<ar[i]<<' ';
            cout<<'\n';
            fore(i, 0, n) cout<<oliver[i]<<' ';
            cout<<'\n';
            fore(i, 0, n) susu += nico(i);
            cout<<susu<<' ';
            cout<<mateo<<'\n';
            if(mateo == n)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
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
