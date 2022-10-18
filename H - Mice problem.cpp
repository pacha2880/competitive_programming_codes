	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	#define PI 			acos(-1)
	#define mp			make_pair
	#define pb			push_back
	#define all(a)		(a).begin(), (a).end()
	#define srt(a)			sort(all(a))
	#define mem(a, h)	memset(a, (h), sizeof(a))
	#define f 			first
	#define s 			second
	#define MOD			1000000007
	#define MOD1		998244353
	#define EPS			1e-12
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
		double x, y;
		point() {}
		point(double x, double y) : x(x), y(y) {}
	};
	point translate(point a, point b)
	{
		return point(a.x + b.x, a.y + b.y);
	}
	point tovec(point a, point b)
	{
		return point(b.x - a.x, b.y - a.y);
	}
	struct line
	{
		double a, b, c;
		line(point p, point q)
		{
			a = p.y - q.y;
			b = q.x - p.x;
			c = -a * p.x - b * p.y;
			double z = sqrt(a * a + b * b) * (a < - EPS ? -1 : 1);
			a /= z;
			b /= z;
			c /= z;
		}
	};

	double crossd(point a, point b)
	{
		return a.x * b.y - a.y * b.x;
	}
	double cross(point a, point b, point c)
	{
		return crossd(tovec(a, b), tovec(a, c));
	}

	double det(double a, double b, double c, double d)
	{
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<"asdasd\n";
		return a * d - b * c;
	}
	point intersect(line l1, line l2)
	{
		double d = -det(l1.a, l1.b, l2.a, l2.b);
		//cout<<l1.a<<' '<<l1.b<<' '<<l1.c<<','<<l2.a<<' '<<l2.b<<' '<<l2.c<<'\n';
		//cout<<d<<'\n';
		return point(det(l1.c, l1.b, l2.c, l2.b) / d, det(l1.a, l1.c, l2.a, l2.c) / d);
	}
	point scale(point p, double d)
	{
		return point(p.x * d, p.y * d);
	}
	bool ins(point p, point a, point b)
	{
		return p.x < b.x + EPS && p.x > a.x - EPS && p.y < b.y + EPS && p.y > a.y - EPS;
	}
	bool eq(double a, double b)
	{
		return fabs(a - b) < EPS;
	}

	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("qwe.txt", "r", stdin);
		//freopen("asd.txt", "w", stdout);
		int n;
		cin>>n;
		point aa, bb, cc, dd;
		cin>>aa.x>>aa.y>>cc.x>>cc.y;
		bb = point(cc.x, aa.y);
		dd = point(aa.x, cc.y);
		pair<point, point> seg[4];
		seg[0] = mp(aa, bb);
		seg[1] = mp(bb, cc);
		seg[2] = mp(cc, dd);
		seg[3] = mp(dd, aa);
		pair<point, point> ar[n];
		vector<double> v;
		point ex;
		double tt = -1;
		for(int i = 0; i < n; i++)
		{
			cin>>ar[i].f.x>>ar[i].f.y>>ar[i].s.x>>ar[i].s.y;
			vector<point> posib;
			if(fabs(ar[i].s.x) < EPS && fabs(ar[i].s.y) < EPS)
			{
				tt = max(tt, 0.0);
			}
			point ax = translate(ar[i].f, ar[i].s);
			double ins = 1e9;
			if(eq(ar[i].s.x, 0) && eq(ar[i].s.y, 0))
			{
				tt = 0;
				if(!(ar[i].f.x < cc.x - EPS && ar[i].f.x > aa.x + EPS && ar[i].f.y < cc.y - EPS && ar[i].f.y > aa.y + EPS))
					{
						cout<<-1;
						return 0;
					}
					tt = max(tt, 0.0);
					continue;
			}
			//cout<<ax.x<<' '<<ax.y<<'\n';
			line l(ar[i].f, ax);
			bool abo = false;
			for(int j = 0; j < 4; j++)
			{
				double croa = cross(ar[i].f, ax, seg[j].f);
				double crob = cross(ar[i].f, ax, seg[j].s);
				//cout<<croa<<'@'<<crob<<'\n';
				if(eq(croa, 0) || eq(crob, 0))
				{
					if(eq(croa, 0) && eq(crob, 0))
					{
						abo = true;
						break;
					}
					if(eq(croa, 0))
						posib.pb(seg[j].f);
					if(eq(crob, 0))
						posib.pb(seg[j].s);
				}
				else
				{
					if(croa * crob < EPS)
						posib.pb(intersect(l, line(seg[j].f, seg[j].s)));
				}
			}
			if(abo && !(ar[i].f.x < cc.x - EPS && ar[i].f.x > aa.x + EPS && ar[i].f.y < cc.y - EPS && ar[i].f.y > aa.y + EPS))
			{
				cout<<"-1";
				return 0;
			}
			bool bo = false;
			for(int j = 0; j < posib.size(); j++)
			{
				if((posib[j].x - ar[i].f.x) * (ax.x - ar[i].f.x) > -EPS && (posib[j].y - ar[i].f.y) * (ax.y - ar[i].f.y) > -EPS)
				{
					//cout<<i<<' '<<posib[j].x<<','<<posib[j].y<<'\n';
					if(fabs(ar[i].s.x) < EPS)
						ins = min(ins,(posib[j].y - ar[i].f.y) / (ar[i].s.y));
					else
						ins = min(ins,(posib[j].x - ar[i].f.x) / (ar[i].s.x));
					bo = true;
				}	
			}
			if(ar[i].f.x < cc.x + EPS && ar[i].f.x > aa.x - EPS && ar[i].f.y < cc.y + EPS && ar[i].f.y > aa.y - EPS)
				ins = 0;
			if(bo)
			{
				{tt = max(tt, ins);}
			}
		}
		int max = 0;
		double t = 0;
		int can = 0;
		sort(v.begin(), v.end());
		double ttt = tt;
		tt += 1e-10;
		//cout<<tt<<'\n';
			for(int j = 0; j < n; j++)
			{
				point p(ar[j].f.x+ar[j].s.x*tt, ar[j].f.y+ar[j].s.y*tt);
				//cout<<p.x<<','<<p.y<<' ';
				if(p.x < cc.x + EPS && p.x > aa.x - EPS && p.y < cc.y + EPS && p.y > aa.y - EPS)
				{
					can++;
				}
			}
			if(can == n)
			{
				cout<<fixed<<setprecision(7)<<tt;
			}
			else
				cout<<-1;
			
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS