#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-12
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct point
{
	ll x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	bool operator <(point p) {return x == p.x ? y < p.y : x < p.x;}
};
const int tam = 100010;
vector<point> hull(vector<point> p)
{
	vector<point> h;
	sort(p.begin(), p.end());
	int n = p.size();
	fore(i, 0, n)
	{
		while(h.size() >= 2 && ((h.back() - h[h.size()-2]) ^ (p[i] - h[h.size()-2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= k + 2 && ((h.back() - h[h.size()-2]) ^ (p[i] - h[h.size()-2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	return h;
}
ll a;
double cal(point p, double x)
{
	p.y = abs(p.y);
	double dz = p.y + a, dx = p.x - x;
	return p.x - dx + (double)a * dx / dz;
}
bool eq(double a, double b)
{
	return fabs(a - b)  < EPS;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	scanf("%d", &cas);
	//cout<<fixed<<setprecision(7);
	while(cas--)
	{
		int n, m;
		scanf("%d %d", &n, &a);
		//assert(n < 50000);
		vector<point> p(n);
		ll zmi = MOD, zma = 0;
		fore(i, 0, n)
		{
			scanf("%lld %lld", &(p[i].x), &(p[i].y));
			//cin>>p[i].x>>p[i].y;
			zmi = min(zmi, p[i].y);
			zma = max(zma, p[i].y);
			p[i].y = -p[i].y;
		}
		//cout<<1;
		if(n > 1)
			p = hull(p);
		//cout<<2;
		n = p.size();
		int dowl = 0, dowr = 0, upl = 0, upr = 0;
		fore(i, 0, p.size())
		{
			if(p[dowl].y == p[i].y)
			{
				if(p[dowl].x > p[i].x)
					dowl = i;
				if(p[dowr].x < p[i].x)
					dowr = i;
			}
			else
			{
				if(p[dowl].y > p[i].y)
					dowl = dowr = i;
			}
			if(p[upl].y == p[i].y)
			{
				if(p[upr].x < p[i].x)
					upr = i;
				if(p[upl].x > p[i].x)
					upl = i;
			}
			else
			{
				if(p[upr].y < p[i].y)
					upl = upr = i;
			}
		}
		//cout<<3;
		vector<point> left, right;
		for(int i = dowl; (i%n) != upl; i++)
		{
			left.pb(p[i]);
		}
		left.pb(p[upl]);
		left.pb( point(p[upl].x + 10, p[upl].y));
		for(int i = dowr; (i+n)%n != upr; i--)
		{
			right.pb(p[i]);
		}
		right.pb(p[upr]);
		right.pb(point(p[upr].x - 10, p[upr].y));
		//cin>>m;
		scanf("%d", &m);
		double x, y, x1, x2, y1, y2, dy, dz, an, al;
		int lo, hi, mid, res;
		while(m--)
		{
			scanf("%lf %lf",&x, &y);
			dy = y;
			dz = zma + a;
			y1 = dy - (double) a * dy / dz;
			dz = zmi + a;
			y2 = dy - (double) a * dy / dz;
			al = fabs(y1 - y2);
			lo = 1, hi = left.size()-2,res = 0;
			bool sen = cal(left[0], x) < cal(left[1], x) - EPS;
				while(lo <= hi)
				{
					mid = (lo + hi) / 2;
					if((cal(left[mid], x) < cal(left[mid+1], x) - EPS) != sen)
						res = mid, hi = mid -1;
					else
						lo = mid + 1;
				}
			x1 = cal(left[res], x);

			lo = 1, hi = right.size()-2,res = 0;
			sen = cal(right[0], x) < cal(right[1], x) - EPS;
				while(lo <= hi)
				{
					mid = (lo + hi) / 2;
					if((cal(right[mid], x) < cal(right[mid+1], x) - EPS) != sen)
						res = mid, hi = mid -1;
					else
						lo = mid + 1;
				}
			x2 = cal(right[res], x);
			an = fabs(x1 - x2);
			an *= al;
			printf("%.10lf\n", an);
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2
