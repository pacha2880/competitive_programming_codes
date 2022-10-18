#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef pair<pair<ll, ll>, ll> iii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll x, y, d;
void extendedEuclid(ll a, ll b)
{
    if(b == 0) {x = 1; y = 0; d = a; return;}
    extendedEuclid(b, a % b);
    ll x1 = y;
    y = x - (a / b) * y;
    x = x1;
}
ll f(ll a, ll b, ll c, ll xp, ll yp)
{
    // if(xp == yp) return xp;
    extendedEuclid(a, b);
    // cout<<a<<' '<<b<<' '<<c<<' '<<xp<<' '<<yp<<' '<<x<<' '<<y<<' '<<d<<'\n';
    if(c % d != 0)
        return 1ll * MOD * MOD;
    x *= c / d;
    y *= c / d;
    // cout<<xp<<' '<<yp<<" -> "<<x<<' '<<y<<' '<<d<<'\n';
    // ll res = 0;
    c = a * x + xp;
    ll m = a * b / d;
    // cout<<c<<' '<<m<<'\n';
    ll nu = floor(-c / (long double)m) ;
    ll n = ceil(-c / (long double)m);

    c = -b * y + yp;
    m = a * b / d;
    // cout<<c<<' '<<m<<'\n';
    nu = min(nu, (ll)floor(-c / (long double)m));
    n = max(n, (ll)ceil(-c / (long double)m));
    // cout<<n<<'\n';
    if(m < 0) return abs(a * x + a * b / d * n + xp);
    return a * x + a * b / d * n + xp;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    ll n, m;
    cin>>n>>m;
    ll k;
    cin>>k;
    fore(i, 0, k)
    {
        ll x1, y1, x, y;
        cin>>x1>>y1;
        ll res = 1ll * MOD * MOD;
        x = -2*n + x1, y = -2 * m + y1;
        res = min(res, f(2 * n, -2 * m, y - x, x, y));
        x = - x1, y = -2 * m + y1;
        res = min(res, f(2 * n, -2 * m, y - x, x, y));
        x = -2*n +  x1, y = - y1;
        res = min(res, f(2 * n, -2 * m, y - x, x, y));
        x =  - x1, y = -y1;
        res = min(res, f(2 * n, -2 * m, y - x, x, y));
        if(res == 1ll * MOD * MOD)
            cout<<"-1\n";
        else
            cout<<res<<'\n';
    }
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
