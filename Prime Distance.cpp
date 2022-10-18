#include <bits/stdc++.h>
#define PI 			acos(-1)
#define fi 			(1+sqrt(5))/2
#define Binet(n)	(pow(fi,n)-pow(-fi,-n))/sqrt(5)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
bitset<100000> bi;

vector<long long> pric,primos;
void criba()
{
	bi.set();
	bi[0]=bi[1]=0;
	for(ll i=2;i<100000;i++)
		if(bi[i])
		{
			for(ll j=i+i;j<100000;j+=i)
				bi[j]=0;
			primos.push_back(i);
			pric.push_back(i*i);
		}
}
bool primo(ll n)
{
	if(n<100000) return bi[n];
	for(int i=0;pric[i]<=n;i++)
		if(n%primos[i]==0) return false;
	return true;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd", "w", stdout);
	criba();
	pair<ll,ll> maxi,mini;
	ll a,b,i,la;
	while(cin>>a)
	{
		cin>>b;
		maxi=make_pair(0,0);
		mini=make_pair(LLONG_MAX,0);
		for(i=a;i<=b;i++)
		{
			if(primo(i)) {la=i; break;}
		}
		for(i=i+1;i<=b;i++)
		{
			if(primo(i))
			{
				maxi=max(maxi,make_pair(i-la,-la));
				mini=min(mini,make_pair(i-la,la));
				la=i;
			}
		}
		if(maxi==make_pair(0ll,0ll)) cout<<"There are no adjacent primes."<<endl;
		else cout<<mini.second<<','<<mini.first+mini.second<<" are closest, "<<-maxi.second<<','<<maxi.first-maxi.second<<" are most distant."<<endl;

	}
	return 0;
}