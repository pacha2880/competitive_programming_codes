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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll c[17][100010];
ll solo[17][100010];
vll dp[17][100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
    cin>>n;
    int k = 1<<n;
    fore(i, 0, k)
        fore(j, 1, n + 1)
            cin>>c[j][i];
    fore(i, 0, n + 1)
    {
        fore(j, 0, 1<<(n - i))
        {
            dp[i][j].assign(1<<i, 0);
            if(i > 0)
            {
                fore(l, 0, (1<<(i - 1)))
                {
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j * 2][l] + solo[i - 1][j * 2 + 1] + c[i][j * (1<<i) + l] - c[i - 1][j * (1<<i) + l]);
                    solo[i][j] = max(solo[i][j], dp[i][j][l]);
                }
                fore(l, 1<<(i - 1), 1<<i)
                {
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j * 2 + 1][l - (1<<(i - 1))] + solo[i - 1][j * 2]+ c[i][j * (1<<i) + l] - c[i - 1][j * (1<<i) + l]);
                    solo[i][j] = max(solo[i][j], dp[i][j][l]);
                }
            }
        }
    }
    cout<<solo[n][0]<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
