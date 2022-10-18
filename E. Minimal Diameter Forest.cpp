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
	#define EPS			1e-9
	int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

	using namespace std;

	typedef long long 		ll;
	typedef unsigned long long 		ull;
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	vector<vi> g;
	vector<ii> ed;
	bool visited[1005];
	int parent[1005];
	ii dfs(int node)
	{
		visited[node] = 1;
		ii res(0,node);
		for(int i = 0; i < g[node].size(); i++)
		{
			if(!visited[g[node][i]])
			{
				parent[g[node][i]] = node;
				res = max(res, dfs(g[node][i]));
			}
		}
		res.f++;
		return res;
	}
	ii dfs2(int node,int parent)
	{
		ii res(0,node);
		for(int i = 0; i < g[node].size(); i++)
		{
			if(parent != g[node][i])
			{
				res = max(res, dfs2(g[node][i],node));
			}
		}
		res.f++;
		return res;
	}
	int main()
	{
		ios::sync_with_stdio(false); cin.tie(0);
		//freopen("qwe.txt", "r", stdin);
		//freopen("asd.txt", "w", stdout);
		int n, m, a, b;
		vi v;
		pair<int,int> r,r1;
		cin>>n>>m;
		g.assign(n+1,v);
		for(int i = 0; i < m; i++)
		{
			cin>>a>>b;
			g[a-1].pb(b-1);
			g[b-1].pb(a-1);
		}
		m = n-1 - m;
		vector<ii> pos;
		mem(visited,0);
		for(int i = 0; i< n; i++)
		{		
			if(!visited[i])
			{
				r = dfs(i);
				r = dfs2(r.s,r.s);
				pos.pb(mp(-r.f,r.s));
			}
		}
		int y = 1;
		sort(pos.begin(), pos.end());
		for(int i = 0; i < m; i++)
		{
			mem(visited,0);
			r = dfs(pos[0].s);
			mem(visited,0);
			mem(parent,-1);
			r = dfs(r.s);
			r.f/=2;
			while(r.f--)
			{
				r.s = parent[r.s];
			}
			int j=0;
			while(visited[j]) j++;

			r1 = dfs(j);
			mem(visited,0);
			mem(parent,-1);
			r1 = dfs(r1.s);
			r1.f/=2;
			while(r1.f--)
			{
				r1.s = parent[r1.s];
			}
			ed.pb(mp(r1.s+1,r.s+1));
			g[r1.s].pb(r.s);
			g[r.s].pb(r1.s);
		}
		mem(visited,0);
		r = dfs(0);
		mem(visited,0);
		r = dfs(r.s);
		cout<<r.f-1<<endl;
		for(int i = 0; i < ed.size(); i++)
			cout<<ed[i].f<<' '<<ed[i].s<<'\n';
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS