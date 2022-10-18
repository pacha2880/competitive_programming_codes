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
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[tam];
ii dp[2][tam];
bool vis[2][tam];
ii f(int pin, int node, int par)
{
	ii &res = dp[pin][node];
	if(vis[pin][node]) return res;
	vis[pin][node] = 1;
	if(pin)
	{
		res = {1, -sz(g[node])};
		for(int x : g[node])
			if(x != par)
			{
				ii ra;
				if(sz(g[x]) == 1 && sz(g[node]) == 1)
					ra = f(1, x, node);
				else
					ra = f(0, x, node);
				res.f += ra.f;
				res.s += ra.s;
			}
	}
	else
	{
		res = {0, -1};
		for(int x : g[node])
		{
			if(x != par)
			{
				ii ra = max(f(0, x, node), f(1, x, node));
				res.f += ra.f;
				res.s += ra.s;
			}
		}
	}
	// cout<<pin<<' '<<node<<' '<<par<<' '<<dp[pin][node].f<<' '<<dp[pin][node].s<<'\n';
	return res;
}
int col[tam];
void dfs(int pin, int node, int par)
{
	// cout<<pin<<' '<<node<<' '<<par<<' '<<sz(g[node])<<'\n';
	if(pin)
		col[node] = sz(g[node]);
	else
		col[node] = 1;
	if(pin)
	{
		for(int x : g[node])
			if(x != par)
				dfs(0, x, node);
	}
	else
	{
		for(int x : g[node])
			if(x != par)
			{
				if(dp[0][x] > dp[1][x])
					dfs(0, x, node);
				else
					dfs(1, x, node);
			}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, a, b;
	cin>>n;
	fore(i, 0, n - 1)
	{
		cin>>a>>b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	ii cua = max(f(0, 0, -1), f(1, 0, -1));
	if(dp[0][0] > dp[1][0])
		dfs(0, 0, -1);
	else
		dfs(1, 0, -1);
	cout<<cua.f<<' '<<-cua.s<<'\n';
	fore(i, 0, n)
		cout<<col[i]<<' ';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
