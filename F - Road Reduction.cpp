#include <bits/stdc++.h>
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

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
    cin>>n>>m;
    vector<vi> g(n), in(n), gp(n);
    fore(i, 0, m)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        in[a].pb(i + 1);
        in[b].pb(i + 1);
        gp[a].pb(c);
        gp[b].pb(c);
    }
    vi pup(n, -1);
    vi vis(n);
    vi dist(n, MOD * MOD);
    priority_queue<ii, vii, greater<ii>> que;
    que.push({0, 0});
    dist[0] = 0;
    vi res;
    while(!que.empty())
    {
        int node = que.top().s;
        que.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        if(pup[node] != -1)
            res.pb(pup[node]);
        fore(i, 0, g[node].size())
        {
            int x = g[node][i], pe = gp[node][i], pu = in[node][i];
            if(dist[node] + pe < dist[x])
            {
                dist[x] = dist[node] + pe;
                pup[x] = pu;
                que.push({dist[x], x});
            }
        }
    }
    for(int x : res)
        cout<<x<<' ';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
