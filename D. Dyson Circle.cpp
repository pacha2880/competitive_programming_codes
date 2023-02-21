#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <bits/stdc++.h>
#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define sz(x) (int)x.size()
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;



struct point{
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    point operator -(point p) {return point(x - p.x, y - p.y);}
    int operator ^(point p) {return x * p.y - y * p.x;}
    bool left(point a, point b) {return ((a - b) ^ (a - *this)) >= 0;}
    bool operator <(const point &p) const {return y == p.y ? x < p.x : y < p.y;}
};
vector<point> hull(vector<point> p)
{
	int n = p.size();
	vector<point> h;
	sort(all(p));
	fore(i, 0, n)
	{
		while(h.size() >= 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.push_back(p[i]);
	}
	h.pop_back();
	int k = h.size();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= k + 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.pb(p[i]);
	}
	h.pop_back();
	return h;
}
int go(point a, point b)
{
    int x = abs(a.x - b.x), y = abs(a.y - b.y);
    return max(x, y);
}
signed main()
{
    fast;
    int n;
    cin>>n;
    vector<point> pol(n);
    fore(i, 0, n) cin>>pol[i].x>>pol[i].y;
    pol = hull(pol);
    pol.pb(pol[0]);
    int si = pol.size();
    int res = 4;
    // cout<<si<<'\n';
    // fore(i, 0, si) cout<<pol[i].x<<' '<<pol[i].y<<'\n';
    int ver = 0;
    fore(i, 0, si - 1)
    {
        res += go(pol[i], pol[i + 1]);
        if(pol[i].y == pol[i + 1].y)
            ver++;
    }
    
    if(sz(pol) == 3 && abs(pol[0].x - pol[1].x) == abs(pol[0].y - pol[1].y))
        res++;
    cout<<res<<'\n';
    return 0;
}  