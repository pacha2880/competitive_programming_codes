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
const int tam = 500010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int t[4 * tam], ar[tam], laz[4 * tam], la[4 * tam], eq[4 * tam];
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = ar[b];
        eq[node] = 1;
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = t[l] + t[r];
}
void push(int b, int e, int node)
{
    if(la[node])
    {
        t[node] = (e - b + 1) * laz[node];
        if(b != e)
        {
            laz[node * 2 + 1] = laz[node * 2 + 2] = laz[node];
            la[node * 2 + 1] = la[node * 2 + 2] = 1;
        }
        la[node] = 0;
        eq[node] = 1;
    }
}
void update1(int b, int e, int node, int i, int j, int val)
{
    if(b > e) return;
    push(b, e, node);
    if(b > j || e < i)
        return;
    if(b >= i && e <= j)
    {
        laz[node] = val;
        la[node] = 1;
        push(b, e, node);
        return;
    }
    index;
    eq[node] = 0;
    update1(b, mid, l, i, j, val);
    update1(mid + 1, e, r, i, j, val);
    t[node] = t[l] + t[r];
}
void update2(int b, int e, int node, int i, int j, int val)
{
    if(b > e) return;
    push(b, e, node);
    if(b > j || e < i)
        return;
    if(b >= i && e <= j && eq[node])
    {
        laz[node] = t[node] / (e - b + 1) / val;
        la[node] = 1;
        push(b, e, node);
        return;
    }
    index;
    eq[node] = 0;
    update2(b, mid, l, i, j, val);
    update2(mid + 1, e, r, i, j, val);
    t[node] = t[l] + t[r];
    if(t[node] == 0)
        eq[node] = 1;
}
int query(int b, int e, int node, int i, int j)
{
    push(b, e, node);
    if(b >= i && e <= j)
        return t[node];
    index;
    if(j <= mid)
        return query(b, mid, l, i, j);
    if(i > mid)
        return query(mid + 1, e, r, i, j);
    return query(b, mid, l, i, j) + query(mid + 1, e, r, i, j);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, q;
    cin>>n>>q;
    fore(i, 0, n) cin>>ar[i];
    init(0, n - 1, 0);
    forn(i, q)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 3)
            cout<<query(0, n - 1, 0, b - 1, c - 1)<<'\n';
        else
        {
            int d;
            cin>>d;
            if(a == 1)
                update2(0, n - 1, 0, b - 1, c - 1, d);
            else
                update1(0, n - 1, 0, b - 1, c - 1, d);
        }
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
