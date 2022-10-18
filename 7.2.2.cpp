			#include <bits/stdc++.h>
		#define PI 			acos(-1)
		#define mp			make_pair
		#define pb			push_back
		#define all(a)		(a).begin(), (a).end()
		#define srt(a)			sort(all(a))
		#define mem(a, h)	memset(a, (h), sizeof(a))
		#define f 			first
		#define s 			second
		#define MOD			1000000007
		#define EPS			1e-9
		int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

		using namespace std;

		typedef long long 		ll;
		typedef unsigned long long 		ull;
		typedef pair<int, int>  ii;
		typedef vector<int>     vi;
		typedef vector<ii>      vii;
		typedef vector<ll>      vll;
		struct line {double a,b,c;};
		bool areParallel(line a, line b)
		{
			return((fabs(a.a-b.a)<EPS)&&(fabs(a.b-b.b)<EPS));
		}
		bool areSame(line a, line b)
		{
			return areParallel(a,b)&&(fabs(a.c-b.c)<EPS);
		}
		struct point
		{
			double x,y;
			point(double _x, double _y) : x(_x), y(_y) {}
			point operator+(point a) const
			{
				a.x+=x;
				a.y+=y;
				return a;
			}
		};
		double dist(point a, point b)
		{
			return hypot(a.x-b.x,a.y-b.y);
		}
		void toline(point a, point b, line &l)
		{
			if(fabs(a.x-b.x)<EPS)
				{l.a = 1, l.b = 0, l.c = -a.x; return;}
			l.a = -(a.y - b.y) / (a.x - b.x);
			l.b = 1;
			l.c = -l.a * a.x - a.y;
		}
		void tolinegr(point a, double gr, line &l)
		{
			l.a = -gr;
			l.b = 1;
			l.c = a.x * gr - a.y;
		}
		point tovec(point a, point b)
		{
			return point(b.x-a.x,b.y-a.y);
		}
		point translate (point p, point v)
		{
			return point(p.x+v.x,p.y+v.y);
		}
		point scale(point v, double sc)
		{
			return point(v.x*sc,v.y*sc);
		}
		point rotate(point v, double theta)
		{
			theta *= acos(-1)/180.0;
			return point(v.x*cos(theta)-v.y*sin(theta),v.x*sin(theta)+ v.y*cos(theta));
		}
		bool areIntersect(line l1, line l2, point &p)
		{
			if(areParallel(l1,l2)) return false;
			p.x = (-l1.c*l2.b + l2.c*l1.b) / (l1.a*l2.b-l2.a*l1.b);
			if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
			else
				p.y = -(l2.a*p.x +l2.c);
			return true;
		}
		point clos(point a, line l, line &pe)
		{
			if(fabs(l.a) < EPS)
			{
				pe.a = 1, pe.b = 0, pe.c = -a.x;
				return point(a.x,-l.c); 
			}
			if(fabs(l.b) < EPS)
			{
				pe.a = 0, pe.b = 1, pe.c = -a.y;
				return point(-l.c,a.y);
			}
			tolinegr(a, 1/(l.a),pe);
			areIntersect(l,pe,a);
			return a;
		}
		point reflexion(point p, point a, point b)
		{
			line l,li;
			toline(a,b,li);
			point p1 = clos(p,li,l);
			p1 = p1+(tovec(p,p1));
			return p1;
		}
		double norm_sq(point a)
		{
			return a.x * a.x + a.y * a.y;
		}
		double dot(point a, point b)
		{
			return a.x*b.x + b.y*a.y;
		}
		double angle(point a, point b, point c)
		{
			a = tovec(b,a), b = tovec(b,c);
			double res = dot(a,b);
			res = acos(res / (sqrt(norm_sq(a))*sqrt(norm_sq(b))));
			res*= 180.0/acos(-1);
			return res;
		}
		double cross(point a, point b)
		{
			return a.x * b.y - a.y * b.x;
		}
		bool left(point a, point b, point c)
		{
			c = tovec(b,c);
			a = tovec(b,a);
			return (cross(c,a)>0.0);
		}
		bool coolinear(point a, point b, point c)
		{

			c = tovec(b,c);
			a = tovec(b,a);
			return (fabs(cross(c,a))<EPS);
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			point a(2,2), b(4,3), c(2,2), d(2,4);
			line l1, l2;
			toline(a,b,l1);
			toline(c,d,l2);
			cout<<l1.a<<' '<<l1.b<<' '<<l1.c<<endl<<l2.a<<' '<<l2.b<<' '<<l2.c<<endl;
			c.x=3;
			d = tovec(a,b);
			c = translate(c,d);
			cout<<c.x<<' '<<c.y<<endl;
			a = scale(d,0.5);
			c = point(3,2);
			c = translate(c,a);
			cout<<c.x<<' '<<c.y<<endl;
			c = point(3,2);
			c = translate(c,d);
			c = rotate(c,90);
			cout<<c.x<<' '<<c.y<<endl;
			c = point(3,2);
			c = rotate(c,90);
			c = translate(c,d);
			cout<<c.x<<' '<<c.y<<endl;
			c = rotate(tovec(point(2,1),point(3,2)),90)+point(2,1);
			cout<<c.x<<' '<<c.y<<endl;
			a = point(2,2), b = point(4,3);
			point o = point(2,4);
			cout<<angle(a,o,b)<<endl;
			point r = point(35,31), p = point(3,7), q =point(11,13);
			if(coolinear(r,p,q))
			{
				cout<<"coolinear"<<endl;
			}
			else
				if(left(r,p,q))
					cout<<"left"<<endl;
				else
					cout<<"right"<<endl;

			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS