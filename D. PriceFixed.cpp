#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(ll i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(ll i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
// ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](ll a, ll b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<ll, ll> ar[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n;
	cin>>n;
	fore(i, 0, n) cin>>ar[i].s>>ar[i].f;
	sort(ar, ar + n);
	ll cosi = 0, lev = 0;
	ll in = n - 1;
	while(in > -1 && lev < ar[0].f)
	{
		if(ar[in].s >= ar[0].f - lev)
		{
			ar[in].s -= ar[0].f - lev;
			cosi += 2 * (ar[0].f - lev);
			lev = ar[0].f;
		}
		else
		{
			lev += ar[in].s;
			cosi += 2 * ar[in].s;
			ar[in].s = 0;
		}
		// cout<<in<<' '<<lev<<' '<<cosi<<'\n';
		in--;
	}
	map<ll, ll> pipi;
	// cout<<cosi<<' '<<lev<<'\n';
	ll a, b, c;
	fore(i, 0, n)
	{
		if(ar[i].s == 0) continue;
		if(lev < ar[i].f)
		{
			a = ar[i].f - lev;
			b = lev + ar[i].s;
			if(b > ar[i].f)
			{
				c = b - ar[i].f + (ar[i].f - lev) * 2;
			}
			else
				c = ar[i].s * 2;
			// cout<<i<<' '<<lev<<' '<<c<<' '<<a<<' '<<ar[i].s<<'\n';
			pipi[a] += c - ar[i].s;
		}
		else
			c = ar[i].s;
		cosi += c;
		lev += ar[i].s;
	}
	ll resi = 0;
	ll ac = 0;
	for(auto cat : pipi)
	{
		resi = min(resi, cat.f - cat.s - ac);
		ac += cat.s;
		// cout<<"$"<<cat.f<<' '<<cat.s<<'\n';
	}
	// cout<<cosi<<' '<<resi<<'\n';
	cout<<cosi + resi<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil