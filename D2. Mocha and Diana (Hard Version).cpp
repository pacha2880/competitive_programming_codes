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
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
int par[tam];
int find(int n)
{
	if(par[n] == -1) return n;
	return par[n] = find(par[n]);
}
vi g[tam];
bool vis[tam];
int gru = 0;
vi gr[2 * tam];
void dfs(int node)
{
	vis[node] = 1;
	gr[gru].pb(node);
	for(int x : g[node])
		if(!vis[x])
			dfs(x);
}
int el[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, ma, mb, a, b;
	cin>>n>>ma>>mb;
	mem(par, -1);
	// set<int> sat;
	fore(i, 0, ma)
	{
		cin>>a>>b;
		a--;
		b--;
		// sat.insert(a);
		// sat.insert(b);
		a = find(a);
		b = find(b);
		if(a != b)
			par[a] = b;
	}
	fore(i, 0, mb)
	{
		cin>>a>>b;
		a--, b--;
		// sat.insert(a);
		// sat.insert(b);
		g[a].pb(b);
		g[b].pb(a);
	}
	// cout<<sat.size()<<'\n';
	fore(i, 0, n)
		if(!vis[i])
		{
			dfs(i);
			gru++;
		}
	set<int> pars;
	for(int x : gr[0])
	{
		el[find(x)] = x;
		pars.insert(find(x));
	}
	vii res;
	// cout<<pars.size()<<' '<<gru<<'\n';
	fore(i, 1, gru)
	{
		if(pars.size() > 1)
		{
			a = find(gr[i][0]);
			pars.erase(a);
			res.pb({gr[i][0], el[*pars.begin()]});
			par[a] = *pars.begin();
			for(int x : gr[i])
			{
				el[find(x)] = x;
				pars.insert(find(x));
			}
		}
		else
		{
			bool bo = false;
			for(int x : gr[i])
			{
				a = find(x);
				if(bo)
				{
					el[a] = x;
					pars.insert(a);
				}
				else if(*pars.begin() != a)
				{
					res.pb({x, el[*pars.begin()]});
					par[a] = *pars.begin();
					bo = true;
				}
			}
			if(!bo) 
			{
				// for(int x : pars) cout<<x + 1<<',';
				// cout<<'\n';
				// cout<<gr[i][0] + 1<<' '<<find(gr[i][0]) + 1<<' '<<*pars.begin() + 1<<' '<<find(*pars.begin()) + 1<<'\n';
				if(gru < 2 * tam)
				gr[gru++] = gr[i];
			}
		}
	}
	cout<<res.size()<<'\n';
	for(ii x : res)
		cout<<x.f + 1<<' '<<x.s + 1<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
