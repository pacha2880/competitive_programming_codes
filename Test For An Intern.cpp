#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long double      ld;
typedef long long      ll;
#define pb                push_back
#define mp                make_pair
#define	sz(a)			  a.size()
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)	  for (int i = b; i < e; i++)
#define forr(i, b, e)     for (ll i = (ll)b; i < (ll)e; i++)
ll faster_in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = ll(1e9 + 7);
const ld EPS = 1e-9;
const ld EPS1 = 1e-8;
const ld PI = acos(-1);
bool eq(ld a, ld b) {return fabs(a - b) < EPS;}
struct point
{
	ld x, y;
	point() {}
	point(ld x, ld y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	point operator *(ld d) {return point(x * d, y * d);}
	point operator /(ld d) {return point(x / d, y / d);}
	ld norm() {return hypot(x, y);}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) > -EPS;}
	bool right(point a, point b) {return ((b - a) ^ (*this - a)) < EPS;}
	bool operator <(point p) {return eq(x, p.x) ? y < p.y - EPS : x < p.x - EPS;}
	ld operator ^(point p) {return x * p.y - y * p.x;}
};
ld dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
ld area(vector<point> po)
{
	ld res = 0;
	fore(i, 0, po.size()-1)
	{
		res += po[i].x * po[i+1].y - po[i].y * po[i+1].x;
	}
	return fabs(res) / 2;
}
struct line
{
	ld a, b, c;
	line() {}
	line(point p, point q)
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
	}
};
ld det(ld a, ld b, ld c, ld d)
{
	return a * d - c * b;
}
point intersect(line a, line b)
{
	ld d = -det(a.a, a.b, b.a, b.b);
	return point(det(a.c, a.b, b.c, b.b) / d, det(a.a, a.c, b.a, b.c) / d);
}
bool interseg(ld a, ld b, ld c, ld d)
{
	return max(min(a, b), min(c, d)) < min(max(a, b), max(c,d)) + EPS;
}
bool inter(point a, point b, point c, point d)
{
	if(!((a.left(c, d) && b.right(c, d) || a.right(c, d) && b.left(c, d)) &&
		(c.left(a, b) && d.right(a, b) || d.left(a, b) && c.right(a, b))))
	return false;
	return interseg(a.x, b.x, c.x, d.x) && interseg(a.y, b.y, c.y, d.y);
}
bool para(point a, point b, point c, point d)
{
	return a.left(c, d) && a.right(c, d) && b.right(c, d) && b.left(c, d);
}
vector<point> hull (vector<point> p)
{
	int n = p.size();
	vector<point> h;
	sort(all(p));
	fore(i, 0, n)
	{
		while(h.size() >= 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n - 1; i >-1; i--)
	{
		while(h.size() >= k + 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.pb(p[i]);
	}
	return h;
}
bool inslog(vector<point> &pol, point p)
{
	int lo = 1, hi = pol.size() - 2, mid;
	if(!p.left(pol[0], pol[1]) || !p.left(pol[hi], pol[0])) return false;
	while(lo < hi - 1)
	{
		mid = (lo + hi) / 2;
		if(!p.left(pol[0], pol[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return !p.left(pol[hi], pol[lo]);
}
point cen(vector<point> p)
{
	ld x = 0, y = 0, area = 0, ax;
	int n = p.size() - 1;
	fore(i, 0, n)
	{
		ax = (p[i] ^ p[i+1]) / 2;
		area += ax;
		x += ax * (p[i].x + p[i+1].x) / 3;
		y += ax * (p[i].y + p[i+1].y) / 3;
	}
	//cout<<"eee "<<ar<<'\n';
	return point(x / area, y / area);
}
point v, axv;
int n, m;
vector<point> pola, polb;
ld f(ld mul, bool im)
{
	vector<point> hu;
	axv = axv * mul;
	fore(i, 0, m + 1)
	{
		polb[i] = polb[i] + axv;
	}
	if(im){
	fore(i, 0, m) cout<<polb[i].x<<' '<<polb[i].y<<'\n';
	cout<<'\n';}
	fore(i, 0, n)
	{
		if(inslog(polb, pola[i]))
			hu.pb(pola[i]);
	}
	fore(i, 0, m)
	{
		if(inslog(pola, polb[i]))
			hu.pb(polb[i]);
	}

	//cout<<"@\n";
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			if(inter(pola[i], pola[i + 1], polb[j], polb[j + 1]) && !para(pola[i], pola[i + 1], polb[j], polb[j+1]))
				hu.pb(intersect(line(pola[i], pola[i + 1]), line(polb[j], polb[j+1])));
		}
	}
	//cout<<"$\n";
	fore(i, 0, m + 1)
	{
		polb[i] = polb[i] - axv;
	}
	//cout<<"&\n";
	//cout<<hu.size()<<' '<<mul<<'\n';
	/*fore(i, 0, hu.size())
	{
		cout<<hu[i].x<<' '<<hu[i].y<<'\n';
	}*/
	hu = hull(hu);
	axv = v / v.norm();
	//cout<<"^\n";
	if(im)
	fore(i, 0, hu.size())
	{
		cout<<hu[i].x<<' '<<hu[i].y<<'\n';
	}
	return area(hu);
}
int main()
{
    //std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ld ar;
    cin>>n>>m>>ar;
    pola.resize(n); polb.resize(m);
    fore(i, 0, n) {cin>>pola[i].x>>pola[i].y; }
    fore(i, 0, m) {cin>>polb[i].x>>polb[i].y; }
    pola.pb(pola[0]);
    polb.pb(polb[0]);
    point ca = cen(pola), cb = cen(polb);
    ld ar1 = area(pola), ar2 = area(polb);
    if(eq(ar, ar1 + ar2))
    {
    	cout<<"Yes\n";
    	cout<<0<<' '<<0<<'\n';
    	return 0;
    }
    if(ar1 + ar2 < ar - 1e4)
    {
    	cout<<"No\n";
    	return 0;
    }
    //cout<<ca.x<<','<<ca.y<<' '<<cb.x<<','<<cb.y<<'\n';
    v = cen(pola) - cen(polb), axv = v;
    while(fabs(axv.y) < 10 && fabs(axv.x) <10)
    	axv = axv * 2;
    ld maxd = -1, mind = 1e20;
    point ax;
    //cout<<v.x<<' '<<v.y<<'\n';
    //cout<<axv.x<<' '<<axv.y<<'\n';
    fore(i, 0, m)
    {
    	fore(j, 0, n)
    	{
    		if(inter(polb[i], polb[i] + axv, pola[j], pola[j+1]))
    		{
    			point t = polb[i] + axv;
    		ax = intersect(line(polb[i], t), line(pola[j], pola[j+1]));
    		maxd = max(maxd, dist(ax, polb[i]));
    		mind = min(mind, dist(ax, polb[i]));}

    		if(inter(polb[i], polb[i + 1], pola[j], pola[j] - axv))
    		{
    			point t = pola[j] - axv;
    		ax = intersect(line(pola[i], t), line(polb[i], polb[i+1]));
    		maxd = max(maxd, dist(ax, pola[j]));
    		mind = min(mind, dist(ax, pola[j]));}
    	}
    }
    //cout<<'\n';
    //cout<<mind<<' '<<maxd<<'\n';
    ld lo = mind, hi = maxd, mid;
    axv = v / v.norm();
    //cout<<"chachp\n";
    fore(i, 0, 50)
    {
    	mid = (lo + hi) / 2;
    	if(f(mid, 0) < f(mid + EPS1, 0))
    		lo = mid;
    	else
    		hi = mid;
    }
    //cout<<"asd"<<f(mid,1)<<' '<<mid<<'\n';
    if(ar1 + ar2 - f(mid, 0) < ar + 1e-4)
    {
    	lo = mind, hi = mid - EPS;
    	//cout<<lo<<' '<<f(hi, 0)<<"   sdfsdfsdfdsfsfd\n";
    	fore(i, 0, 50)
    	{
    		mid = (lo + hi) / 2;
    		if(ar1 + ar2 - f(mid, 0) > ar + EPS)
    			lo = mid;
    		else
    			hi = mid;
    	}
    	//cout<<f(mid, 1)<<'\n';
    	cout<<"Yes\n";
    	cout<<fixed<<setprecision(6)<<(double)(axv.x * mid) <<' '<<(double)(axv.y * mid) <<'\n';
    }
    else
    {
    	cout<<"No\n";
    }
    return 0;
}
// PLUS ULTRA!
