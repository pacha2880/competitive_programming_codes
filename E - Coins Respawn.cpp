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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int lle[2501][2501];
bool vis[2501], vas[2501];
void dfs(int node)
{
	vis[node] = 1;
	fore(i, 0, 2501)
	{
		if(lle[i][node] && !vis[i])
			dfs(i);
	}
}
void dfs1(int node)
{
	vas[node] = 1;
	fore(i, 0, 2501)
	{
		if(lle[node][i] && !vas[i])
			dfs1(i);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m, p, a, b, c;
	cin>>n>>m>>p;
	vii ed(m);
	vi et(m);
	fore(i, 0, m)
	{
		cin>>a>>b>>c;
		lle[a - 1][b - 1] = 1;
		ed[i] = {a - 1, b - 1};
		et[i] = c - p;
	}
	int ras = 0;
	vi dist(n, -MOD);
	dist[0] = 0;
	dfs(n - 1);
	dfs1(0);
	fore(asdf, 0, 2 * n)
		fore(i, 0, m)
			dist[ed[i].s] = max(dist[ed[i].s], dist[ed[i].f] + et[i]);
	ras = dist[n - 1];
	vi dast = dist;
	fore(asdf, 0, 2 * n)
		fore(i, 0, m)
			dast[ed[i].s] = max(dast[ed[i].s], dast[ed[i].f] + et[i]);
	// cout<<ras<<' '<<dist[n - 1]<<'\n';
	bool bo = false;
	fore(i, 0, n)
	{
		if(dist[i] < dast[i] && vis[i] && vas[i])
			bo = true;
	}
	if(bo)
		cout<<-1<<'\n';
	else
		cout<<max(ras, 0);
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
