#include <bits/stdc++.h>
#define PI 			acos(-1)
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
vi primos;
vector<ll> pric;
bitset<200000> bi;
void criba()
{
	bi.set();
	for(int i=2;i<200000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<200000;j+=i)
				bi[j]=0;
			primos.push_back(i);
			pric.push_back((ll)i*(ll)i);
		}
}
bool light(ll n)
{
	int res=1,c;
	for(int i=0;pric[i]<=n;i++)
	{
		if(n%primos[i]==0)
		{
			c=1;
			while(n%primos[i]==0)
			{
				c++;
				n/=primos[i];
			}
			res*=c;
		}
	}
	if(n!=1) res*=2;
	return res&1;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd", "w", stdout);
	criba();
	ll n;
	while(cin>>n&&n)
	{
		if(light(n))
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}