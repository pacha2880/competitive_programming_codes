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
const ll tam = 100'010;
const ll MOD = 1'000'000'007;
const ll MOD1 = 998'244'353;
const ld DINF=1e100;
const ld EPS = 1e-9; 
typedef complex<ld> cd;
const ld PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    ll n = a.size();

    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            cd w(1);
            for (ll j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
ll res[2][tam];
void muls(vi a, vi b, ll val, ll i, ll n, ll po)
{
	ll t = a.size();
	vi c = multiply(a, b);
	fore(j, i, n)
	{
		val += c[j - i];
		res[po][j] = val;
		val -= c[j - i];
	}
}
void sol(vi ar, vi br, ll n, ll po)
{
	sort(all(ar));
	sort(all(br));
	ll i = 0, j = n - 1;
	ll val = 0;
	ll con = 0;
	while(i <= j && (ar[i] * br[i] > 0 || ar[j] * br[j] > 0))
	{
		if(ar[i] * br[i] > ar[j] * br[j])
			val += ar[i] * br[i], i++;
		else
			val += ar[j] * br[j], j--;
		res[po][con++] = val;
	}	
	if(i <= j)
	{
		vi a, b;
		ll su = 0;
		fore(k, i, j + 1)
		{
			su += ar[k];
			a.pb(ar[k]), b.pb(br[k]);
		}
		if(su < 0)
			reverse(all(a));
		else
			reverse(all(b));
		muls(a, b, val, con, n, po);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n;
	cin>>n;
	vi ar(n), br(n);
	fore(i, 0, n) cin>>ar[i];
	fore(i, 0, n) cin>>br[i];
	sol(ar, br, n, 0);
	fore(i, 0, n)
	{
		ar[i] *= -1;
		// br[i] *= -1;
	}
	sol(ar, br, n, 1);
	fore(i, 0, n)
		cout<<-res[1][i]<<' '<<res[0][i]<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
