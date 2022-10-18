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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int n, m;
uint64_t g[70];
uint64_t res = 0, su, ax;
// unordered_set<uint64_t> mem;
int stop = 0, ans;
void go(int i, uint64_t pio) {
	// if (checkTL())
	// 	return;
	// su = 0;
	// fore(j, i, n)
	// 	if((pio >> j) & 1)
	// 		su |= (pio & ~g[j]);
	if(__builtin_popcountll(pio) < ans) return;
	if(i == n) {
		stop = 1;
		res = pio;
		// mem.insert(pio);
		return;
	}
	//memorization ??
	// if(mem.count(pio))
		// return;
	go(i + 1, pio & ~(1ll << i)); // fo not take i-th element
	if((pio >> i) & 1)
		go(i + 1, pio & (g[i] | (1ull << i))); // take it
	// mem.insert(pio);
}
vi g1[100000];
bool vis[100000];
int dfs(int node)
{
	vis[node] = 1;
	int res = 1;
	for(int x : g1[node])
		if(!vis[x])
			res += dfs(x);
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	cin>>n>>m;
	if(n <= 60)
	{
		fore(i, 0, n)
		{
			g[i] = ((1ull<<n) - 1) ^ (i);
		}
		int a, b;
		while(m--)
		{
			cin>>a>>b;
			g[a] ^= 1ull << b;
			g[b] ^= 1ull << a;
		}
		fore(i, 0, n)
		{
			// g[i] ^= 1ull << i;
			// cout<<i<<'\n';
			// fore(j, 0, n)
			// 	cout<<((g[i]>>j) & 1)<<' ';
			// cout<<'\n';
		}
		ax = (1ull<<n) - 1;
		uint64_t add = 0;
		fore(i, 0, n)
		{
			if((g[i] ^ ax) == (1ull << i))
			{
				fore(j, 0, n)
					g[j] &= ~(1ull << i);
				add |= (1ull << i);
				ax &= ~(1ull << i);
			}
		}
		// go(0, ax);
		for (ans = n; !stop; ans--) {
			go(0, ax);
		}
		res |= add;
		int tam = __builtin_popcountll(res);
		if(tam >= n - 28)
			cout<<tam<<'\n';
		else
			cout<<-1<<'\n';
	}
	else
	{
		int a, b;
		while(m--)
		{
			cin>>a>>b;
			g1[a].pb(b);
			g1[b].pb(a);
		}
		assert(dfs(0) == n);
		cout<<"-1\n";
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil