#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(ll i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(ll i = b, asdz = e, frz; i < asdz; i+=frz)
#define index	ll mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](ll a, ll b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll d, m;
ll dp[2020][2020];
string tupu(string s)
{
	ll fro = s.size();
	bool ac = false;
	for(ll i = s.size() - 1; i > -1; i--)
	{
		if(i & 1)
		{
			if(s[i] - '0' > d)
			{
				fro = min(fro, i + 1);
				ac = false;
			}
			else if(s[i] - '0' < d)
				ac = true;
			s[i] = d + '0';
		}
		else
		{
			if(ac)
			{
				if(s[i] == '0')
				{
					s[i] = '9';
					if(s[i] - '0' == d)
					{
						s[i]--;
					}
				}
				else
				{
					s[i]--;
					if(s[i] - '0' == d)
					{
						if(s[i] == '0')
							s[i] == '9';
						else
						{
							s[i]--;
							fro = min(fro, i + 1);
							ac = false;
						}
					}
					else
					{
						fro = min(fro, i + 1);
						ac = false;
					}
				}
			}
			else
			{
				if(s[i] - '0' == d)
				{
					if(s[i] == '0')
					{
						s[i] = '9';
						ac = true;
						if(i == 0)
							return "$";
					}
					else
					{
						fro = min(fro, i + 1);
						s[i]--;
					}
				}
			}
		}
	}
	if(s[0] == '0')
		return "$";
	fore(i, fro, s.size())
	{
		if(i & 1)
			s[i] = d + '0';
		else
			s[i] = d == 9 ? '8' : '9';
	}
	return s;
}
ll pot(ll b, ll e)
{
	ll res = 0;
	while(e > 0)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
ll molo[2020];
ll chacha(string &s, ll pos, ll mula, bool bolo)
{
	// cout<<pos<<' '<<s.size()<<'\n';
	if(pos == s.size()) return mula == 0;
	if(bolo)
	{
		return chacha(s, pos + 1, (mula + m - molo[pos] * d % m) % m, !bolo);
	}
	else
	{
		ll dig = s[pos] - '0';
		ll res = 0;
		// cout<<"$"<<molo[pos]<<'\n';
		// cout<<dp[pos + 1][0]<<'\n';
		fore(i, 0, dig)
		{
			if(i == d) continue;
			if(pos != 0 || i > 0)
			{
				res = (res + dp[pos + 1][(mula + m - molo[pos] * i % m) % m]) % MOD;
			}
			// cout<<i<<' '<<res<<'\n';
		}
		return (res + chacha(s, pos + 1, (mula + m - molo[pos] * dig % m) % m, !bolo)) % MOD;
	}
}
ll modo(string &a)
{
	ll mods = 0;
	for(char ch : a)
	{
		mods = (mods * 10 + (ch - '0')) % m;
	}
	return mods;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>m>>d;
	string a, b;
	cin>>a>>b;
	if(a.size() == 1)
	{
		ll res = 0;
		fore(i, a[0] - '0', b[0] - '0' + 1)
		{
			if(i == d) continue;
			res += i % m == 0;
		}
		cout<<res<<'\n';
		return 0;
	}
	string sava = a;
	a = tupu(a);
	b = tupu(b);
	// cout<<a<<' '<<b<<'\n';
	if(a == "$" && b == "$")
	{
		cout<<"0\n";
		return 0;
	}
	ll n = b.size();
	ll mola = 10;
	molo[n - 1] = 1;
	if(n & 1)
	{
		fore(i, 0, 10)
		{
			if(i == d) continue;
			dp[n - 1][i % m]++;
		}
	}
	else
		dp[n - 1][d % m] = 1;
	for(ll i = n - 2; i > 0; i--)
	{
		fore(j, 0, m)
		{
			if(i & 1)
			{
				dp[i][(d * mola + j) % m] += dp[i + 1][j];
				dp[i][(d * mola + j) % m] %= MOD;
			}
			else
				fore(k, 0, 10)
				{
					if(k == d) continue;
					dp[i][(k * mola + j) % m] += dp[i + 1][j];	
					dp[i][(k * mola + j) % m] %= MOD;
				}
		}
		molo[i] = mola;
		mola = mola * 10 % m;
	}
	dp[n][0] = 1;
	// cout<<dp[1][0]<<'\n';
	molo[0] = molo[1] * 10 % m;
	// cout<<"-----\n";
	// fore(i, 1, n)
	// 	fore(j, 0, m) cout<<dp[i][j]<<'\n';
	// cout<<"-----\n";
	if(a == "$")
	{
		cout<<chacha(b, 0, 0, false)<<'\n';
	}
	else
	{
		// cout<<chacha(b, 0, 0, false)<<' '<<chacha(a, 0, 0, false)<<'\n';
		cout<<((chacha(b, 0, 0, false) - chacha(a, 0, 0, false) + (a == sava && modo(a) == 0 ? 1 : 0)) % MOD + MOD) % MOD<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	