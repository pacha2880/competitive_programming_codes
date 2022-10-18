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

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n;
	string a;
	cin>>n;
	int num[n];
	cin>>num[0];
	bool con[n-2];

	mem(con,false);
	for(int i=0;i<n-1;i++)
	{
		cin>>a;
		if(a=="-")
			con[i]=true;
		cin>>num[i+1];
	}
	int dp[n];
	memset(dp,0,sizeof(dp));
	dp[n-1]=1;
	dp[n-2]=1;
	for(int i=n-3;i>-1;i--)
	{
		if(con[i])
		{
			for(int j=n-1;j>i;j--)
			{
				dp[i]+=dp[j];
			}
		}
		else
			dp[i]=dp[i+1];
	}
	cout<<dp[0]<<endl;

	return 0;
}