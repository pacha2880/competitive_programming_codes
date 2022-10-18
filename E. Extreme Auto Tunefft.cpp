#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long int	li;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 998244353;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
typedef complex<double> cd;
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
 
void normalize(vector<int> &v);
vector<int> multiply(vector<int> & a, vector<int> & b)
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
 	normalize(fa);
	return fa;
}
//input : B = b0 + b1x + ... + bnx^n with b0, bn != 0 and an integer d ≥ 0
//output: First d + 1 terms of 1 / B(x), it is: q0 + q1x + . . . + qdx^d
//falta refinar 
int pot(int b, int e)
{
	int res = 1;
	while(e > 0)
	{
		if(e & 1) res = 1ll * res * b % MOD;
		b = 1ll * b * b % MOD;
		e /= 2;
	}
	return res;
}
typedef vector<int> poly;
void normalize(poly &p)
{
	while(p.size() > 1 && p.back() == 0) p.pop_back();
}
poly invert(poly b, int d)
{
	if(d == 0) return {pot(b[0], MOD - 2)};
	poly c = invert(b, d / 2);
	b.resize(sz(c) * 2);
	poly q = multiply(c, b);
	q[0] = (q[0] + MOD - 2) % MOD;
	fore(i, 0, q.size())
		q[i] = (-q[i] % MOD + MOD) % MOD;
	q = multiply(c, q);
	q.resize(d + 1);
	return q;
}
//input : A(x) and B(x) polynomials of degree m and n
//output: {Q, R} the quotient and remainder of dividing A by B

pair<poly,poly> divslow(poly &a, poly &b){
	poly q, r = a;
	while(sz(r) >= sz(b)){
		q.pb(1ll * r.back() * pot(b.back(), MOD - 2) % MOD);
		if(q.back()) fore(i, 0, sz(b)){
			r[sz(r) - i - 1] = (r[sz(r)-i-1] + MOD - 1ll * q.back() * b[sz(b) - i - 1] % MOD) % MOD;
		}
		r.pop_back();
	}
	reverse(all(q));
	return {q, r};
}

pair<poly, poly> divide(poly a, poly b)
{
	int m = sz(a), n = sz(b), magic = 750;
	if(m < n) return {{0}, a};
	if(min(m - n, n)< magic) return divslow(a, b);
	reverse(all(a));
	reverse(all(b));
	poly q = invert(b, m - n);
	q = multiply(a, q);
	q.resize(m - n + 1, 0);
	reverse(all(q));
	reverse(all(a));
	reverse(all(b));
	poly r = multiply(b, q);
	if(r.size() < a.size())
		r.resize(a.size());
	fore(i, 0, a.size())
		r[i] = ((a[i] - r[i]) % MOD + MOD) % MOD;
	normalize(r);
	return {q, r};
}
//input : A(x) of degree m and a n-uple x = (x1, . . . , xn)
//output: (A(x1), A(x2), . . . , A(xn))
vector<poly> init(poly &x)
{
	int n = sz(x);
	vector<poly> t(2 * n);
	fore(i, n, 2 * n) {t[i] = {(MOD - x[i - n]) % MOD, 1}; cout<<t[i][0]<<' '<<i<<'\n';}
	for(int i = n - 1; i > 0; i--) t[i] = multiply(t[i<<1], t[i<<1|1]);
		return t;
}
poly evaluate(poly a, poly x)
{
	int n = x.size();
	vector<poly> tree = init(x), ans(2 * n);
	ans[1] = divide(a, tree[1]).s;
	fore(i, 2, 2 * n) 
		ans[i] = divide(ans[i>>1], tree[i]).s;
	poly r; 
	fore(i, 0, n) r.pb(ans[i + n][0]);
	return r;
}
poly sum(poly a, poly b)
{
	if(a.size() < b.size())
		swap(a, b);
	fore(i, 0, b.size())
		a[i] = (a[i] + b[i]) % MOD;
	return a;
}

poly evaluate1(poly a, poly b)
{
	poly res(b.size());
	fore(i, 0, b.size())
	{
		ll x = 1;
		res[i] = 0;
		fore(j, 0, a.size())
		{
			res[i] = (res[i] + a[j] * x) % MOD;
			x = 1ll * x * b[i] % MOD;
		}
		res[i] = (res[i] %	MOD + MOD) % MOD;
	}
	return res;
}
ll fac[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, k;
	ll x, res, mula;
	cin>>n>>k;
	fac[0] = 1;
	fore(i, 1, k + 1)
		fac[i] = pot(i + 1, k) % MOD;
	fore(i, 0, k)
	{
		for(int j = k; j > i; j--)
				fac[j] = (fac[j] + MOD - fac[j - 1]) % MOD;
	}
	//cout<<"choyo\n";
	ll fic = 1;
	fore(i, 1, k + 1)
	{
		fic = fic * pot(i + 1, MOD - 2) % MOD;
		fac[i] = fac[i] * fic % MOD;
	}
	vector<poly> tree(k + 1), tree1(k + 1);
	fore(i, 0, k + 1)
	{
		tree[i] = {(MOD - i) % MOD, 1};
		tree1[i] = {(int)((MOD - i) * fac[i] % MOD), (int)fac[i]};
	}
	int si = k + 1;
	while(si > 1)
	{
		fore(i, 0, si / 2)
		{
			tree1[i] = sum(multiply(tree[i<<1], tree1[i<<1|1]), tree1[i<<1]);
			tree[i] = multiply(tree[i<<1], tree[i<<1|1]);
		}
		if(si & 1)
		{
			swap(tree1[si / 2], tree1[si - 1]);
			swap(tree[si / 2], tree[si - 1]);
			si++;
		}
		si = si / 2;
	}
	poly b(n);
	fore(i, 0, n)
	{
		cin>>x;
		b[i] = x % MOD;
	}
	b = evaluate1(tree1[0], b);
	fore(i, 0, n)
	{
		if(i > 0) cout<<' ';
		cout<<b[i];
	}
	cout<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	