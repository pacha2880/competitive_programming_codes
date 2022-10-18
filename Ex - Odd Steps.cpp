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
const int tam = 100010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll a, b, c, d;
void pot(ll e)
{
    a = 1, b = 0, c = 0, d = 1;
    ll ba = 1, bb = 1, bc = 1, bd = 0;
    ll ax, bx, cx, dx;
    while(e)
    {
        if(e & 1)
        {
            ax = (a * ba + b * bc) % MOD, bx = (a * bb + b * bd) % MOD,
            cx = (c * ba + d * bc) % MOD, dx = (c * bb + d * bd) % MOD;
            a = ax, b = bx, c = cx, d = dx;
        }
        ax = (ba * ba + bb * bc) % MOD, bx = (ba * bb + bb * bd) % MOD,
        cx = (bc * ba + bd * bc) % MOD, dx = (bc * bb + bd * bd) % MOD;
        ba = ax, bb = bx, bc = cx, bd = dx;
        e >>= 1;
    }
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    ll n, s;
    cin>>n>>s;
    ll x = 1, y = 0, xx;
    ll la = 0, in;
    while(n--)
    {
        cin>>in;
        ll dif = in - 1 - la;
        pot(dif);
        xx = (x * a + y * c) % MOD;
        y = (x * b + y * d) % MOD;
        x = xx;
        swap(x, y);
        la = in;
    }
    ll dif = s - la - 1;
    pot(dif);
    xx = (x * a + y * c) % MOD;
    y = (x * b + y * d) % MOD;
    x = xx;
    cout<<x<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
