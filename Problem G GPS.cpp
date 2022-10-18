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
	double x,y,z;
	point(){}
	point(double x, double y, double z) : x(x), y(y), z(z) {}
};
double dist(point a, point b)
{
	return hypot(hypot(a.x-b.x,a.y-b.y),a.z-b.z);
}
point scale(point a, double b)
{
	return point(a.x*b, a.y*b, a.z*b);
}
double norm(point a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
point rotatex(point a, double ang)
{
	return point(a.x, a.y*cos(ang) - a.z * sin(ang), a.y*sin(ang) + a.z*cos(ang));
}
point rotatey(point a, double ang)
{
	return point(a.x*cos(ang) + a.z*sin(ang), a.y, -a.x*sin(ang) + a.z*cos(ang));
}
point rotatez(point a, double ang)
{
	return point(a.x*cos(ang) - a.y*sin(ang), a.x*sin(ang) + a.y * cos(ang), a.z);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	point me, sat;
	double a, b, c, d, hip, dis,f;
	cin>>a>>b;
	a *= PI/180.0;
	b *= PI/180.0;
	me = point(1,0,0);
	me = rotatez(me, b);
	//cout<<fixed<<setprecision(3)<<me.x<<' '<<me.y<<' '<<me.z<<'\n'<<'\n';
	me = rotatey(me, a);
	//cout<<norm(me)<<'\n';
	//cout<<fixed<<setprecision(3)<<me.x<<' '<<me.y<<' '<<me.z<<'\n'<<'\n';
	me = scale(me,6371000.0);
	double e = 6371000.0 * 6371000.0;
	while(n--)
	{
		cin>>a>>b>>c>>d;
		a *= PI/180.0;
		f = a;
		c *= 1000.0;
		a =  2.0 * PI *d;
		b *= PI/180.0;
		sat = point(1,0,0);
		sat = rotatey(sat,a);
		//cout<<fixed<<setprecision(3)<<sat.x<<' '<<sat.y<<' '<<sat.z<<'\n';
		sat = rotatex(sat,b);
		//cout<<fixed<<setprecision(3)<<sat.x<<' '<<sat.y<<' '<<sat.z<<'\n';
		sat = rotatey(sat,f);
		//cout<<'\n'<<'#'<<norm(sat)<<'\n';
		//cout<<fixed<<setprecision(3)<<sat.x<<' '<<sat.y<<' '<<sat.z<<'\n';
		sat = scale(sat, c);
		dis = sqrt(c*c - e);
		//cout<<dis<<' '<<dist(sat, me)<<'\n'<<me.x<<' '<<me.y<<' '<<me.z<<'\n'<<sat.x<<' '<<sat.y<<' '<<sat.z<<'\n';
		//cout<<norm(sat)<<'@'<<'\n';
		if(dis > dist(sat, me) - EPS)
		{
			cout<<fixed<<setprecision(8)<<dist(sat, me)/299792458.0<<'\n';
		}
		else
			cout<<"no signal\n";
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS