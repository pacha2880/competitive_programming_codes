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
const int tam = 2030;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll r, n, m;

ll dp[tam];
ll bino[tam][tam];
void bin()
{
	fore(i, 0, tam) bino[i][0] = 1 % m;
	fore(i, 1, tam)
	fore(j, 1, tam)
		bino[i][j] = (bino[i - 1][j] + bino[i - 1][j - 1]) % m;
}
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
ll f1(int n)
{
	if(n <= 2) return 1 % m;
	ll &res = dp[n];
	if(res != -1) return res;
	res = 0;
	// cout<<"hola "<<n<<'\n';
	fore(i, 0, (n + 1) / 2)
	{
		res = (res + f1(i) * f1(n - i - 1) % m * (n - 1 == 2 * i ? bino[n - 2][i] : bino[n - 1][i]) % m) % m;
		// cout<<"for "<<i<<' '<<n<<' '<<f1(i)<<' '<<f1(n - i - 1)<<' '<<bino(n - 1, i)<<'\n';
	}
	return res;
}
ll dp2[tam][tam];
ll f2(int n, int r)
{
	if(r == 1) return f1(n);
	ll &res = dp2[n][r];
	if(res != -1) return res;
	res = f1(n);
	fore(i, 1, r)
		res = (res + m - f2(n - i, r - i) * f1(i + 1) % m * bino[r - 1][i] % m) % m;
	return res;
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	mem(dp, -1);
	mem(dp2, -1);
	cin>>r>>n>>m;
	// m = MOD;
	bin();
	// fore(i, 1, 11)
	// cout<<i<<' '<<f1(i)<<'\n';
	cout<<f2(n, r);
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	