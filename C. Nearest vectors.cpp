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
	ll sq() {return x * x + y * y;}
	long double abs() {return sqrt((long double)sq());}
	ll operator ^(point p) {return x * p.y - y * p.x;}
  	ll operator *(point p) {return x * p.x + y * p.y;}
  	point operator *(ll a) {return point(x * a, y * a);}
	bool operator <(point p) {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}
	ostream& operator<<(ostream& os) {
		return os << "("<< x << "," << y << ")";
	}

};
point ar[tam];
int ind[tam];
int lev[tam];
int la, lb;
bool cmp(int a, int b)
{
	if(lev[a] == lev[b])
		return (ar[a] ^ ar[b]) > 0;
	else
		return lev[a] < lev[b];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n) 
	{
		ind[i] = i;
		cin>>ar[i].x>>ar[i].y;
		lev[i] = ar[i].y > 0 || ar[i].y == 0 && ar[i].x > 0;
	}
	sort(ind, ind + n, cmp);
	pair<long double, int> memo(1e10, -1);
	point a, b;
	long double x, y, an;
	fore(i, 0, n)
	{
		a = ar[ind[i]], b = ar[ind[(i + 1) % n] % n];
		x = atan2(a.y, a.x), y = atan2(b.y, b.x);
		if(x * y >= -EPS)
		{
			an = fabs(x - y);
		}
		else
		{
			if(x < 0) swap(x, y);
			an = min(x - y, PI - x + PI + y);
		}
		memo = min(memo, {an, i});
	}
	cout<<ind[memo.s] + 1<<' '<<ind[(memo.s + 1) % n] + 1<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	