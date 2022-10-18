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
#define EPS			1e-9
#define TIEPS			1e-10

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

    point operator+(const point &p) const {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p) const {
        return point(x - p.x, y - p.y);
    }
};
double dist(point &a, point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
double cross2(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
point tovec(point &a, point &b)
{
	return point(b.x - a.x, b.y - a.y);
}
double cross(point &a, point &b, point &c)
{
	return cross2(b-a, c-a);
}
point rotate(point a, double an)
{
	return point(a.x * cos(an) - a.y * sin(an), a.y * cos(an) + a.x * sin(an));
}
struct line
{
	double a, b, c;
	line() {}
	line(point p, point q)
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		double z = sqrt(a * a + b * b) * (a < - EPS ? -1 : 1);
		a /= z;
		b /= z;
		c /= z;
	}
};

double det(double &a, double &b, double &c, double &d)
{
	return a * d - b * c;
}

point intersect(line &l1, line &l2)
{
	double d = l1.b * l2.a - l1.a * l2. b;
	return point((l1.c * l2.b - l1.b * l2.c) / d, (l1.a * l2.c - l1.c * l2.a) / d);
}
bool eq(double &a, double &b)
{
	return fabs(a - b) < EPS;
}
point translate(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
double an(point a, point b, point c)
{
	b = tovec(a, b);
	c = tovec(a, c);
	return fabs(asin(cross2(b, c) / hypot(b.x, b.y) / hypot(c.x, c.y)));
}
point scale(point a, double d)
{
	return point(a.x * d, a.y * d);
}
point norm(point a)
{
	double d = hypot(a.x, a.y);
	return point(a.x / d, a.y / d);
}
point circun(point &a, point &b, point &c)
{
	point mea((a.x + b.x) / 2, (a.y + b.y) / 2), meb((a.x + c.x) / 2, (a.y + c.y) / 2);
	line l1(mea, mea + rotate(b - a, PI/2.0)), l2(meb, meb + rotate(c - a, PI/2.0));
	return intersect(l1, l2);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd1.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);

	int cas;
	cin>>cas;
	//cout<<fixed<<setprecision(9);
	point pri, posiba, posibc, d;
	while(cas--)
	{
		point a, b, c;
		scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
		if(fabs(cross(a,b,c)) < EPS)
		{
			printf("NO\n\n");
			continue;
		}
		if(cross(a, b, c) < -EPS)
			swap(b, c);
		bool bo = true;
		for(int i = 0; i < 3; i++)
		{
			pri = b + (b - a);
			pri = circun(b, pri, c);	
			posiba = b + (b - pri);
			posibc = c + (c -pri);
			if(fabs(dist(posiba, a) - dist(pri, b)) < EPS && fabs(dist(posibc, c) - dist(pri, b)) < EPS)
			{

				d = a + (a - posiba);
				//cout<<a.x<<' '<<a.y<<' '<<posiba.x<<' '<<posiba.y<<' '<<d.x<<' '<<d.y<<'\n';
				if(cross(pri, posibc, d) < EPS || cross(posibc, d, posiba) < EPS || cross(d, posiba, pri) < EPS || cross(posiba, pri, posibc) < EPS)
					{}
				else
				{
					printf("YES %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf \n", pri.x, pri.y, posiba.x, posiba.y, d.x, d.y, posibc.x, posibc.y);
					bo = false;
					break;
				}

			}
			swap(a, c);
			swap(b, c);
		}
		if(bo)
			printf("NO\n\n");


	}

	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2