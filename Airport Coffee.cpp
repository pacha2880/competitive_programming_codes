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
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	double lon,a,b,r,t,x,y;
	int n;
	cin>>lon>>a>>b>>r>>t>>n;
	if(n==0) {cout<<0; return 0;}
	double puestos[n];
	for(int i=0;i<n;i++)
		cin>>puestos[i];
	x = a;
	y = b;
	a = a * r;
	b = b * t;
	int parent[n];
	double dp[n];
	for(int i=0;i<n;i++)
		{dp[i] = LLONG_MAX/4;
			parent[i] = -1;
		}
	for(int i=n-1;i>=0;i--)
	{
		ll te=puestos[i]+a+b;
		if(te>=lon)
		{
			dp[i] = ((puestos[i]+a<=lon)?r+(lon-puestos[i]-a)/y:(-puestos[i]+lon)/x);
		}
		else
		{
			int hi = n-1,
			lo = 0,
			mid,res;
			while(hi>=lo)
			{
				mid = (hi+lo)/2;
				if(puestos[mid]<=te){
					lo = mid+1;
					res = mid;
				}
				else
					hi = mid-1;
			}
			ll p=(puestos[i]+a<=puestos[res]?r+(puestos[res]-puestos[i]-a)/y:(puestos[res]-puestos[i])/x);
			if(res==n-1)
			{
				
				if(dp[res]+p<(lon-te)/x+t+r)
				{
					parent[i] = res;
					dp[i] = dp[res] + p;
				}
				else
					dp[i] = (lon-te)/x+t+r;
			}
			else
			{
				ll pu = r+t+(puestos[res+1]-te)/x;
				if(dp[res]+p<dp[res+1]+pu)
				{
					parent[i] = res;
					dp[i] = dp[res] + p;
				}
				else
				{
					parent[i] = res + 1;
					dp[i] = dp[res+1] + pu;
				}
			}
		}
	}
	int in = 0,con=1;
	while(parent[in]!=-1)
		{in = parent[in];
			con++;
		}
	cout<<con<<endl;
	in = 0;
	while(parent[in]!=-1)
	{
		cout<<in<<' ';
		in = parent[in];
	}
	cout<<in;
	return 0;
}