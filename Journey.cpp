#include <bits/stdc++.h>
#define PI 			acos(-1)
#define fi 			(1+sqrt(5))/2
#define Binet(n)	(pow(fi,n)-pow(-fi,-n))/sqrt(5)
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
double tot=0;
map<int,vector<int> > graph;
vector<bool> visited;
dfs(int node, double pro,double part)
{
	bool v=true;
	visited[node]=true;
	for(int i=0;i<graph[node].size();i++)
	{
		if(!visited[graph[node][i]])
		{
			v=false;
			dfs(graph[node][i],pro+1,(node==0?graph[0].size():(graph[node].size()-1))*part);
		}
	}
	if(v) {tot+= pro/part;}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n, a, b;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	visited.assign(n,false);
	dfs(0,0,1);
	cout<<fixed<<setprecision(15)<<tot;

	return 0;
}