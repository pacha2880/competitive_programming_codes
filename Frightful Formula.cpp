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
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef int      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
typedef vector<ll> poly;

typedef ll tp;
#define add(n,s,d,k) fore(i,0,n)(d)[i]+=(s)[i]*k
tp* ini(int n){tp *r=new tp[n];fill(r,r+n,0);return r;}
void karatsura(int n, tp* p, tp* q, tp* r){
	if(n<=0)return;
	if(n<35)fore(i,0,n)fore(j,0,n)r[i+j]+=p[i]*q[j];
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
vector<tp> multiply2(vector<tp> p0, vector<tp> p1){
	int n=max(p0.size(),p1.size());
	tp *p=ini(n),*q=ini(n),*r=ini(2*n);
	fore(i,0,p0.size())p[i]=p0[i];
	fore(i,0,p1.size())q[i]=p1[i];
	karatsura(n,p,q,r);
	vector<tp> rr(r,r+p0.size()+p1.size()-1);
	free(p);free(q);free(r);
	return rr;
}
poly karatsuba(poly &a, poly &b)
{
	if(sz(a) & 1) a.pb(0), b.pb(0);
	int n = a.size(), m = n / 2;
	poly r(2 * n);
	if(n < 35) fore(i, 0, n) fore(j, 0, n) r[i + j] += a[i] * b[j];
	else
	{
		poly x0(m), x1(m), y0(m), y1(m);
		fore(i, 0, m)
		{
			x0[i] = a[i], y0[i] = b[i];
			x1[i] = a[i + m], y1[i] = b[i + m];
		}
		poly z0 = karatsuba(x0, y0), z1 = karatsuba(x1, y1);	
		fore(i, 0, m) x1[i] += x0[i], y1[i] += y0[i];
		poly z2 = karatsuba(x1, y1);
		fore(i, 0, n) 
		{
			r[i] += z0[i], r[i + n] += z1[i];
			r[i + m] += z2[i] - z1[i] - z0[i];
		}
	}
	return r;
} 
void normalize(poly &p)
{
	while(p.size() > 1 && p.back() == 0) p.pop_back();
}
poly multiply(poly a, poly b)
{
	int n = max(a.size(), b.size());
	a.resize(n);
	b.resize(n);
	poly r = karatsuba(a, b);
	normalize(r);
	return r;
}
poly multiply1(poly a, poly b)
{
	poly r(sz(a) + sz(b) - 1);
	fore(i, 0, sz(a)) fore(j, 0, sz(b)) r[i + j] += a[i] * b[j];
	normalize(r);
	return r;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n = 1023;
	poly a(n), b(n);
	fore(i, 0, n)
		a[i] = rand() % 10000, b[i] = rand() % 10000;
	double t = clock();
	poly r = multiply(a, b);
	cout<<(clock() - t) / CLOCKS_PER_SEC<<'\n';
	cout<<"yai\n";
	t = clock();
	r = multiply(a, b);
	cout<<(clock() - t) / CLOCKS_PER_SEC<<'\n';
	cout<<"yei\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	