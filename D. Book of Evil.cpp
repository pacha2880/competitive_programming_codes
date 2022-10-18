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
int d;
vector<int> g[100010];
int maxo[100010];
int marco[100010];
bool marcad[100010];
void dfs(int node, int pa)
{
	int maxi = -MOD;
	if(marcad[node])
		maxi = 0;
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != pa)
		{
			dfs(g[node][i], node);
			maxi = max(maxi, 1 + maxo[g[node][i]]);
		}
	}
	maxo[node] = maxi;
}
int dfs1(int node, int pa, int capa)
{
	int n = g[node].size();
	int maxa[2][n];
	fore(i, 0, 2) fore(j, 0, n) maxa[i][j] = -MOD;
	if(marcad[node])
		capa = max(capa, 0);
	int mac = -MOD;
	int canti = 0;
	maxa[0][0] = (g[node][0] == pa ? -MOD : maxo[g[node][0]]);
	maxa[1][n-1] = (g[node][n-1] == pa ? -MOD : maxo[g[node][n-1]]);
	//cout<<"node "<<node<<' '<<capa<<'\n';
	fore(i, 1, n)
	{
		maxa[0][i] = max(maxa[0][i-1], (g[node][i] == pa ? -MOD : maxo[g[node][i]]));
		maxa[1][n - i - 1] = max(maxa[1][n - i], (g[node][n - i - 1] == pa ? -MOD : maxo[g[node][n - i - 1]]));
	}
	/*fore(i, 0, n)
	{
		cout<<"asd  "<<g[node][i]<<' '<<maxa[0][i]<<' '<<maxa[1][i]<<'\n';
	}*/
	fore(i, 0, n)
	{
		if(g[node][i] != pa)
		{
			mac = max(((i > 0) ? (maxa[0][i-1]) : (-MOD)), ((i < n - 1) ? (maxa[1][i+1]) : (-MOD)));
			canti += dfs1(g[node][i], node, max(mac + 2, capa + 1)); 
		}
	}
	/*if(d >= max(maxo[node], capa))
	{
		cout<<node<<' '<<maxo[node]<<' '<<capa<<'\n';
	}*/
	return canti + (d >= max(maxo[node], capa));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	cin>>n>>m>>d;
	fore(i, 0, m) 
	{
		cin>>marco[i];
		marco[i]--;
		marcad[marco[i]] = 1;
	}
	int a, b;
	fore(i, 0, n - 1)
	{
		cin>>a>>b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	//fore(i, 0, n) cout<<maxo[i]<<' ';
	//cout<<'\n';
	cout<<dfs1(0, -1, -MOD)<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2