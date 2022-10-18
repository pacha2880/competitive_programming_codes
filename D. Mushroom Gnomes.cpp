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
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<'\n'
#define RAYA cerr<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 100010;
ll MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
typedef vector<vector<ll>> mat;
mat ans;
void mult(mat m1, mat m2)
{
	assert(m1[0].size() == m2.size());
	ans.clear();
	ll answer = 0;
	fore(i, 0, m1.size())
	{
		vector<ll> fila;
		fore(j, 0, m2[0].size())
		{
			answer = 0;
			fore(k, 0, m2.size())
				answer = (answer + (__int128)m1[i][k] * m2[k][j]) % MOD;
			fila.pb(answer);
		}
		ans.pb(fila);
	}
}
void pot(mat base, ll exp)
{
	mat res(base.size(), vector<ll>(base.size(), 0));
	fore(i, 0, base.size())
	res[i][i] = 1;
	while(exp)
	{
		if(exp & 1)
		{
			mult(res, base);
			res = ans;
		}
		mult(base, base);
		base = ans;
		exp /= 2;
	}
	ans = res;
}
ll ar[1000010];
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = (__int128)res * b % MOD;
		b = (__int128)b * b % MOD;
		e /= 2;
	}
	return res;
}
ll div(ll a)
{
	if(a == 0)
		return MOD / 2;
	return a /2;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
	ll x, y;
	ll a, b, c, su = 0;
	cin>>n>>x>>y>>MOD;
	fore(i, 0, n){ cin>>ar[i]; su += ar[i];}
	if(n == 1)
	{
		cout<<ar[0] % MOD<<'\n';
	}
	else
	{
		MOD *= 4;
		a = ar[0] % MOD, b = ar[n - 2] % MOD, c = ar[n - 1] % MOD;
		if(x == 0)
			swap(x, y);
		su = ((__int128)pot(3, x) * su % (MOD / 2) - (__int128)(a + c) * div(pot(3, x) - 1) % (MOD / 2) + MOD / 2) % (MOD / 2);
		MOD /= 2;
		if(y == 0)
			cout<<su<<'\n';
		else
		{
			swap(x, y);
			mat ma(2, vll(2));
			ma[0][0] = 1;
			ma[0][1] = 1;
			ma[1][0] = 1;
			// cout<<y<<'\n';
			pot(ma, y);
			ma = ans;
			c = (__int128)ma[0][0] * c % (MOD / 2) + (__int128)ma[1][0] * b % (MOD / 2);
			c %= MOD / 2;
			// cout<<ma[0][0]<<' '<<ma[1][0]<<'\n';
			// cout<<su<<' '<<a<<' '<<c<<'\n';
			su = ((__int128)pot(3, x) * su % (MOD / 2) - (__int128)(a + c) * div(pot(3, x) - 1) % (MOD / 2) + MOD / 2) % (MOD / 2);
			MOD /= 2;
			cout<<su<<'\n';
		}
	}

	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
