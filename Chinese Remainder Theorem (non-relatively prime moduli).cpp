	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
ll x,y,d;
bitset<40000> bi;
vll pri, pric;
void criba()
{
	bi.set();
	for(ll i=2;i<40000;i++)
		if(bi[i])
		{
			for(ll j=i+i;j<40000;j+=i)
				bi[j]=0;
			pri.pb(i);
			pric.pb(i*i);
		}
	}
map<ll,ll> fac(ll n)
{
	int i = 0, s = pri.size();
	map<ll,ll> mp;
	while(pric[i]<=n)
	{
		while(n%pri[i]==0)
		{
			n/=pri[i];
			mp[pri[i]]++;
		}
		i++;
		if(i==s) break;
	}
	if(n>1ll) mp[n]++;
	return mp;
}
void dioph(ll a, ll b)
{
	if(b==0ll) {x = 1ll; y = 0ll; d = a; return; }
	dioph(b, a % b);
	ll x1 = y;
	y = x - (a/b)*y;
	x = x1;

}
ll pot(ll base, ll exp)
{
	if(exp==0) return 1;
	return pot(base*base,exp/2)*(exp&1?base:1ll);
}
/* 
x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of 
         pp[i] with respect to num[i]
*/
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	int t;
	ll a,n,b,m,par,g,mul,res;
	cin>>t;
	map<ll,ll> mpn,mpm;
	map<ll,ll>::iterator it;
	while(t--)
	{
		cin>>a>>n>>b>>m;
		mul = 1;
		res = 0;
		g = __gcd(n,m);
		vll di1,di2;
		if(a % g == b % g)
		{
			mpn = fac(n);
			mpm = fac(m);
			for(it = mpn.begin();it!=mpn.end();it++)
			{
				if(it->second<mpm[it->first])
				{
					mpm[it->first]+=it->second;
					mpn.erase(it);
				}
				else
				{
					par = pot(it->first,it->second+mpm[it->first]);
					mpm.erase(it->first);
					mul*=par;
					di1.push_back(par);
				}
			}
			for(it = mpm.begin(); it!= mpm.end(); it++)
			{
				par = pot(it->first,it->second);
				mul*=par;
				di2.pb(par);
			}
			for(int i=0;i<di1.size();i++)
			{
				par = mul/di1[i];
				dioph(par,di1[i]);
				if(x < 0ll) x+=di1[i];
				res += (a*(mul/di1[i])*x)%mul;
			}
			for(int i=0;i<di2.size();i++)
			{
				par = mul/di2[i];
				dioph(par,di2[i]);
				if(x<0ll) x+=di2[i];
				res += (b*(mul/di2[i])*x)%mul;
			}
			mul = (m/g)*n;
			cout<<res%mul<<' '<<mul<<endl;
		}
		else
			cout<<"no solution\n";
	}
	return 0;
}