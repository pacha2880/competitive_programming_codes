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
string tab[2000];
int n, m;
int vis[2000][2000];
int can(int x, int y, char chu)
{
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;
    if(tab[x][y] != chu)
        return -1;
    if(vis[x][y]) return 0;
    return 1;
}
int dir[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};
ii dfs(int x, int y)
{
    // cout<<'*'<<x<<' '<<y<<'\n';
    vis[x][y] = 1;
    int isedge = 0;
    ii aca(1,0);
    fore(i, 0, 4)
    {
        int xx = x + dir[0][i], yy = y + dir[1][i];
        int cual = can(xx, yy, tab[x][y]);
        if(cual)
        {
            if(cual == 1)
            {
                ii ris = dfs(xx, yy);
                aca.f += ris.f;
                aca.s += ris.s;
            }
            else
                isedge = 1;
        }
    }
    return {aca.f, aca.s + isedge};
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    vi poto(4000001);
	poto[0] = 1;
    fore(i, 1, 4000001)
        poto[i] = poto[i - 1] * 2 % MOD;
    cin>>n>>m;
    fore(i, 0, n) cin>>tab[i];
    int res = 1;
    fore(i, 0, n)
        fore(j, 0, m)
        {
            // cout<<i<<' '<<j<<'\n';
            if(!vis[i][j])
            {
                int cuan = 0, eds =0;
                queue<ii> que;
                que.push({i, j});
                vis[i][j] = 1;
                while(!que.empty())
                {
                    int x = que.front().f, y = que.front().s;
                    que.pop();
                    cuan++;
                    bool ised = 0;
                    fore(i, 0, 4)
                    {
                        int xx = x + dir[0][i], yy = y + dir[1][i];
                        int cual = can(xx, yy, tab[x][y]);
                        if(cual == 1)
                        {
                            vis[xx][yy] = 1;
                            que.push({xx, yy});
                        }
                        if(cual == -1)
                            ised = 1;
                    }
                    eds += ised;
                }
                // cout<<i<<' '<<j<<' '<<rus.f<<' '<<rus.s<<'\n';
                res = res * poto[cuan - eds] % MOD;
            }
        }
    cout<<res<<'\n';
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
