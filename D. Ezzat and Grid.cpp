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
typedef pair<int, pair<int, int>> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ii t[8 * tam], lazy[8 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = {0, -1};
		return;
	}
	index;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = max(t[l], t[r]);
}
void push(int node, int b, int e)
{
	if(lazy[node].f != 0)
	{
		t[node] = lazy[node];
		if(b < e)
		{
			lazy[node * 2 + 1] = lazy[node];
			lazy[node * 2 + 2] = lazy[node];
		}
		lazy[node].f = 0;
	}
}
void update(int b, int e, int node, int i, int j, ii val)
{
	if(b > e) return;
	push(node, b, e);
	if(e < i || b > j) return;
	if(i <= b && j >= e)
	{
		lazy[node] = val;
		push(node, b, e);
		return;
	}
	index;
	update(b, mid, l, i, j, val);
	update(mid + 1, e, r, i, j, val);
	t[node] = max(t[l], t[r]);
}
ii query(int b, int e, int node, int i, int j)
{
	push(node, b, e);
	if(b >= i && e <= j)
		return t[node];
	index;
	if(mid >= j)
		return query(b, mid, l, i, j);
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	return max(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
int par[tam], al[tam];
vector<ii> seg[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a, b, c;
	set<int> st;
	fore(i, 0, m) 
	{
		cin>>a>>b>>c;
		seg[a - 1].pb({b, c});
		st.insert(b);
		st.insert(c);
	}
	map<int, int> ma;
	int co = 0;
	for(int x : st)
		ma[x] = co++;
	init(0, co - 1, 0);
	mem(par, -1);
	fore(i, 0, n)
	{
		// cout<<i<<'\n';
		sort(all(seg[i]));
		int ini = -1, end = -1;
		ii dum;
		for(ii cat: seg[i])
		{
			if(end < cat.f)
			{
				if(end != - 1)
				{
					dum = query(0, co - 1, 0, ma[ini], ma[end]);
					if(dum.f + 1 > al[i])
					{
						al[i] = dum.f + 1;
						par[i] = dum.s;
					}
					update(0, co - 1, 0, ma[ini], ma[end], {al[i], i});
				}
				ini = cat.f, end = cat.s;
			}
			else
				end = max(end, cat.s);
		}
		if(end != -1)
		{
			dum = query(0, co - 1, 0, ma[ini], ma[end]);
			if(dum.f + 1 > al[i])
			{
				al[i] = dum.f + 1;
				par[i] = dum.s;
			}
			update(0, co - 1, 0, ma[ini], ma[end], {al[i], i});
		}
		end = -1;
		for(ii cat: seg[i])
		{
			if(end < cat.f)
			{
				if(end != - 1)
				{
					update(0, co - 1, 0, ma[ini], ma[end], {al[i], i});
				}
				ini = cat.f, end = cat.s;
			}
			else
				end = max(end, cat.s);
		}
	}
	vi res(n, 1);
	int ra = t[0].s, ru = 0;
	while(ra != -1)
	{
		res[ra] = 0;
		ra = par[ra];
		ru++;
	}
	cout<<n - ru<<'\n';
	fore(i, 0, n)
		if(res[i])
			cout<<i + 1<<' ';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
