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
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y -y * p.x;}
	bool  left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0ll;}
	bool  right(point a, point b) {return ((b - a) ^ (*this - a)) <= 0ll;}
};
bool cross(point a, point b, point c, point d)
{
	if(!((c.left(a, b) && d.right(a, b) || c.right(a,b) && d.left(a, b)) && (a.left(c, d) && b.right(c, d) || a.right(c,d) && b.left(c, d))))
		return false;
	//cout<<"asdasd\n";
	return max(min(a.x, b.x), min(c.x, d.x)) <= min(max(a.x, b.x), max(c.x, d.x)) && max(min(a.y, b.y), min(c.y, d.y)) <= min(max(a.y, b.y), max(c.y, d.y));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	point p1, p2, q1, q2, v;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>p1.x>>p1.y>>p2.x>>p2.y>>q1.x>>q1.y>>q2.x>>q2.y>>v.x>>v.y;
		while(abs(v.x) < 1000000000ll && abs(v.y) < 1000000000ll)
			v.x *= 2,v.y*=2;
		point antiv = point(-v.x, -v.y);
		point a, b;
		a = q1 - p1;
		b = q2 - p1;
		//cout<<v.x<<' '<<v.y<<' '<<antiv.x<<' '<<antiv.y<<'\n';
		//cout<<'-';
		//cout<<v.x<<','<<v.y<<' '<<a.x<<','<<a.y<<' '<<b.x<<','<<b.y<<'\n';
		if(cross(point(0,0), v, a, b))
		{
			cout<<"Yes\n";
			continue;
		}
		a = q1 - p2;
		b = q2 - p2;
		//cout<<'#';
		if(cross(point(0,0), v, a, b))
		{
			cout<<"Yes\n";
			continue;
		}
		a = p1 - q1;
		b = p2 - q1;
		//cout<<'@';
		//cout<<antiv.x<<','<<antiv.y<<' '<<a.x<<','<<a.y<<' '<<b.x<<','<<b.y<<'\n';
		if(cross(point(0,0), antiv, a, b))
		{
			cout<<"Yes\n";
			continue;
		}
		a = p1 - q2;
		b = p2 - q2;
		//cout<<'!';
		if(cross(point(0,0), antiv, a, b))
		{
			cout<<"Yes\n";
			continue;
		}
		cout<<"No\n";
	}
	return 0;
}
 
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2