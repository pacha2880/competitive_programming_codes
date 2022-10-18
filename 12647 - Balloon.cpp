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
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
  	ll operator *(point p) {return x * p.x + y * p.y;}
  	point operator *(ll a) {return point(x * a, y * a);}
	bool operator <(point p) {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) > 0;}
	ostream& operator<<(ostream& os) {
		return os << "("<< x << "," << y << ")";
	}

};
pair<point, point> seg[tam];
int ar[tam];
struct stru{
	bool operator ()(int a, int b)
	{
		if(seg[a].f.x <= seg[b].f.x)
			return seg[b].f.left(seg[a].f, seg[a].s);
		else
			return seg[a].f.left(seg[b].s, seg[b].f);
	}
};
pair<int, int> resos[tam];
int parent[tam];
pair<int, int> val(int n, int x)
{
	if(parent[n] == -1)
	{
		if(seg[n].f.y == seg[n].s.y)
			return {x, seg[n].f.y};
		else if(seg[n].f.y > seg[n].s.y)
			return {seg[n].f.x, -1};
		else 
			return {seg[n].s.x, -1};
	}
	if(resos[n].f != -1) return resos[n];
	if(seg[n].f.y == seg[n].s.y)
		return {x, seg[n].f.y};
	else if(seg[n].f.y > seg[n].s.y)
		return resos[n] = val(parent[n], seg[n].f.x);
	else 
		return resos[n] = val(parent[n], seg[n].s.x);
}
pair<int, int> res[tam];
pair<int, pair<int, int>> sweep[tam * 4];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	while(cin>>n)
	{
		cin>>m;
		fore(i, 0, n)
		{
			cin>>seg[i].f.x>>seg[i].f.y>>seg[i].s.x>>seg[i].s.y;
			if(seg[i].f.x > seg[i].s.x)
				swap(seg[i].f, seg[i].s);
			sweep[i * 2] = {seg[i].f.x, {0, i}};
			sweep[i * 2 + 1] = {seg[i].s.x, {2, i}};
		}
		fore(i, 0, m)
		{
			cin>>ar[i];
			sweep[2 * n + i] = {ar[i], {1, i}};
		}
		int ta = 2 * n + m;
		sort(sweep, sweep + ta);
		set<int, stru> st;
		set<int, stru>::iterator it;
		int a, b, c, x;
		fore(i, 0, n) parent[i] = -1, resos[i].f = -1;
		fore(i, 0, ta)
		{
			x = sweep[i].f;
			a = sweep[i].s.f;
			b = sweep[i].s.s;
			if(a == 0)
			{
				it = st.upper_bound(b);
				if(seg[b].s.y < seg[b].f.y && it != st.end())
						parent[b] = *it;
				st.insert(b);
			}
			else if(a == 2)
			{
				st.erase(b);
				it = st.upper_bound(b);
				if(seg[b].s.y > seg[b].f.y && it != st.end())
					parent[b] = *it;
			}
			else
			{
				if(st.size())
					res[b] = {-*st.begin() - 1, 0};
				else
					res[b] = {x, -1};
			}
		}
		fore(i, 0, m)
		{
			if(res[i].f < 0)
				res[i] = val(-res[i].f -1, ar[i]);
			if(res[i].s == -1)
				cout<<res[i].f<<'\n';
			else
				cout<<res[i].f<<' '<<res[i].s<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	