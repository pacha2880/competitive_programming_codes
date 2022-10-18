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
		struct point
		{
			double x,y;
			point() {x=0.0; y = 0.0;}
			point(int _x, int _y) : x(_x), y(_y) {}
			point operator+(point b) const
			{
				b.x += x;
				b.y+=y;
				return b;
			}
		};
		struct line
		{
			double a,b,c;
		};
		double dist(point a, point b)
		{
			return hypot(fabs(a.x-b.x),fabs(a.y-b.y));
		}
		point tovec(point a, point b)
		{
			return point(b.x-a.x,b.y-a.y);
		}
		point translate(point a, point b)
		{
			a= a+b;
			return a;
		}
		point scale(point a, double s)
		{
			a.x*=s;
			a.y*= s;
			return a;
		}
		void pointsToLine(point a, point b, line &l)
		{
			if(fabs(a.x-b.x)<EPS)
			{
				l.a = 1, l.b = 0, l.c = -a.x; 
			}
			else
			{
				l.a = -(a.y-b.y) / (a.x - b.y), l.b = 1, l.c = -l.a * a.x - a.y;
			}
		}
		double rInCircle(double ab, double bc, double ca)
		{
			double s = (ab+bc+ca)/2;
			return sqrt(s*(s-ab)*(s-bc)*(s-ca));
		}
		double rIncircle(point a, point b, point c)
		{
			return rInCircle(dist(a,b),dist(b,c),dist(c,a));
		}
		bool areParallel(line a, line b)
		{
			return (fabs(a.a-b.a)<EPS)&&(a.b == b.b);
		}
		bool areIntersect(line a, line b, point &c)
		{
			if(areParallel(a,b)) return false;
			c.x = (b.c*a.b-a.c*b.b) / (a.a*b.b-b.a*a.b);
			if(a.b == 0.0) c.y = -(b.b*c.x + b.c);
			else			c.y = -(a.b*c.x + a.c);
			return true;
		}
		bool inCircle(point a, point b, point c, point &ctr)
		{
			double r = rIncircle(a,b,c);
			if(r< EPS) return false;
			line l1,l2;
			point p1;
			double ratio = dist(a,b) / dist(a,c);
			p1 = translate(b, scale(tovec(b,c),ratio/(1+ratio)));
			pointsToLine(a,p1,l1);
			ratio = dist(b,a) / dist(b,c);
			p1 = translate(a, scale(tovec(a,c),ratio/(1+ratio)));
			pointsToLine(b,p1,l2);
			areIntersect(l1,l2,ctr);
			return true;
		}
		bool circle2PtsRad(point a, point b, double r, point &c)
		{
			double det = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
			det = r * r / det - 0.25;
			if(det < 0.0) return false;
			det = sqrt(det);
			c.x = (a.x + b.x) * 0.5 + (b.y-a.y) * det;
			c.y = (a.y + b.y) * 0.5 + (a.x-b.x) * det;			
			return true;
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			point a = point(0,3), b(0,-3), c;
			circle2PtsRad(a,b,5,c);
			cout<<c.x<<' '<<c.y<<endl;
			circle2PtsRad(b,a,5,c);
			cout<<c.x<<' '<<c.y<<endl;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS