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
const int tam = 1000010;
struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y){}
};
double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
double cross2(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
point tovec(point a, point b)
{
	return point(b.x - a.x, b.y - a.y);
}
double cross(point a, point b, point c)
{
	return cross2(tovec(a, b), tovec(a, c));
}
bool eq(double a, double b)
{
	return fabs(a-b) < EPS;
}
point mini;
bool comp(point a, point b)
{
	point ta = tovec(mini, a);
	point tb = tovec(mini, b);
	double ana = atan2(ta.y, ta.x), anb = atan2(tb.y, tb.x);
	if(eq(ana, anb))
		return dist(a, mini) < dist(b, mini);
	return ana < anb - EPS;
}
vector<point> hull(vector<point> p)
{
	for(int i = 1; i < p.size(); i++)
	{
		if(eq(p[i].y, p[0].y) )
		{
			if(p[i].x < p[0].x - EPS)
				swap(p[i], p[0]);
		}
		else
		{
			if(p[i].y < p[0].y - EPS)
				swap(p[i], p[0]);
		}
	}
	mini = p[0];
	sort(++p.begin(), p.end(), comp);
	p.pb(p[0]);
	vector<point> res;
	res.pb(p[0]);
	res.pb(p[1]);
	for(int i = 2; i < p.size(); i++)
	{
		while(cross(res[res.size()-2], res.back(), p[i]) < EPS)
		{	
			res.pop_back();
		}
		res.pb(p[i]);
	}
	return res;
}
double ang(point a, point b)
{
	a = tovec(mini, a);
	b = tovec(mini, b);
	return fabs(asin(cross2(a, b) / hypot(a.x, a.y) / hypot(b.x, b.y)));
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd1.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cout<<fixed<<setprecision(6);
	int cas, n;
	cin>>cas;
	while(cas--)
	{
		double res = 1e15;
		cin>>n;
		int nn = n*4 + 5;
		vector<point> ar(nn);
		for(int i = 0; i < nn; i++)
		{
			cin>>ar[i].x>>ar[i].y;
		}
		vector<point> hu = hull(ar);
		if(hu.size() == nn + 1)
		{
			cout<<"Impossible\n";
			continue;
		}
		bool bo;
		for(int i = 0; i < nn; i++)
		{
			bo = true;
			for(int j = 0; j < hu.size()-1; j++)
			{
				if(eq(ar[i].x, hu[j].x) && eq(ar[i].y, hu[j].y))
				{
					bo = false;
					break;
				}
			}
			if(bo)
			{
				vector<point> pol;
				for(int j = 0; j < i; j++)
				{
					pol.pb(ar[j]);
				}
				for(int j = i+1; j < nn; j++)
				{
					pol.pb(ar[j]);
				}
				mini = ar[i];
				sort(pol.begin(), pol.end(), comp);
				//cout<<0;
				int si = pol.size();
				for(int j = 0; j < si; j++)
					pol.pb(pol[j]);
				//cout<<1;
				for(int j = 0; j < nn/4; j++)
				{
					//cout<<j;
					double par = 0;
					point pre = pol[j];
					for(int k = j + nn/4; k < nn; k += nn/4)
					{
						par += 1.0/tan(ang(pre, pol[k]));
						pre = pol[k];
					}
					res = min(res, par);
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2