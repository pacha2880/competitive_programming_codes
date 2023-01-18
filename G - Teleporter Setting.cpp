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
vi g[3 * tam];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
    cin>>n>>m;
    vi loc;
    fore(i, 0, m)
    {
        int a, b;
        cin>>a>>b;
        if(a == 0)
        {
            loc.pb(b - 1);
            continue;
        }
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi dis1(n, MOD), dis2(n, MOD);
    dis1[0] = 0;
    dis2[n - 1] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int node = que.front();
        que.pop();
        for(int x : g[node])
            if(dis1[x] == MOD)
            {
                dis1[x] = dis1[node] + 1;
                que.push(x);
            }
    }
    que.push(n - 1);
    while(!que.empty())
    {
        int node = que.front();
        que.pop();
        for(int x : g[node])
            if(dis2[x] == MOD)
            {
                dis2[x] = dis2[node] + 1;
                que.push(x);
            }
    }
    ii min1 = {MOD, 0}, min2 = {MOD, 0};
    for(int x : loc)
    {
        min1 = min(min1, {dis1[x], x});
        min2 = min(min2, {dis2[x], x});
    }
    int res = dis1[n - 1];
    fore(i, 0, n)
    {
        int ras = min(res, min(dis1[i], min1.f + 1) + min(dis2[i], min2.f + 1));
        if(ras == MOD)
            cout<<-1<<" ";
        else
            cout<<ras<<" ";
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
