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

typedef long long 		rll;
typedef long double ld;	
typedef unsigned long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int tam = 300030;
ll muls[] = {0, 1, 3, 6, 10, 15, 21};
ll dos;
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
ll fuc[100];
ll f(ll x)
{
	if(x <= 7) return 0;
	ll mul = 7;
	int p = 0;
	while(mul <= x)
	{
		p++;
		mul *= 7;
	}
	mul /= 7;
	ll res = 0;
	if(mul == x)
	{
		//cout<<"cho "<<mul<<' ';
		//cout<<res<<'\n';
		return fuc[p];
	}
	//cout<<mul<<'\n';
	ll div = x / mul;
	res = (div + 1) * f(x % mul) % MOD;
	ll y = (mul - 1) % MOD, m = (mul - x % mul - 1) % MOD;
	res += div * ((y * (y + 1) % MOD + (MOD - m * (m + 1) % MOD)) * dos % MOD) % MOD;
	res %= MOD;
	ll pir = y * (y + 1) % MOD * dos % MOD;
	//cout<<div<<' '<<pir<<' '<<muls[div - 1]<<' '<<y<<'\n';;
	res += muls[div - 1] * pir % MOD;
	res %= MOD;
	//cout<<res<<' '<<f(mul)<<'\n';
	res += muls[div] * fuc[p];
	res %= MOD;
	//cout<<res<<'\n';
	//cout<<"ca "<<x<<' '<<div<<' '<<mul<<' '<<pir<<'\n';
	return res;
}

int ar[2][1000000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	ll x;
	cin>>n;
	dos = pot(2, MOD -2);
	ll mul = 49;
	int p = 2;
	fuc[1] = 0;
	while(mul < 1e18)
	{
		ll res = 0;
		ll z = (mul / 7 - 1) % MOD;
		res = 28ll * fuc[p - 1] % MOD;
		res += 21ll * (z * (z + 1) % MOD * dos % MOD) % MOD;
		res %= MOD;
		fuc[p] = res;
		mul *= 7;
		p++;
	}
	fore(i, 1, n + 1)
	{
		cin>>x;
		cout<<"Case "<<i<<": "<<f(x + 1)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	