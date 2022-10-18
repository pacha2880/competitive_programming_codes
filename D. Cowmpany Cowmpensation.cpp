#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<'\n'
#define RAYA cerr<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 3010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
typedef vector<ll> poly;
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
//copiado del vasito
typedef ll tp;
#define add(n,s,d,k) fore(i,0,n)(d)[i]+=(s)[i]*k % MOD, (d)[i] %= MOD;
tp* ini(int n){tp *r=new tp[n];fill(r,r+n,0);return r;}
void karatsura(int n, tp* p, tp* q, tp* r){
	if(n<=0)return;
	if(n<35)fore(i,0,n)fore(j,0,n)r[i+j]+=p[i]*q[j]%MOD, r[i + j] %= MOD;
	else {
		int nac=n/2,nbd=n-n/2;
		tp *a=p,*b=p+nac,*c=q,*d=q+nac;
		tp *ab=ini(nbd+1),*cd=ini(nbd+1),*ac=ini(nac*2),*bd=ini(nbd*2);
		add(nac,a,ab,1);add(nbd,b,ab,1);
		add(nac,c,cd,1);add(nbd,d,cd,1);
		karatsura(nac,a,c,ac);karatsura(nbd,b,d,bd);
		add(nac*2,ac,r+nac,-1);add(nbd*2,bd,r+nac,-1);
		add(nac*2,ac,r,1);add(nbd*2,bd,r+nac*2,1);
		karatsura(nbd+1,ab,cd,r+nac);
		free(ab);free(cd);free(ac);free(bd);
	}
}
vector<tp> multiply(vector<tp> p0, vector<tp> p1){
	int n=max(p0.size(),p1.size());
	tp *p=ini(n),*q=ini(n),*r=ini(2*n);
	fore(i,0,p0.size())p[i]=p0[i];
	fore(i,0,p1.size())q[i]=p1[i];
	karatsura(n,p,q,r);
	vector<tp> rr(r,r+p0.size()+p1.size()-1);
	free(p);free(q);free(r);
	return rr;
}
void normalize(poly &p)
{
	while(p.size() > 1 && p.back() == 0) p.pop_back();
}
poly derivate(poly v)
{
	fore(i, 0, v.size() - 1)
		v[i] = 1ll * v[i + 1] * (i + 1) % MOD;
	v.pop_back();
	return v;
}
poly sum(poly a, poly b)
{
	if(a.size() < b.size())
		swap(a, b);
	fore(i, 0, b.size())
		a[i] = (a[i] + b[i]) % MOD;
	return a;
}
//input : B = b0 + b1x + ... + bnx^n with b0, bn != 0 and an integer d ≥ 0
//output: First d + 1 terms of 1 / B(x), it is: q0 + q1x + . . . + qdx^d
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
	fore(i, n, 2 * n) t[i] = {MOD - x[i - n], 1};
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
// interpola ps n + 1 puntos para polinomio de grado n
poly interpol(poly x, poly y)
{
	int n = x.size();
	vector<poly> tree = init(x), tree1(2 * n);
	poly d = evaluate(derivate(tree[1]), x);
	fore(i, n, 2 * n)
		tree1[i] = {(int)(1ll * y[i - n] * pot(d[i - n], MOD - 2) % MOD)};
	for(int i = n - 1; i > 0; i--) 
		tree1[i] = sum(multiply(tree[i<<1], tree1[i<<1|1]), multiply(tree1[i<<1], tree[i<<1|1]));
	return tree1[1];
}
int dp[tam][tam];
vector<int> g[tam];
ll f(int node, int d)
{
	if(d == 0) return 0;
	int &res = dp[node][d];
	if(res != -1) return res;
	res = 1;
	for(int x : g[node])
	{
		res = 1ll * res * f(x, d) % MOD;
	}
	res = (res + f(node, d - 1)) % MOD;
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	mem(dp, -1);
	ll n, d;
	cin>>n>>d;
	int a;
	fore(i, 0, n - 1)
	{
		cin>>a;
		a--;
		g[a].pb(i + 1);
	}
	f(0, tam - 1);
	if(d < tam) {cout<<dp[0][d]<<'\n';
	return 0;}
	dp[0][0] = 0;
	// poly x, y;
	// fore(i, 0, tam){
	// 	// cout<<i<<' '<<dp[0][i]<<'\n';
	// 	x.pb(i), y.pb(dp[0][i]);
	// } 
	// // cout<<dp[0][d]<<'\n';
	// x = interpol(x, y);
	// // assert(d < 100000);
	// ll X = 1;
	// ll res = 0;
	// for(ll cat : x)
	// {
	// 	// cout<<cat<<'\n';
	// 	res = (res + X * cat) % MOD;
	// 	X = X * d % MOD;
	// }
	// cout<<res<<'\n';
	ll res = 0, up = 1, dow = 1;
	fore(i, 1, n + 2)
		dow = dow * (MOD - i) % MOD,
		up = up * (d - i) % MOD;
	fore(i, 1, n + 2)
	{
		up = up * (d - (i - 1)) % MOD * pot(d - i, MOD - 2) % MOD;
		dow = dow * i % MOD * pot(MOD - (n + 1 - i + 1), MOD - 2) % MOD;
		res = (res + dp[0][i] * up % MOD * pot(dow, MOD - 2) % MOD) % MOD;
	}
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil