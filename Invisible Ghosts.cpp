#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
string tab[550];
bool vis[550][550];
int pas[550][550];
char par[550][550];
string dirs = "DLRU";
int dir[2][4] = {{1, 0, 0, -1}, {0, -1, 1, 0}};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int t;
    cin>>t;
    fore(asd, 1, t + 1)
    {
        cout<<"Case #"<<asd<<": ";
        int n, m;
        cin>>n>>m;
        queue<pair<ii, int>> q;
        int x, y;
        fore(i, 0, n)
        {
            cin>>tab[i];
            fore(j, 0, m)
            {
                if(tab[i][j] == 'G')
                {
                    pas[i][j] = 0;
                    q.push({{i, j}, 0});
                }
                else
                    pas[i][j] = MOD;
                if(tab[i][j] == 'P')
                {
                    x = i;
                    y = j;
                }
            }
        }
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.f.f;
            int y = p.f.s;
            int d = p.s;
            forn(i, 4)
            {
                int nx = x + dir[0][i];
                int ny = y + dir[1][i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && tab[nx][ny] != 'X')
                {
                    if(pas[nx][ny] > d + 1)
                    {
                        pas[nx][ny] = d + 1;
                        q.push({{nx, ny}, d + 1});
                    }
                }
            }
        }
        pair<int, ii> ans = {-pas[x][y] + 1, {x, y}};
        q.push({{x, y}, 0});
        vis[x][y] = 1;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.f.f;
            int y = p.f.s;
            int d = p.s;
            // cout<<x<<' '<<y<<' '<<d<<' '<<pas[x][y]<<'\n';
            if(pas[x][y] > d)
                ans = min(ans, {-pas[x][y] + 1, {x, y}});
            else
                continue;
            forn(i, 4)
            {
                int nx = x + dir[0][i];
                int ny = y + dir[1][i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && tab[nx][ny] != 'X' && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    par[nx][ny] = dirs[i];
                    q.push({{nx, ny}, d + 1});
                }
            }
        }
        
        string res = "";
        // cout<<ans.f<<' '<<ans.s.f<<' '<<ans.s.s<<' '<<x<<' '<<y<<'\n';
        // return 0;
        if(ans.s.f == x && ans.s.s == y)
        {
            res = "STAY";
        }
        else
        {
            int x1 = ans.s.f, y1 = ans.s.s;
            while(x1 != x || y1 != y)
            {
                res += par[x1][y1];
                int nx = x1 - dir[0][dirs.find(par[x1][y1])];
                int ny = y1 - dir[1][dirs.find(par[x1][y1])];
                x1 = nx;
                y1 = ny;
            }
        }
        if(pas[ans.s.f][ans.s.s] == MOD)
        {
            if(res != "STAY")
                reverse(all(res));
            cout<<"INFINITE "<<res<<'\n';
        }
        else
        {
            if(res == "STAY")
                cout<<res<<'\n';
            else
            {
                reverse(all(res));
                cout<<-ans.f<<' '<<res<<'\n';
            }
        }
        fore(i, 0, n) fore(j, 0, m) pas[i][j] = 0;
        fore(i, 0, n) fore(j, 0, m) vis[i][j] = 0;
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
