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
typedef long int	li;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 998244353;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int fac[100010];
ll ax[100010];
int facs[100010];
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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, k;
	ll x, mula;
	int res;
	scanf("%d %d", &n, &k);
	fac[0] = 1;
	fore(i, 1, k + 1)
		fac[i] = pot(i + 1, k) % MOD;
	facs[0] = fac[0];
	fore(i, 1, k + 1)
		facs[i] = (facs[i - 1] + fac[i]) % MOD;
	fore(i, 0, k + 1)
		ax[i] = fac[i];
	fore(i, 0, k)
	{
		for(int j = k; j > i; j--)
				ax[j] -= ax[j - 1];
	}

	fore(j, 0, k + 1)
		ax[j] = (ax[j] % MOD + MOD) % MOD;
	//cout<<"choyo\n";
	ll fic = 1;
	fore(i, 1, k + 1)
	{
		fic = fic * pot(i + 1, MOD - 2) % MOD;
		ax[i] = ax[i] * fic % MOD;
	}
	fore(i, 0, k + 1)
		fac[i] = ax[i];
	bool bo = false;
	//cout<<"choyo\n";
	ll nu;
	int i;
	while(n--)
	{
		scanf("%lld",&x);
		x %= MOD;
		nu = x - k;
		res = 0, mula = x;
		if(x > k + 1)
		{
			for(i = k; i > - 1; i--)
			{
				res = (res + fac[i]) * (nu++) % MOD;
			}
		}
		else
		{
			res = facs[x - 1];
		}	
		if(bo) printf(" ");
		printf("%ld", res);
		bo = true;
	}
	printf("\n");
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	