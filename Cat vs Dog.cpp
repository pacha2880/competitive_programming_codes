#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
map<int,vector<int> > graph;
vector<bool> visited;
int bfs(int node)
{
	queue<pair<int,int> > que;
	que.push(make_pair(node,1));
	int bo;
	int n=0,b=0;
	visited[node]=true;
	while(!que.empty())
	{
		node=que.front().first;
		bo=que.front().second;
		que.pop();
		if(bo==-1)
			n++;
		else
			b++;

		for(int i=0;i<graph[node].size();i++)
		{
			if(!visited[graph[node][i]])
			{
				visited[graph[node][i]]=true;
				que.push(make_pair(graph[node][i],bo*(-1)));
			}
		}
	}
	return max(b,n);
}
int main()
{
	
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	freopen("ghj", "w", stdout);
	int n,d,v,e,c,res;
	string x,y;
	vector<pair<string,string> > gru;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c>>d>>v;
		visited.assign(v,false);
		graph.clear();
		gru.resize(v);
		for(int j=0;j<v;j++)
		{
			cin>>x>>y;
			gru[j]=make_pair(x,y);
			for(int k=0;k<j;k++)
			{
				if(gru[k].first==gru[j].second||gru[k].second==gru[j].first)
				{
					graph[k].push_back(j);
					graph[j].push_back(k);
				}
			}
		}

	
	res=0;
	for(int i=0;i<v;i++)
	{
		if(!visited[i]) res+=bfs(i);
	}
	cout<<v-res<<endl;
	}
	return 0;
}