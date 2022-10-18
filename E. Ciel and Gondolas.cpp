#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 4010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int mat[tam][tam], pre[tam][tam], cost[tam][tam], dp[tam][tam];

		
void dc(int lev, int b, int e, int l, int r)
{
	if(b > e) return;
	int mid = (b + e) / 2;
	int k = r;
	fore(i, l, min(mid + 1, r + 1))
	{
		if(dp[mid][lev] > dp[i - 1][lev - 1] + cost[i][mid])
		{
			k = i;
			dp[mid][lev] = dp[i - 1][lev - 1] + cost[i][mid];
		}
	}
	dc(lev, b, mid - 1, l, k);
	dc(lev, mid + 1, e, k, r);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	fore(i, 0, n)
	{
		cin>>mat[i][0];
		pre[i][0] = mat[i][0];
		fore(j, 1, n)
		{
			cin>>mat[i][j];
			pre[i][j] = pre[i][j - 1] + mat[i][j];
		}
	}
	fore(i, 0, n + 1) fore(j, 0, n + 1) dp[i][j] = MOD;
	fore(i, 0, n)
	{
		fore(j, i + 1, n)
			cost[i][j] = cost[i][j - 1] + pre[j][j] - (i > 0 ? pre[j][i - 1] : 0);
		dp[i][1] = cost[0][i];
		dp[0][i] = 0;
	}
	fore(j, 2, k + 1)
	{
		dc(j, 1, n - 1, 1, n - 1);
	}
	cout<<dp[n - 1][k]<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil