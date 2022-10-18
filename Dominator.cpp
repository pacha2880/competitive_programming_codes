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
		vector<vector<int>> g;
		vector<vector<int>> no;
		bool nr[10000], visited[10000];
		int marcado = -1;
		void dfs(int node)
		{
			visited[node]=1;
			if(node==marcado)
				return;
			if(marcado!=-1)
				no[marcado][node]=0;
			else
				nr[node]=1;
			for(int i = 0; i < g[node].size(); i++)
			{
				if(!visited[g[node][i]])
				{
					dfs(g[node][i]);
				}
			}

		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("asd.txt", "r", stdin);
			//freopen("", "w", stdout);
			int ca;
			cin>>ca;
			for(int er = 0; er<ca;er++)
			{
			int n,a;
			cin>>n;
			vi v,nv(n,1);
			no.clear();
			g.clear();
			marcado=-1;
			for(int i = 0; i < n; i++)
			{
				no.pb(nv);
				g.pb(v);
				for(int j = 0; j<n; j++)
				{
					cin>>a;
					if(a)
					{
						g[i].pb(j);
					}
				}
			}
			mem(nr,0);
			mem(visited,0);
			dfs(0);
			for(int i = 0; i < n; i++)
			{
				mem(visited,0);
				marcado = i;
				dfs(0);
			}
			cout<<"Case "<<er+1<<':'<<'\n';
			cout<<'+';
			for(int i = 0; i < 2*n-1; i++)
			{
				cout<<'-';
			}
			cout<<"+\n";
			for(int i = 0; i < n; i++)
			{
				cout<<'|';
				for(int j = 0; j < n; j++)
				{
					if(no[i][j]&&nr[j])
					{
						cout<<"Y|";
					}
					else
						cout<<"N|";
				}
				cout<<endl;

			cout<<'+';
			for(int i = 0; i < 2*n-1; i++)
			{
				cout<<'-';
			}
			cout<<"+\n";
			}
			}	
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS