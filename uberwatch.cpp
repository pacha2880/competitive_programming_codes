#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
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
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
vector<int> g[500];
bool conected[500][500];
bool visited[500];
int princi;
void dfs(int node)
{
	visited[node] = true;
	int si = g[node].size();
	fore(i, 0, si)
	{
		if(!conected[princi][g[node][i]])
		{
			g[princi].pb(g[node][i]);
			conected[node][g[node][i]] = 1;
		}
		if(!visited[g[node][i]])
			dfs(g[node][i]);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	map<string, int> ma;
	int co = 1;
	string fro, to, s;
	int a, b;
	mem(conected, 0);
	fore(i, 0, n)
	{
		cin>>fro>>s>>s>>s>>to;
		//cout<<fro<<' '<<to<<' ';
		if(ma[fro] == 0)
		{
			ma[fro] = co;
			co++;
		}
		if(ma[to] == 0)
		{
			ma[to] = co;
			co++;
		}
		a = ma[fro]; b = ma[to];
		//cout<<a<<' '<<b<<'\n';
		g[a].pb(b);
		conected[a][b] = 1;
	}
	fore(i, 1, co+1)
	{
		princi = i;
		mem(visited,0);
		dfs(i);
	}
	fore(i, 1, co+1)
	{
		princi = i;
		mem(visited,0);
		dfs(i);
	}
	while(m--)
	{
		cin>>fro>>s>>s>>s>>to;
		//cout<<fro<<' '<<to<<'\n';
		if(ma[fro] == 0 || ma[to] == 0)
			cout<<"Pants on Fire\n";
		else
		{
			a = ma[fro], b = ma[to];
			//cout<<a<<' '<<b<<'\n';
			if(conected[a][b])
				cout<<"Fact\n";
			else
			{
				if(conected[b][a])
					cout<<"Alternative Fact\n";
				else
					cout<<"Pants on Fire\n";
			}
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2