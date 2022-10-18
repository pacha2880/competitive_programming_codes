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
vi pri;
vector<ll> pric;
bitset<100000> bi;
void init()
{
	bi.set();
	bi[0]=bi[1]=0;
	for(int i=2;i<100000;i++)
	{
		if(bi[i])
		{
			for(int j=i+i;j<100000;j+=i)
				bi[j]=0;
			pri.push_back(i);
			pric.push_back(i*i);
		}
	}
}
int digSum(int n)
{
	int s =0;
	while(n>0)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int priSum(int n)
{
	int res = 0;
	bool prim = true;
	for(int i=0;pric[i]<=n;i++)
	{
		if(n%pri[i]==0)
		{
			prim=false;
			while(n%pri[i]==0)
			{
				n/=pri[i];
				res+= digSum(pri[i]);
			}
		}
	}
	if(prim) return 0;
	if(n!=1) res+=digSum(n);
	return res;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	freopen("asd.txt", "w", stdout);
	init();
	int n,e,smith;
	cin>>n;
	while(n--)
	{
		cin>>e;
		smith = e+1;
		while(digSum(smith)!=priSum(smith))
			smith++;
		cout<<smith<<'\n';
	}
	return 0;
}