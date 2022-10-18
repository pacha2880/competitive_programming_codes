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
int n, m, o;
struct point 
{
	double x,y;
	point() {}
	point(double x, double y) : x(x), y(y) {}
};
double dest[1000000];
pair<point,point> seg[1000000];
bool eq(double a, double b)
{
	return fabs(a - b) < EPS;
}
point intr(point a, point b, point c, point d)
{
	double aa = c.y - d.y, bb = d.x - c.x, cc = -aa*c.x - bb*c.y;
	return point(a.x, (-aa*a.x-cc)/bb );
}
double find(point p, int in)
{
	if(in != -1)
	{
		if(!eq(dest[in], -1.0))
			return dest[in];
	}
	point inte;
	double elej = -1;
	int ele = -1;
	for(int i = 0; i < m; i++)
	{
		if(in == i) continue;
		if(seg[i].f.x - EPS < p.x && seg[i].s.x + EPS > p.x)
		{
			inte = intr(p, point(p.x, -1), seg[i].f, seg[i].s);
			if(inte.y -EPS < p.y)
			{
				if(inte.y -EPS > elej)
				{
					elej = inte.y;
					ele = i;
				}
			}
		}
	}
	if(ele != -1)
	{
		return dest[in] = find((seg[ele].f.y < seg[ele].s.y? seg[ele].f : seg[ele].s), ele);
	}
	else
		return p.x;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	double a, b;
	cin>>n;
	bool bo = false;
	while(n--)
	{
		if(bo) cout<<'\n';
		bo = true;
		cin>>m;
		for(int i = 0; i < m; i++)
			dest[i] = -1.0;
		for(int i = 0; i < m; i++)
		{
			cin>>seg[i].f.x>>seg[i].f.y>>seg[i].s.x>>seg[i].s.y;
			if(seg[i].f.x > seg[i].s.x)
				swap(seg[i].f, seg[i].s);
		} 
		cin>>o;
		while(o--)
		{
			cin>>a>>b;
			cout<<((int)(round(find(point(a,b), -1)) + EPS))<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS