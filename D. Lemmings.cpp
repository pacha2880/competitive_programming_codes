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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<pair<int, int>, int> ar[tam];
int res[tam];
int n, k, h;
bool f(double t)
{
	int mul = 1;
	fore(i, 0, n)
	{
		if(mul <= k && mul * h <= ar[i].f.s * t)
		{
			res[mul - 1] = ar[i].s + 1;
			mul++;
		}
	}
	return mul > k;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	cin>>n>>k>>h;
	fore(i, 0, n)
	{
		cin>>ar[i].f.f;
		ar[i].s = i;
	}
	fore(i, 0, n)
		cin>>ar[i].f.s;
	sort(ar, ar + n);
	double lo = 0, hi = 1000000000, mid, resp;
	fore(i, 0, 100)
	{
		mid = (lo + hi) / 2;
		if(f(mid))
			resp = mid, hi = mid;
		else
			lo = mid;
	}
	assert(f(resp));
	fore(i, 0, k)
	{
		if(i > 0) cout<<' ';
		cout<<res[i];
	}
	cout<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil