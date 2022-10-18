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
		typedef unsigned long long 		ull;
		typedef pair<int, int>  ii;
		typedef vector<int>     vi;
		typedef vector<ii>      vii;
		typedef vector<ll>      vll;
		vector<vector<int> > g,gc;
		bool visited[300030];
		int times = 0, low[300030], lle[300030],dis[300030];
		set<pair<int,int> > bri;
		void brid(int node, int par)
		{
			low[node]=times, lle[node]=times;
			visited[node]=1;
			for(int i = 0;i<g[node].size();i++)
			{
				if(!visited[g[node][i]])
				{
					times++;
					brid(g[node][i],node);
					if(lle[node]<low[g[node][i]])
					{
						bri.insert(mp(node,g[node][i]));
						bri.insert(mp(g[node][i],node));
					}
				}
				if(g[node][i]!=par)
						low[node]=min(low[node],low[g[node][i]]);
			}
		}
		void com(int node,int par)
		{
			visited[node]=1;
			for(int i = 0;i<g[node].size();i++)
			{
				if(!visited[g[node][i]])
				{
					if(bri.find(mp(node,g[node][i]))==bri.end())
					{
						com(g[node][i],par);
					}
					else
					{
						gc[par].pb(g[node][i]);
						gc[g[node][i]].pb(par);
						com(g[node][i],g[node][i]);
					}
				}
			}
		}
		void dfs(int node,int tim)
		{
			visited[node]=1;
			dis[node]=tim;
			for(int i = 0;i<gc[node].size();i++)
			{
				if(!visited[gc[node][i]])
					dfs(gc[node][i],tim+1);
			}
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,m,a,b;
			cin>>n>>m;
			vi vv;
			g.assign(n,vv);
			for(int i = 0; i <m; i++)
			{
				cin>>a>>b;
				g[a-1].pb(b-1);
				g[b-1].pb(a-1);
			}
			mem(visited,0);
			brid(0,-1);
			mem(visited,0);
			gc.assign(n,vv);
			com(0,0);
			mem(visited,0);
			dfs(0,0);
			int di = 0,no=0;
			set<ii>::iterator it;
			for(int i = 0;i<n;i++)
			{
				if(di<dis[i])
				{
					di = dis[i];
					no = i;
				}
			}
			mem(visited,0);
			dfs(no,0);
			int res = 0;
			for(int i = 0;i<n;i++)
			{
				res = max(res,dis[i]);
			}
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS