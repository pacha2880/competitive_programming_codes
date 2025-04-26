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
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int pot(int b, int e)
{
    int res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
vi operator *(vi a, vi b)
{
    vi res(sz(a) + sz(b) - 1);
    forn(i, sz(a)) forn(j, sz(b)) res[i + j] = (res[i + j] + a[i] * b[j]) % MOD;
    return res;
}
vi operator %(vi v, vi &m)
{
    while(sz(v) >= sz(m))
    {
        int c = MOD - v.back() * pot(m.back(), MOD - 2) % MOD;
        fore(i, 1, sz(m))
            v[sz(v) - i - 1] = (v[sz(v) - i - 1] + c * m[sz(m) - i - 1]) % MOD;
        v.pop_back();
    }
    return v;
}
vi powo(vi b, int e, vi m)
{
    vi res{1};
    while(e)
    {
        if(e & 1) res = res * b % m;
        b = b * b % m;
        e /= 2;
    }
    return res;
}
void gauss (vector <vi> a, vi &b) {
    int n = sz(a);
    fore(i, 0, n)
    {
        if(!a[i][i])
            fore(j, i + 1, n)
                if(a[j][i])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    break;
                }
        int inv = pot(a[i][i], MOD - 2);
        fore(j, 0, n)
            a[i][j] = a[i][j] * inv % MOD;
        b[i] = b[i] * inv % MOD;
        fore(j, 0, n)
            if(j != i && a[j][i])
            {
                inv = MOD - a[j][i];
                fore(k, 0, n) a[j][k] = (a[j][k] + a[i][k] * inv) % MOD;
                b[j] = (b[j] + b[i] * inv) % MOD;
            }
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m, k;
    cin>>n>>m>>k;
    vi ar(n);
    int su = 0;
    fore(i, 0, n) cin>>ar[i], su += ar[i];
    vi f(n + 1);
    f[n] = 1;
    su = pot(su, MOD - 2);
    fore(i, 0, n) ar[i] = ar[i] * su % MOD;
    fore(i, 0, n)
        f[n - 1 - i] = (MOD - ar[i]) % MOD;
    f = f * vi{MOD-1, 1};
    vi baso(n + 1);
    baso[1] = 1;
    vi meme = powo(baso, m - n + 1, f);
    vector<vi> lolo;
    forn(i, n - 1)
        lolo.pb(meme), meme = meme * vi{0, 1} % f;
    vector<vi> a(n + 1, vi(n + 1));
    vi b(n + 1, 1);
    forn(i, n + 1)
    {
        b[i] = MOD - 1;
        a[i][i] = MOD - 1;
        if(i == 0)
        {
            a[i][i] = 1;
            b[i] = 0;
            continue;
        }
        fore(j, 0, n)
        {
            int c = i - j - 1;
            if(c >= 0)
                a[i][c] = (a[i][c] + ar[j]) % MOD;
            else
            {
                fore(k, 0, n + 1)
                    a[i][k] = (a[i][k] + ar[j] * (lolo[n - 1 + c][k])) % MOD;
            }
        }
    }
    gauss(a, b);
    vi mama = powo(baso, k, f);
    // cout<<sz(mama)<<' '<<sz(b)<<' '<<n + 1<<'\n';
    // fore(i, 0, n + 1)
    //     cout<<mama[i]<<' '<<b[i]<<'\n';
    // cout<<'\n';
    // cout<<"asdf\n";
    // return 0;
    int res = 0;
    fore(i, 0, n + 1)
        res = (res + mama[i] * b[i]) % MOD;
    cout<<res<<'\n';
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

