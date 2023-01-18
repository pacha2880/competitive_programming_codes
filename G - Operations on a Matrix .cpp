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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int bit[tam];
void update(int pos, int val)
{
    for(; pos < tam; pos += pos & -pos)
        bit[pos] += val;
}
int query(int pos)
{
    int ans = 0;
    for(; pos > 0; pos -= pos & -pos)
        ans += bit[pos];
    return ans;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m, q;
    cin>>n>>m>>q;
    vector<vi> que(q);
    vi res(q, -1);
    fore(i, 0, q)
    {
        int t, a, b, c;
        cin>>t>>a>>b;
        if(t == 1)
        {
            cin>>c;
            que[i] = {t, a, b, c};
        }
        else
            que[i] = {t, a, b};
    }
    vector<vector<pair<int, ii>>> rus(n + 1);
    for(int i = q - 1; i > -1; i--)
    {
        vi qu = que[i];
        if(qu[0] == 3)
            rus[qu[1]].pb({-query(qu[2]), {i, qu[2]}});
        else if(qu[0] == 2)
        {
            for(auto p : rus[qu[1]])
                res[p.s.f] = qu[2] + p.f + query(p.s.s);
            rus[qu[1]].clear();
        }
        else
            update(qu[1], qu[3]), update(qu[2] + 1, -qu[3]);
    }
    fore(i, 1, n + 1)
        for(auto cat : rus[i])
            res[cat.s.f] = cat.f + query(cat.s.s);
    for(int x : res)
        if(x != -1)
            cout<<x<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
