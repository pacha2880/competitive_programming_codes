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
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int tam = 2000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int t[4 * tam], lazy[4 * tam];
void push(int node, bool bo)
{
	t[node] += lazy[node];
	if(bo)
		lazy[node * 2 + 1] += lazy[node], lazy[node * 2 + 2] += lazy[node];
	lazy[node] = 0;
}
void update(int b, int e, int node, int i, int j, int val)
{
	push(node, b != e);
	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		lazy[node] += val;
		push(node, b != e);
		return;
	}
	index;
	update(b, mid, l, i, j, val);
	update(mid + 1, e, r, i, j, val);
	t[node] = min(t[l], t[r]);
}
vii seg[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m, a, b, c;
	cin>>n>>m;
	fore(i, 0, n)
	{
		// cout<<i<<'\n';
		cin>>a>>b>>c;
		seg[c].pb({a * 2, b * 2});
	}
	int to = 1, res = MOD;
	m *= 2;
	fore(i, 1, tam)
	{
		while(to < tam && t[0] < 1)
		{
			for(ii cat : seg[to])
				update(2, m, 0, cat.f, cat.s, 1);
			to++;
		}
		if(t[0] > 0)
			res = min(res, to - 1 - i);
			for(ii cat : seg[i])
				update(2, m, 0, cat.f, cat.s, -1);
	}
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
