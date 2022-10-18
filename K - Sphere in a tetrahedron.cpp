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
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}
};
double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
point rotate(point a, double d)
{
	return point(a.x * cos(d) - a.y * sin(d), a.x * sin(d) + a.y * cos(d));
}
bool eq(double a, double b)
{
	return fabs(a - b) < EPS;
}
double sq(double a)
{
	return a*a;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd1.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	point p1, p2;
	double a, b, c, d, e, f, suri, sur, sura, surb, surc, surd, s, vol, h1, h2, h, h3, h4, bet, fi, g;
	cout<<fixed<<setprecision(4);
	while(n--)
	{
		cin>>a>>b>>c>>d>>e>>f;
		if(eq(a, 0) || eq(b, 0) ||eq(c, 0) ||eq(d, 0) ||eq(e, 0) ||eq(f, 0))
		sur = 0;
		s = (a + b + d) / 2.0;
		sura = sqrt(s * (s - a) * (s - b) * (s - d));
		s = (a + c + e) / 2.0;
		sur += sura;
		//cout<<sur<<' ';
		surb = sqrt(s * (s - a) * (s - c) * (s - e));
		sur += surb;
		//cout<<sur<<' ';
		s = (b + c + f) / 2.0;
		surc = sqrt(s * (s - c) * (s - b) * (s - f));
		sur += surc;
		//cout<<sur<<' ';
		h1 = 2.0 * surc / f;
		s = (d + e + f) / 2.0;
		surd = sqrt(s * (s - d) * (s - e) * (s - f));
		sur += surd;
		//cout<<sur<<' ';
		h3 = 2.0 * surc / f;
		//cout<<surc<<'^';
		g = sqrt(-h3*h3 + b*b);
		//cout<<'#'<<h3<<'$'<<g<<'+';
		h4 = 2.0 * surd / f;
		bet = fabs(asin(h4 / d));
		//cout<<bet*180.0/PI<<'%';
		//cout<<bet*180.0/PI<<' ';
		h2 = sqrt(d*d + g*g - 2*d*g*cos(bet));
		//cout<<h2<<'&';
		s = (a + h3 + h2) / 2.0;
		suri = sqrt(s * (s - a) * (s - h3) * (s - h2));
		h = 2.0 * suri / h2;
		//cout<<"asd "<<h<<' '<<suri<<' '<<h2<<'\n';
		vol = surd * h / 3.0;
		a *= a;
		b *= b;
		c *= c;
		d *= d;
		e *= e;
		f *= f;
		vol = sqrt(4.0*a*b*c-a*sq((b+c-f))-b*sq((a+c-e))-c*sq((a+b-d))+(b+c-f)*(c+a-e)*(a+b-d))/12.0;
		sur = 0;
		sur += sura;
		sur += surb;
		sur += surc;
		sur += surd;
		//sur = sura + surb + surc + surd;
		//cout<<vol<<' '<<sur<<' ';
		cout<<vol*3.0/sur<<'\n';
	}	

	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2