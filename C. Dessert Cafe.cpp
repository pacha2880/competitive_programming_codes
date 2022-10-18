#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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
bool vis[tam], hot[tam], has[tam];
vi g[tam];
bool dfs(int node)
{
	has[node] = hot[node];
	vis[node] = 1;
	vi ax;
	for(int x : g[node])
		if(!vis[x])
		{
			has[node] |= dfs(x);
			ax.pb(x);
		}
	g[node] = ax;
	return has[node];
}
int res;
void dfs1(int node, bool par)
{
	int con = par;
	for(int x : g[node])
		con += has[x];
	if(g[node].size() > 0)
	{
		vector<bool> pre(g[node].size()), suf(g[node].size());
		fore(i, 1, g[node].size())
		{
			pre[i] = pre[i - 1] || has[g[node][i - 1]];
			suf[sz(g[node]) - i - 1] = suf[sz(g[node]) - i] || has[g[node][sz(g[node]) - i]];
		}
		fore(i, 0, g[node].size())
			dfs1(g[node][i], par || hot[node] || pre[i] || suf[i]);
	}
	res += con > 1 || hot[node];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, k, a, b, c;
	cin>>n>>k;
	fore(i, 0, n - 1)
	{
		cin>>a>>b>>c;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	fore(i, 0, k)
	{
		cin>>a;
		hot[a - 1] = 1;
	}
	dfs(0);
	mem(vis, 0);
	dfs1(0, 0);
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	