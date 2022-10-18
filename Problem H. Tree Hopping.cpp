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
const int tam = 400010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[tam], t[4 * tam];
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = ar[b];
        return;
    }
    int mid = (b + e) / 2, l = 2 * node + 1, r = l + 1;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = min(t[l], t[r]);
}
int query(int b, int e, int node, int i, int j)
{
    if(b >= i && e <= j)
        return t[node];
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    if(i > mid)
        return query(mid + 1, e, r, i, j);
    if(j <= mid)
        return query(b, mid, l, i, j);
    return min(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
vi g[tam];
int po = 0, lug[tam], prof[tam];
void dfs(int node, int pro, int par)
{
    lug[node] = po;
    ar[po++] = pro;
    prof[node] = pro;
    for(int x : g[node])
        if(x != par)
        {
            ar[po++] = pro;
            dfs(x, pro + 1, node);
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
        int n;
        cin>>n;
        fore(i, 0, n - 1)
        {
            int a, b;
            cin>>a>>b;
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        int x;
        cin>>x;
        x--;
        bool bo = true;
        dfs(0, 0, -1);
        init(0, po - 1, 0);
        // cout<<"asdfasdf "<<2 * n - 1<<'\n';
        fore(i, 1, n)
        {
            int y;
            cin>>y;
            y--;
            // cout<<2 * n - 1<<' '<<min(lug[x], lug[y])<<' '<<max(lug[x], lug[y])<<'\n';
            int pa = query(0, po - 1, 0, min(lug[x], lug[y]), max(lug[x], lug[y]));
            if(prof[x] - pa + prof[y] - pa > 3)
                bo = false;
            x = y;
        }
        cout<<bo<<'\n';
        fore(i, 0, n) g[i].clear();po = 0;
    }
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
