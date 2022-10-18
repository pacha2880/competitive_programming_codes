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
		vector<vi> g;
		int tam[200001];
		vi arb;
		int dfs(int node)
		{
			arb.pb(node);
			tam[node] = 1;
			for(int i = 0; i< g[node].size(); i++)
			{
				tam[node] += dfs(g[node][i]);
			}
			return tam[node];
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,m,a,b;
			cin>>n>>m;
			vi v;
			g.assign(n,v);
			for(int i = 1; i<n;i++)
			{
				cin>>a;
				g[a-1].pb(i);
			}
			for(int i = 0; i < n; i++)
				sort(g[i].begin(),g[i].end());
			dfs(0);
			for(int i = 0; i < m; i++)
			{
				cin>>a>>b;
				a--;
				if(tam[a]<b)
					cout<<"-1\n";
				else
					cout<<arb[a+b-1]+1<<'\n';
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS