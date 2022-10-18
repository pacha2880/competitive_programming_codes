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
const int tam = 110;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
string tab1[tam], tab2[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m, h;
	cin>>n>>m>>h;
	fore(i, 0, n)
		cin>>tab1[i];
	fore(i, 0, n)
		cin>>tab2[i];
	string s;
	vector<pair<pair<int, int>, int>> res1, res2;
	fore(i, 0, n)
	{
		vi a, b;
		swap(s, tab1[i]);
		fore(i, 0, m)
			if(s[i] == '1')
				a.pb(i);
		swap(s, tab2[i]);
		fore(i, 0, h)
			if(s[i] == '1')
				b.pb(i);
		if(sz(a) > 0 != sz(b) > 0)
		{
			cout<<"-1\n";
			return 0;
		}
		if(a.size() == 0 && b.size() == 0) continue;
		fore(j, 0, a.size())
			fore(k, 0, b.size())
				res1.pb({{i, a[j]}, b[k]});
		if(a.size() < b.size())
		{
			int in = 0;
			for(; sz(a) <= sz(b) - in; in++)
				res2.pb({{i, a[0]}, b[in]});
			fore(j, in, b.size())
				res2.pb({{i, a[j - in + 1]}, b[j]});
		}
		else
		{
			int in = 0;
			for(; sz(b) <= sz(a) - in; in++)
				res2.pb({{i, a[in]}, b[0]});
			fore(j, in, a.size())
				res2.pb({{i, a[j]}, b[j - in + 1]});
		}
	}
	sort(all(res1));
	sort(all(res2));
	cout<<res1.size()<<'\n';
	fore(i, 0, res1.size())
	{
		cout<<res1[i].f.f<<' '<<res1[i].f.s<<' '<<res1[i].s<<'\n';
	}
	cout<<res2.size()<<'\n';
	fore(i, 0, res2.size())
	{
		cout<<res2[i].f.f<<' '<<res2[i].f.s<<' '<<res2[i].s<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil