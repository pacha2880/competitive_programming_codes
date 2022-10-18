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
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100'010;
const int MOD = 1'000'000'007;
const int MOD1 = 998'244'353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n, g, in, ex;
	cin>>n>>g>>in>>ex;
	const int ta = 3000000;
	vll fac(ta), facin(ta);
	auto bino = [&](int n, int k){
		return fac[n] * facin[k] % MOD * facin[n - k] % MOD;
	};
	fac[0] = facin[0] = 1;
	fore(i, 1, ta)
	{
		fac[i] = fac[i - 1] * i % MOD;
		facin[i] = pot(fac[i], MOD - 2);
	}
	ll res = min(g, 2 * n);
	if(2 * g < n)
	{
		vll poso(n + 1);
		if(g % 2 == 0)
		{
			for(int i = 0; i + g / 2 <= n; i++)
				poso[2 * i] = bino(n, g / 2 + i) * bino(g / 2 + i, g / 2 - i) % MOD
							* bino(2 * n, g) % MOD;
		}
		else
			for(int i = 0; g / 2 + 1 + i <= n; i++)
				poso[2 * i + 1] = bino(n, g / 2 + i + 1) * bino(g / 2 + i + 1, g / 2 - i + 1) % MOD
							* bino(2 * n, g) % MOD;
		ex = min(ex, 2 * n - g);
		in = min(in, 2 * n - g - ex);
		fore(i, 0, n + 1)
		{
			if(ex <= i)
			{
				res = (res + poso[i] * ex) % MOD;
				if(in <= n - i - g / 2)
					res = (res + poso[i] * in) % MOD;
				else if(in <= n - i - g / 2 + i - ex)
					res = (res + poso[i] * (n - i - g / 2)) % MOD;
				else
					res = (res + poso[i] * (n - i - g / 2 - (in - (n - i - g / 2) - (i - ex)))) % MOD;
			}
			else
			{
				res = (res + poso[i] * (ex - (ex & 1))) % MOD;
				ll oc = g / 2 + i + ex / 2
				if(ex & 1)
				{
					
				}
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
