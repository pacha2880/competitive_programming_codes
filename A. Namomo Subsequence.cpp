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
#define mad(x)			x = x > MOD ? x - MOD : x
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
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
const int tam = 1000100;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

string s;
int n;
int dp1[62][tam];
int dp2[62][62];
int dp3[62][62];
int cant[62][tam];
int can[62];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	cin>>s;
	n = s.size();
	fore(i, 0, n) 
	{
		// cout<<s[i]<<',';
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a';
		else if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] -= 'A' - 26;
		else
			s[i] -= '0' - 52;
		// cout<<(int(s[i]))<<' ';
	}
	cant[s[0]][0]++;
	can[s[0]]++;

	fore(i, 1, n)
	{
		fore(j, 0, 62)
		{
			dp1[j][i] = dp1[j][i - 1] + (s[i] == j ? 0 : i - can[j] - can[s[i]]);
			mad(dp1[j][i]);
			cant[j][i] = can[j];
		}
		can[s[i]]++;
		cant[s[i]][i]++;
	}
	mem(can, 0);
	can[s[n - 1]]++;
	ll res = 0;
	for(int i = n - 2; i > 2; i--)
	{
		// cout<<i<<'\n';
		if(i < n - 2)
		{
			fore(j, 0, 62)
			{
				dp2[s[i]][j] += dp3[j][s[i]];
				mad(dp2[s[i]][j]);
				// cout<<dp2[s[i]][j]<<' ';;
			}
			// cout<<'\n';
			fore(j, 0, 62)
			{
				// cout<<dp1[s[i - 1]][i - 2]<<' '<<cant[j][i - 2] << ' ' <<i - 1 - cant[j][i - 2] - cant[s[i-1]][i - 2]<<' '<< dp2[j][s[i - 1]]<<'\n';;
				res += ((dp1[s[i - 1]][i - 2] - (1ll * cant[j][i - 2] * (i - 1 - cant[j][i - 2] - cant[s[i-1]][i - 2]) % MOD)) * dp2[j][s[i - 1]]) % MOD;
				mad(res);
				// cout<<((dp1[s[i - 1]][i - 2] - (cant[j][i - 2] * (i - 1 - cant[j][i - 2] - cant[s[i-1]][i - 2]) % MOD)) * dp2[j][s[i - 1]]) % MOD<<'\n';
			}
			// cout<<i<<' '<<res<<'\n';
		}
		fore(j, 0, 62)
		{
			if(s[i] != j)
			{
				dp3[s[i]][j] += can[j];
				mad(dp3[s[i]][j]);
			}
			// cout<<dp3[s[i]][j]<<' ';
		}
		// cout<<'\n';
		can[s[i]]++;
	}
	
	// fore(i, 2, n)
	// {
	// 	res = (res + dp1[s[i]][i-1] * dp2[s[i]][i]) % MOD;
	// 	cout<<i<<' '<<dp1[s[i]][i - 1]<<' '<<dp2[s[i]][i]<<'\n';
	// }
	// fore(i, 0, n)
	// {
	// 	cout<<i<<'\n';
	// 	fore(j, 0, 62)
	// 	cout<<dp1[j][i]<<' ';
	// 	cout<<'\n';
	// 	fore(j, 0, 62)
	// 	cout<<dp2[j][i]<<' ';
	// 	cout<<'\n';
	// 	fore(j, 0, 62)
	// 	cout<<dp3[j][i]<<' ';
	// 	cout<<'\n';
	// 	cout<<"---------------\n";
	// }
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil