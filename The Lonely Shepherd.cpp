#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 86400;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
vector<int> g[100010];
bool visited[100010];
int si[100010];
int k;
void dfs(int node, int par)
{
	si[node] = 1;
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
		{
			dfs(g[node][i], node);
			si[node] += si[g[node][i]];
		}
	}
}
void dfs2(int node, int par)
{
	cout<<"flip "<<node<<'\n';
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
		{
			dfs2(g[node][i], node);
		}
	}
}
bool dfs1(int node, int par, int up)
{
	int tot = up + 1;
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
			tot += si[g[node][i]];
	}

	if(up != 0)
	{
		if(up == k)
		{
			dfs2(par, node);
			cout<<"cut "<<node<<' '<<par<<'\n';
			return true;
		}
	}
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
		{
			if(si[g[node][i]] == k)
			{
				dfs2(g[node][i], node);
				cout<<"cut "<<node<<' '<<g[node][i]<<'\n';
				return true;		
			}
		}
	}

	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
		{
			if(dfs1(g[node][i], node, tot - si[g[node][i]]))
				return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n>>k;
	int a, b;
	fore(i, 0, n-1)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	if(!dfs1(1, 0, 0))
		cout<<-1<<'\n';
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2