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

// el init para lazy propagation es igualito, no hay cambios
ll t[4 * tam], lazy[4 * tam];
void push(int node, int b, int e) // propagar
{
	if(lazy[node] != 0)
	{
		t[node] += lazy[node] * (e - b + 1);
		if(b < e)
		{
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int b, int e, int i, int j, int val)
{
	if(b > e)
		return;
	push(node, b, e);
	if(j < b || i > e) return;
	if(i <= b && j >= e)
	{
		lazy[node] += val;
		push(node, b, e);
		return;
	}
	index;
	update(l, b, mid, i, j, val);
	update(r, mid + 1, e, i, j, val);
	t[node] = t[l] + t[r];
}
ll query(int node, int b, int e, int i, int j)
{
	push(node, b, e);
	if(b >= i && e <= j)
		return t[node];
	index;
	if(j <= mid)
		return query(l, b, mid, i, j);
	if(i > mid)
		return query(r, mid + 1, e, i, j);
	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--)
	{
		int n, q;
		cin>>n>>q;
		fore(i, 0, 4 * n) t[i] = 0, lazy[i] = 0;
		while(q--)
		{
			int a, b, c, d;
			cin>>a>>b>>c;
			if(a == 0)
			{
				cin>>d;
				update(0, 0, n - 1, b - 1, c - 1, d);
			}
			else
				cout<<query(0, 0, n - 1, b - 1, c - 1)<<'\n';
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
