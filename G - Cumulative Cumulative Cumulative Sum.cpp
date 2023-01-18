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
const int tam = 200010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct node {
    ll suma1, suma2, suma3, dis;
    node() {
        suma1 = suma2 = suma3 = 0; dis = 1;
    }
    node(ll a, ll b, ll c) {
        suma1 = a;
        suma2 = b;
        suma3 = c;
        dis = 1;
    }
};
node join(node a, node b) {
    node c;
    c.suma1 = (a.suma1 + b.suma1) % MOD;
    c.suma2 = (b.suma2 + a.suma2 + b.dis * a.suma1) % MOD;
    c.suma3 = (b.suma3 + a.suma3 + b.dis * a.suma2 + b.dis * (b.dis - 1) / 2 % MOD * a.suma1) % MOD;
    c.dis = a.dis + b.dis;
    return c;
}
node t[4 * tam];
ll a[tam];
void build(int node, int b, int e) {
    if(b == e) {
        t[node] = {a[b], 2 * a[b], a[b]};
        return;
    }
    index;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = join(t[l], t[r]);
}
void update(int node, int b, int e, int pos, ll val) {
    if(b == e) {
        t[node] = {val, 2 * val, val};
        return;
    }
    index;
    if(pos <= mid) update(l, b, mid, pos, val);
    else update(r, mid + 1, e, pos, val);
    t[node] = join(t[l], t[r]);
}
node query(int node, int b, int e, int i, int j) {
    if(b >= i && e <= j) return t[node];
    index;
    if(j <= mid) return query(l, b, mid, i, j);
    if(i > mid) return query(r, mid + 1, e, i, j);
    return join(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, q;
    cin>>n>>q;
    fore(i, 0, n)
        cin>>a[i];
    build(0, 0, n - 1);
    while(q--) {
        int t, a, b;
        cin>>t>>a;
        a--;
        if(t == 1) {
            cin>>b;
            update(0, 0, n - 1, a, b);
        } else {
            node ans = query(0, 0, n - 1, 0, a);
            cout<<ans.suma3 % MOD<<'\n';
        }
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
