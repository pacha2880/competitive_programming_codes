#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
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
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[200];
bool visited[200], used[200][200], vasi[200];
pair<int, int> dfs(int node, int pa)
{
	pair<int, int> reso = mp(0, node), raza;
	fore(i, 0, g[node].size())
	{
		if(!visited[g[node][i]] && g[node][i] != pa)
		{
			raza = dfs(g[node][i], node);
			raza.f++;
			reso = max(reso, raza);
		}
	}
	return reso;
}
pair<int, int> dfs1(int node, int pa)
{
	pair<int, int> reso = mp(0, node), raza;
	vasi[node] = 1;
	fore(i, 0, g[node].size())
	{
		if(!visited[g[node][i]] && g[node][i] != pa)
		{
			raza = dfs1(g[node][i], node);
			raza.f++;
			reso = max(reso, raza);
		}
	}
	return reso;
}
int dia(int node)
{
	pair<int, int> cao;
	cao = dfs(node, -1);
	cao = dfs1(cao.s, -1);
	return cao.f;
}
int res = 0;
int n;
void viso(int fro, int node, int pa, int ta)
{
	visited[node] = true;
	if(!used[fro][node])
	{
		used[fro][node] = 1;
		used[node][fro] = 1;
		int mamo = 0;
		mem(vasi, 0);
		fore(i, 0, n)
		{
			if(!visited[i] && !vasi[i])
				mamo = max(dia(i), mamo);
		}
		res = max(res, ta * mamo);
	}
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != pa)
		{
			viso(fro, g[node][i], node, ta + 1);
		}
	}
	visited[node] = false;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);	
	cin>>n;
	int a, b;
	fore(i, 0, n-1)
	{
		cin>>a>>b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	pair<bool, int> pa;
	int mam;
	fore(i, 0, n)
	{
		viso(i, i, -1, 0);
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2