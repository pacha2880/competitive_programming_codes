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

	bitset<1000> bi;
	int n;
	int c[3][6];
	void sum (int a, int b, int d){
		if((n==1&&(a==2||a==1))||(n==2&&(a==2||b==2))) return;

	for(int i=0;i<6;i++)
	{
		bi[c[a][i]]=0;

		if(n>1)
		{
			for(int j=0;j<6;j++)
			{
				bi[c[a][i]*10+c[b][j]]=0;
				if(n>2)
				{
					for(int k=0;k<6;k++)
					{
						bi[c[a][i]*100+c[b][j]*10+c[d][k]]=0;
					}
				}
			}
		}
	}
	}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	cin>>n;
	memset(c,(0),sizeof(c));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<6;j++)
		{
			cin>>c[i][j];
		}
	}
	bi.set();
	sum(0,1,2);
	sum(0,2,1);
	sum(1,2,0);
	sum(1,0,2);
	sum(2,1,0);
	sum(2,0,1);
	for(int i=1;i<1000;i++)
	{
		if(bi[i]){
			cout<<i-1;
			break;
		}
	}
	return 0;
}