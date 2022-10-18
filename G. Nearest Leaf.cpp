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
#define forn(i, n)			for(int i = 0; i < n; i++)
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
ll ar[500050], t[2000020];
pair<int, int> ran[500050];
ll lazy[2000020];
vector<int> g[500050];
vector<int> gp[500050];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = ar[b];
		return;
	}
	int mid = (b + e) / 2, l = 2 * node + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = min(t[l], t[r]);
}
void update(int b, int e, int node, int i, int j, int val)
{
	if(b > e) return;
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	t[node] += lazy[node];
	if(b != e)
	{
		lazy[l] += lazy[node];
		lazy[r] += lazy[node];
	}
	lazy[node] = 0;
	if(b > j || e < i) return;
	if(b == e)
	{
		t[node] += val;
	}
	else if(b >= i && e <= j)
	{
		t[node] += val;
		lazy[l] += val;
		lazy[r] += val;
	}
	else
	{
		update(b, mid, l, i, j, val);
		update(mid + 1, e, r, i, j, val);
		t[node] = min(t[l], t[r]);
	}
}
ll query(int b, int e, int node, int i, int j)
{
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	t[node] += lazy[node];
	if(b != e)
	{
		lazy[l] += lazy[node];
		lazy[r] += lazy[node];
	}
	lazy[node] = 0;
	if(b >= i && e <= j)
		return t[node];
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	if(mid >= j)
		return query(b, mid, l, i, j);
	return min(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
void dfs(int node, ll dis)
{
	//cout<<node<<' '<<dis<<'\n';
	ran[node] = {node, node};
	if(g[node].size() == 0)
		ar[node] = dis;
	else
	{
		ar[node] = 1ll * MOD * MOD;
		fore(i, 0, g[node].size())
		{
			//cout<<i<<'\n';
			dfs(g[node][i], dis + gp[node][i]);
			ran[node].f = min(ran[node].f, ran[g[node][i]].f);
			ran[node].s = max(ran[node].s, ran[g[node][i]].s);
		}
	}
}
vector<pair<pair<int, int>, int>> que[500050];
ll res[500050];
int n;
void dfs1(int node)
{
	//cout<<"ran "<<node<<' '<<ran[node].f<<' '<<ran[node].s<<'\n';
	for(auto cat : que[node])
	{
		//cout<<cat.s<<' '<<cat.f.f<<' '<<cat.f.s<<'\n';
		res[cat.s] = query(0, n - 1, 0, cat.f.f, cat.f.s);
	}
	//cout<<node<<'\n';
	int to;
	fore(i, 0, g[node].size())
	{
		to = g[node][i];
		update(0, n - 1, 0, ran[to].f, ran[to].s, -gp[node][i]);
		update(0, n - 1, 0, 0, ran[to].f - 1, gp[node][i]);
		update(0, n - 1, 0, ran[to].s + 1, n - 1, gp[node][i]);
		dfs1(to);
		update(0, n - 1, 0, ran[to].f, ran[to].s, gp[node][i]);
		update(0, n - 1, 0, 0, ran[to].f - 1, -gp[node][i]);
		update(0, n - 1, 0, ran[to].s + 1, n - 1, -gp[node][i]);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int  q;
	cin>>n>>q;
	int a, b, c;
	fore(i, 1, n)
	{
		cin>>a>>b;
		g[a - 1].pb(i);
		gp[a - 1].pb(b);
	}
	//cout<<"a\n";
	dfs(0, 0);
	//cout<<"b\n";
	fore(i, 0, q)
	{
		cin>>a>>b>>c;
		que[a - 1].pb({{b - 1, c - 1}, i});
	}
	//cout<<"c\n";
	init(0, n - 1, 0);
	//cout<<"d\n";
	dfs1(0);
	//cout<<"e\n";
	fore(i, 0, q)
		cout<<res[i]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	