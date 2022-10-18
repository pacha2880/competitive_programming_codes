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
bitset<1000000> bs;
vi primes;
ll potmod(ll b, ll e, ll mod)
{
	if(e==0) return 1;
	ll res=potmod(b,e/2,mod);
	return ((res%mod*res%mod)*(e&1?b:1))%mod;
}
void criba()
{

	bs.set();
	bs[0] = bs[1] = 0;
	for(int i=2;i<1000000;i++)
	{
		if(bs[i])
			{for(int j=i+i;j<1000000;j+=i)
				bs[j]=0;
			primes.push_back(i);
		}
	}
}
bool primo(ll n)
{
	if(n<=1000000) return bs[n];
	for(int i=0;i<primes.size();i++)
		if(n%primes[i]==0) return false;
	return true;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll a,b;
	criba();
	while(cin>>a&&a)
	{
		cin>>b;
		if(potmod(b,a,a)==b&&!primo(a))
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}