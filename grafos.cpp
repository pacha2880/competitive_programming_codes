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

#pragma GCC optimization ("O2")
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
void matriz_adyacencia()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n, vector<int>(n));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
}

vector<vector<int>> g;
void lista_adyacencia()
{
    int n,m;
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].pb(a);
        g[b].pb(a);
    }
}

vector<bool> vis(tam);
void dfs(int node)
{
    vis[node] = 1;
    for(int x : g[node])
        if(!vis[x])
            dfs(x);
}

vector<int> bfs(vector<vector<int>>& g , int v) {
    vector<int> dis(g.size(), -1); // vector de distancias
    queue<int> q;
    dis[v] = 0;
    q.push(v);
    while(!q.empty()) { // mientras haya nodos por procesar
        int node= q.front();
        q.pop();
        for(int x : g[node]) { // para cada y vecino de x
            if(dis[x] == -1) { // si x no fue encolado aun
                dis[x] = dis[node] + 1;
                q.push(x);
            }
        }
    }
    return dis; 
}

int n, m; // dimensiones del tablero
int dir[2][4] = {{0,0,1,-1}, {1,-1,0,0}}; // direcciones
vector<vector<int>> tab, visi;
int floodfill(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || visi[x][y] || tab[x][y] == 0)
        return;
    visi[x][y] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++)
        ret += floodfill(x + dir[0][i], y + dir[1][i]);
    return ret;
}
// g debe ser un DAG
vector<int> topSort(vector<vector<int>> &g, vector<int> in)
{
    int n = in.size();
    vector<int> topo;
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(in[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        topo.push_back(node);
        for(int x : g[node]) 
            if(--in[x] == 0)
                q.push(x);
    }
    return topo;
}

struct edge{
    int u, v, cost;
};
vector<int> bellmanFord(int n, int m, vector<edge> &e, int s){
    vector<int> dis(n, 1e9);
    dis[s] = 0;
    for (int i = 0; i< n-1; i++)
        for (int j = 0; j < m; j++)
            dis[e[j].v] = min(dis[e[j].v], dis[e[j].u] + e[j].cost);
    return dis;
}


vector<int> dijkstra(vector<vector<pair<int, int>>> g, int source)
{
    int n = g.size();
    vector<int> dis(n, 1e9);
    vector<bool> vis(n);
    priority_queue<pair<int, int>> que;
    que.push({0, source});
    dis[source] = 0;
    while(!que.empty())
    {
        int node = que.top().s;
        que.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(ii ed : g[node])
            if(dis[ed.f] > dis[node] + ed.s)
            {
                dis[ed.f] = dis[node] + ed.s;
                que.push({-dis[ed.f], ed.f});
            }
    }
    return dis;
}

void floyd(vector<vector<int> > &dis){
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

struct unionFind {
    vi p;
    unionFind(int n) : p(n, -1) {}
    int findParent(int v) {
        if (p[v] == -1) return v;
        return p[v] = findParent(p[v]);
    }
    bool join(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b) return false;
        p[a] = b;
        return true;
    }
};

int kruskal(vector<pair<int, pair<int, int>>> edges, int n) {
//edges: lista de aristas en la forma {peso, {nodo1, nodo2}}
    sort(edges.begin(),edges.end()); // ordena por peso
    unionFind uni(n);
    int cont = 0, res = 0;
    for(auto e: edges){
        int costo = e.first, u = e.second.first, v = e.second.second;
        if(uni.join(u, v))
        {
            cont++;
            res += costo;
        }
        if(cont == n - 1) // completamos el arbol?
        return res;
    }
    return -1; // si llegamos hasta aca entonces no es conexo
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	
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
