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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct pt{
    ll x, y;
    pt operator -(const pt &p) const{return {x - p.x, y - p.y};}
    pt operator +(const pt &p) const{return {x + p.x, y + p.y};}
    __int128 operator %(const pt &p) const{return (__int128)x * p.y - (__int128) p.x * y;}
    double norm(){return 1.0 * x * x + 1.0 * y * y;}
};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int n;
    cin>>n;
    vector<pt> up, dow;
    fore(i, 0, n)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        pt p = {a - b, c - d};
        if(p.y > 0 || p.y == 0 && p.x > 0)
            up.pb(p);
        else if(p.x != 0 || p.y != 0)
            dow.pb(p);
    }
    sort(all(up), [&](pt &a, pt &b){
        return a % b > 0;
    });
    sort(all(dow), [&](pt &a, pt &b){
        return a % b > 0;
    });
    double res = 0;
    fore(asd, 0, 2)
    {
        int i = 0, j = 0;
        pt apa = {0, 0}, dowo = {0, 0};
        for(pt p : up)
            apa = apa + p;
        for(pt p : dow)
            dowo = dowo + p;
        res = max(res, max(apa.norm(), dowo.norm()));
        while(i < sz(up))
        {
            while(j < sz(dow) && up[i] % dow[j] > 0)
                apa = apa + dow[j], dowo = dowo - dow[j], j++;
            res = max(res, max(apa.norm(), dowo.norm()));
            dowo = dowo + up[i];
            apa = apa - up[i];
            i++;
        }
        swap(apa, dowo);
        swap(up, dow);
    }
    cout<<fixed<<setprecision(12)<<res<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
