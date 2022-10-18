#include <bits/stdc++.h>
#define mp					make_pair
#define pb					push_back
#define fst 					first
#define snd 					second
#define sz(a)				a.size()
#define fore(i, b, e)		for(int i = b; i < e; i++)
#define forn(i, n)			for(int i = 0; i < n; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
using namespace std;
typedef long long 		ll;
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int tam = 1000010;
//copiado del vasito

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
// optimized version: replace rho and fact with the following:
const int MAXP=1e6+1; // sieve size
int sv[MAXP]; // sieve
ll add(ll a, ll b, ll m){return (a+=b)<m?a:a-m;}
ll rho(ll n){
	static ll s[MAXP];
	while(1){
		ll x=rand()%n,y=x,c=rand()%n;
		ll *px=s,*py=s,v=0,p=1;
		while(1){
			*py++=y=add(mulmod(y,y,n),c,n);
			*py++=y=add(mulmod(y,y,n),c,n);
			if((x=*px++)==y)break;
			ll t=p;
			p=mulmod(p,abs(y-x),n);
			if(!p)return gcd(t,n);
			if(++v==26){
				if((p=gcd(p,n))>1&&p<n)return p;
				v=0;
			}
		}
		if(v&&(p=gcd(p,n))>1&&p<n)return p;
	}
}
void init_sv(){
	fore(i,2,MAXP)if(!sv[i])for(ll j=i;j<MAXP;j+=i)sv[j]=i;
}
void fact(ll n, map<ll,int>& f){ // call init_sv first!!!
	for(auto&& p:f){
		while(n%p.fst==0){
			p.snd++;
			n/=p.fst;
		}
	}
	if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
	else if(rabin(n))f[n]++;
	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
}
vector<ll> res;
const int ta = 10000000;
int crib[ta];
void criba()
{
	fore(i, 2, ta)
	{
		if(crib[i] == 0)
		{
			for(int j = i; j < ta; j += i)
				crib[j] = i;
		}
	}
}
void fac(ll x)
{
	if(x > 1)
	{
		bool bo;
		if(x < ta)
		{
			bo = crib[x] == x;
			if(!bo)
			{
				res.pb(crib[x]);
				fac(x / crib[x]);
			}
		}
		else
		{
			bo = rabin(x);
			if(!bo)
			{
				ll ro = rho(x);
				fac(ro);
				fac(x / ro);
			}
		}
		if(bo)
			res.pb(x);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	ll x;
	criba();
	while(n--)
	{
		cin>>x;
		res.clear();
		fac(x);
		sort(res.begin(), res.end());
		fore(i, 0, res.size())
		{
			if(i > 0)
				cout<<' ';
			cout<<res[i];
		}
		cout<<'\n';
	}
	return 0;
}
