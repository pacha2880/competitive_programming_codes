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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int xo[tam], vis[tam];
vector<int> g[tam], gp[tam];
iii que[2 * tam];
int BIT[2 * tam], par[20][tam], poso[2][2 * tam], alt[tam];
int posa = 0, posb = 0;
void update(int pos, int val)
{
  pos++;
  while(pos < 2 * tam)
  {
    BIT[pos] += val;
    pos += (pos & -pos);
  }
}

int query(int pos)
{
  pos++;
  int res = 0;
  while(pos > 0)
  {
    res += BIT[pos];
    pos -= (pos & -pos);
  }
  return res;
}
void cal(int node, int x)
{
	vis[node] = 1;
	fore(i, 1, 20)
		par[i][node] = par[i - 1][par[i - 1][node]];
	fore(i, 0, g[node].size())
	{
		int x = g[node][i];
		if(!vis[x])
		{
			alt[x] = alt[node] + 1;
			poso[0][x] = posa++;
			xo[x] = xo[node] ^ gp[node][i];
			par[0][x] = node;
			cal(x, xo[x]);
			poso[1][x] = posa++;
		}
	}
}
struct unionFind {
  vi p;
  unionFind(int n) : p(n, -1) {}
  int findParent(int v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};
int lca(int a, int b)
{
	if(alt[a] < alt[b])
		swap(a, b);
	for(int i = 19; i > -1; i--)
		if(alt[par[i][a]] >= alt[b])
			a = par[i][a];
	for(int i = 19; i > -1; i--)
		if(par[i][a] != par[i][b])
			a = par[i][a], b = par[i][b];
	// cout<<a<<' '<<b<<' '<<par[0][a]<<' '<<par[0][b]<<'\n';
	return a == b ? a : par[0][a];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m, a, b, c;
	cin>>n>>m;
	unionFind u(n);
	fore(i, 0, m)
	{
		cin>>a>>b>>c;
		a--, b--;
		if(u.join(a, b))
		{
			// cout<<a<<' '<<b<<'\n';
			// cout<<c<<'\n';
			g[a].pb(b);
			g[b].pb(a);
			gp[a].pb(c);
			gp[b].pb(c);
		}
		que[i] = {{a, b}, c};
	}
	posa = 0;
	fore(i, 0, n)
	{
		if(!vis[i])
		{
			poso[0][i] = posa++;
			fore(j, 0, 20) par[j][i] = i;
			cal(i, 0);
		}
	}
	u.p.assign(n, -1);
	int d;
	fore(i, 0, m)
	{
		// cout<<i<<'\n';
		a = que[i].f.f, b = que[i].f.s, d = que[i].s;
		// cout<<"### "<<a<<' '<<b<<' '<<d<<'\n';
		if(u.join(a, b))
			cout<<"YES\n";
		else
		{
			c = lca(a, b);
			// cout<<a<<' '<<b<<' '<<c<<'\n';
			// cout<<poso[0][a]<<' '<<poso[0][b]<<' '<<poso[0][c]<<'\n';
			// cout<<c<<' '<<xo[a]<<' '<<xo[b]<<' '<<query(poso[0][a])<<' '<<query(poso[0][b])<<' '<<query(poso[0][c])<<'\n';
			if(query(poso[0][a]) + query(poso[0][b]) - 2 * query(poso[0][c]) == 0 && (xo[a] ^ xo[b] ^ d) == 1)
			{
				cout<<"YES\n";
				while(a != c)
				{
					// cout<<poso[0][a]<<' ';
					// cout<<"-"<<poso[1][a]<<'\n';
					// cout<<a<<'\n';
					update(poso[0][a], 1);
					update(poso[1][a], -1);
					a = par[0][a];
				}
				while(b != c)
				{
					// cout<<poso[0][b]<<' '<<'-'<<poso[1][b]<<'\n';
					update(poso[0][b], 1);
					update(poso[1][b], -1);
					b = par[0][b];
				}
			}
			else
				cout<<"NO\n";
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
