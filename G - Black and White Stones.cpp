#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
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
const int tam = 100010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll fac[tam], facin[tam];
ll bino(ll n, ll k)
{
    return n >= 0 && k >= 0 && n >= k ? fac[n] * facin[k] % MOD * facin[n - k] % MOD : 0;
}
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
map<ll, ll> dp[2][2][10010];
int d;
ll f(int j, int k, int i, int n)
{
    if(n == 1)
        return bino(d - 1, i - j - k);
    if(dp[j][k][i].count(n)) return dp[j][k][i][n];
    ll res = 0;
    if(n & 1)
    {
        fore(l, 0, 2)
            res = (res + f(j, l, i, n - 1) * bino(d - 1, i - k - l)) % MOD;
    }
    else
    {
        fore(l, 0, 2)
            res = (res + f(j, l, i, n / 2) * f(k, l, i, n / 2)) % MOD;
    }
    return dp[j][k][i][n] = res;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    fac[0] = facin[0] = 1;
    fore(i, 1, tam)
    {
        fac[i] = fac[i - 1] * i % MOD;
        facin[i] = pot(fac[i], MOD - 2);
    }
	ll n;
    cin>>n>>d;
    ll res = 0;
    fore(i, 0, d + 2)
        fore(j, 0, 2)
            fore(k, 0, 2)
            {
                res = (res + f(j, k, i, n - 1) * bino(d - 1, i - j - k)) % MOD;
                // cout<<i<<' '<<j<<' '<<k<<' '<<f(j, k, i, n - 1)<<' '<<bino(d - 1, i - j - k)<<'\n';
            }
    cout<<res<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
