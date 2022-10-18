#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef long double ld;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 988244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	bool operator <(point p) const {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}
	bool lefto(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}
	bool right(point a, point b) {return ((b - a) ^ (*this - a)) <= 0;}
	bool operator !=(point p) {return x != p.x || y != p.y;}
};
struct line
{
	ld a, b, c;
	line() {}
	line(point p, point q) 
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
	}
};
ld det(ld a, ld b, ld c, ld d)
{
	return a * d - b * c;
}
ld inter(line a, line b)
{
	ld d = -det(a.a, a.b, b.a, b.b);
	return det(a.c, a.b, b.c, b.b) / d;
}
vector<pair<point, int>> upp(vector<pair<point, int>> p)
{
	int n = p.size();
	sort(all(p));
	vector<pair<point, int>> h;
	fore(i, 0, n)
	{
		while(sz(h) >= 2 && p[i].f.left(h[sz(h) - 2].f, h.back().f)) h.pop_back();
		h.pb(p[i]);
	}
	return h;
}
vector<pair<point, int>> lowe(vector<pair<point, int>> p)
{
	int n = p.size();
	sort(all(p));
	vector<pair<point, int>> h;
	fore(i, 0, n)
	{
		while(sz(h) >= 2 && p[i].f.right(h[sz(h) - 2].f, h.back().f)) h.pop_back();
		h.pb(p[i]);
	}
	return h;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	vector<pair<point, int>> up(n), low(n);
	fore(i, 0, n)
	{
		cin>>up[i].f.x>>up[i].f.y>>low[i].f.x>>low[i].f.y;
		low[i].s = i;
		up[i].s = i;
	}
	//cout<<'\n';
	//vector<line> lilo(sz(low)), liup(sz(up));
	fore(i, 0, sz(low))
	{
		//cout<<low[i].f.x<<' '<<low[i].f.y<<' '<<low[i].s<<'\n';
		//lilo[i] = line(point(0, low[i].f.x), point(1, low[i].f.y + low[i].f.x));
	}
	//cout<<'\n';
	fore(i, 0, sz(up))
	{
		//cout<<up[i].f.x<<' '<<up[i].f.y<<' '<<up[i].s<<'\n';
		//liup[i] = line(point(0, up[i].f.x), point(1, up[i].f.y + up[i].f.x));
	}
	up = upp(up);
	low = lowe(low);
	if(sz(up) >= 2)
	{
		reverse(all(up));
		while(sz(up) >= 2)
		{
			if(up.back().f.left(up[sz(up) - 2].f, point(up[sz(up) - 2].f.x - 1, up[sz(up) - 2].f.y)))
				up.pop_back();
			else
				break;
		}
	}
	while(sz(low) >= 2)
	{
		if(low.back().f.left(low[sz(low) - 2].f, point(low[sz(low) - 2].f.x + 1, low[sz(low) - 2].f.y)))
			low.pop_back();
		else
			break;
	}
	//cout<<'\n';
	vector<line> lilo(sz(low)), liup(sz(up));
	fore(i, 0, sz(low))
	{
		//cout<<low[i].f.x<<' '<<low[i].f.y<<' '<<low[i].s<<'\n';
		lilo[i] = line(point(0, low[i].f.x), point(1, low[i].f.y + low[i].f.x));
	}
	//cout<<'\n';
	fore(i, 0, sz(up))
	{
		//cout<<up[i].f.x<<' '<<up[i].f.y<<' '<<up[i].s<<'\n';
		liup[i] = line(point(0, up[i].f.x), point(1, up[i].f.y + up[i].f.x));
	}
	int a = 0, b = 0;
	int res = 0;
	ld ax, bx;
	while(a < up.size()&& b < low.size())
	{
		//////cout<<a<<' '<<b<<' '<<up[a].s+1<<' '<<low[b].s+1<<'\n';
		if(a == up.size() - 1)
		{
			while(b < low.size())
			{
				if(up[a].s == low[b].s)
				{
					res++;
				}
				b++;
			}
		}
		else
		{
			if(b == low.size() - 1)
			{
				if(low[b].s == up[a].s)
				{
					res++;
					b++;
				}
			}
			else
			{
				ax = inter(liup[a], liup[a + 1]);
				while(b < low.size() - 1 && ax > inter(lilo[b], lilo[b+1]) + EPS)
				{
					if(low[b].s == up[a].s)
						res++;
					b++;
				}
				if(low[b].s == up[a].s)
					res++;
			}
		}
		a++;
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2