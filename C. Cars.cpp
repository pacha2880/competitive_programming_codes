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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
	point  operator -(point p) {return point(x - p.x, y - p.y);}
	point  operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	point operator /(ll a) {return point(x / a, y / a);}
	bool operator <(point p) {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a , point b) {return ((b - a) ^ (*this - a)) >= 0;}
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
	for(int i = n - 1; i > -1; i--)
	{
		while(h.size() >= k + 2 && p[i].left(h[sz(h) - 2], h.back())) h.pop_back();
		h.pb(p[i]);
	}
	reverse(all(h));
	return h;
}
bool ins(vector<point> &pol, point p)
{
	fore(i, 0, pol.size() - 1)
	{
		if(((pol[i+1] - pol[i]) ^ (p - pol[i])) < 0)
			return false;
	}
	return true;
}
bool ins1(vector<point> &pol, point p)
{
	fore(i, 0, pol.size() - 1)
	{
		if(((pol[i+1] - pol[i]) ^ (p - pol[i])) <= 0)
			return false;
	}
	return true;
}
ll sig(ll a)
{
	return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
bool intersec(point a, point b, point c, point d)
{
	return sig((b - a) ^ (c - a)) * sig((b - a) ^ (d - a)) == -1 
			&& sig((d - c) ^ (a - c)) * sig((d - c) ^ (b - c)) == -1;
}
bool polinter(vector<point> pola, vector<point> polb)
{
	bool res = false;
	fore(i, 0, pola.size() - 1)
	{
		res |= ins1(polb, pola[i]);
		res |= ins1(polb, (pola[i] + pola[i+1]) / 2);
	}
	fore(i, 0, polb.size() - 1)
	{
		res |= ins1(pola, polb[i]);
		res |= ins1(pola, (polb[i] + polb[i+1]) / 2);
	}
	fore(i, 0, polb.size() - 1)
		fore(j, 0, pola.size() - 1)
		{
			res |= intersec(polb[i], polb[i + 1], pola[j], pola[j + 1]);	
		}
	return res;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll t;
	cin>>t;
	ll dirx = 0, diry = 0;
	char ch;
	cin>>ch;
	if(ch == 'N')
		diry = 1;
	if(ch == 'S')
		diry = -1;
	if(ch == 'E')
		dirx = 1;
	if(ch == 'W')
		dirx = -1;
	ll x, y, v, wid, lon;
	cin>>x>>y>>v>>wid>>lon;
	x *= 2;
	y *= 2;
	v *= 2;
	wid *= 2;
	lon *= 2;
	if(ch == 'E' || ch == 'W')
		swap(wid, lon);
	dirx *= v;
	diry *= v;

	ll dirx1 = 0, diry1 = 0;
	char ch1;
	cin>>ch1;
	if(ch1 == 'N')
		diry1 = 1;
	if(ch1 == 'S')
		diry1 = -1;
	if(ch1 == 'E')
		dirx1 = 1;
	if(ch1 == 'W')
		dirx1 = -1;
	ll x1, y1, v1, wid1, lon1;
	cin>>x1>>y1>>v1>>wid1>>lon1;
	x1 *= 2;
	y1 *= 2;
	v1 *= 2;
	wid1 *= 2;
	lon1 *= 2;
	if(ch1 == 'E' || ch1 == 'W')
		swap(wid1, lon1);
	dirx1 *= v1;
	diry1 *= v1;

	dirx -= dirx1;
	diry -= diry1;

	dirx *= t;
	diry *= t;
	//cout<<wid1<<' '<<lon1<<'\n';
	vector<point> pola, polb;
	pola.pb(point(x1 - wid1 / 2, y1 - lon1 / 2));
	pola.pb(point(x1 + wid1 / 2, y1 - lon1 / 2));
	pola.pb(point(x1 + wid1 / 2, y1 + lon1 / 2));
	pola.pb(point(x1 - wid1 / 2, y1 + lon1 / 2));
	pola.pb(pola[0]);

	polb.pb(point(x - wid / 2, y - lon / 2));
	polb.pb(point(x + wid / 2, y - lon / 2));
	polb.pb(point(x + wid / 2, y + lon / 2));
	polb.pb(point(x - wid / 2, y + lon / 2));
	polb.pb(point(x - wid / 2 + dirx, y - lon / 2 + diry));
	polb.pb(point(x + wid / 2 + dirx, y - lon / 2 + diry));
	polb.pb(point(x + wid / 2 + dirx, y + lon / 2 + diry));
	polb.pb(point(x - wid / 2 + dirx, y + lon / 2 + diry));
	
	polb = hull(polb);
	/*fore(i, 0, pola.size())
	{
		cout<<pola[i].x / 2<<' '<<pola[i].y / 2<<'\n';
	}
	cout<<'\n';
	fore(i, 0, polb.size())
	{
		cout<<polb[i].x / 2<<' '<<polb[i].y / 2<<'\n';
	}*/
	if(polinter(pola, polb))
		cout<<"crash\n";
	else
		cout<<"safe\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	