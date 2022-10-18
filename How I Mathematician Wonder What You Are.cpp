#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
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
typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };

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
/*
	Check wether there is a point in the intersection of
	several semi-planes. if p lies in the border of some
	semiplane it is considered to belong to the semiplane.
	Expected Running time: linear
	Tested on Triathlon [Cuban Campament Contest]
*/
bool side(line &l, point &p){
		// IMPORTANT: point p belongs to semiplane defined by l
		// iff p it's clockwise respect to segment < l.p, l.q >
		// i.e. (non negative cross product)

		return cross( l.q - l.p, p - l.p ) >= 0;
	}

	bool crosspoint(const line &l, const line &m, point &x){
		double A = cross(l.q - l.p, m.q - m.p);
		double B = cross(l.q - l.p, l.q - m.p);
		if (abs(A) < eps) return false;
		x = m.p + B / A * (m.q - m.p);
		return true;
	}
bool intersect( vector<line> semiplane ){

	


	int n = (int)semiplane.size();

	random_shuffle( semiplane.begin(), semiplane.end() );

	point cent(0, 1e9);

	for (int i = 0; i < n; ++i){
		line &S = semiplane[ i ];

		if (side(S, cent)) continue;

		point d = S.q - S.p; d /= abs( d );

		point A = S.p - d * 1e8, B = S.p + d * 1e8;

		for (int j = 0; j < i; ++j){
			point x;
			line &T = semiplane[j];

			if ( crosspoint(T, S, x) ){
				int cnt = 0;


				if (!side(T, A)){
					A = x;
					cnt++;
				}

				if (!side(T, B)){
					B = x;
					cnt++;
				}

				if (cnt == 2)
					return false;
			}
			else{
				if (!side(T, A)) return false;
			}
		}

		if (imag(B) > imag(A)) swap(A, B);
		cent = A;
	}

	return true;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
	while(cin>>n && n)
	{
		polygon p(n);
		double a, b;
		fore(i, 0, n)
		{
			cin>>a>>b;
			p[i] = complex<double>(a, b);
		}
		vector<line> lis(n);
		fore(i, 0, n)
		{
			lis[i].p = p[i];
			lis[i].q = p[NEXT(i)];
		}
		cout<<intersect(lis)<<'\n';
	}
	return 0;
}

