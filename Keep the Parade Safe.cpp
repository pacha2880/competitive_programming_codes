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
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 988244353;
const double EPS = 1e-9;
const double PI = acos(-1);
struct point
{
	ll x, y;
	point () {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	bool operator <(point p) {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) > 0;}
};
vector<point> hull(vector<point> p)
{
	int n = p.size();
	sort(all(p));
	vector<point> h;
	fore(i, 0, n)
	{
		while(sz(h) >= 2 && !p[i].left(h.back(), h[sz(h) - 2])) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n - 1; i > -1; i--)
	{
		while(sz(h) >= k + 2 && !p[i].left(h.back(), h[sz(h) - 2])) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	return h;
}
bool inpoly(vector<point> &pol, point p)
{
	int n = pol.size();
	if(p.left(pol[0], pol[1]) || p.left(pol[n - 1], pol[0])) return 0;
	int lo = 1, hi = n-1, mid;
	while(lo < hi - 1)
	{
		mid = (lo + hi) / 2;
		if(p.left(pol[0], pol[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return !p.left(pol[lo], pol[hi]);
}
bool inpoly1(vector<point> &pol, point p)
{
	int n = pol.size();
	if(!p.left(pol[1], pol[0]) || !p.left(pol[0], pol[n - 1])) return 0;
	int lo = 1, hi = n-1, mid;
	while(lo < hi - 1)
	{
		mid = (lo + hi) / 2;
		if(p.left(pol[0], pol[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return p.left(pol[hi], pol[lo]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int con = 0;
	vector<point> pal(n);
	fore(i, 0, n) cin>>pal[i].x>>pal[i].y;
	vector<point> pol = hull(pal);
	int cana = 0;
	fore(i, 0, n)
	{
		cana += inpoly1(pol, pal[i]);
	}
	point p;
	bool bo = false;
	int sa;
	vector<point> polk[3];
	if(sz(pol) + cana < 4)
	{
		bo = true;
		if(sz(pol) == 3)
		{
			fore(i, 0, 3)
			{
				fore(j, 0, n)
				{
					if(pal[j].x != pol[i].x || pal[j].y != pol[i].y)
						polk[i].pb(pal[j]);
				}
				polk[i] = hull(polk[i]);
			}
		}
	}
	cin>>n;
	while(n--)
	{
		cin>>p.x>>p.y;
		if(bo)
		{
			sa = 0;
			fore(i, 0, 3)
			{
				if(polk[i].size() > 3)
				{
					sa = sa || inpoly(polk[i], p);
				}
			}
			con += sa;
		}
		else
			con += inpoly(pol, p);
	}
	//cout<<sz(pol)<<' '<<cana<<'\n';
	cout<<con<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2