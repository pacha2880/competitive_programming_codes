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
const int tam = 600010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vii g[tam];
struct unionFind{
    vi p;
    unionFind(int n) : p(n, -1){}
    int find(int x)
    {
        if(p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
    bool join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        p[a] = b;
        return true;
    }
};
int par[20][tam], mins[20][tam];
int prof[tam];
void dfs(int node, int p = -1, int pro = 0)
{
    prof[node] = pro;
    // cout<<node<<' '<<pro<<'\n';
    for(ii cat : g[node])
        if(cat.f != p)
        {
            dfs(cat.f, node, pro + 1);
            mins[0][cat.f] = cat.s;
            par[0][cat.f] = node;
        }
}
void build(int n)
{
    fore(i, 0, 19)
        fore(j, 0, n)
            {
                par[i + 1][j] = par[i][par[i][j]];
                mins[i + 1][j] = min(mins[i][j], mins[i][par[i][j]]);
            }
}
int query(int a, int b)
{
    int res = MOD * MOD;
    // cout<<a<<' '<<b<<' '<<prof[a]<<' '<<prof[b]<<'\n';
    if(prof[a] < prof[b]) swap(a, b);
    for(int i = 19; i >= 0; i--)
    {
        if(prof[par[i][a]] >= prof[b])
        {
            // cout<<i<<' '<<a<<' '<<mins[i][a]<<'\n';
            // cout<<par[i][a]<<'\n';
            res = min(res, mins[i][a]), a = par[i][a];
        }
    }
    if(a == b)
    return res;
    // cout<<res<<'\n';
    for(int i = 19; i >= 0; i--)
    {
        if(par[i][a] != par[i][b])
        {
            res = min({res, mins[i][a], mins[i][b]});
            a = par[i][a], b = par[i][b];
        }
    }
    // cout<<a<<' '<<b<<' '<<res<<'\n';
    return min({res, mins[0][a], mins[0][b]});
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m, q;
    cin>>n>>m>>q;
    vector<string> tab(n);
    ii esquinero(0, 0);
    queue<ii> que;
    vector<vi> dis(n, vi(m, -1));
    fore(i, 0, n)
    {
        cin>>tab[i];
        fore(j, 0, m)
        {
            if(tab[i][j] == '#')
                esquinero = max(esquinero, {i, j});
            if(tab[i][j] == 'v')
                que.push({i, j}), dis[i][j] = 0;
        }
    }
    // cout<<n<<' '<<m<<'\n';
    auto in = [&](int x, int y)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    };
    vii dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    while(!que.empty())
    {
        auto [x, y] = que.front();
        // cout<<'#'<<x<<' '<<y<<' '<<dis[x][y]<<'\n';
        que.pop();
        fore(i, 0, 4)
        {
            int xx = x + dir[i].f, yy = y + dir[i].s;
            // cout<<xx<<' '<<yy<<' '<<in(xx, yy)<<'\n';
            if(in(xx, yy) && dis[xx][yy] == -1)
            {
                dis[xx][yy] = dis[x][y] + 1;
                que.push({xx, yy});
            }
        }
    }
    // cout<<n<<' '<<m<<'\n';
    // fore(i, 0, n)
    // {
    //     fore(j, 0, m)
    //     {
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    vector<vi> ari;
    auto encode = [&](int x, int y, int z){
        return x * m + y + z * n * m;
    };
    fore(i, 0, n)
        fore(j, 0, m)
        {
            if(tab[i][j] != '#')
            {
                if(i < n - 1)
                {
                    if(tab[i + 1][j] != '#')
                        ari.pb({min(dis[i][j], dis[i + 1][j]), encode(i, j, 0), encode(i + 1, j, 0)}),
                        ari.pb({min(dis[i][j], dis[i + 1][j]), encode(i, j, 1), encode(i + 1, j, 1)});
                }
                if(j < m - 1)
                {
                    if(tab[i][j + 1] != '#')
                    {
                        if(i > esquinero.f && j == esquinero.s - 1)
                            ari.pb({min(dis[i][j], dis[i][j + 1]), encode(i, j, 0), encode(i, j + 1, 1)}),
                            ari.pb({min(dis[i][j], dis[i][j + 1]), encode(i, j, 1), encode(i, j + 1, 0)});
                        else
                            ari.pb({min(dis[i][j], dis[i][j + 1]), encode(i, j, 0), encode(i, j + 1, 0)}),
                            ari.pb({min(dis[i][j], dis[i][j + 1]), encode(i, j, 1), encode(i, j + 1, 1)});
                    }
                }
            }
        }
    sort(all(ari), greater<>());
    unionFind uni(n * m * 2);
    for(vi x : ari)
    {
        // cout<<x[1]<<' '<<x[2]<<'\n';
        if(uni.join(x[1], x[2]))
            g[x[1]].pb({x[2], x[0]}), g[x[2]].pb({x[1], x[0]});
    }
    // lca y tabla de minimis
    dfs(0);
    mins[0][0] = MOD * MOD;
    build(2 * n * m);
    fore(i, 0, q)
    {
        int x, y;
        cin>>x>>y;
        x--, y--;
        cout<<query(encode(x, y, 0), encode(x, y, 1))<<'\n';
    }
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasándola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Si te caes 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad.
// Take a sad song and make it better.
