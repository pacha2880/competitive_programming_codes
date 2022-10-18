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
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int cas,n;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		ll g[n][n] ,d[n][n];
		int ord[n];
		for(int i =0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>d[i][j];
			}
			ll sum = 0;
		for(int i=0;i<n;i++)
			cin>>ord[i];
		for(int i =0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				g[i][j]=d[ord[n-1-i]][ord[n-1-j]];
			}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					g[j][i]=min(g[j][i],g[j][k]+g[k][i]);
					if(i<=k&& j<=k)
					{
						sum+=g[j][i];
					}
				}
		}
		cout<<sum<<endl;
	}
	return 0;
}