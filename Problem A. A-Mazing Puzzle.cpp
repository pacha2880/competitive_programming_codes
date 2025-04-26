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
const int ta = 55;
int di[ta][ta];
ii dis[ta][ta][ta][ta];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m, ex;
    cin>>m>>n>>ex;
    int x1, y1, x2, y2;
    char ch1, ch2;
    vi po(500);
    po['N'] = 0;
    po['E'] = 1;
    po['S'] = 2;
    po['W'] = 3;
    cin>>y1>>x1>>ch1>>y2>>x2>>ch2;
    int del = po[ch2] - po[ch1] + 4;
    vii dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<vi>> can(4, vector<vi>(ta, vi(ta, 1)));
    fore(i, 1, n + 1)
        can[1][i][m] = can[3][i][1] = 0;
    fore(i, 1, m + 1)
        can[0][n][i] = can[2][1][i] = 0;
    can[2][1][ex] = 1;
    can[1][0][ex] = 0;
    can[3][0][ex] = 0;
    can[2][0][ex] = 0;
    int k;
    cin>>k;
    while(k--)
    {
        int x, y;
        cin>>y>>x;
        can[0][x][y] = can[2][x + 1][y] = 0;
    }
    cin>>k;
    while(k--)
    {
        int x, y;
        cin>>y>>x;
        can[1][x][y] = can[3][x][y + 1] = 0;
    }
    // fore(i, 0, 4)
    // {
    //     for(int j = n + 1; j >= 0; j--)
    //     {
    //         fore(k, 0, m + 2)
    //             cout<<can[i][j][k]<<' ';
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    queue<ii> que1;
    // fore(i, 0, ta)
    //     fore(j, 0, ta)
    //         di[i][j] = -1;
    mem(di, -1);
    que1.push({0, ex});
    di[0][ex] = 0;
    while(!que1.empty())
    {
        int x  = que1.front().f, y = que1.front().s;
        que1.pop();
        fore(i, 0, 4)
        {
            int xx = x + dir[i].f, yy = y + dir[i].s;
            if(can[i][x][y] && di[xx][yy] == -1)
            {
                di[xx][yy] = di[x][y] + 1;
                que1.push({xx, yy});
            }
        }
    }
    // for(int j = n + 1; j >= 0; j--)
    // {
    //     fore(k, 0, m + 2)
    //         cout<<di[j][k]<<' ';
    //     cout<<'\n';
    // }
    mem(dis, -1);
    // fore(i, 0, ta)
    //     fore(j, 0, ta)
    //         fore(k, 0, ta)
    //             fore(l, 0, ta)
    //                 dis[i][j][k][l] = {-1, -1};
    queue<vi> que;
    que.push({x1, y1, x2, y2});
    dis[x1][y1][x2][y2] = {0, 0};
    ii res(MOD, 0);
    while(!que.empty())
    {
        int x1 = que.front()[0], y1 = que.front()[1], x2 = que.front()[2], y2 = que.front()[3];
        que.pop();
        ii didi = dis[x1][y1][x2][y2];
        int a = x1, b = y1, c = x2, d = y2;
        // cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
        // if(a < 0 || a > n || b < 0 || b > m || c < 0 || c > n || d < 0 || d > m)
        //     return 0;
        if(x1 == x2 && y1 == y2) continue;
        if(x1 == 0)
        {
            // cout<<'@'<<' '<<x2<<' '<<y2<<'\n';
            // cout<<didi.f<<' '<<didi.s<<'\n';
            // cout<<di[x2][y2]<<'\n';
            didi.f += di[x2][y2];
            res = min(res, didi);
        }
        else if(x2 == 0)
        {
            // cout<<'@'<<' '<<x1<<' '<<y1<<'\n';
            // cout<<didi.f<<' '<<didi.s<<'\n';
            // cout<<di[x1][y1]<<'\n';
            didi.f += di[x1][y1];
            res = min(res, didi);
        }
        else
        {
            fore(i, 0, 4)
            {
                int j = (i + del) % 4;
                int a = x1 + dir[i].f, b = y1 + dir[i].s,
                c = x2 + dir[j].f, d = y2 + dir[j].s;
                if(can[i][x1][y1] && can[j][x2][y2] && dis[a][b][c][d].f == -1)
                {
                    dis[a][b][c][d] = {didi.f + 1, didi.s};
                    que.push({a, b, c, d});
                }
            }
            fore(i, 0, 4)
            {
                int j = (i + del) % 4;
                int a = x1 + dir[i].f * can[i][x1][y1], 
                    b = y1 + dir[i].s * can[i][x1][y1],
                    c = x2 + dir[j].f * can[j][x2][y2],
                    d = y2 + dir[j].s * can[j][x2][y2];
                if((can[i][x1][y1] != can[j][x2][y2]) && dis[a][b][c][d].f == -1)
                {
                    dis[a][b][c][d] = {didi.f + 1, didi.s + 1};
                    que.push({a, b, c, d});
                }
            }
        }
    }
    cout<<res.f<<' '<<res.s<<'\n';
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
