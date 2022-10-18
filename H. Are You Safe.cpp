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
#define MOD1		998244353
#define EPS			1e-9
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}
};
bool eq(double a, double b)
{
	return fabs(a-b) < EPS;
}
double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
point tovec(point a, point b)
{
	return point(b.x - a.x, b.y - a.y);
}
double crossv(point a, point b)
{
	return (a.x*b.y - a.y*b.x);
}
double cross(point a, point b, point c)
{
	return crossv(tovec(a,b), tovec(a, c));
}
bool adentro(vector<point> &p, point a)
{
	for(int i = 0; i < p.size()-1; i++)
	{
		if(cross(p[i], p[i + 1], a) < EPS)
			return true;
	}
	return false;
}
point mini(0,0);
bool comp(point a, point b)
{
	double an1 = atan2(a.y - mini.y, a.x - mini.x);
	double an2 = atan2(b.y - mini.y, b.x - mini.x);
	if(an1 < an2 - EPS)
		return true;
	if(eq(an1, an2))
		return dist(mini, a) < dist(mini, b) - EPS;
	return false;
}
vector<point> hull(vector<point> q)
{
	vector<point> p;
	mini = q[0];
	for(int i = 1; i < q.size(); i++)
	{
		if(q[i].x < q[0].x - EPS)
		{
			swap(q[0], q[i]);
		}
		else
		{
			if(eq(q[i].x, q[0].x))
			{
				if(q[i].y > q[0].y + EPS)
					swap(q[0], q[i]);
			}
		}
	}
	mini = q[0];
	sort(++q.begin(), q.end(), comp);
	q.pb(q[0]);
	p.push_back(q[0]); p.pb( q[1]);

	for(int i = 2; i < q.size(); i++)
	{
		while(cross(p[p.size()-2], p.back(), q[i]) < -EPS)
		{
			p.pop_back();
		}
		p.push_back(q[i]);
	}
	return p;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cases;
	cin>>cases;
		//cout<<fixed<<setprecision(0);
	for(int q = 1; q <= cases; q++)
	{
		if(q > 1) cout<<'\n';
		int n, m;
		cin>>n>>m;
		vector<point> sen(n);
		point pru;
		for(int i = 0; i < n; i++)
			cin>>sen[i].x>>sen[i].y;
		cout<<"Case "<<q<<'\n';
		vector<point> conve = hull(sen);
		for(int i = 0; i < conve.size(); i++)
		{
			cout<<conve[i].x<<' '<<conve[i].y<<'\n';
		}
		bool pri = false;
		while(m--)
		{
			pri = 1;
			cin>>pru.x>>pru.y;
			cout<<pru.x<<' '<<pru.y;
			if(adentro(conve, pru))
				cout<<" is safe!\n";
			else
				cout<<" is unsafe!\n";
		}

	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS