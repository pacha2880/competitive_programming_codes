#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int n, m;
char mapa[2000][2000];
int usados[2000];
int mapai[2000][2000];
vector<int> g[2000];
int gp[2000][2000];
int level[2000];
bool bfs()
{
	queue<int> que;
	que.push(0);
	int node, lev;
	mem(level,-1);
	level[0] = 0;
	while(!que.empty())
	{
		node = que.front();
		que.pop();
		for(int i = 0; i < g[node].size(); i++)
		{
			if(level[g[node][i]] == -1 && gp[node][g[node][i]] > 0)
			{
				que.push(g[node][i]);
				level[g[node][i]] = level[node] + 1;
			}
		}
	}
	return level[n+m+1] != -1;
}
int dfs(int node, int floc)
{
	if(node == n+m+1) return floc;
	for(;usados[node] < g[node].size(); usados[node]++)
	{
		int u = g[node][usados[node]];
		if(level[u] == level[node]+1 && gp[node][u] > 0)
		{
			int flow = dfs(u, min(gp[node][u],floc));
			if(flow > 0)
			{
				gp[node][u] -= flow;
				gp[u][node] += flow;
				return flow;
			}
		}
	}
	return 0;
}
int maxFlow()
{
	int flow = 0;
	while(bfs())
	{
		int ax;
		memset(usados, 0, sizeof(usados));
		//cout<<'=';
		while(ax = dfs(0, MOD))
		{
			//cout<<3;
			//cout<<ax<<' ';
			flow += ax;
		}
	}
	return flow;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--)
	{
		for(int i = 0; i < 2000; i++)
		{
			g[i].clear();
		}
		cin>>n>>m;
		int x, y;
		string s;
		memset(mapai, -1, sizeof(mapai));
		mem(gp,0);
		for(int k = 0; k < n; k++)
		{
			cin>>x>>y>>s;
			for(int i = x; i < x + s.size(); i++)
			{
				mapa[i][y] = s[i-x];
				mapai[i][y] = k+1;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			gp[0][i] = 1;
			g[0].pb(i);
			g[i].pb(0);
			gp[i][0] = 0;
		}
		for(int k = n+1; k <= n+m; k++)
		{
			cin>>x>>y>>s;
			for(int i = y; i < y + s.size(); i++)
			{
				if(mapai[x][i] != -1)
				{
					if(mapa[x][i] != s[i-y])
					{
						g[mapai[x][i]].pb(k);
						gp[mapai[x][i]][k] = 1;
						g[k].pb(mapai[x][i]);
						gp[k][mapai[x][i]]=0;
					}
				}
			}
		}
		for(int i = n+1; i <= n+m; i++)
		{
			g[i].pb(n+m+1);
			gp[i][n+m+1] = 1;
			g[n+m+1].pb(i);
			gp[n+m+1][i] = 0;
		}
		int asd = maxFlow();
		cout<<n+m - asd<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS