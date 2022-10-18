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
double dp[2][5050];
double pot(double b, int e)
{
	double res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b;
		b = b * b;
		e /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, t, ts, now, last;
	cin>>n>>t;
	dp[1][0] = 1;
	double res = 0, po, p, ac;
	cout<<fixed<<setprecision(6);
	fore(i, 0, n)
	{
		now = i % 2;
		last = abs(now - 1);
		cin>>p>>ts;
		p /= 100;
		po = pot(1 - p, ts - 1);
		ac = 0;
		mem(dp[now], 0);
		fore(i, 0, t + 1)
		{
			if(i >= ts)
			{
				ac -= dp[last][i - ts] * po;
				dp[now][i] +=  dp[last][i - ts] * po;
			}
			dp[now][i] += ac * p;
			ac *= 1 - p;
			ac += dp[last][i];
		}
		//fore(i, 0, t + 1)
		//	cout<<dp[now][i]<<' ';
		//cout<<'\n';
		res += (dp[now][t]) * (i + 1) + (ac - dp[last][t]) * i;
		if(i == n - 1)
		{
			fore(j, 0, t)
				res += dp[now][j] * (i + 1);
		}
		//cout<<"vaca lola  ->  "<<i<<' '<<res<<' '<<ac - dp[last][t]<<'\n';
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	