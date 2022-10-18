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
const int tam = 500010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[tam];
vector<int> mig[tam];
vector<int> mag[tam];
int mi[tam], ma[tam], mire[tam], mare[tam], parent[tam];
void mima(int node, int par)
{
	mi[node] = node;
	ma[node] = node;
	fore(i, 0, g[node].size())
	{
		int x = g[node][i];
		if(x != par)
		{
			mima(x, node);
			mig[node][i] = mi[x];
			mag[node][i] = ma[x];
			mi[node] = min(mi[node], mi[x]);
			ma[node] = max(ma[node], ma[x]);
		}
		else
			parent[node] = i;
	}
}
void pars(int node, int par)
{
	if(par != -1)
	{
		mig[node][parent[node]] = mire[node];
		mag[node][parent[node]] = mare[node];
	}
	mire[node] = min(mire[node], node);
	mare[node] = max(mare[node], node);
	vector<int> ax;
	for(int x : g[node])
		if(x != par)
			ax.pb(x);
	int n = ax.size();
	vector<int> pmi(n, MOD), smi(n, MOD), pma(n, -1), sma(n, -1);
	fore(i, 1, n)
	{
		pmi[i] = min(pmi[i - 1], ax[i - 1]);
		pma[i] = max(pma[i - 1], ax[i - 1]);
		smi[n - i - 1] = min(smi[n - i], ax[n - i]);
		sma[n - i - 1] = max(sma[n - i], ax[n - i]);
	}
	fore(i, 0, n)
	{
		int x = ax[i];
		mire[x] = min(pmi[i], min(mire[node], smi[i]));
		mare[x] = max(pma[i], max(mare[node], sma[i]));
		pars(x, node);
	}
}
bool no[tam];
int parnt[tam];
void burn(int node, int par)
{
	if(no[node]) return;
	no[node] = 1;
	for(int x : g[node])
	{
		if(x != par)
		{
			if(parnt[node] == x)
			{
				cout<<-1<<'\n';
				exit(0);
			}
			parnt[x] = node;
			burn(x, node);
		}
	}
}
void barn(int node, int chil)
{
	no[node] = 1;
	int difo = 0, dafa = 0;
	for(int x : g[node])
	{
		if(x != chil && x < node != chil < node)
		{
			if(parnt[node] == x)
			{
				cout<<-1<<'\n';
				exit(0);
			}
			parnt[x] = node;
			burn(x, node);
			difo++;
		}
		if(x != chil && x < node == chil < node)
		{
			if(parnt[x] == node)
			{
				cout<<-1<<'\n';
				exit(0);
			}
			parnt[node] = x;
			dafa++;
		}
	}
	if(difo > 1 || dafa > 1)
	{
		cout<<"-1\n";
		exit(0);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, a ,b;
	cin>>n;
	fore(i, 0, n - 1)
	{
		cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		mig[a].pb(0);
		mig[b].pb(0);
		mag[a].pb(0);
		mag[b].pb(0);
	}
	fore(i, 0, n)
		if(g[i].size() > 3)
		{
			cout<<"-1\n";
			return 0;
		}
	mima(0, -1);
	mire[0] = 0;
	mare[0] = 0;
	pars(0, -1);
	int nopo;
	fore(node, 0, n)
	{
		nopo = 0;
		fore(i, 0, g[node].size())
		{
			if(mig[node][i] < node && mag[node][i] > node)
			{
				// cout<<"hola "<<node+1<<' '<<g[node][i]+1<<'\n';
				if(parnt[g[node][i]] == node)
				{
					cout<<"-1\n";
					return 0;
				}
				parnt[node] = g[node][i];
				burn(node, g[node][i]);
				barn(g[node][i], node);
				nopo++;
			}
		}
		if(nopo > 1)
		{
			cout<<-1<<'\n';
			return 0;
		}
	}
	int imp = 0;
	fore(i, 0, n)
	{
		if(!no[i])
		{
			imp++;
			cout<<i + 1<<' ';
		}
	}
	if(!imp)
		cout<<"-1\n";
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil