#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI                acos(-1)
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define fore(i, b, e)  	  for(int i = b; i < e; i++)
#define forg(i, b, e, m)  for(int i = b; i < e; i+=m)
#define F first
#define S second
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
struct point
{
	ll x, y;
	point(ll x = 0, ll y = 0) : x(x), y(y) {}
	ll man(point p) {return abs(p.x - x) + abs(p.y - y);}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	bool operator <(point p) const{ return x == p.x ? y < p.y : x < p.x;}
	int ori(point p) 
	{
		if(p.x >= x && p.y >= y)
			return 0;
		if(p.x >= x && p.y < y)
			return 1;
		if(p.x < x && p.y < y)
			return 2;
		if(p.x < x && p.y >= y)
			return 3;
	}
};
vector<point> hull(vector<point> p)
{
	vector<point> h;
	sort(p.begin(), p.end());
	int n = p.size();
	fore(i, 0, n)
	{
		while(h.size() >= 2 && ((h.back() - h[h.size() - 2]) ^(p[i] - h[h.size() - 2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= k + 2 && ((h.back() - h[h.size() - 2]) ^(p[i] - h[h.size() - 2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	return h;
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int cas;
    cin>>cas;
    while(cas--)
    {
    	int n;
    	cin>>n;
    	vector<point> p(n);
    	fore(i, 0, n) cin>>p[i].x>>p[i].y;
    	p = hull(p);
    	if(p.size() == 1)
    	{
    		cout<<0<<'\n';
    		return 0;
    	}
    	if(p.size() == 2)
    	{
    		cout<<p[0].man(p[1])<<'\n';
    		continue;
    	}
    	n = p.size();
    	deque<int> que[4];
    	//cout<<"asda\n";
    	fore(i, 1, n)
    	{
    		que[p[0].ori(p[i])].push_back(i);
    		//cout<<p[0].ori(p[i])<<' '<<i<<'\n';
    	}
    	//cout<<"asda\n";
    	ll resul = 0;
    	int lo, hi, mid, res;
    	fore(i, 0, n)
    	{
    		fore(j, 0, 4)
    		{
    			while(!que[j].empty() && p[i].ori(que[j].back()) != j)
    			{
    				que[p[i].ori(que[j].back())].push_front(que[j].back());
    				que[j].pop_back();
    			}
    		}
    		fore(j, 0, 4)
    		{
    			if(!que[j].empty())
    			{
	    			res = que[j].front(), lo = que[j].front(), hi = que[j].back();
	    			int cnt = 0;
	    			while(lo < hi)
	    			{
	    				assert(cnt < 1000);
	    				cnt++;
	    				mid = (lo + hi) / 2;
	    				if(p[i].man(p[mid]) >= p[i].man(p[(mid + 1) % n]))
	    				{
	    					if(p[i].man(p[mid]) > p[i].man(p[res]))
	    						res = mid;
	    					hi = mid -1;
	    				}
	    				else
	    				{
	    					if(p[i].man(p[mid+1]) > p[i].man(p[res]))
	    						res = mid + 1;
	    					lo = mid + 1;
	    				}
	    			}
	    			resul = max(resul, p[i].man(p[res]));
	    		}
    		}
    		if(!que[p[i].ori(p[(i+1) % n])].empty())
    			que[p[i].ori(p[(i+1) % n])].pop_front();
    	}
    	cout<<resul<<'\n';
    }
    return 0;
}
// PLUS ULTRA!