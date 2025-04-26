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

// #pragma GCC optimization ("O2")
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
struct Dinitz{
    const int INF = 1e9 + 7;
    Dinitz(){}
    Dinitz(int n, int s, int t) {init(n, s, t);}

    void init(int n, int s, int t)
    {
        S = s, T = t;
        nodes = n;
        G.clear(), G.resize(n);
        Q.resize(n);
    }
    struct flowEdge
    {
        int to, rev, f, cap;
    };

    vector<vector<flowEdge> > G;

    // Añade arista (st -> en) con su capacidad
    void addEdge(int st, int en, int cap) {
        flowEdge A = {en, (int)G[en].size(), 0, cap};
        flowEdge B = {st, (int)G[st].size(), 0, 0};
        G[st].pb(A);
        G[en].pb(B);
    }

    int nodes, S, T; // asignar estos valores al armar el grafo G
                    // nodes = nodos en red de flujo. Hacer G.clear(); G.resize(nodes);
    vi work, lvl;
    vi Q;

    bool bfs() {
        int qt = 0;
        Q[qt++] = S;
        lvl.assign(nodes, -1);
        lvl[S] = 0;
        for (int qh = 0; qh < qt; qh++) {
            int v = Q[qh];
            for (flowEdge &e : G[v]) {
                int u = e.to;
                if (e.cap <= e.f || lvl[u] != -1) continue;
                lvl[u] = lvl[v] + 1;
                Q[qt++] = u;
            }
        }
        return lvl[T] != -1;
    }

    int dfs(int v, int f) {
        if (v == T || f == 0) return f;
        for (int &i = work[v]; i < G[v].size(); i++) {
            flowEdge &e = G[v][i];
            int u = e.to;
            if (e.cap <= e.f || lvl[u] != lvl[v] + 1) continue;
            int df = dfs(u, min(f, e.cap - e.f));
            if (df) {
                e.f += df;
                G[u][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

    int maxFlow() {
        int flow = 0;
        while (bfs()) {
            work.assign(nodes, 0);
            while (true) {
                int df = dfs(S, INF);
                if (df == 0) break;
                flow += df;
            }
        }
        return flow;
    }
};
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, w, h;
    cin>>n>>h>>w;
    vii ara(n), arb(n);
    fore(i, 0, n)
    {
        int a, b;
        cin>>a>>b;
        ara[i] = {a - 1, b - 1};
    }
    fore(i, 0, n)
    {
        int a, b;
        cin>>a>>b;
        arb[i] = {a - 1, b - 1};
    }
    vii axa = ara;
    int lo = 1, hi = w + h - 2, mid, res = 0;
    Dinitz dinic;
    int tas;
    auto flow = [&](int mid)
    {
        tas = w * h * (mid + 1) * 2 + 2;
        dinic.init(tas + n, tas - 2, tas - 1);
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        fore(i, 0, mid)
        {
            fore(x, 0, h)
                fore(y, 0, w)
                {
                    fore(j, 0, 4)
                    {
                        int xx = x + dx[j], yy = y + dy[j];
                        if(xx == -1 || xx == h || yy == -1 || yy == w) continue;
                        // cout<<x<<' '<<y<<' '<<h<<' '<<w<<'\n';
                        // cout<<xx<<' '<<yy<<'\n';
                        dinic.addEdge(i * w * h + x * w + y, (mid + 1) * w * h + (i + 1) * w * h + xx * w + yy, 1);
                    }
                    dinic.addEdge(i * w * h + x * w + y, (mid + 1) * w * h + (i + 1) * w * h + x * w + y, 1);
                    dinic.addEdge((mid + 1) * w * h + i * w * h + x * w + y, i * w * h + x * w + y, 1);
                }
        }
        fore(x, 0, h)
            fore(y, 0, w)
                dinic.addEdge((mid + 1) * w * h + mid * w * h + x * w + y, mid * w * h + x * w + y, 1);
        fore(i, 0, n)
        {
            dinic.addEdge(tas - 2, (mid + 1) * w * h + ara[i].f * w + ara[i].s, 1);
            fore(j, 0, mid + 1)
            {dinic.addEdge(w * h * j + arb[i].f * w + arb[i].s, tas + i, 1);}
            dinic.addEdge(tas + i, tas - 1, 1);
        }
        return dinic.maxFlow();
    };
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        
        // cout<<dinic.maxFlow()<<'\n';
        int coso = flow(mid);
        // cout<<'$'<<mid<<' '<<coso<<'\n';
        if(coso == n)
            res = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout<<res<<'\n';
    // cout<<"asdfas"<<endl;

    mid = res;
    
        // cout<<dinic.maxFlow()<<'\n';
        int coso = flow(res);
    // cout<<coso<<'\n';
    set<ii> st;
    fore(i, 0, n)
    {
        string re;
        int x = ara[i].f, y = ara[i].s;
        cout<<x + 1<<' '<<y + 1;
        fore(i, 0, res)
        {
            bool bo = false;
            // cout<<"*****"<<i<<' '<<x<<' '<<y<<"#\n";

            for(auto ed : dinic.G[i * w * h + x * w + y])
            {
                // cout<<'@'<<ed.cap<<' '<<ed.first<<' '<<ed.rev<<' '<<ed.to<<'\n';
                    int totu = ed.to;
                    int xx = (totu - (i + 1) * w * h - (mid + 1) * w * h ) / w, yy = (totu - (i + 1) * w * h - (mid + 1) * w * h ) % w;
                // cout<<xx<<' '<<yy<<'\n';
            }
            bool brak = 0;
            for(auto ed : dinic.G[i * w * h + x * w + y])
            {
                if(ed.cap > 0 && ed.f == ed.cap)
                {
                    if(ed.to >= tas)
                    {
                        brak = 1;
                        break;
                    }
                    int totu = ed.to;
                    int xx = (totu - (i + 1) * w * h - (mid + 1) * w * h ) / w, yy = (totu - (i + 1) * w * h - (mid + 1) * w * h ) % w;
                    // cout<<'^'<<xx<<' '<<yy<<'\n';
                    if(xx > x)
                        re += 'D';
                    else if(xx < x)
                        re += 'U';
                    else if(yy > y)
                        re += 'R';
                    else if(yy < y)
                        re += 'L';
                    else re += 'S';
                    x = xx, y = yy;
                    bo = true;
                    break;
                }
            }
            if(brak) break;
            // cout<<bo<<'\n';
        }
        while(sz(re) < res) re += 'P';
        cout<<' '<<x + 1<<' '<<y + 1<<' '<<re<<'\n';
    }   
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
