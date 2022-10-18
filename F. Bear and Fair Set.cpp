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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
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
const int tam = 10010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
struct edge
{
	int to, cap, used;
	int rev;
};
vector<edge> g[4 * tam];
pair<int, int> ar[tam];
int niv[4 * tam];
int ind[4 * tam];
bool bfs(int from, int to)
{
	mem(niv, -1);
	niv[from] = 0;
	queue<int> que;
	que.push(from);
	int node;
	while(!que.empty())
	{
		node = que.front();
		// cout<<node<<' '<<que.size()<<'\n';
		que.pop();
		fore(i, 0, g[node].size())
		{
			// cout<<i<<'\n';
			if(niv[g[node][i].to] == -1 && g[node][i].cap > g[node][i].used)
			{
				niv[g[node][i].to] = niv[node] + 1;
				que.push(g[node][i].to);
			}
			// cout<<i<<'\n';
		}
	}
	// cout<<"to "<<niv[to];
	return niv[to] != -1;
}
int dfs(int node, int to, int flow)
{
	// cout<<node<<' '<<niv[node]<<' '<<flow<<'\n';
	if(node == to) return flow;
	edge *tu;
	for(;ind[node] < g[node].size(); ind[node]++)
	{
		tu = &g[node][ind[node]];
		// cout<<tu.to<<' '<<niv[tu.to]<<' '<<tu.cap<<' '<<tu.used<<'\n';
		if(tu->cap > tu->used && niv[tu->to] == niv[node] + 1)
		{
			int re = dfs(tu->to, to, min(flow, tu->cap - tu->used));
			if(re > 0)
			{
				tu->used += re;
				g[tu->to][tu->rev].used -= re;
				return re;
			}
		}
	}
	return 0;
}
int flow(int from, int to)
{
	int flow = 0, x;
	while(bfs(from, to))
	{
		// cout<<flow<<'\n';
		mem(ind, 0);
		do
		{
			x = dfs(from, to, MOD);
			flow += x;
		}
		while(x > 0);
	}
	return flow;
}
void daf(int node)
{
	cout<<node<<' '<<niv[node]<<'\n';
	fore(i, 0, g[node].size())
	{
		if(g[node][i].cap > g[node][i].used)
			daf(g[node][i].to);
	}
	cout<<"-- "<<node<<'\n';
}
void add(int fro, int to, int cap)
{
	edge x, y;
	x.to = to;
	x.cap = cap;
	x.used = 0;
	x.rev = g[to].size();
	y.to = fro;
	y.cap = cap;
	y.used = cap;
	y.rev = g[fro].size();
	g[fro].pb(x);
	g[to].pb(y);
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, b, q;
	cin>>n>>b>>q;
	fore(i, 0, q)
		cin>>ar[i].f>>ar[i].s;
	sort(ar, ar + q);
	if(ar[q - 1].f != b)
		ar[q++] = {b, n};
	// cout<<q<<'\n';
	int las = 0, can = 0;
	// a partir de b + 7
	int nex = b + 7;
	fore(i, 0, q)
	{
		if(can > ar[i].s)
		{
			cout<<"unfair\n";
			return 0;
		}
		if(las < ar[i].f && can < ar[i].s)
		{
			add(0, nex, ar[i].s - can);
			fore(j, las + 1, ar[i].f + 1)
				add(nex, j, 1);
			nex++;
		}
		las = ar[i].f;
		can = ar[i].s;
	}
	fore(i, 1, b + 1)
		add(i, b + 1 + i % 5, 1);
	fore(i, 1, 6)
		add(b + i, b + 6, n / 5);
	// cout<<"ddddddd\node";
	// bfs(0, b + 6);
	// daf(0);
	// cout<<"---------\n";
	int flo = flow(0, b + 6);
	// cout<<"==================\n";
	// cout<<'\n'<<flo<<'\n';
	cout<<(flo == n ? "fair" : "unfair")<<'\n';
	// cout<<"what\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	