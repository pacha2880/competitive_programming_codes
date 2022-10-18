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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct edge
{
	int to, rev;
	ll cap, f;
};
vector<edge> g[2010];
int s, t;
int lev[2010], nex[2010];
bool bfs()
{
	queue<int> que;
	mem(lev, -1);
	int node;
	que.push(s);
	lev[s] = 0;
	while(!que.empty())
	{
		node = que.front();
		//cout<<node<<'\n';
		que.pop();
		fore(i, 0, g[node].size())
		{
			if(g[node][i].cap > g[node][i].f && lev[g[node][i].to] == -1)
			{
				lev[g[node][i].to] = lev[node] + 1;
				que.push(g[node][i].to);
			}
		}
	}
	//cout<<"ya";
	return lev[t] != -1;
}
ll dfs(int node, ll flow)
{
	//cout<<node<<' ';
	if(node == t || flow == 0) return flow;
	for(; nex[node] < g[node].size(); nex[node]++)
	{
		edge &e = g[node][nex[node]];
		if(e.cap > e.f && lev[node] + 1 == lev[e.to])
		{
			int flo = dfs(e.to, min(e.cap - e.f, flow));
			if(flo > 0)
			{
				e.f += flo;
				//g[node][nex[node]].f += flo;
				g[e.to][e.rev].f -= flo;
				return flo;
			}
		}
	}
	return 0;
}
ll maxFlow()
{
	ll flow = 0;
	//cout<<"asd  "<<s<<' '<<t<<'\n';
	while(bfs())
	{
		mem(nex, 0);
		for(int f = dfs(s, MOD); f > 0; f = dfs(s, MOD))
		{
			//cout<<"\n\n\n";
			flow += f;
		}
	}
	return flow;
}
void add(int s, int t, int cap)
{
	edge a = {t, (int)g[t].size(), cap, 0};
	edge b = {s, (int)g[s].size(), 0, 0};
	g[s].pb(a);
	g[t].pb(b);
}
int ar[2010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a, b, c;
	s = n + m + 1, t = n + m + 2;
	//cout<<"asdfasdf\n";
	//cout<<s<<' '<<t<<'\n';
	ll su = 0;
	fore(i, 0, n) {cin>>ar[i]; add(i + 1, t, ar[i]);}
	fore(i, 0, m)
	{
		cin>>a>>b>>c;
		su += c;
		add(s, n + i + 1, c);
		add(n + i + 1, a, MOD);
		add(n + i + 1, b, MOD);
	}
	cout<<su - maxFlow()<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	