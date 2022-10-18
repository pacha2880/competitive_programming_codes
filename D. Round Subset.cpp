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
int dp[2][210][4000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	ll x, y;int now, last, two, fiv, twop, fivp;
	mem(dp, -1);
	dp[0][0][0] = 0;
	fore(i, 1, n + 1)
	{
		cin>>x;
		y = x;
		two = fiv = 0;
		while(x % 2 == 0)
		{
			two++;
			x /= 2;
		}
		while(y % 5 == 0)
		{
			fiv++;
			y /= 5;
		}
		//cout<<fiv<<' '<<two<<'\n';
		now = i % 2;
		last = abs(now - 1);
		for(int j = i - 1; j > -1; j--)
		{
			for(int k = 3600; k > -1; k--)
			{
				dp[now][j][k] = dp[last][j][k];
				if(dp[now][j][k] != -1)
				{
					twop = min(3600, k + two);
					fivp = min(3600, dp[now][j][k] + fiv);
					dp[now][j + 1][twop] = max(dp[now][j + 1][twop], fivp);
				}
			}
		}
	}
	int res = 0;
		fore(j, 1, 4000)
			if(dp[n % 2][k][j] >= 0)
			{
				//cout<<i<<' '<<j<<' '<<dp[n%2][i][k][j]<<'\n';
				res = max(res, min(j, dp[n % 2][k][j]));
			}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2