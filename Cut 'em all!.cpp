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
	vector<vector<int> > g;
	bool visited[100020];
	int n,cant=0;
	bool dfs(int node)
	{
		visited[node] = 1;
		int con=1;
		for(int i=0;i<g[node].size();i++)
		{
			if(g[g[node][i]].size()==1)
				con++;
			else
			{
				if(!visited[g[node][i]])
				{
					if(dfs(g[node][i]))
					{
						cant++;
					}
					else
						con++;
				}
			}
		}
		return con%2==0;
	}
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int a,b;
		cin>>n;
		vi v;
		memset(visited,0,sizeof(visited));
		g.assign(n,v);
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b;
			a--;
			b--;
			g[a].push_back(b);
			g[b].pb(a);
		}
		if(n==1||n==3)
		{
			cout<<-1;
			return 0;
		}
		if(n==2)
		{
			cout<<0;
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			if(g[i].size()>1&&!visited[i])
			{
				if(dfs(i))
					cant++;
				else
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<cant-1;
		return 0;
	}