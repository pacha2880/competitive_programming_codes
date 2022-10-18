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
int math[1010][1010], matv[1010][1010];
int vis[1010][1010];
int lim = 1000;
ll dfs(int i, int j)
{
    // cout<<i<<' '<<j<<'\n';
    vis[i][j] = 1;
    if(i == 0 || i == lim || j == 0 || j == lim)
        return -MOD;
    ll res = 1;
    if(!math[i][j] && !vis[i][j - 1])
        res += dfs(i, j - 1);
    if(!math[i][j + 1] && !vis[i][j + 1])
        res += dfs(i, j + 1);
    if(!matv[i][j] && !vis[i - 1][j])
        res += dfs(i - 1, j);
    if(!matv[i + 1][j] && !vis[i + 1][j])
        res += dfs(i + 1, j);
    return res;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
    cin>>n;
    int x, y;
    cin>>x>>y;
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        if(a == x)
        {
            if(b > y)
                matv[x][y]++, matv[x][b]--;
            else
                matv[x][b]++, matv[x][y]--;
        }
        else
        {
            if(a > x)
                math[x][y]++, math[a][y]--;
            else
                math[a][y]++, math[x][y]--;
        }
        x = a, y = b;
    }
    fore(i, 1, lim + 1)
        fore(j, 1, lim + 1)
            matv[i][j] += matv[i][j - 1],
            math[j][i] += math[j - 1][i];
    // fore(i, 1, lim + 1)
    // fore(j, 1, lim + 1)
    // {
    //     cout<<i<<' '<<j<<' '<<matv[i][j]<<' '<<math[i][j]<<'\n';
    // }
    ll res = 0;
    fore(i, 1, lim)
    fore(j, 1, lim)
        if(!vis[i][j])
        {
            ll can = dfs(i, j);
            // cout<<"--> "<<can<<'\n';
            res = max(res, can);
        }
    cout<<res<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
