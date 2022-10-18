#include <bits/stdc++.h>
#define PI 			acos(-1)
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
int c,n;

map<int,map<int,int> > mp;
long long bfs(int x,int y)
{
	priority_queue<pair<int,pair<int,int> > > que;
	que.push(make_pair(-mp[x][y]-c,make_pair(x,y)));
	int peso;
	long long int pesos[n][n];
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			pesos[i][j]=LLONG_MIN;
	pesos[x][y]=-mp[x][y]-c;
	while(!que.empty())
	{
		x=que.top().second.first, y=que.top().second.second;
		peso=que.top().first;
		que.pop();
		if(y==n-1) continue;
		if(peso-mp[x][y+1]>pesos[x][y+1]) 
		{
			pesos[x][y+1]=peso-mp[x][y+1];
			que.push(make_pair(pesos[x][y+1],make_pair(x,y+1)));
		}
			if(peso-mp[y+1][y+1]-c>pesos[y+1][y+1])
			{

				pesos[y+1][y+1]=peso-mp[y+1][y+1]-c;
				que.push(make_pair(pesos[y+1][y+1],make_pair(y+1,y+1)));
			}
	}
	long long int may=LLONG_MIN;
	for(int i=0;i<n;i++)
	{
		may=max(pesos[i][n-1],may);

	}
	return -may;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);a
	while(cin>>c)
		{
			cin>>n;
			
			mp[0][-1]=0;
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					cin>>mp[i][j];
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=n-1;j>i;j--)
					mp[i][j]=mp[i][j]-mp[i][j-1];
			}
			cout<<bfs(0,0)<<endl;
		}

	return 0;
}
