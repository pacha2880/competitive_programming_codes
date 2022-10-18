#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;

ll gcd(ll a,ll b){return a?gcd(b%a,a):b;} 	
ll multmod(ll a,ll b,ll m)
{
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0? r+m:r;
}
ll expmod(ll b,ll e,ll m)
{
	if (!e)return 1;
	ll q=expmod(b,e/2,m);q=multmod(q,q,m);
	return e&1?multmod(b,q,m):q;
}
bool is_prime_prob(ll n,int a)
{
	if (n==a)return 1;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if ((x==1)|| (x+1==n))return 1;
	fore(_,0,s-1)
	{
		x=multmod(x,x,n);
		if (x==1)return 0;
		if (x+1==n)return 1;
	}
	return 0;
}
bool rabin(ll n){
	if (n==1)return 0;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if (!is_prime_prob(n,ar[i]))return 0;
	return 1;
}
const int MAXP=1e6+1;
int sv[MAXP];
ll add(ll a,ll b,ll m){return (a+=b)<m?a:a-m;}
ll rho(ll n){
	static ll s[MAXP];
	while(1){
		ll x=rand()%n,y=x,c=rand()%n;
		ll *px=s,*py=s,v=0,p=1;
		while(1)
		{
			*py++=y=add(multmod(y,y,n),c,n);
			*py++=y=add(multmod(y,y,n),c,n);
			if ((x=*px++)==y)break;
			ll t=p;
			p=multmod(p,abs(y-x),n);
			if (!p)return gcd(t,n);
			if (++v==26)
			{
				if ((p=gcd(p,n))>1 && p<n)return p;
				v=0;
			}
		}
		if (v && (p=gcd(p,n))>1 && p<n)return p;
	}
}
void init_sv(){
	fore(i,2,MAXP)if (!sv[i])for(ll j=i;j<MAXP;j+=i)sv[j]=i;
}
void fact(ll n,map<ll,int> &f)
{	
	for(auto && p:f)
	{
		while(n%p.first==0){
			p.second++;
			n/=p.first;
		}
	}
	if (n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
	else if (rabin(n)){f[n]++;return;}
	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
		
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	init_sv();
	map<ll,int> primos;
	fact(24,primos);
	for(map<ll,int>::iterator ite=primos.begin();ite!=primos.end();ite++)
		cout<<(ite->first)<<' '<<(ite->second)<<endl;
	cout<<endl;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2