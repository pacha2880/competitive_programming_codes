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
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
mt19937 rng(100055128505716009ll);
// rng
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const __float128 EPS = 1e-20;
const double PI = acos(-1); 
const __float128 eh = powl(2, -10);
const __float128 maxh = 55504;
const __float128 es = powl(2, -23);
const __float128 maxs = 1.4028234664e38;
const __float128 ed = powl(2, -52);
__float128 resu = 0;
pair<double, int> ar[tam];

ii chi[4 * tam];
pair<__float128, __float128> vals[4 * tam];
pair<__float128, __float128> calc(int node)
{
    if(chi[node].f == -1)
        return vals[node] = {ar[node].f, fabsl(ar[node].f) * ed};
    auto a = calc(chi[node].f);
    auto b = calc(chi[node].s);
    return vals[node] = {a.f + b.f, a.s + b.s + fabsl(a.f + b.f) * ed};
}
string out;
void print(int node)
{
    if(chi[node].f == -1)
    {
        out += to_string(ar[node].s);
        return;
    }
    auto oro = max({fabsl(vals[node].f), fabsl(vals[chi[node].f].f), fabsl(vals[chi[node].s].f)});
    // cout<<node<<' '<<(double)oro<<' '<<(double)maxs<<'\n';
    // if(oro < maxh && oro * eh < resu * EPS)
    //     out += "{h:";
    // else if(oro < maxs && oro * es < resu * EPS)
    //     out += "{s:";
    // else
        out += "{d:";
    print(chi[node].f);
    out += ",";
    print(chi[node].s);
    out += "}";
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    double t = clock(), TLE = 5.5;
	int n;
	cin>>n;
    fore(i, 0, n) cin>>ar[i].f, resu += ar[i].f;
    fore(i, 0, n) ar[i].s = i + 1;
    vector<vector<pair<double, int>>> bobo;
    forg(i, 0, n, 16)
    {
        sort(ar + i, ar + min(i + 16, n), [](pair<double, int> a, pair<double, int> b){
            return fabsl(a.f) < fabsl(b.f);
        });
        if(i + 16 > n) continue;
        // shuffle(ar + i, ar + min(i + 16, n), rng);
        __float128 su = 0;
        fore(j, 0, 16) su += ar[i + j].f;
        bobo.pb(vector<pair<double, int>>(ar + i, ar + i + 16));
    }
    // cout<<sz(bobo)<<' '<<n / 16<<'\n';
    // sort(all(bobo), [](const pair<double, vector<pair<double, int>>> &a, const pair<double, vector<pair<double, int>>> &b){
    //     return fabsl(a.f) < fabsl(b.f);
    // });
    pair<__float128, vi> res(MOD, {});
    int m = sz(bobo);
    vi bobos(m);
    fore(i, 0, m) bobos[i] = i;
    vi nu(n);
    int cono = n;
    fore(i, 0, n) nu[i] = i;
    fore(i, 0, n) chi[i] = {-1, -1};
    while(n > 1)
    {
        forg(i, 1, n, 2)
        {
            chi[cono] = {nu[i - 1], nu[i]};
            nu[i / 2] = cono;
            cono++;
        }
        if(n & 1) nu[n / 2] = nu[n - 1];
        n = (n + 1) / 2;
    }
    vector<double> pozo;
    // while((clock() - t) / CLOCKS_PER_SEC < TLE)
    // fore(i, 0, 3)
        shuffle(all(bobos), rng);
        fore(i, 0, m)
            fore(j, 0, 16)
                ar[i * 16 + j] = bobo[bobos[i]][j];

        auto cal = calc(cono - 1);
    fore(i, 0, m)
        fore(j, 0, 16)
            ar[i * 16 + j] = bobo[bobos[i]][j];
    print(cono - 1);
    cout<<out<<'\n';
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
