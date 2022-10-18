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
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
const ll INF = 1e18;
const double PI = acos(-1);
ll ar[2][200010];
pair<pair<ll, int>, pair<ll, int>> t[2][800040];
void init(int b, int e, int node, int ti)
{
	//cout<<b<<' '<<e<<'\n';
	if(b == e)
	{
		t[ti][node] = mp(mp(ar[ti][b], b), mp(-INF, -1));
		return;
	}
	int mid = (b + e) / 2, l = 2 * node + 1, r = l + 1;
	init(b, mid, l, ti);
	init(mid + 1, e, r, ti);
	if(t[ti][l].f.f > t[ti][r].f.f)
	{
		t[ti][node].f = t[ti][l].f;
		t[ti][node].s = max(t[ti][l].s, t[ti][r].f);
	}
	else
	{
		t[ti][node].f = t[ti][r].f;
		t[ti][node].s = max(t[ti][r].s, t[ti][l].f);
	}
}
pair<pair<ll, int>, pair<ll, int>> query(int b, int e, int node, int i, int j, int ti)
{
	if(b >= i && e <= j)
		return t[ti][node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		return query(mid + 1, e, r, i, j, ti);
	if(mid >= j)
		return query(b, mid, l, i, j, ti);
	pair<pair<ll, int>, pair<ll, int>> le, ri, res;
	le = query(b, mid, l, i, j, ti);
	ri = query(mid + 1, e, r, i, j, ti);
	if(le.f.f > ri.f.f)
	{
		res.f = le.f;
		res.s = max(le.s, ri.f);
	}
	else
	{
		res.f = ri.f;
		res.s = max(ri.s, le.f);
	}
	return res;
}
ll d[200020], h[200020];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, n) {cin>>d[i]; d[i + n] = d[i];}
	fore(i, 0, n) {cin>>h[i]; h[i + n] = h[i];}
	ll su = 0;
	fore(i, 0, 2 * n)
	{
		ar[0][i] = 2 * h[i] + su;
		ar[1][i] = 2 * h[i] - su;
		su += d[i];
	}
	//cout<<"adads";
	init(0, 2 * n - 1, 0, 0);
	//cout<<"dasda";
	init(0, 2 * n - 1, 0, 1);
	int a, b, ax, bx, x, y;
	ll sav;
	pair<pair<ll, int>, pair<ll, int> > le, ri;
	while(m--)
	{
		cin>>a>>b;
		a--; b--;
		x = a, y = b;
		if(a <= b) a += n;
		swap(a, b);
		a++;
		b--;
		le = query(0, 2 * n - 1, 0, a, b, 1);
		ri = query(0, 2 * n - 1, 0, a, b, 0);
		if(le.f.s == ri.f.s)
			cout<<max(le.f.f + ri.s.f, le.s.f + ri.f.f)<<'\n';
		else
			cout<<le.f.f + ri.f.f<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	