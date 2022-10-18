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

struct nodo
{
	vi let;
	int ta;
	nodo() {let.assign(26, 0);ta = 1;}
	nodo(int x)
		{let.assign(26, 0); let[x]++;ta = 1;}
};
nodo join(nodo a, nodo b)
{
	fore(i, 0, 26)
		a.let[i] += b.let[i];
	a.ta += b.ta;
	return a;
}
int ar[tam], lazy[4 * tam];
nodo t[4 * tam];
void init(int node, int b, int e)
{
	if(b == e)
	{
		t[node] = nodo(ar[b]);
		return;
	}
	index;
	init(l, b, mid);
	init(r, mid + 1, e);
	t[node] = join(t[l], t[r]);
}
void push(int node, int b, int e)
{
	if(lazy[node] != 0)
	{
		if(b < e)
		{
			int can = t[node * 2 + 1].ta;
				vi le(26), ri = t[node].let;
			int ind = lazy[node] == 1 ? 0 : 25;
			while(can)
			{
				if(ri[ind] > can)
				{
					le[ind] = can;
					ri[ind] -= can;
					can = 0;
				}
				else
				{
					le[ind] = ri[ind];
					can -= ri[ind];
					ri[ind] = 0;
					ind += lazy[node];
				}
			}
			t[node * 2 + 1].let = le;
			t[node * 2 + 2].let = ri;
			lazy[node * 2 + 1] = lazy[node];
			lazy[node * 2 + 2] = lazy[node];
		}
		lazy[node] = 0;
	}
}
vi sel;
void upd(int node, int b, int e, int i, int j)
{
	if(b > e) return;
	push(node, b, e);
	if(e < i || b > j) return;
	if(i <= b && j >= e)
	{
		sel.pb(node);
		return;
	}
	index;
	upd(l, b, mid, i, j);
	upd(r, mid + 1, e, i, j);
}
void update(int node, int b, int e, int i, int j)
{
	if(b > e) return;
	push(node, b, e);
	if(e < i || b > j) return;
	if(i <= b && j >= e)
	{
		return;
	}
	index;
	update(l, b, mid, i, j);
	update(r, mid + 1, e, i, j);
	t[node] = join(t[l], t[r]);
}
nodo query(int node, int b, int e, int i)
{
	push(node, b, e);
	if(b == e)
		return t[node];
	index;
	if(i <= mid)
		return query(l, b, mid, i);
	if(i > mid)
		return query(r, mid + 1, e, i);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, q;
	cin>>n>>q;
	string s;
	cin>>s;
	fore(i, 0, n) ar[i] = s[i] - 'a';
	init(0, 0, n - 1);
	while(q--)
	{
		int a, b, c;
		cin>>a>>b>>c;
		a--; b--;
		upd(0, 0, n - 1, a, b);
		vi lets(26);
		for(int x : sel)
		{
			// cout<<x<<' '<<t[x].ta<<'\n';
			fore(i, 0, 26)
				lets[i] += t[x].let[i];
		}
		int ind = 0;
		if(c == 0)
		{
			c--;
			ind = 25;
		}
		// cout<<ind<<'\n';
		// fore(i, 0, 26)
		// 	cout<<(char)(i + 'a')<<' '<<lets[i]<<'\n';
		for(int x : sel)
		{
			lazy[x] = c;
			t[x].let.assign(26, 0);
			int can = t[x].ta;
			while(can)
			{
				if(lets[ind] > can)
				{
					t[x].let[ind] += can;
					lets[ind] -= can;
					can = 0;
				}
				else
				{
					t[x].let[ind] += lets[ind];
					can -= lets[ind];
					lets[ind] = 0;
					ind += c;
				}
			}
		}
		sel.clear();
		update(0, 0, n - 1, a, b);
	}
	fore(i, 0, n)
	{
		nodo no = query(0, 0, n - 1, i);
		fore(i, 0, 26)
			if(no.let[i])
				cout<<(char)(i + 'a');
	}
	cout<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
