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
#define forev(i, e, b) for(int i = e; i >= b; i--)
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
typedef vector<vi>      mat;
// template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order kth largest  order_of_key <
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int ti;
    cin>>ti;
    int ta = 5050;
    vi fac(ta), facin(ta);
    fac[0] = facin[0] = 1;
    auto pot = [&](int b, int e) {
        int res = 1;
        while(e){
            if(e & 1) res = res * b % MOD;
            b = b * b % MOD;
            e /= 2;
        }
        return res;
    };
    fore(i, 1, ta)
    {
        fac[i] = fac[i - 1] * i % MOD;
        facin[i] = pot(fac[i], MOD - 2);
    }
    auto bino = [&](int n, int k) {
        return k > n ? 0 : fac[n] * facin[k] % MOD * facin[n - k] % MOD;
    };
    while(ti--)
    {
        int n;
        cin>>n;
        int t = 0;
        vi ar(n); forn(i, n) {cin>>ar[i], t += ar[i] == -1; if(ar[i] == -1) ar[i] = MOD;}
        vi mil = ar, mir = ar;
        fore(i, 1, n) mil[i] = min(mil[i], mil[i - 1]), 
        mir[n - i - 1] = min(mir[n - i - 1], mir[n - i]);
        mat tab(n + 1, vi(n + 1));
        // fore(i, 0, n) cout<<mil[i]<<' ';
        // cout<<'\n';
        // fore(i, 0, n) cout<<mir[i]<<' ';
        // cout<<'\n';
        fore(i, 0, n)
        {
            int me = 0;
            fore(j, i, n)
            {
                me += ar[j] == MOD;
                int mi = n;
                if(i > 0) mi = min(mi, mil[i - 1]);
                if(j < n - 1) mi = min(mi, mir[j + 1]);
                // cout<<me<<' '<<mi<<'\n';
                if(mi > 0)
                tab[me][mi - 1]++;
            }
        }
        // cout<<"$\n";
        // fore(i, 0, n + 1)
        // {
        //     fore(j, 0, n)
        //         cout<<tab[i][j]<<' ';
        //     cout<<'\n';
        // }
        fore(i, 0, n + 1)
            forev(j, n - 1, 0)
                tab[i][j] += tab[i][j + 1];
        // cout<<"@\n";
        // fore(i, 0, n + 1)
        // {
        //     fore(j, 0, n)
        //         cout<<tab[i][j]<<' ';
        //     cout<<'\n';
        // }
        int res = 0;
        vi f(n, 1);
        fore(i, 0, n) if(ar[i] != MOD) f[ar[i]]--;
        fore(i, 1, n) f[i] += f[i - 1];
        // cout<<'%';
        // fore(i, 0, n) cout<<f[i]<<' ';
        // cout<<'\n';
        fore(i, 0, n + 1)
            fore(j, 0, n)
            {
                // cout<<i<<' '<<j<<" -> "<< bino(i, f[j]) % MOD * 
                // fac[f[j]] % MOD * fac[t - f[j]] % MOD * tab[i][j] % MOD<<'\n';;
                // cout<<j + 1<<'\n';
                // cout<<f[j]<<' '<<t<<'\n';
                // cout<<bino(i, f[j])<<'\n';
                // cout<<fac[f[j]]<<'\n';
                // cout<<fac[t - f[j]]<<'\n';
                // cout<<tab[i][j]<<'\n';
                res = (res + bino(i, f[j]) % MOD * 
                fac[f[j]] % MOD * fac[t - f[j]] % MOD * tab[i][j] % MOD) % MOD;
            }
        cout<<res<<'\n';
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
