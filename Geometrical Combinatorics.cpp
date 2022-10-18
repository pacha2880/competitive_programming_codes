#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 2000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll fac[tam], facin[tam];
ll bino(int n, int k)
{
	return fac[n] * facin[k] % MOD * facin[n - k] % MOD;
}
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
pair<ll, ll> operator +(pair<ll, ll> a, pair<ll, ll> b)
{
	return {a.f + b.f, a.s + b.s};
}
pair<ll, ll> operator -(pair<ll, ll> a, pair<ll, ll> b)
{
	return {a.f - b.f, a.s - b.s};
}
ll operator ^(pair<ll, ll> a, pair<ll, ll> b)
{
	return a.f * b.s - a.s * b.f;
}
bool vaca, vaco;
ll prig = MOD, ug = MOD, prib = MOD, ub = MOD;
ll f(pair<ll, ll> a, pair<ll, ll> b)
{
	ll mul = 1;
	if(a.f + a.s > b.f + b.s)
	{
		mul = -1;
		swap(a, b);
	}
	ll res = 0, lo, hi, mid, re;
	pair<ll, ll> mi;
	int fro, to;
	fro = max(0ll, a.f + a.s);
	to = b.f + b.s;
	if(vaca && mul == 1)
	{
		if(fro == ug)
			fro++;
		if(to == prig)
			to--;
	}
	if(vaco && mul == -1)
	{
		if(fro == ub)
			fro++;
		if(to == prib)
			to--;	
	}
	// cout<<mul<<'\n';
	// cout<<a.f<<' '<<a.s<<' '<<b.f<<' '<<b.s<<'\n';
	// cout<<fro<<' '<<to<<'\n';
	fore(asdf, fro, to + 1)
	{
		if(asdf % 2 == 0)
		{
			int i = asdf / 2;
			lo = 0, hi = 2000000, mid, re = -1;
			mi = {i, i};
			while(lo <= hi)
			{
				mid = (lo + hi) / 2;
				if(mul == 1)
				{
					if((((mi + mp(-mid, mid)) - a) ^ (b - a)) >= 0)
						re = mid, lo = mid + 1;
					else
						hi = mid - 1;
				}
				else
				{
					if((((mi + mp(-mid, mid)) - a) ^ (b - a)) > 0)
						re = mid, lo = mid + 1;
					else
						hi = mid - 1;	
				}
			}
			// cout<<"papa "<<i<<' '<<re<<'\n';
			// cout<<bino(re + 1 + i, i + 1)<<'\n';
			if(re != -1 )
				res = (res + bino(re + 1 + i, i + 1)) % MOD;
		}
	}
	// cout<<"hola "<<res * mul<<'\n';
	if(mul == 1)
	{
		vaca = 1;
		prig = fro;
		ug = to;
	}
	else
	{
		vaco = 1;
		prib = fro;
		ub = to;
	}
	return (MOD + res * mul % MOD) % MOD;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	fac[0] = facin[0] = 1;
	fore(i, 1, tam)
	{
		fac[i] = fac[i - 1] * i % MOD;
		facin[i] = pot(fac[i], MOD - 2);
	}
	int t;
	cin>>t;
	pair<ll, ll> a, b, c;
	while(t--)
	{
		vaca = vaco = 0;
		cin>>a.f>>a.s>>b.f>>b.s>>c.f>>c.s;
		if((b.f - a.f) * (c.s - a.s) - (b.s - a.s) * (c.f - a.f) > 0)
			swap(b, c);
		cout<<(f(a, b) + f(b, c) + f(c, a)) % MOD<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	