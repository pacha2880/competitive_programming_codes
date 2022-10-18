#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
// #include <ext/rope>
// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/MinCostMaxFlow.h

// #include <bits/extc++.h> // <- Incluir
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

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 1010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int dir[2][8] = {{1, 1, 0, -1, -1, -1, 0, 1}, {0, 1, 1, 1, 0, -1, -1, -1}};
int gut[8][3] = {{0, 1, 2}, {2, 3, 4}, {4, 5, 6}, {6, 7, 0}, {0, 2, 3}, {1, 2, 4}, {4, 6, 7}, {5, 6, 0}};
pair<int, pair<int, int>> ar[tam];
vector<pair<pair<int, int>, vi>> bag;
bool good(vi &v)
{
	int co;
	fore(i, 0, 8)
	{
		co = 0;
		fore(j, 0, 3) co += v[gut[i][j]];
		if(co == 3) return false;
	}
	return true;
}

const ll INF = numeric_limits<ll>::max() / 4;

// Aprox: O(E^2)
// Recordar que tambien esta acotado por el flujo maximo

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<vll> cap, flow, cost;
	vi seen;
	vll dist, pi;
	vector<ii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, vll(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		fore(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		fore(i,0,N) fore(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			fore(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};
bool go(int ind)
{
	vi nue(8);
	int x = ar[ind].s.f, y = ar[ind].s.s, x1, y1;
	vector<pair<pair<int, int>, vi>> ax = bag;
	bool bo = true;
	fore(i, 0, ax.size())
	{
		x1 = ax[i].f.f, y1 = ax[i].f.s;

		fore(j, 0, 8)
		{
			if(x1 + dir[0][j] == x && y1 + dir[1][j] == y)
				ax[i].s[j] = 1;
			if(x + dir[0][j] == x1 && y + dir[1][j] == y1)
				nue[j] = 1;
		}
		if(x1 % 2 == 0 && y1 % 2 == 0 && !good(ax[i].s))
		{
			bo = false;
			break;
		}
	}
	if(x % 2 == 0 && y % 2 == 0)
		bo &= good(nue);
	if(bo)
	{
		ax.pb({{x, y}, nue});
		swap(ax, bag);
	}
	return bo;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	ll res = 0;
	fore(i, 0, n) cin>>ar[i].s.f>>ar[i].s.s>>ar[i].f;
	sort(ar, ar + n);
	reverse(ar, ar + n);
	fore(i, 0, n)
	{	
		if(go(i))
		{
			// cout<<ar[i].f<<'\n';
			res += ar[i].f;
		}
	}
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
