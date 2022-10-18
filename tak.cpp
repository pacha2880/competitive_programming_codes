#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
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
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
struct 
point
{
	ll x, y;
	point(ll x = 0, ll y = 0) : x(x), y(y) {}
	bool operator <(point p) const {return x == p.x ? y < p.y : x < p.x;}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	ll man(point p) {return abs(x - p.x) + abs(y - p.y);}
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
		while(h.size() >= 2 && ((h.back() - h[h.size() - 2]) ^ (p[i] - h[h.size() -2])) >= 0) h.pop_back();
			h.pb(p[i]);
	}
	h.pop_back();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= 2 && ((h.back() - h[h.size() - 2]) ^ (p[i] - h[h.size() -2])) >= 0) h.pop_back();
			h.pb(p[i]);
	}
	h.pop_back();
	return h;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
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
			cout<<0;'\n';
			return 0;
		}
		if(p.size() == 2)
		{
			cout<<p[0].man(p[1]);
		}
		n = p.size();
		deque<int> que[4];
		fore(i, 1, n)
		{
			que[p[0].ori(p[i])].push_back(i);
		}
		int resul = 0;
		int lo, hi, mid, res;
		fore(i, 0, n)
		{
			fore(j, 0, 4)
			{
				while(!que[j].empty() && p[i].ori(que[j].back()) != j)
				{
					que[(j+1) % 4].push_front(que[j].back());
					que[j].pop_back();
				}
			}
			fore(j, 0, 4)
			{
				if(!que[j].empty())
				{
					res = que[j].front(), lo = que[j].front(), hi = que[j].front();
					while(lo < hi)
					{
						mid = (lo + hi) / 2;
						if(p[i].man(p[mid]) >= p[i].man(p[mid+1]))
							res = mid, hi = mid -1;
						else
							res = mid + 1, lo = mid + 1;
					}
					resul = max((ll)resul, p[i].man(p[res]));
				}
			}
			if(i < n-1)
				que[p[i].ori(p[i+1])].pop_front();
		}
		cout<<resul<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2