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
	point() {x=y=0;}
	point(double X, double Y): x(X), y(Y){}
};
point tovec(point a, point b)
{
	return point(b.x-a.x, b.y - a.y);
}
double cross(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
bool ccw(point a, point b, point c)
{
	return cross(tovec(a,b), tovec(a,c)) > 0;
}
double area(const vector<point> &p)
{
	double res = 0;
	for(int i = 0; i < p.size()-1; i++)
		res += p[i].x*p[i+1].y - p[i].y*p[i+1].x;
	return fabs(res)/2.0;
}
point lineIntersectSeg(point p, point q, point A, point B)
{
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x*A.y - B.y*A.x;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u)/(u+v), (p.y * v + q.y * u)/(u+v));
}
vector<point> cutPolygon(point a, point b,const vector<point> &q, bool left)
{
	vector<point> p;
	for(int i = 0; i< q.size(); i++)
	{
		double left1 = cross(tovec(a,b), tovec(a,q[i])), left2 = 0;
		if(left1 > -EPS && left || left1 < EPS && !left) p.pb(q[i]);
		if(i!=q.size()-1) left2 = cross(tovec(a,b), tovec(a,q[i+1]));
		if(left1 * left2 < -EPS) p.pb(lineIntersectSeg(q[i],q[i+1],a,b));
	}
	if(!p.empty() && (p.front().x != p.back().x || p.front().y != p.back().y)) 
		p.pb(p.front());
	return p;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n,con=0;;
	double w,h;
	point a,b,c;
	while(cin>>n)
	{
		con++;
		cin>>w>>h>>c.x>>c.y;
		vector<point> p = {point(0,0),point(w,0),point(w,h),point(0,h),point(0,0)};
		while(n--)
		{
			cin>>a.x>>a.y>>b.x>>b.y;
			if(ccw(a,b,c))
				p = cutPolygon(a,b,p,true);
			else
				p = cutPolygon(a,b,p,false);
		}
		cout<<"Case #"<<con<<": "<<fixed<<setprecision(3)<<area(p)<<endl;
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS