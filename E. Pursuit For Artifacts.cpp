#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[tam], art[tam], bri[tam], neo[tam], brn[tam];
vector<int> ot[tam];
bool has[tam];
int nu[tam], lo[tam], con, don[tam];
bool vis[tam];
void brid(int node, int par)
{
	nu[node] = lo[node] = con++;
	fore(i, 0, g[node].size())
	{
		int x = g[node][i];
		if(nu[x] == -1)
		{
			brid(x, node);
			lo[node] = min(lo[node], lo[x]);
			if(nu[node] < lo[x])
			{
				bri[node][i] = 1;
				bri[x][ot[node][i]] = 1;
			}
		}
		else if(x != par)
			lo[node] = min(lo[node], nu[x]);
	}

}

void build(int node, int nu)
{
	don[node] = nu;
	vis[node] = 1;
	fore(i, 0, g[node].size())
	{
		int x = g[node][i];
		if(!vis[x])
		{
			if(bri[node][i])
			{
				con++;
				brn[nu].pb(art[node][i]);
				brn[con].pb(art[node][i]);
				neo[nu].pb(con);
				neo[con].pb(nu);
				build(x, con);
			}
			else
			{
				has[nu] |= art[node][i];
				build(x, nu);
			}
		}
		else
		{
			if(don[x] == don[node])
				has[nu] |= art[node][i];
		}
	}
}
bool can(int a, int b, bool lle)
{
	if(a == b)
		return lle || has[b];
	bool res = false;
	vis[a] = 1;
	fore(i, 0, neo[a].size())
	{
		int x = neo[a][i];
		if(!vis[x])
		{
			res |= can(x, b, lle | has[a] | brn[a][i]);
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a, b, c;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--, b--;
		ot[a].pb(g[b].size());
		ot[b].pb(g[a].size());
		g[a].pb(b);
		g[b].pb(a);
		cin>>c;
		art[a].pb(c);
		art[b].pb(c);
		bri[a].pb(0);
		bri[b].pb(0);
	}
	mem(nu, -1);
	brid(0, -1);
	con = 0;
	build(0, 0);
	cin>>a>>b;
	a--; b--;
	mem(vis, 0);
	// fore(i, 0, n)
	// 	cout<<don[i]<<' ';
	// cout<<'\n';
	// fore(i, 0, con + 1)
	// 	cout<<has[i]<<' ';
	// cout<<'\n';
	if(can(don[a], don[b], false))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil