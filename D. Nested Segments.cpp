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
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int pos[tam], res[tam];
int t[4 * tam], lazy[4 * tam];
void push(int node, bool bo)
{
	t[node] += lazy[node];
	if(bo)
	{
		lazy[node * 2 + 1] += lazy[node];
		lazy[node * 2 + 2] += lazy[node];
	}
	lazy[node] = 0;
}
int query(int b, int e, int node, int i, int j)
{
	if(b > e || e < i || b > j) return 0;
	push(node, b != e);
	if(b >= i && e <= j)
		return t[node];
	index;
	return query(b, mid, l, i, j) + query(mid + 1, e, r, i, j);
}
void update(int b, int e, int node, int i, int j)
{
	push(node, b != e);
	if(b > e || e < i || b > j) return;
	if(b >= i && e <= j)
	{
		lazy[node]++;
		push(node, b != e);
		return;
	}
	index;
	update(b, mid, l, i, j);
	update(mid + 1, e, r, i, j);
	t[node] = t[l] + t[r];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	vector<pair<int, int>> sweep;
	int n, a, b;
	mem(pos, -1);
	cin>>n;
	fore(i, 0, n)
	{
		cin>>a>>b;
		sweep.pb({a, i});
		sweep.pb({b, i});
	}
	sort(all(sweep));
	int po = 0;
	for(ii cat : sweep)
	{
		if(pos[cat.s] == -1)
			pos[cat.s] = po++;
		else
		{
			res[cat.s] = query(0, n - 1, 0, pos[cat.s], pos[cat.s]);
			update(0, n - 1, 0, 0, pos[cat.s]);
		}
	}
	fore(i, 0, n)
		cout<<res[i]<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil