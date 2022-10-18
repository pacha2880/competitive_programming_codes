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
pair<ll, ll> dp[2][tam];
vector<pair<ll, ll>> ar[tam];
	__float128 x = 1;
bool cmp(vector<pair<ll, ll>> &a, vector<pair<ll, ll>> &b)
{
	return min(a[0].s - a[0].f, a[1].s - a[1].f) > min(b[0].s - b[0].f, b[1].s - b[1].f);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n, a, b, c, d;
	cin>>n;
	dp[0][0] = {0, 0};
	dp[1][0] = {0, 0};
	fore(i, 0, n)
	{
		ar[i].resize(2);
		fore(j, 0, 2)
			cin>>ar[i][j].f>>ar[i][j].s;
	}
	sort(ar, ar + n, cmp);
	fore(i, 1, n + 1)
	{
		fore(j, 0, 2) 
		{
			a = ar[i - 1][j].f, b = ar[i - 1][j].s;
			if(x * (dp[0][i - 1].s + b) * (dp[1][i - 1].f + a) > x * (dp[1][i - 1].s + b) * (dp[0][i - 1].f + a))
				dp[j][i] = {dp[0][i - 1].f + a, dp[0][i - 1].s + b};
			else
				dp[j][i] = {dp[1][i - 1].f + a, dp[1][i - 1].s + b};
		}
	}
	cout<<fixed<<setprecision(9)<<(double)max(x * dp[0][n].s / dp[0][n].f, x * dp[1][n].s / dp[1][n].f)<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil