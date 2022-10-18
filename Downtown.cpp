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
	int c,m;
	cin>>c>>m;
	bool mu[m],co[c];
	mem(mu,0);
	mem(co,0);
	int prec[c][m],prem[m][c],r;
	pair<int,int> rank[m];
	for(int i=0;i<c;i++)
		for(int j=0;j<m;j++)
			{
				cin>>prec[i][j];
				prec[i][j]--;
			}
	for(int i=0;i<m;i++)
	{
		cin>>r;
		rank[i] = make_pair(r,i);
		for(int j=0;j<c;j++)
		{
			cin>>prem[i][j];
			prem[i][j]--;
		}
	}
	int res[m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!mu[j])
			{
				for
			}
		}
	}
	return 0;
}