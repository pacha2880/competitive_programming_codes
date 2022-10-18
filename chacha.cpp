#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/MinCostMaxFlow.h

// #include <bits/extc++.h> // <- Incluir
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](ll a, ll b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// const ll tam = 1010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
const ll tam = 1000000;

struct Edge
{
	ll to, rev;
	ll flow, cap;
	ll cost;
};
vector<Edge> G[tam];

void addEdge(ll s, ll t, ll cap, ll cost)
{
	Edge a = {t, (ll)G[t].size(), 0, cap, cost};
	Edge b = {s, (ll)G[s].size(), 0, 0, -cost};
	G[s].pb(a);
	G[t].pb(b);
}

// ll n, m; // En vez de n es mejor usar una variable diferente como 'nodes'
          // La cantidad de nodos en la red de flujo suele ser difente a la
          // cantidad en el grafo original

ll S, T;
vector<ll> dist;
ll pot[tam], curFlow[tam], prevNode[tam], prevEdge[tam];
ll Q[tam];
bool inQueue[tam];

ll n = 100000;
ii MinCostMaxFlow()
{
	// bellmanFord();
	ll flow = 0;
	ll flowCost = 0;
	while (true) // always a good start for an algorithm :v
	{
		set<ii> s;
		s.insert( mp(0, S) );
		dist.assign(n, MOD);
		dist[S] = 0;
		curFlow[S] = MOD;
		while (s.size() > 0)
		{
			ll u = s.begin() -> second;
			ll actDist = s.begin() -> first;
			s.erase(s.begin());
			if (actDist > dist[u]) continue;
			for (ll i = 0; i < (ll)G[u].size(); i++)
			{
				Edge &e = G[u][i];
				ll v = e.to;
				if (e.cap <= e.flow) continue;
				ll newDist = actDist + e.cost + pot[u] - pot[v];
				if (newDist < dist[v])
				{
					dist[v] = newDist;
					s.insert( mp(newDist, v) );
					prevNode[v] = u;
					prevEdge[v] = i;
					curFlow[v] = min(curFlow[u], e.cap - e.flow);
				}
			}
		}
		if (dist[T] == MOD) 
			break;
		for (ll i = 0; i < n; i++)
			pot[i] += dist[i];
		ll df = curFlow[T];
		flow += df;
		for (ll v = T; v != S; v = prevNode[v])
		{
			Edge &e = G[prevNode[v]][prevEdge[v]];
			e.flow += df;
			G[v][e.rev].flow -= df;
			flowCost += df * e.cost;
		}
	}
	return mp(flow, flowCost);
}
	ll n1;
ll dir[2][8] = {{1, 1, 0, -1, -1, -1, 0, 1}, {0, 1, 1, 1, 0, -1, -1, -1}};
ll gut[8][3] = {{0, 1, 2}, {2, 3, 4}, {4, 5, 6}, {6, 7, 0}, {0, 2, 3}, {1, 2, 4}, {4, 6, 7}, {5, 6, 0}};
pair<ll, pair<ll, ll>> ar[1010];
bool good(vii &v)
{
	ll co;
	fore(i, 0, 8)
	{
		co = 0;
		fore(j, 0, 3) co += v[gut[i][j]].f;
		if(co == 3) return false;
	}
	return true;
}

void go(ll ind)
{
	vii nue(8);
	ll x = ar[ind].s.f, y = ar[ind].s.s, x1, y1;
	if(x % 2 == 1 || y % 2 == 1) return;
	fore(j, 0, 8)
	{
		x1 = x + dir[0][j], y1 = y + dir[1][j];
		fore(i, 0, n1)
		{
			if(ar[i].s.f == x1 && ar[i].s.s == y1)
			{
				nue[j] = {1, i};
				break;
			}
		}
	}
	if(!good(nue))
	{
		ll co;
		fore(i, 0, 8)
		{
			co = 0;
			fore(j, 0, 3) co += nue[gut[i][j]].f;
			if(co == 3)
			{
				addEdge(ind + 2, 2 + n1 + ind * 8 + i, 1, 0);
				addEdge(2 + n1 + ind * 8 + i, 1, 1, 0);
				fore(j, 0, 3)
				{
					addEdge(2 + nue[gut[i][j]].s, 2 + n1 + ind * 8 + i, 1, 0);
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	cin>>n1;
	S = 0, T = 1;
	ll res = 0;
	fore(i, 0, n1) 
	{
		cin>>ar[i].s.f>>ar[i].s.s>>ar[i].f;
		res += ar[i].f;
		addEdge(0, 2 + i, MOD, ar[i].f);
	}
	fore(i, 0, n1)
	{	
		go(i);
	}
	cout<<res - MinCostMaxFlow().s<<'\n';                                                                                      
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
