#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
// el modulo debe ser un primo de la forma p = c*2^k + 1
const int mod = 998244353; // c*2^k + 1 = 119*2^23 + 1

// 3 es raiz primitiva de mod, root = 3^c % mod = 3^119 % mod
const int root = 15311432;

// root_1 = root^-1
const int root_1 = 469870224;

// 2^k
const int root_pw = 1 << 23;
 
int modPow(int b, int e)
{
	if (e == 0) return 1;
	int res = modPow(b, e/2);
	if (e%2 == 1)
		return ((1LL * b * res % mod) * res % mod) % mod;
	else 
		return (1LL * res * res % mod) % mod;
}
 
void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
	// Pre-calcular inversos modulares para mejorar eficiencia
        int n_1 = modPow(n, mod-2);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}
 
vector<int> fftMul(vector<int> & a, vector<int> & b)
{
	vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
	fa.resize(n);
	fb.resize(n);
 
	fft(fa, false);
	fft(fb, false);
 
	for (int i = 0; i < n; i++)
		fa[i] = (int)(1LL * fa[i] * fb[i] % mod);
	fft(fa, true);
 
	return fa;
}
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
void f(vi &ar)
{
	if(ar.size() == 1)
	{
		ar.pb(ar.back());
		ar[0] = 1;
		return;
	}
	vi a, b;
	fore(i, 0, sz(ar) / 2)
		a.pb(ar[i]);
	fore(i, sz(ar) / 2, sz(ar))
		b.pb(ar[i]);
	f(a); f(b);
	ar = fftMul(a, b);
	while(ar.size() > 1 && ar.back() == 0)
		ar.pop_back();
}
ll fac[tam], facin[tam];
ll bino(int n, int k)
{
	return facin[n] * fac[n - k] % MOD * fac[k] % MOD; 
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
	cin>>t;
	fac[0] = facin[0] = 1;
	fore(i, 1, tam)
		fac[i] = fac[i - 1] * i % MOD;
	facin[tam - 1] = pot(fac[tam - 1], MOD - 2);
	for(int i = tam - 2; i > 0; i--)
		facin[i] = facin[i + 1] * (i + 1) % MOD;
	while(t--)
	{
		int n;
		cin>>n;
		vi ar(n);
		fore(i, 0, n) cin>>ar[i];
		f(ar);
		ll res = 0;
		fore(i, 1, ar.size())
		{
			res = (res + (1ll * ar[i] * bino(n, i))) % MOD;
		}
		cout<<res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	