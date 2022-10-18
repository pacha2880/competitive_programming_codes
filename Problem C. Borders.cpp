#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
// const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DMOD=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int tam = 1010;
struct flowEdge
{
    int to, rev, f, cap;
};

vector<vector<flowEdge> > G;

// Añade arista (st -> en) con su capacidad
void addEdge(int st, int en, int cap) {
	// cout<<"add "<<st<<' '<<en<<' '<<cap<<'\n';
    flowEdge A = {en, (int)G[en].size(), 0, cap};
    flowEdge B = {st, (int)G[st].size(), 0, 0};
    G[st].pb(A);
    G[en].pb(B);
}

int nodes, S, T; // asignar estos valores al armar el grafo G
                 // nodes = nodos en red de flujo. Hacer G.clear(); G.resize(nodes);
vi work, lvl;
int Q[200010];

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
            int df = dfs(S, MOD);
            if (df == 0) break;
            flow += df;
        }
    }
    return flow;
}

string tab[110];
int mat[110][110];
    int a, b;
int di[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void fil(int i, int j, int nu)
{
	// cout<<"muuu "<<i<<' '<<j<<' '<<nu<<'\n';
	mat[i][j] = nu;
	fore(k, 0, 4)
	{
		int x = i + di[k][0];
		int y = j + di[k][1];
		if(x >= 0 && x < a && y >= 0 && y < b && mat[x][y] == 0 && tab[x][y] == tab[i][j])
			fil(x, y, nu);
	}
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin>>a>>b;
    int nu = 2;
    fore(i, 0, a){ cin>>tab[i];}
    // cout<<"adsfadfs"<<'\n';
    vii lu;
    fore(i, 0, a)
    fore(j, 0, b)
    	if(mat[i][j] == 0)
    	{
    		fil(i, j, nu++);
    		lu.pb({i, j});
    	}

    // fore(i, 0, a)
   	// {
   	// 	fore(j, 0, b)
   	// 	cout<<mat[i][j]<<' ';
   	// 	cout<<'\n';
   	// }
   	// cout<<nu<<'\n';
    nodes = nu;
    G.resize(nodes);
    S = 0, T = 1;
    // cout<<"DD\n";
    for(ii cat : lu)
    {
    	// cout<<nu<<' '<<mat[cat.f][cat.s]<<'\n';
    	if(tab[cat.f][cat.s] == '0')
    		addEdge(0, mat[cat.f][cat.s], 1);
    	else
    		addEdge(mat[cat.f][cat.s], 1, 1);
    }
    // cout<<"werwer\n";
    set<ii> st;
    set<int> bor;
    fore(i, 0, a)
    fore(j, 0, b)
    {
    	if(i < a - 1 && mat[i][j] != mat[i + 1][j])
    	{
    		if(tab[i][j] == '0')
    			st.insert({mat[i][j], mat[i + 1][j]});
    		else
    			st.insert({mat[i + 1][j], mat[i][j]});
    	}
    	if(j < b - 1 && mat[i][j] != mat[i][j + 1])
    	{
    		if(tab[i][j] == '0')
    			st.insert({mat[i][j], mat[i][j + 1]});
    		else
    			st.insert({mat[i][j + 1], mat[i][j]});
    	}
    	if(i == 0 || i == a - 1 || j == 0 || j == b - 1)
    		bor.insert(mat[i][j]);
    }
    for(ii cat : st)
    {
    	if(!bor.count(cat.f) && !bor.count(cat.s))
    	{
    		addEdge(cat.f, cat.s, 1);
    	}
    }
    // cout<<nu<<'\n';
    cout << maxFlow() + sz(bor)<< '\n';
    return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
