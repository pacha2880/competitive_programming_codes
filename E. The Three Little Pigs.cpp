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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
//copiado del vasito
typedef ll tp;
typedef vector<ll> poly;
// #define add(n,s,d,k) fore(i,0,n)(d)[i]+=(s)[i]*k
#define add(n,s,d,k) fore(i,0,n)(d)[i]+=(s)[i]*k%MOD, (d)[i] = ((d)[i] % MOD + MOD) % MOD;
tp* ini(int n){tp *r=new tp[n];fill(r,r+n,0);return r;}
void karatsura(int n, tp* p, tp* q, tp* r){
	if(n<=0)return;
	// if(n<35)fore(i,0,n)fore(j,0,n)r[i+j]+=p[i]*q[j];
	if(n<35)fore(i,0,n)fore(j,0,n)r[i+j]+=p[i]*q[j] % MOD, r[i + j] %= MOD;
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
void normalize(poly &p)
{
	while(p.size() > 1 && p.back() == 0) p.pop_back();
}
vector<tp> multiply(vector<tp> p0, vector<tp> p1){
	int n=max(p0.size(),p1.size());
	tp *p=ini(n),*q=ini(n),*r=ini(2*n);
	fore(i,0,p0.size())p[i]=p0[i];
	fore(i,0,p1.size())q[i]=p1[i];
	karatsura(n,p,q,r);
	vector<tp> rr(r,r+p0.size()+p1.size()-1);
	free(p);free(q);free(r);
	normalize(rr);
	return rr;
}
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
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
poly sum(poly a, poly b)
{
	if(a.size() < b.size())
		swap(a, b);
	fore(i, 0, b.size())
		a[i] = (a[i] + b[i]) % MOD;
	return a;
}
poly pot(poly base, ll exp)
{
	poly res = {1};
	while(exp)
	{
		if(exp & 1)
		{
			res = multiply(res, base);
		}
		base = multiply(base, base);
		exp /= 2;
	}
	return res;
}

ll fac[3 * tam], facin[3 * tam];
ll bino(int n, int k)
{
	return fac[n] * facin[n - k] % MOD * facin[k] % MOD;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, q;
	cin>>n>>q;
	fac[0] = facin[0] = 1;
	fore(i, 1, 3 * tam)
	{
		fac[i] = i * fac[i - 1] % MOD;
		facin[i] = pot(fac[i], MOD - 2);
	}
	poly p = {1, 3, 3, 1}, nu(3 * (n + 1) + 1), pn;

	fore(i, 0, 3 * n + 4)
		nu[i] = bino(3 * n + 3, i);
	nu[0]--;
	p[0]--;
	pn = divide(nu, p).f;
	int a;
	while(q--)
	{
		cin>>a;
		cout<<pn[a]<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
