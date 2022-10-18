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
#define forn(i, m)			for(int i = 0; i < n; i++)
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
vector<pair<int, ll>> gp[200020];
vector<int> g[200020];
pair<ll, int> dist[200020];
bool visited[200010];
void dijstra()
{
	int node = 0;
	ll cos;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
	que.push(mp(0, 0));
	dist[0] = mp(0, 0);
	pair<ll, int> can;
	while(!que.empty())
	{
		cos = que.top().f;
		node = que.top().s;
		que.pop();
		if(visited[node])
			continue;
		visited[node] = 1;
		fore(i, 0, g[node].size())
		{
			can = mp(cos + gp[node][i].s, gp[node][i].f);
			if(dist[g[node][i]] > can)
			{
				dist[g[node][i]] = can;
				que.push(mp(can.f, g[node][i]));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, k;
	int a, b, c;
	cin>>n>>m>>k;
	//scanf("%d %d %d", &n, &m, &k);
	fore(i, 0, m)
	{
		//scanf("%d %d %d", &a, &b, &c);
		cin>>a>>b>>c;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		gp[a].pb(mp(0, c));
		gp[b].pb(mp(0, c));
	}
	fore(i, 0, k)
	{
		//scanf("%d %d", &a, &b);
		cin>>a>>b;
		a--;
		g[0].pb(a);
		gp[0].pb(mp(1, b));
	}
	fore(i, 0, n)
	{
		dist[i] = mp(100000000000000000ll, 1);
	}
	dijstra();
	set<int> st;
	fore(i, 0, n)
	{
		//cout<<i + 1<<'\n'<<parent[i].f<<' '<<parent[i].s<<"  dast   "<<dist[i].f<<' '<<dist[i].s<<'\n';
		if(dist[i].s == 1)
		{
			st.insert(i);
		}
	}
	//printf("%d",k - (int)st.size());
	cout<<k - (int)st.size()<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	