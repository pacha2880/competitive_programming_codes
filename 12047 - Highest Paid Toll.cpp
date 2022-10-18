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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
vector<int> g[2][20020], gp[2][20020];
ll dist[2][20020];
pair<pair<int, int>, int> ar[100020];
int n, m;
void dij(int s, int t, int wa)
{
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll, int>>> que;
	que.push(mp(0, s));
	fore(i, 1, n+1)
		dist[wa][i] = MOD;
	dist[wa][s] = 0;
	ll ax;
	while(!que.empty())
	{
		s = que.top().s;
		que.pop();
		for(int i = 0; i < g[wa][s].size(); i++)
		{
			ax = dist[wa][s] + gp[wa][s][i];
			if(ax < dist[wa][g[wa][s][i]])
			{
				dist[wa][g[wa][s][i]] = ax;
				que.push(mp(ax, g[wa][s][i]));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int s, t, a, b, c, p;
	int cant;
	cin>>cant;
	fore(i, 1, cant + 1)
	{
		cin>>n>>m>>s>>t>>p;
		fore(j, 0, 2) fore(i, 1, n + 1) g[j][i].clear(), gp[j][i].clear();

		fore(i, 0, m)
		{
			cin>>a>>b>>c;
			g[0][a].pb(b);
			gp[0][a].pb(c);
			g[1][b].pb(a);
			gp[1][b].pb(c);
			ar[i] = mp(mp(a, b), c);
		}
		dij(s, t, 0);
		dij(t, s, 1);
		if(dist[0][t] != MOD)
		{
			int res = -1;
			fore(i, 0, m)
			{
				a = ar[i].f.f;
				b = ar[i].f.s;
				c = ar[i].s;
				if(dist[0][a] + dist[1][b] + c <= p)
				{
					res = max(res, c);
				}
			}
			cout<<res<<'\n';
		}
		else
			cout<<-1<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	