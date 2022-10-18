#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define aint(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(aint(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < (int)e; i++)
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
// #pragma GCC optimization ("unroint-loops")

typedef long double ld;	
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<int>      vint;
// typedef tree<int,nuint_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[10100], gp[10100];
vector<int> chancho[10][10010];
int ind[10][10010];
struct nodo
{
    int peso, mask, node;
    bool operator <(const nodo &a) const {return a.peso < peso;}
};
vi take_me_home(int from, int n, int k)
{
    vector<vi> dist(1<<k, vi(n, MOD)), vis(1<<k, vi(n));
    priority_queue<nodo> que;
    dist[0][from] = 0;
    que.push({0, 0, from});
    while(!que.empty())
    {
        int mask = que.top().mask;
        int node = que.top().node;
        que.pop();
        if(vis[mask][node]) continue;
        vis[mask][node] = 1;
        fore(i, 0, k)
        {
            if(!(mask & (1<<i)))
            {
                int misk = mask | (1<<i);
                while(ind[i][node] < sz(chancho[i][node]) && chancho[i][node][ind[i][node]] < dist[mask][node])
                    ind[i][node]++;
                if(ind[i][node] < sz(chancho[i][node]) && chancho[i][node][ind[i][node]] < dist[misk][node])
                {
                    dist[misk][node] = chancho[i][node][ind[i][node]];
                    que.push({chancho[i][node][ind[i][node]], misk, node});
                }
            }
        }
        fore(i, 0, g[node].size())
        {
            int x = g[node][i];
            if(dist[mask][x] > dist[mask][node] + gp[node][i])
            {
                dist[mask][x] = dist[mask][node] + gp[node][i];
                que.push({dist[mask][x], mask, x});
            }
        }
    }
    vi res(1<<k, MOD);
    // cout<<from<<'\n';
    fore(i, 0, 1<<k)
        fore(j, 0, n)
        {
            // cout<<i<<' '<<j<<' '<<dist[i][j]<<'\n';
            res[i] = min(res[i], dist[i][j]);
        }
    return res;
}
void solve()
{
    int n, m, k;
    cin>>n>>m>>k;
    fore(i, 0, m)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
        gp[a].pb(c);
        gp[b].pb(c);
    }
    int e, t_max;
    cin>>e>>t_max;
    fore(i, 0, e)
    {
        int p, x, t;
        cin>>p>>x>>t;
        p--, x--;
        chancho[p][x].pb(t);
    }
    int x, y;
    cin>>x>>y;
    fore(i, 0, n)
    {
        fore(j, 0, k)
            sort(aint(chancho[j][i]));
    }
    fore(i, 0, n)
        fore(j, 0, k)
            ind[j][i] = 0;
    vi a = take_me_home(x - 1, n, k);
    fore(i, 0, n)
        fore(j, 0, k)
            ind[j][i] = 0;
    vi b = take_me_home(y - 1, n, k);
    int res = MOD;
    // cout<<k<<' '<<((1<<k) - 1)<<'\n';
    fore(i, 0, 1<<k)
    {
        // cout<<a[i]<<' '<<b[i ^ ((1<<k) - 1)]<<'\n';
        res = min(res, max(a[i], b[i ^ ((1<<k) - 1)]));
    }

    // fore(i, 0, 1<<k)
    // fore(j, 0, 1<<k)
    // {
    //     // cout<<a[i]<<' '<<b[i ^ ((1<<k) - 1)]<<'\n';
    //     if((i | j ) == ((1<<k) - 1))
    //     res = min(res, max(a[i], b[j]));
    // }
    // cout<<res<<"->";
    cout<<(res <= t_max ? res : -1)<<'\n';
    fore(i, 0, n)
    {
        g[i].clear();
        gp[i].clear();
        fore(j, 0, k)
            chancho[j][i].clear();
    }
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
