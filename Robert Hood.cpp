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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };
using segment = line;

const double eps = 1e-9;

// fix comparations on doubles with this two functions
int sign(double x) { return x < -eps ? -1 : x > eps; }

int dblcmp(double x, double y) { return sign(x - y); }

double dot(point a, point b) { return real(conj(a) * b); }

double cross(point a, point b) { return imag(conj(a) * b); }

double area2(point a, point b, point c) { return cross(b - a, c - a); }

int ccw(point a, point b, point c)
{
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (dot(b, b) < dot(c, c)) return -2; // a--b--c on line
	return 0;
}

namespace std
{
	bool operator<(point a, point b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}
polygon convex_hull(vector<point> &P)
{
	int n = P.size(), k = 0;
	vector<point> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}
vector<pair<int, int>> antipodal(const polygon &P)
{
	vector<pair<int, int>> ans;
	int n = P.size();

	if (P.size() == 2)
		ans.push_back({ 0, 1 });

	if (P.size() < 3)
		return ans;

	int q0 = 0;

	while (abs(area2(P[n - 1], P[0], P[NEXT(q0)]))
			> abs(area2(P[n - 1], P[0], P[q0])))
		++q0;

	for (int q = q0, p = 0; q != 0 && p <= q0; ++p)
	{
		ans.push_back({ p, q });

		while (abs(area2(P[p], P[NEXT(p)], P[NEXT(q)]))
				> abs(area2(P[p], P[NEXT(p)], P[q])))
		{
			q = NEXT(q);
			if (p != q0 || q != 0)
				ans.push_back({ p, q });
			else
				return ans;
		}

		if (abs(area2(P[p], P[NEXT(p)], P[NEXT(q)]))
				== abs(area2(P[p], P[NEXT(p)], P[q])))
		{
			if (p != q0 || q != n - 1)
				ans.push_back({ p, NEXT(q) });
			else
				ans.push_back({ NEXT(p), q });
		}
	}

	return ans;
}
const int oo = 1e9; // adjust

double check(int a, int b, int c, int d, const polygon &P)
{
	for (int i = 0; i < 4 && a != c; ++i)
	{
		if (i == 1) swap(a, b);
		else swap(c, d);
	}
	if (a == c) // a admits a support line parallel to bd
	{
		double A = abs(area2(P[a], P[b], P[d])); 
		// double of the triangle area
		double base = abs(P[b] - P[d]);
		// base of the triangle abd
		return A / base;
	}
	return oo;
}

double polygon_width(const polygon &P)
{
	auto pairs = antipodal(P);
	double best = 0;
	int n = pairs.size();
	// cout<<n<<'\n';
	for (int i = 0; i < n; ++i)
	{
		// cout<<pairs[i].f<<' '<<pairs[i].s<<'\n';
		double tmp = abs(P[pairs[i].f] - P[pairs[i].s]);
		best = max(best, tmp);
	}

	return best;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	polygon p(n);
	double a, b;
	fore(i, 0, n)
	{
		cin>>a>>b;
		p[i] = {a, b};
	}
	p = convex_hull(p);
	// for(auto cat : p)
	// 	cout<<real(cat)<<' '<<imag(cat)<<'\n';
	cout<<fixed<<setprecision(6)<<(double)polygon_width(p)<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil