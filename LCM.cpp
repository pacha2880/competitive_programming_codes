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
bitset<1000000> bi;
vector<ll> primos;
void criba()
{
	bi.set();
	for(int i=2;i<1000000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<1000000;j+=i)
				bi[j]=false;
			primos.push_back(i);
		}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	ll n, res, tr;
	while(cin>>n&&n)
	{
		if(n==1) cout<<1<<endl;
		else
		{
			res=1;
			for(int i=0;i<primos.size()&&primos[i]<=n;i++)
			{
				
				if(i!=2) {
				tr=primos[i];
				while(tr*primos[i]<=n)
					tr*=primos[i];
				res=(res*tr)%1000000000;}
			}
			if(n>4)
			{
				tr=5;
				while(tr*5<=n)
					tr*=5;
				res*=tr;
			}
			while(res%10==0) res/=10;
			cout<<res%10<<endl;
		}
	}
	return 0;
}