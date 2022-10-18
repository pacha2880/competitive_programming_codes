#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007ll
#define EPS			1e-9
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
ll divp1[100000],divp2[100000];
ll pot(ll b, ll e)
{
	if(e == 0) return 1ll;
	return (pot((b*b)%MOD, e/2) * (e&1? b: 1))%MOD;
}
ll inv(ll n)
{
	return pot(n, MOD - 2);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n;
	int k;
	cin>>n>>k;
	vll div;
	map<ll,int> posi;
	for(ll i = 1; i*i <= n; i++)
	{
		if(n % i == 0)
			div.pb(i), div.pb(n/i);
	}
	sort(all(div));
	int m = div.size();
	pair<ll,ll> dp[m][k];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++)
			dp[i][j] = mp(0,1);
	int in;
	int sq;
	for(int i = 0; i < m; i++)
	{
		posi[div[i]] = i;
		dp[i][0] = mp(div[i],m);
	}
	ll divs,acs;
	for(int i = m-1; i > -1;i--)
	{
		in = 0;
		sq = -1;
		acs = 1;	
		for(int j = 0; div[j]*div[j] <= div[i]; j++)
		{
			if(div[j]*div[j] == div[i]) sq = j;
			else
				if(div[i] % div[j] == 0)
				{
					divp1[in] = j;
					divp2[in] = posi[div[i]/div[j]];	
					in++;
				}
		}
		divs = in*2 + (sq!= -1? 1:0);
		for(int j = 0; j < k-1; j++)
		{
			if(sq != -1)
			{

				dp[sq][j+1].f = dp[sq][j+1].f * dp[i][j].s * divs + dp[sq][j+1].s;
				dp[sq][j+1].f %= MOD;
				dp[sq][j+1].s *= dp[i][j].s * divs;
				dp[sq][j+1].s %= MOD;
			}
			if(sq != 0)
			for(int l = 0; l < in; l++)
			{
				dp[divp1[l]][j+1].f = dp[divp1[l]][j+1].f * dp[i][j].s * divs+ dp[divp1[l]][j+1].s;
				dp[divp1[l]][j+1].f %= MOD;
				dp[divp1[l]][j+1].s *= dp[i][j].s* divs;
				dp[divp1[l]][j+1].s %= MOD;

				dp[divp2[l]][j+1].f = dp[divp2[l]][j+1].f * dp[i][j].s* divs + dp[divp2[l]][j+1].s;
				dp[divp2[l]][j+1].f %= MOD;
				dp[divp2[l]][j+1].s *= dp[i][j].s* divs;
				dp[divp2[l]][j+1].s %= MOD;
			}
		}
	}
	ll res = 0;
	for(int i = 0 ; i < m; i++)
	{
		res += (div[i] * ((dp[i][k-1].f * inv(dp[i][k-1].s))%MOD))%MOD;
		res %= MOD;
		//cout<<dp[i][k-1].f <<' '<<dp[i][k-1].s<<endl;
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS