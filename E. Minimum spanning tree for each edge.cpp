#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[tam];
vector<ll> gp[tam];
pair<pair<int, int>, pair<int, int>> ar[tam];
pair<pair<int, int>, pair<int, int>> er[tam];
int parent[tam];

int find(int n)
{
	if(parent[n] == -1) return n;
	return parent[n] = find(parent[n]);
}
int levs[tam];
int pars[20][tam];
int maxop[20][tam];
void dfs(int node, int par, int pua, int lev)
{
	pars[0][node] = par;
	maxop[0][node] = pua;
	levs[node] = lev;
	fore(i, 1, 20)
	{
		if(pars[i - 1][node] != -1)
		{
			pars[i][node] = pars[i - 1][pars[i - 1][node]];
			maxop[i][node] = max(maxop[i - 1][node], maxop[i - 1][pars[i - 1][node]]);
		}
	}
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
			dfs(g[node][i], node, gp[node][i], lev + 1);
	}
}
int lca(int a, int b)
{
	// cout<<"\nraso\n";
	if(levs[a] < levs[b])
		swap(a, b);
	int res = 0, dif = levs[a] - levs[b];
	// cout<<dif<<'\n';
	fore(i, 0, 20)
	{
		if(dif & (1 << i))
		{
			// cout<<i<<' '<<maxop[i][a]<<'\n';
			res = max(res, maxop[i][a]);
			a = pars[i][a];
		}
	}
	// cout<<res<<' '<<a<<' '<<b<<'\n';
	// cout<<pars[0][a]<<' '<<pars[0][b]<<'\n';
	// cout<<maxop[0][a]<<' '<<maxop[0][b]<<'\n';

	if(a == b)
	return res;
	for(int i = 19; i > -1; i--)
	{
		if(pars[i][a] != pars[i][b])
		{
			res = max(res, max(maxop[i][a], maxop[i][b]));
			a = pars[i][a];
			b = pars[i][b];
		}
	}
	// cout<<a<<' '<<b<<'\n';
	return max(res, max(maxop[0][a], maxop[0][b]));
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, m)
	{
		cin>>ar[i].s.f>>ar[i].s.s>>ar[i].f.f;
		ar[i].s.f--;
		ar[i].s.s--;
		ar[i].f.s = i;
		er[i] = ar[i];
	}
	sort(ar, ar + m);
	int co = 0, a, b;
	ll span = 0;
	mem(parent, -1);
	set<int> st;
	int con = 0;
	while(con < n - 1)
	{
		a = find(ar[co].s.f);
		b = find(ar[co].s.s);
		if(a != b)
		{
			st.insert(ar[co].f.s);
			parent[a] = b;
			span += ar[co].f.f;
			g[ar[co].s.f].pb(ar[co].s.s);
			gp[ar[co].s.f].pb(ar[co].f.f);
			g[ar[co].s.s].pb(ar[co].s.f);
			gp[ar[co].s.s].pb(ar[co].f.f);
			con++;
		}
			co++;
	}
	mem(pars, -1);
	mem(maxop, -1);
	dfs(0, -1, -1, 0);
	// fore(i, 0, n)
	// {
	// 	fore(j, 0, 5)
	// 	{
	// 		cout<<'('<<j<<','<<pars[j][i]<<','<<maxop[j][i]<<')'<<' ';
	// 	}
	// 	cout<<'\n';
	// }
	fore(i, 0, m)
	{
		if(st.count(er[i].f.s))
			cout<<span<<'\n';
		else
		{
			cout<<span - lca(er[i].s.f, er[i].s.s) + er[i].f.f<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	