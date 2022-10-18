#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
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
const ld EPS = 1e-9;
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
	ll sq() {return x * x + y * y;}
	ld abs() {return sqrtl((ld)sq());}
  	point operator *(ll a) {return point(x * a, y * a);}
	bool operator <(const point& p) const {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}

};
struct point1
{
	ld x, y, pro;
	point1() {}
	point1(ld x, ld y): x(x), y(y) {}
	point1(ld x, ld y, ld pro): x(x), y(y), pro(pro) {}
	point1 operator -(point1 p) {return point1(x - p.x, y - p.y);}
	point1 operator +(point1 p) {return point1(x + p.x, y + p.y);}
	ld operator ^(point1 p) {return x * p.y - y * p.x;}
  	ld operator *(point1 p) {return x * p.x + y * p.y;}
  	point1 operator *(ld a) {return point1(x * a, y * a);}
	ld sq() {return x * x + y * y;}
	ld abs() {return sqrtl(sq());}
	bool operator <(const point1& p) const{return pro < p.pro;}
	bool left(point1 a, point1 b) {return ((b - a) ^ (*this - a)) >= 0;}
	ostream& operator<<(ostream& os) {
		return os << "("<< x << "," << y << ")";
	}

};
struct line
{
  ld a, b, c;
  line(point p, point q)
  {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
  };
  void setOrigin(point p) { c += a * p.x + b * p.y; } //trasladar linea como si p fuera el origen
};

ld det(ld a, ld b, ld c, ld d)
{
	return a * d - b * c;
}

point1 intersec(line a, line b) //primero estar seguro si no son paralelas
{
	ld d = -det(a.a, a.b, b.a, b.b);
	return {det(a.c, a.b, b.c, b.b) / d, det(a.a, a.c, b.a, b.c) / d};
}
ll sig(ll x)
{
	return x == 0 ? 0 : (x > 0 ? 1 : -1);
}
int main()
{
		ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, q;
	vector<point> pol;
	cin>>n>>q;
	point p;
	double a, b, c, d;
	fore(i, 0, n)
	{
		cin>>a>>b;
		p = {(ll)(a * 100 + (a < -EPS ? -0.1 : 0.1)), (ll)(b * 100 + (b < -EPS ? -0.1 : 0.1))};
		while(pol.size() > 2 && ((pol.back() - p) ^ (pol[sz(pol) - 2] - p)) == 0)
			pol.pop_back();
		pol.pb(p);
	}
	point p1, p2, q1, q2, q3, q4;
	n = pol.size();
	point1 wer, wur;
	ld xx, yy, aa, bb;
	cout<<fixed<<setprecision(6);
	fore(i, 0, q)
	{
		vector<pair<point1, int>> su;
		cin>>a>>b>>c>>d;
		p1 = {(ll)(a * 100 + (a < -EPS ? -0.1 : 0.1)), (ll)(b * 100 + (b < -EPS ? -0.1 : 0.1))};
		p2 = {(ll)(c * 100 + (c < -EPS ? -0.1 : 0.1)), (ll)(d * 100 + (d < -EPS ? -0.1 : 0.1))};
		//cout<<p1.x<<' '<<p1.y<<' '<<p2.x<<' '<<p2.y<<'\n';
		line l(p1, p2);
		aa = -l.a;
		bb = -l.b;
		wur = {aa, bb};
		ld res = 0;
		fore(i, 0, n)
		{
			q1 = pol[i], q2 = pol[(i + 1) % n], q3 = pol[(i + n - 1) % n], q4 = pol[(i + 2) % n];
			if(((p1 - p2) ^ (q1 - p2)) == 0)
			{
				xx = q1.x, yy = q1.y;
				if(n == 3)
				{
					if(sig((p1 - p2) ^ (q2 - p2)) * sig((p1 - p2) ^ (q3 - p2)) <= 0)
					su.pb({{xx, yy, aa * yy - bb * xx}, 0});
					continue;
				}
				if(((p1 - p2) ^ (q3 - p2)) == 0)
					continue;
				if(((p1 - p2) ^ (q2 - p2)) == 0)
				{
					if(sig((p1 - p2) ^ (q3 - p2)) * sig((p1 - p2) ^ (q4 - p2)) < 0)
					{
						su.pb({{xx, yy, aa * yy - bb * xx}, 1});
						xx = q2.x, yy = q2.y;
						su.pb({{xx, yy, aa * yy - bb * xx}, 1});
						res += (q1 - q2).abs();
					}
					else
					{
						su.pb({{xx, yy, aa * yy - bb * xx}, 2});
						xx = q2.x, yy = q2.y;
						su.pb({{xx, yy, aa * yy - bb * xx}, 2});
					}
				}
				else if(sig((p1 - p2) ^ (q2 - p2)) * sig((p1 - p2) ^ (q3 - p2)) < 0)	
					su.pb({{xx, yy, aa * yy - bb * xx}, 0});
			}
			else if(sig((p1 - p2) ^ (q1 - p2)) * sig((p1 - p2) ^ (q2 - p2)) < 0)
			{
				wer = intersec(l, line(q1, q2));
				su.pb({{wer.x, wer.y, wur ^ wer}, 0});
			}
		}

		sort(all(su));
		if(0)
		{
			cout<<fixed<<setprecision(2);
			cout<<"el mono tiene tamanio "<<su.size()<<"\n";
			cout<<(double)res / 100<<'\n';
			cout<<(double)a<<' '<<(double)b<<' '<<(double)c<<' '<<(double)d<<'\n'<<'\n';
			fore(i, 0, su.size())
			{
				cout<<(double)su[i].f.x / 100.0<<' '<<(double)su[i].f.y / 100.0<<' '<<su[i].s<<' '<<(double)su[i].f.pro / 100.0<<'\n';
			}
		}
		int la = 0, bo = 1;
		fore(i, 0, su.size())
		{
			if(su[i].s == 1)
			{
				res += (su[i + 1].f - su[i + 2].f).abs();
				i++;
				if(su[i + 1].s == 1) i++;
			}
			else if(su[i + 1].s == 1)
			{
				res += (su[i].f - su[i + 1].f).abs();
				i++;
			}
			else if(su[i].s == 2)
			{
				res += (su[i].f - su[i + 1].f).abs();	
			}
			else if(su[i + 1].s == 2)
			{
				la = i;
				while(su[i + 1].s == 2) i++;
				res += (su[la].f - su[i + 1].f).abs();
			}
			else
			{
				res += (su[i].f - su[i + 1].f).abs();
			}
			i++;
		}
		cout<<(double)(res/ 100)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	