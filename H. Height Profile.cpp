#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)	  for (int i = (int)b; i < (int)e; i++)
#define forr(i, b, e)	  for (int i = (int)b; i < (int)e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<ll, ll>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
};
struct line
{
	double a, b, c;
	line(){}
	line(point p, point q)
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
	}
};
double det(double a, double b, double c, double d)
{
	return a * d - b * c;
}
double intersect(line a, line b)
{
	return -det(a.c, a.b, b.c, b.b) / det(a.a, a.b, b.a, b.b);
}
point po[100010];
pair<ll, int> oro[100010];
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("asd.txt","r",stdin);
    //freopen("qwe.txt","w",stdout);
    int n, m;
    cin>>n>>m;
    n++;
    int a;
    fore(i, 0, n)
    {
    	cin>>a;
    	po[i] = point(i * 1000, a);
    }
    cout<<fixed<<setprecision(9);
    while(m--)
    {
    	double asd;
    	ll oxi;
    	point re;
    	cin>>asd;
    	oxi = asd * 10 + EPS;
    	re = point(1000, oxi);
    	fore(i, 0, n) oro[i] = mp(-(re ^ po[i]), -i);
    	sort(oro, oro + n);
    	set<int> st;
    	set<int>::iterator it;
    	double res = -1;
    	fore(i, 0, n)
    	{
    		st.insert(-oro[i].s);
    		it = st.end();
    		it--;
    		if((*it) != -oro[i].s)
    		{
    			if((*it) < n-1)
    				res = max(res, intersect(line(po[-oro[i].s], po[-oro[i].s] + re), line(po[(*it)], po[(*it)+1])) / 1000 + oro[i].s);
    			else
    				res = max(res, (double)(*it) + oro[i].s);
    		}
    	}
    	//cout<<res<<'\n';
    	fore(i, 0, n) oro[i] = mp((re ^ po[i]), i);
    	sort(oro, oro + n);
    	st.clear();
    	fore(i, 0, n)
    	{
    		st.insert(oro[i].s);
    		it = st.begin();
    		if((*it) != oro[i].s)
    		{
    			if((*it) > 0)
    				res = max(res, -intersect(line(po[oro[i].s], po[oro[i].s] + re), line(po[(*it)], po[(*it)-1])) / 1000 + oro[i].s);
    			else
    				res = max(res, -(double)(*it) + oro[i].s);
    		}
    	}
    	if(res < 0)
    		cout<<"-1\n";
    	else
    		cout<<res<<'\n';
    }
    return 0;
}
// PLUS ULTRA!