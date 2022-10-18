#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
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
struct point
{
	ll x, y;
	point(ll x = 0, ll y = 0) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	bool operator <(point p) const {return x == p.x ? y < p.y : x < p.x;}
	ll operator *(point p) {return x * p.x + y * p.y;}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	ll norm() {return x * x + y * y;}
};
vector<int> kmp(vector<ll> s)
{
	int n = s.size();
	vector<int> pi(n);
	fore(i, 1, n)
	{
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[j] == s[i])
			j++;
		pi[i] = j;
	}
	return pi;
}
vector<int> kmp1(vector<pair<ll,ll>> s)
{
	int n = s.size();
	vector<int> pi(n);
	fore(i, 1, n)
	{
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[j] == s[i])
			j++;
		pi[i] = j;
	}
	return pi;
}
pair<ll,ll> an(point a, point b, point c)
{
	pair<ll, ll> re = mp((b - a)^(c - a), (b - a)*	(c - a));
	ll g = __gcd(re.f, re.s);
	if(re.s && re.f)
		re.f /= g, re.s /= g;
	else if(re.s && !re.f)
		re.s /= abs(re.s);
	else if(re.f && !re.s)
		re.f /= abs(re.f);
	return re;
}
vector<point> hull(vector<point> p)
{
	vector<point> h;
	//cout<<1;
	sort(p.begin(), p.end());
	int n = p.size();
	fore(i, 0, n)
	{
		while(h.size() >= 2 && ((h.back() - h[h.size()-2]) ^ (p[i] - h[h.size()-2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	//cout<<2;
	h.pop_back();
	int k = h.size();
	for(int i = n-1; i > -1; i--)
	{
		while(h.size() >= k + 2 && ((h.back() - h[h.size()-2]) ^ (p[i] - h[h.size()-2])) >= 0) h.pop_back();
		h.pb(p[i]);
	}
	//cout<<3;
	h.pop_back();
	return h;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	vector<point> pola(n), polb(m);
	fore(i, 0, n) cin>>pola[i].x>>pola[i].y;
	fore(i, 0, m) cin>>polb[i].x>>polb[i].y;
	/*cout<<'\n';
	fore(i, 0, pola.size())
	{
		cout<<pola[i].x<<' '<<pola[i].y<<'\n';
	}
	cout<<'\n';
	fore(i, 0, polb.size())
	{
		cout<<polb[i].x<<' '<<polb[i].y<<'\n';
	}
	cout<<'\n';*/
	pola = hull(pola);
	polb = hull(polb);
	if(polb.size() != pola.size())
	{
		cout<<"NO";
		return 0;
	}
	/*fore(i, 0, pola.size())
	{
		cout<<pola[i].x<<' '<<pola[i].y<<'\n';
	}
	cout<<'\n';
	fore(i, 0, polb.size())
	{
		cout<<polb[i].x<<' '<<polb[i].y<<'\n';
	}*/
	vector<ll> sida, sidb;
	vector<pair<ll,ll>> ana, anb;
	n = pola.size();
	fore(i, 0, n) 
	{
		sida.pb((pola[i] - pola[(i+1) % n]).norm());
		sidb.pb((polb[i] - polb[(i+1) % n]).norm());
		ana.pb(an(pola[i], pola[(i+1)%n], pola[(i+2)%n]));
		anb.pb(an(polb[i], polb[(i+1)%n], polb[(i+2)%n]));
	}
	fore(i, 0, n) sidb.pb(sidb[i]), anb.pb(anb[i]);
	sida.pb(-1);
	ana.pb(mp(1e18, 1e18));
	fore(i, 0, sidb.size()) sida.pb(sidb[i]), ana.pb(anb[i]);
	vector<int> pi1 = kmp(sida), pi2 = kmp1(ana);
	fore(i, n + 1, pi1.size())
	{
		if(pi1[i] == n && pi1[i] == pi2[i])
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2s