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

typedef unsigned long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct point
{
	double x,y;
	point(double x, double y) : x(x), y(y) {}
	point() {}
};
double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
double cross2(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
point tovec(point a, point b)
{
	return point(b.x - a.x, b.y - a.y);
}
double cross(point a, point b, point c)
{
	return cross2(tovec(a, b), tovec(a, c));
}
point ar[1010];
int n;
double dp[1010];
double f(int pos)
{
	if(pos == n) return 0;
	if(pos == n-1) return 1e11;
	if(dp[pos] > -1e9) return dp[pos];
	vector<point> hull;
	double dis = dist(ar[pos], ar[pos+1]);
	double res = dis + f(pos + 2);
	hull.pb(ar[pos]);
	hull.pb(ar[pos+1]);
	for(int i = pos + 2; i < n; i++)
	{
		while(hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), ar[i]) > EPS)
		{
			dis -= dist(hull[hull.size()-2],hull.back());
			hull.pop_back();
		}
		dis += dist(hull.back(), ar[i]);
		res = min(res, dis + f(i + 1));
		//cout<<dis<<'#';
		hull.push_back(ar[i]);
	}	
	//cout<<pos<<' '<<n<<"$\n";
	//cout<<hull.size()<<'\n';
	//cout<<'@'<<dis<<'#';
	return dp[pos] = res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	cin>>cas;
	cout<<fixed<<setprecision(6);
	while(cas--)
	{
		cin>>n;
		for(int i = 0; i < n; i++)
			dp[i] = -1e10;
		for(int i = 0; i < n; i++)
			cin>>ar[i].x>>ar[i].y;
		cout<<f(0)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS