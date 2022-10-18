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
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	ll operator *(point p) {return x * p.x + y * p.y;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}
	ostream& operator<<(ostream& os) {
		return os << "(" <<x << "," << y<< ")";
	}
};
bool ins(vector<point> &pol, point p)
{
	fore(i, 0, pol.size() -1)
		if(!p.left(pol[i], pol[i + 1]))
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	vector<point> pol(n);
	fore(i, 0, n)
	{
		cin>>pol[i].x>>pol[i].y;
	}
	reverse(all(pol));
	vector<point> poly = pol;
	poly.pb(pol[0]);
	fore(i, 0, n)
	{
		pol.pb(pol[i]);
	}
	int q;
	cin>>q;
	point p;
	while(q--)
	{
		cin>>p.x>>p.y;
		if(!ins(poly, p))
		{
			cout<<"0\n";
			continue;
		}
		ll tot = 1ll * n * (n - 1) * (n - 2) / 6;
		int lo, hi, mid, res;
		//cout<<tot<<'\n';
		fore(i, 0, n)
		{
			lo = i + 1, hi = i + n - 2, res = i;
			while(lo <= hi)
			{
				mid = (lo + hi) / 2;
				if(p.left(pol[i], pol[mid]))
					res = mid, lo = mid + 1;
				else
					hi = mid - 1;
			}
			//cout<<i<<' '<<res<<'\n';
			tot -= 1ll * (res - i) * (res - i - 1) / 2;
		}
		cout<<tot<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	