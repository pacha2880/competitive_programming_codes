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
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 30011;
#define modsum(a, b) ((a + b) % MOD)
#define modsub(a, b) ((((a - b) % MOD) + MOD) % MOD)
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll c1[tam],c2[tam], dos;  // MAXN must be power of 2 !!
void fht(ll* p, int n, bool inv){
	for(int l=1;2*l<=n;l*=2)for(int i=0;i<n;i+=2*l)fore(j,0,l){
		ll u=p[i+j],v=p[i+l+j];
		if(!inv)p[i+j]=modsum(u,v),p[i+l+j]=modsub(u,v); // XOR
		else p[i+j]=modsum(u,v)*dos%MOD,p[i+l+j]=modsub(u,v)*dos%MOD;
		//if(!inv)p[i+j]=v,p[i+l+j]=u+v; // AND
		//else p[i+j]=-u+v,p[i+l+j]=u;
		//if(!inv)p[i+j]=u+v,p[i+l+j]=u; // OR
		//else p[i+j]=v,p[i+l+j]=u-v;
	}
}
// like polynomial multiplication, but XORing exponents
// instead of adding them (also ANDing, ORing)
vector<ll> multiply(vector<ll>& p1, vector<ll>& p2){
	int n=1<<(32-__builtin_clz(max(sz(p1),sz(p2))-1));
	fore(i,0,n)c1[i]=0,c2[i]=0;
	fore(i,0,sz(p1))c1[i]=p1[i];
	fore(i,0,sz(p2))c2[i]=p2[i];
	fht(c1,n,false);fht(c2,n,false);
	fore(i,0,n)c1[i]*=c2[i];
	fht(c1,n,true);
	return vector<ll>(c1,c1+n);
}
void fht(vector<ll>& p, bool inv)
{
    fore(i, 0, sz(p)) c1[i] = p[i];
    fht(c1, sz(p), inv);
    fore(i, 0, sz(p)) p[i] = c1[i];
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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	dos = pot(2, MOD - 2);	
	int n, k;
	cin>>n>>k;
	k++;
	vector<ll> mul(k, 1), res(1, 1);
	while(sz(mul) & sz(mul) - 1) mul.pb(0);
	fht(mul, 0);
	fore(i, 0, mul.size()) mul[i] = pot(mul[i], n);
	fht(mul, 1);
	ll resp = 0;
	fore(i, 1, mul.size()) resp = modsum(resp, mul[i]);
	cout<<resp<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	