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
double mp[110][110],dist[110];

int n;
double bfs()
{
	priority_queue<pair<double,int> > que;
	que.push(make_pair(0,0));
	double peso;
	int node;
	while(!que.empty())
	{
		node=que.top().second, peso=que.top().first;
		que.pop();
		for(int i=0;i<n+2;i++)
		{
			if(peso-mp[node][i]>dist[i])
			{
				dist[i]=peso-mp[node][i];
				que.push(make_pair(dist[i],i));
			}
		}
	}	return -dist[1];
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	for(int i=0;i<110;i++)
		dist[i]=INT_MIN;
	double f,x,y,d;
	cin>>n;
	pair<pair<int,int>,int> coor[n+2];
	cin>>x>>y;
	coor[0]=make_pair(make_pair(x,y),0);
	cin>>x>>y;
	coor[1]=make_pair(make_pair(x,y),0);
	mp[0][1]=sqrt((x-coor[0].first.first)*(x-coor[0].first.first)+(y-coor[0].first.second)*(y-coor[0].first.second));
	mp[1][0]=mp[0][1];
	for(int i=2;i<n+2;i++)
	{
		cin>>x>>y>>f;
		coor[i]=make_pair(make_pair(x,y),f);
		for(int j=0;j<i;j++)
		{
			d=sqrt((coor[j].first.first-x)*(coor[j].first.first-x)+(coor[j].first.second-y)*(coor[j].first.second-y));
			if(f>d)
				mp[i][j]=min(d,f-d);
			else
				mp[i][j]=d-f;
			if(coor[j].second>d)
				mp[j][i]=min(d,coor[j].second-d);
			else
				mp[j][i]=d-coor[j].second;

		}
	}
	cout<<fixed<<setprecision(2)<<bfs();
	return 0;
}