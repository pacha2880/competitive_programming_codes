#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
double dp[1000010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, a, b;
	cin>>n>>a>>b;
	dp[0] = 0;
	fore(i, 1, a + 1) dp[i] = 1;
	double su = 0;
	int fro = 0, to = 0, in = a + 1;
	if(a == 0)
	{
		a = 1;
		while(in < n + 1)
		{
			while(to <= in - a)
			{
				su += dp[to];
				to++;
			}
			while(fro < in - b)
			{
				su -= dp[fro];
				fro++;
			}
			dp[in] = (su + (b - a + 2)) / (b - a + 1) ;
			//cout<<in<<' '<<su<<' '<<fro<< ' '<<to<<' '<<dp[in]<<'\n';
			in++;
		}
	}
	else
	while(in < n + 1)
	{
		while(to <= in - a)
		{
			su += dp[to];
			to++;
		}
		while(fro < in - b)
		{
			su -= dp[fro];
			fro++;
		}
		dp[in] = 1 + su / (b - a + 1);
		//cout<<in<<' '<<su<<' '<<fro<< ' '<<to<<' '<<dp[in]<<'\n';
		in++;
	}
	cout<<fixed<<setprecision(5)<<dp[n]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	