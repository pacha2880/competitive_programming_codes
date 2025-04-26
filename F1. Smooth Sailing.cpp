// https://codeforces.com/problemset/problem/1920/F1
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
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m, q;
    cin>>n>>m>>q;
    vector<string> mat(n);
    vii volco;
    ii oro;
    fore(i, 0, n)
    {
        cin>>mat[i];
        fore(j, 0, m)
            if(mat[i][j] == 'v')
                volco.pb({i, j});
            else if(mat[i][j] == '#')
                oro = {i, j};
    }
    vector<vi> dis(n, vi(m, -1));
    queue<ii> que;
    for(ii cat : volco)
    {
        dis[cat.f][cat.s] = 0;
        que.push(cat);
    }
    vii dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
    vii dir1({{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
    auto in = [&](int x, int y){
        return x >=0 && x < n && y >= 0 && y < m;
    };
    while(!que.empty())
    {
        int x = que.front().f, y = que.front().s;
        que.pop();
        fore(i, 0, 4)
        {
            int xx = x + dir[i].f, yy = y + dir[i].s;
            if(in(xx, yy) && dis[xx][yy] == -1)
            {
                dis[xx][yy] = dis[x][y] + 1;
                que.push({xx, yy});
            }
        }
    }
    // fore(i, 0, n)
    // {
    //     fore(j, 0, m)
    //     {
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        x--, y--;
        // cout<<"hola"<<x<<' '<<y<<' '<<dis[x][y]<<'\n';
        int lo = 0, hi = dis[x][y], mid, res = -1;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            vector<vi> vis(n, vi(m));
            queue<ii> que;
            vis[x][y] = 1;
            que.push({x, y});
            while(!que.empty())
            {
                int x = que.front().f, y = que.front().s;
                que.pop();
                fore(i, 0, 4)
                {
                    int xx = x + dir[i].f, yy = y + dir[i].s;
                    if(in(xx, yy) && dis[xx][yy] >= mid && mat[xx][yy] != '#' && !vis[xx][yy])
                    {
                        vis[xx][yy] = 1;
                        que.push({xx, yy});
                    }
                }
            }
            bool bo = 1;
            vis[oro.f][oro.s] = 1;
            que.push(oro);
            
            while(!que.empty())
            {
                int x = que.front().f, y = que.front().s;
                if(x == 0 || x == n - 1 || y == 0 || y == m - 1)
                {
                    bo = false;
                    break;
                }
                que.pop();
                fore(i, 0, 8)
                {
                    int xx = x + dir1[i].f, yy = y + dir1[i].s;
                    if(in(xx, yy) && !vis[xx][yy])
                    {
                        vis[xx][yy] = 1;
                        que.push({xx, yy});
                    }
                }
            }
            if(bo)
                res = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        cout<<res<<'\n';
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
