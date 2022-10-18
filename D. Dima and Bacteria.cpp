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
int n,m,k;
int ak[502], dist[500][500], col[100005], color[100005];
bool visited[100005];
vi g[100005];
void dfs(int node, int colo)
{
	visited[node] = 1;
	color[node] = colo;
	for(int i = 0; i < g[node].size(); i++)
	{
		if(!visited[g[node][i]])
			dfs(g[node][i], colo);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n>>m>>k;
	mem(dist,-1);
	for(int i = 0; i < k; i++)
	{
		dist[i][i]=0;
		cin>>ak[i];
		if(i>0) ak[i]+=ak[i-1];
		for(int j = (i==0?0:ak[i-1]); j < ak[i]; j++)
			col[j] = i;
	}
	int a, b, c;
	for(int i = 0; i < m; i++)
	{
		cin>>a>>b>>c;
		a--, b--;
		if(c == 0)
		{
			g[a].pb(b);
			g[b].pb(a);
		}
		a = col[a], b = col[b];
		dist[a][b] = (dist[a][b] == -1 ? c : min(dist[a][b], c));
		dist[b][a] = dist[a][b];
	}
	mem(visited, 0);
	mem(color, -1);
	int colo = 0;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			dfs(i, colo);
			colo++;
		}
	}
	int co;
	for(int i = 0; i < k; i++)
	{
		//cout<<i<<' ';
		if(color[(i==0?0:ak[i-1])] == -1)
		{
			cout<<"No"; return 0;
		}
		co = color[(i==0?0:ak[i-1])];
		//cout<<co<<'#';
		for(int j = (i==0?0:ak[i-1]); j < ak[i]; j++)
		{
			//cout<<j<<' '<<color[j]<<'@';
			if(color[j] != co)
			{
				cout<<"No"; return 0;
			}
		}
	}
		
	for(int p = 0; p < k; p++)
		for(int i = 0; i < k; i++)
			for(int j = 0; j < k; j++)
			{
				if(dist[i][p] != -1 && dist[p][j] != -1)
				{
					if(dist[i][j] == -1) 
						dist[i][j] = dist[i][p] + dist[p][j];
					else
						dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
				}
			}
	cout<<"Yes\n";
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < k; j++)
		{
			if(j > 0) cout<<' ';
			cout<<dist[i][j];
		}
		cout<<endl;
	}
		return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS