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
const int tam = 10001;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll dp[500][500];
ll fac[tam], facin[tam];
ll mo;
ll bino(int n, int k)
{
	return fac[n] * facin[n - k] % mo * facin[k] % mo; 
}
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % mo;
		b = b * b % mo;
		e /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;	
	mo = m;
	fac[0] = facin[0] = 1;
	fore(i, 1, tam)
	{
		fac[i] = fac[i - 1] * i % m;
		facin[i] = pot(fac[i], m - 2);
	}
	vll po(500);
	po[0] = 1;
	fore(i, 1, 500)
		po[i] = po[i - 1] * 2 % m;
	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[1][1] = 0;
	fore(i, 2, n + 1)
	{
		dp[i][0] = po[i - 1];
		fore(j, 1, (i - 1) / 2 + 1)
		{
			// cout<<i<<' '<<j<<'\n';
			fore(k, 1, i)
			{
				// cout<<"#"<<i<<' '<<j<<' '<<k<<'\n';
				// cout<<dp[i - k - 1][j - 1]<<' '<<po[k - 1]<<' '<< bino(i - j, k)<<'\n';
				dp[i][j] = (dp[i][j] + dp[i - k - 1][j - 1] * po[k - 1] % m * bino(i - j, k)) % m;
			}
		}
	}
	ll res = 0;
	fore(i, 0, n + 1)
	{
		// cout<<dp[n][i]<<' ';
		res = (res + dp[n][i]) % m;
	}
	// cout<<'\n';
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
