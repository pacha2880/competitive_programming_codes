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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[2 * tam];
ii dfs(int node, int prof, int ni)
{
    ii res = {0, 0};
    bool ce = false;
    for(int x : g[node])
    {
        ii cat = dfs(x, prof, ni + 1);
        if(cat.f == prof - 2 && ni > 1)
            ce = true;
        else
            res.f = max(res.f, cat.f + 1);
        res.s += cat.s;
    }
    if(ce)
        res.f = -MOD, res.s++;
    // cout<<node<<' '<<res.f<<' '<<res.s<<'\n';
    // cout<<node<<' '<<prof<<' '<<ni<<' '<<res.f<<' '<<res.s<<'\n';
    return res;
}
int daf(int node, int es)
{
    int res = es == 0;
    for(int x : g[node])
        res += daf(x, max(0, es - 1));
    return res;
}
int n, k;
bool f(int prof)
{
    // cout<<'$'<<prof<<'\n';
    if(prof == 1)
        return daf(0, 2) <= k;
    int x = dfs(0, prof, 0).s;
    // cout<<'$'<<x<<'\n';
    // cout<<'%'<<x<<' '<<k<<'\n';
    return x <= k;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int t;
    cin>>t;
    fore(cas, 0, t)
    {
        cin>>n>>k;
        fore(i, 1, n)
        {
            int x;
            cin>>x;
            g[x - 1].pb(i);
        }
        int b = 1, e = n - 1, res, mid;
        while(b <= e)
        {
            int mid = (b + e) / 2;
            // cout<<'$'<<mid<<'\n';
            if(f(mid))
                res = mid, e = mid - 1;
            else
                b = mid + 1;
        }
        cout<<res<<'\n';
        fore(i, 0, n) g[i].clear();
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.

