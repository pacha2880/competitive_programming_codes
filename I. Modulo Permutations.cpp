#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll dp[3][tam];
ll n;
ll f(int a, int b);
ll mul(int x)
{
	ll res = 0;
	forg(i, x + x, n + 1, x)
	{
		res += f(1, i);
		res %= MOD;
		res += f(1, i + 1);
		res %= MOD;
		res += f(1, i + 2);
		res %= MOD;
	}
	return res;
}
ll f(int sal, int x)
{
	if(x > n) return 0;
	if(x == n) return 1;
	ll &res = dp[sal][x];
	if(res != -1) return res;
	int y = x - sal;
	res = 0;
	if(sal == 0)
	{
		res = (f(0, x + 1) + f(1, x + 1))% MOD;
	}
	else if(sal == 1)
		res = (mul(y) + f(1, x + 1) + 1) % MOD;
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int res[] = {0, 1, 2, 6, 16, 40};
	cin>>n;
	mem(dp, -1);
	if(n < 5) cout<<res[n]<<'\n';
	else
	{
		cout<<f(0, 3) * 2 * n % MOD<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	