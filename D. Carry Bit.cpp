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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, k;
    cin>>n>>k;
    vi fac(n + 1), facin(n + 1);
    fac[0] = facin[0] = 1;
    auto pot = [&](int a, int b) {
        int r = 1;
        while (b) {
            if (b & 1) r = (r * 1ll * a) % MOD;
            a = (a * 1ll * a) % MOD;
            b >>= 1;
        }
        return r;
    };
    fore(i, 1, n + 1)
        fac[i] = (fac[i - 1] * 1ll * i) % MOD, facin[i] = pot(fac[i], MOD - 2);
    auto bino = [&](int n, int k) {
        if (k < 0 || k > n) return 0ll;
        return (fac[n] * 1ll * facin[k] % MOD * facin[n - k]) % MOD;
    };
    if(k == 0)
        cout<<pot(3, n)<<'\n';
    else
    {
        // ll res = pot(3, k - 1) * pot(3, n - k) % MOD;
        ll res = 0;
        fore(i, 0, k)
        {
            // cout<<n - k<<' '<<i + 1<<' '<<k - 1<<' '<<i<<'\n';
            // cout<<pot(3, n - k - i - 1)<<' '<<bino(n - k - 1, n - k - i - 1)<<' '<<bino(k - 1, i)<<' '<<pot(3, k - i - 1)<<'\n';
            if(i <= n - k)
                res = (res + pot(3, n - k - i) * bino(n - k, i) % MOD * pot(3, k - 1 - i) % MOD * bino(k - 1, i)) % MOD;
            // cout<<res<<' ';
            if(i + 1 <= n - k)
                res = (res + pot(3 , n - k - i - 1) * bino(n - k, i + 1) % MOD * pot(3, k - 1 - i) % MOD * bino(k - 1, i)) % MOD;
            // cout<<res<<'\n';
        }
        cout<<res<<'\n';
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
