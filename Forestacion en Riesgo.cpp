#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);

struct Node
{
	int mini, can, res, lazy;
	Node() {}
	Node(int mini, int can, int res, int lazy) : mini(mini), can(can), res(res), lazy(lazy) {}
};

Node join(Node a, Node b)
{
	int mi = min(a.mini, b.mini);
	Node res(mi, 0, 0, 0);
	if(a.mini == mi)
		res.can += a.can;
	if(b.mini == mi)
		res.can += b.can;
	if(res.mini == 0)
		res.res = res.can;
	return res;
}

struct edge
{
	int x, y1, y2, mo;
	edge() {}
	edge(int x, int y1, int y2, int mo) : x(x), y1(y1), y2(y2), mo(mo) {}
	bool operator <(const edge &e) const {return x < e.x;}
};
Node t[5 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = Node(0, 1, 1, 0);
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);

}

void push(int b, int e, int node)
{
	if(b < e)
	{
		int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
		t[l].lazy += t[node].lazy;
		t[r].lazy += t[node].lazy;
	}
	t[node].mini += t[node].lazy;
	t[node].lazy = 0;
	if(t[node].mini == 0)
		t[node].res = t[node].can;
	else
		t[node].res = 0;
}

void update(int b, int e, int node, int i, int j, int val)
{
	if(b > j || e < i || b > e) return;
	if(b >= i && e <= j)
	{
		t[node].lazy += val;
		push(b, e, node);
		return;
	}
	push(b, e, node);
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	update(b, mid, l, i, j, val);
	update(mid + 1, e, r, i, j, val);
	push(b, mid, l);
	push(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}

Node query(int b, int e, int node, int i, int j)
{
	push(b, e, node);
	if(b >= i & e <= j)
		return t[node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(j <= mid) return query(b, mid, l, i, j);
	if(i > mid) return query(mid + 1, e, r, i, j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}

ll x1, y1, x2, y2;
pair<pair<ll, ll>, pair<ll, ll>> seg[10010];
int n;
ll ar(int k)
{
	init(0, tam-1, 0);
	int na = 0;
	int a, b, c, d;
	vector<edge> v;
	fore(i, 0, n)
	{
		a = max(min(seg[i].f.f, seg[i].s.f) - k, x1);
		b = max(min(seg[i].f.s, seg[i].s.s) - k + 1, y1+1);
		c = min(max(seg[i].f.f, seg[i].s.f) + k, x2);
		d = min(max(seg[i].f.s, seg[i].s.s) + k, y2);
		v.pb(edge(a, b, d, 1));
		v.pb(edge(c, b, d, -1));
	}
	sort(all(v));
	ll res = 0;
	update(0, tam - 1, 0, v[0].y1, v[0].y2, v[0].mo);
	ll mul = t[0].res;
	fore(i, 1, v.size())
	{
		res += (tam - mul) * (v[i].x - v[i-1].x);
		update(0, tam-1, 0, v[i].y1, v[i].y2, v[i].mo);
		mul = t[0].res;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n;
	fore(i, 0, n) cin>>seg[i].f.f>>seg[i].f.s>>seg[i].s.f>>seg[i].s.s;
	ll por;
	cin>>por;
	cin>>x1>>y1>>x2>>y2;
	ll are = (x2 - x1) * (y2 - y1) * por;
	are = are / 100 + !!(are % 100);
	int lo = 1, hi = 1000000, mid, res = -1;
	ll u;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		u = ar(mid);
		if(u >= are)
			res = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2