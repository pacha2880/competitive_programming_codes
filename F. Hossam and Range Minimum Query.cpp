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
// Better random mt19937_64 para 64 bits
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct st{
    int l, r; ll v;
    st() {v = 0;}
    st(int l, int r, ll v) : l(l), r(r), v(v) {}
};
vector<st> seg;
int init(int b, int e)
{
    if(b == e)
    {
        seg.emplace_back();
        return sz(seg) - 1;
    }
    int mid = (b + e) / 2;
    seg.pb({init(b, mid), init(mid + 1, e), 0});
    return sz(seg) - 1;
}
int update(int node, int b, int e, int pos, ll val)
{
    if(b == e)
    {
        seg.pb({0, 0, seg[node].v ^ val});
        return sz(seg) - 1;
    }
    int mid = (b + e) / 2;
    if(mid >= pos)
    {
        int l = update(seg[node].l, b, mid, pos, val);
        seg.pb({l, seg[node].r, seg[l].v ^ seg[seg[node].r].v});
    }
    else
    {
        int r = update(seg[node].r, mid + 1, e, pos, val);
        seg.pb({seg[node].l, r, seg[r].v ^ seg[seg[node].l].v});
    }
    return sz(seg) - 1;
}
int ma[tam], a[tam];
int query(int l, int r, int b, int e)
{
    // cout<<seg[l].v<<' '<<seg[r].v<<' '<<b<<' '<<e<<'\n';
    // cout<<a[b]<<' '<<ma[a[b]]<<'\n';
    if(seg[l].v == seg[r].v) return 0;
    if(b == e) return ma[b];
    int mid = (b + e) / 2;
    if(seg[seg[l].l].v == seg[seg[r].l].v)
        return query(seg[l].r, seg[r].r, mid + 1, e);
    return query(seg[l].l, seg[r].l, b, mid);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
    cin>>n;
    // read a vector and compress it
    forn(i, n) cin>>a[i];
    vi b(a, a + n);
    srt(b);
    b.resize(unique(all(b)) - b.begin());
    int na = b.size();
    vi valu(na);
    fore(i, 0, na) valu[i] = rng();
    forn(i, n) {int x = lower_bound(all(b), a[i]) - b.begin(); ma[x] = a[i], a[i] = x;}
    // cout<<"32233\n";
    // fore(i, 0, n) cout<<a[i]<<' '<<ma[a[i]]<<'\n';
    vi tree;
    tree.pb(init(0, na - 1));
    forn(i, n)
        tree.pb(update(tree.back(), 0, na - 1, a[i], valu[a[i]]));
    int q;
    cin>>q;
    int las = 0;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        l ^= las;
        r ^= las;
        // cout<<'$'<<l<<' '<<r<<'\n';
        las = query(tree[l - 1], tree[r], 0, na - 1);
        cout<<las<<'\n';
    }

	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más