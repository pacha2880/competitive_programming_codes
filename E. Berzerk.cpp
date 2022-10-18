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
int n, t[2];
int s[2][10000];
int dp[2][10000];
int con[2][10000];
int av[2][10000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    // mem(dp, -1);
    cin>>n;
    fore(i,0, 2)
    {
        cin>>t[i];
        fore(j, 0, t[i])
            cin>>s[i][j];
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    fore(i, 0, 2)
    fore(k, 0, t[i])
    {
        dp[i][(n - s[i][k]) % n] = 2;
        av[i][(n - s[i][k]) % n] = 1;
    }
        // fore(i, 0, 2){
        // fore(j, 0, n)
        //     cout<<dp[i][j]<<' '; cout<<'\n';}
    fore(caca, 0, 2*n)
    for(int j = n - 1; j > 0; j--)
    {
        fore(i, 0, 2)
        {
            if(av[i][j] == 1)
            {
                av[i][j] = -1;
                int ku = i ^ 1;
                fore(k, 0, t[ku])
                    con[ku][(n + j - s[ku][k]) % n]++;
            }
            if(con[i][j] == t[i])
            {
                con[i][j]++;
                dp[i][j] = 1;
                int ku = i ^ 1;
                fore(k, 0, t[ku])
                    if((n + j - s[ku][k]) % n != 0 && dp[ku][(n + j - s[ku][k]) % n] != 2)
                    {
                        if(av[ku][(n + j - s[ku][k]) % n] == 0)
                            av[ku][(n + j - s[ku][k]) % n] = 1;
                        dp[ku][(n + j - s[ku][k]) % n] = 2;
                    }
            }
        }
        // cout<<j<<"  AAAA\n";
        // fore(i, 0, 2){
        // fore(j, 0, n)
        //     cout<<dp[i][j]<<' '; cout<<'\n';}
    }
    fore(i, 0, 2)
    {
        fore(j, 1, n)
        {
            if(j > 1) cout<<' ';
            if(dp[i][j] == 1)
                cout<<"Lose";
            else if(dp[i][j] == 2)
                cout<<"Win";
            else
                cout<<"Loop";
        }
        cout<<'\n';
    }
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
