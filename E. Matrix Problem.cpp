#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
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
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
// O(min(E^2∗V^2, E∗V∗FLOW))
struct CheapDinitz{
    const int INF = 1e9 + 7;

    CheapDinitz() {}
    CheapDinitz(int n, int s, int t) {init(n, s, t);}

    int nodes, S, T;
    vi dist;
    vi pot, curFlow, prevNode, prevEdge, Q, inQue;

    struct flowEdge{
        int to, rev, flow, cap, cost;
    };
    vector<vector<flowEdge>> G;
    void init(int n, int s, int t)
    {
        nodes = n, S = s, T = t;
        curFlow.assign(n, 0), prevNode.assign(n, 0), prevEdge.assign(n, 0);
        Q.assign(n, 0), inQue.assign(n, 0);
        G.clear();
        G.resize(n);
    }

    void addEdge(int s, int t, int cap, int cost)
    {
        flowEdge a = {t, (int)G[t].size(), 0, cap, cost};
        flowEdge b = {s, (int)G[s].size(), 0, 0, -cost};
        G[s].pb(a);
        G[t].pb(b);
    }

    void bellmanFord()
    {
        pot.assign(nodes, INF);
        pot[S] = 0;
        int qt = 0;
        Q[qt++] = S;
        for (int qh = 0; (qh - qt) % nodes != 0; qh++)
        {
            int u = Q[qh % nodes];
            inQue[u] = 0;
            for (int i = 0; i < (int)G[u].size(); i++)
            {
                flowEdge &e = G[u][i];
                if (e.cap <= e.flow) continue;
                int v = e.to;
                int newDist = pot[u] + e.cost;
                if (pot[v] > newDist)
                {
                    pot[v] = newDist;
                    if (!inQue[v])
                    {
                        Q[qt++ % nodes] = v;
                        inQue[v] = 1;
                    }
                }
            }
        }
    }

    ii MinCostFlow()
    {
        bellmanFord();
        int flow = 0;
        int flowCost = 0;
        while (true) // always a good start for an algorithm :v
        {
            set<ii> s;
            s.insert({0, S});
            dist.assign(nodes, INF);
            dist[S] = 0;
            curFlow[S] = INF;
            while (s.size() > 0)
            {
                int u = s.begin() -> s;
                int actDist = s.begin() -> f;
                s.erase(s.begin());
                if (actDist > dist[u]) continue;
                for (int i = 0; i < (int)G[u].size(); i++)
                {
                    flowEdge &e = G[u][i];
                    int v = e.to;
                    if (e.cap <= e.flow) continue;
                    int newDist = actDist + e.cost + pot[u] - pot[v];
                    if (newDist < dist[v])
                    {
                        dist[v] = newDist;
                        s.insert({newDist, v});
                        prevNode[v] = u;
                        prevEdge[v] = i;
                        curFlow[v] = min(curFlow[u], e.cap - e.flow);
                    }
                }
            }
            if (dist[T] == INF) 
                break;
            for (int i = 0; i < nodes; i++)
                pot[i] += dist[i];
            int df = curFlow[T];
            flow += df;
            for (int v = T; v != S; v = prevNode[v])
            {
                flowEdge &e = G[prevNode[v]][prevEdge[v]];
                e.flow += df;
                G[v][e.rev].flow -= df;
                flowCost += df * e.cost;
            }
        }
        return {flow, flowCost};
    }
};

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m;
    cin>>n>>m;
    CheapDinitz dinic(n + m  + 2, n + m, n + m + 1);
    int uns = 0;
    fore(i, 0, n)
        fore(j, 0, m)
        {
            int x;
            cin>>x;
            if(x)
                dinic.addEdge(i, n + j, 1, 0);
            else
                dinic.addEdge(i, n + j, 1, 1);
            uns += x;
        }
    int sa = 0, sb = 0;
    fore(i, 0, n)
    {
        int x;
        cin>>x;
        sa += x;
        dinic.addEdge(n + m, i, x, 0);
    }
    fore(i, 0, m)
    {
        int x;
        cin>>x;
        sb += x;
        dinic.addEdge(n + i, n + m + 1, x, 0);
    }
    if(sa == sb)
    {
        auto fl = dinic.MinCostFlow();
        // cout<<fl.f<<' '<<fl.s<<'\n';
        if(fl.f == sa)
            cout<<uns + 2 * fl.s - sa<<'\n';
        else
            cout<<-1<<'\n';
    }
    else
        cout<<-1<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
