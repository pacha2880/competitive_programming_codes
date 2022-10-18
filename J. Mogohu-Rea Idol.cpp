#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct point
{
	ll x, y;
	point () {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator +(const point &p) const {return {x + p.x, y + p.y};}
	point operator -(const point &p) const {return {x - p.x, y - p.y};}
	ll operator ^(const point &p) const {return x * p.y - y * p.x;}
	bool operator <(const point &p) const{return y == p.y ? x < p.x : y < p.y;}
};
typedef vector<point> poly;
void norm(poly &pol)
{
	int pos = 0;
	fore(i, 0, pol.size())
	{
		if(pol[i] < pol[pos])
			pos = i;
	}
	rotate(pol.begin(), pol.begin() + pos, pol.end());
}
poly minkos(poly &a, poly &b)
{
	norm(a);
	norm(b);
	int posa = 0, posb = 0, ta = a.size(), tb = b.size();
	poly res;
	ll cro;
	while(posa < ta || posb < tb)
	{
		res.pb(a[(posa) % ta] + b[(posb) % tb]);
		cro = (a[(posa + 1) % ta] - a[posa % ta]) ^ (b[(posb + 1) % tb] - b[posb % tb]);
		if(cro == 0)
			posa++, posb++;
		else if(cro < 0)
			posb++;
		else posa++;
	}
	return res;
}
bool inpol(poly &pol, point p)
{
	int n = pol.size();
	if(((pol[1] - pol[0]) ^ (p - pol[0])) < 0 || ((pol[n - 1] - pol[0]) ^ (p - pol[0])) > 0)
		return 0;
	int lo = 1, hi = n - 2, mid, res;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(((pol[mid] - pol[0]) ^ (p - pol[0])) >= 0)
			res = mid, lo = mid + 1;
		else
			hi = mid - 1;
	}
	return ((pol[res + 1] - pol[res]) ^ (p - pol[res])) >= 0;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	poly a, b;
	int n;
	int x, y;
	cin>>n;
	fore(i, 0, n)
	{
		cin>>x>>y;
		a.pb({x, y});
	}
	fore(i, 0, 2)
	{
		cin>>n;
		b.clear();
		fore(i, 0, n)
		{
			cin>>x>>y;
			b.pb({x, y});
		}
		a = minkos(a, b);
	}
	int q;
	cin>>q;
	// cout<<"hola "<<a.size()<<'\n';
	// for(point p : a)
	// 	cout<<p.x<<' '<<p.y<<'\n';
	// RAYA;
	while(q--)
	{
		cin>>x>>y;
		x *= 3;
		y *= 3;
		// cout<<x<<' '<<y<<'\n';
		if(inpol(a, {x, y}))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil