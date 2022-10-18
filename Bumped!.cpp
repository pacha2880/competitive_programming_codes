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
int n,m,f,s,t;
map<int,map<int,int> > g;
map<int,vector<int> > gf;
priority_queue<pair<ll,pair<int,bool> >, vector<pair<ll,pair<int,bool> > >, greater<pair<ll,pair<int,bool> > > > que;
int dijkstra(int s, int t)
{
	pair<ll,pair<int,bool> > node = make_pair(0,make_pair(s,1));
	que.push(node);
	map<int,int>::iterator it;
	ll dist[n][2];
	for(int i=0;i<n;i++)
	{
		dist[i][0]=(ll)INT_MAX*3;
		dist[i][1]=(ll)INT_MAX*3;
	}
	dist[s][0]=0;
	dist[s][1]=0;
	while(!que.empty())
	{
		node = que.top();
		que.pop();
		if(node.second.second)
		for( it=g[node.second.first].begin();it!=g[node.second.first].end();it++)
		{
			if(node.first+it->second<dist[it->first][0])
			{
				que.push(make_pair(node.first+it->second,make_pair(it->first,node.second.second)));
				dist[it->first][0]=node.first+it->second;
			}
		}
		else
			for( it=g[node.second.first].begin();it!=g[node.second.first].end();it++)
		{
			dist[it->first][1]=min(dist[it->first][1],dist[node.second.first][1]+it->second);
		}
			for(int i =0;i<gf[node.second.first].size();i++)
			{
				if(dist[node.second.first][0]<dist[gf[node.second.first][i]][1])
				{
					que.push(make_pair(dist[node.second.first][0],make_pair(gf[node.second.first][i],0)));
					dist[gf[node.second.first][i]][1]=dist[node.second.first][0];
				}
			}
	}
	return min(dist[t][1],dist[t][0]);

}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	cin>>n>>m>>f>>s>>t;
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		g[a][b]=c;
		g[b][a]=c;
	}
	for(int i=0;i<f;i++)
	{
		cin>>a>>b;
		gf[a].push_back(b);
	}
	cout<<dijkstra(s,t)<<endl;
	return 0;
}