#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int tam = 300030;
vector<int> g[tam], gp[tam], dp[tam];
int lo, hi, mid;
int f(int node, int val)
{
	int res = 0;
	int in = g[node].size();
	lo = 0, hi = in - 1;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(gp[node][mid] > val)
			in = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}
	if(in < g[node].size())
	{
		int chu = 0, cha;
		if(dp[node][in] == - 1)
		{
			dp[node][in] = max(f(node, gp[node][in]), 1 + f(g[node][in], gp[node][in]));
			chu = dp[node][in];
			cha = in + 1;
			while(cha < g[node].size() && gp[node][cha] == gp[node][in])
			{
				dp[node][cha] = 1 + f(g[node][cha], gp[node][cha]);
				chu = max(chu, dp[node][cha]);
				cha++;
			}
			dp[node][in] = chu;
		}
		//cout<<node + 1<<' '<<val<<' '<<in<<' '<<dp[node][in]<<'\n';
		return dp[node][in];
	}
		//cout<<"se salio "<<node + 1<<' '<<val<<' '<<in<<' '<<0<<'\n';
	return 0;
}
int ax[300030];
pair<int, int> ord[300030];
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b, c;
	while(m--)
	{
		scanf("%d%d%d", &a, &b, &c);
		g[a - 1].pb(b - 1);
		gp[a - 1].pb(c);
		dp[a - 1].pb(-1);
	}
	fore(i, 0, n)
	{
		fore(j, 0, g[i].size())
			ord[j] = {gp[i][j], j};
		//cout<<"nodeo "<<i + 1<<'\n';
		if(g[i].size() > 0)
		{
			sort(ord, ord + (int)g[i].size());
			fore(j, 0, g[i].size())
			{
				//cout<<ord[j].f<<' ';
				gp[i][j] = ord[j].f;
				ax[j] = g[i][ord[j].s];
			}
			fore(j, 0, g[i].size())
				g[i][j] = ax[j];
		}
		//cout<<'\n';
	}
	int res = 0;
	fore(i, 0, n)
	{
		//cout<<i<<' '<<f(i, 0)<<'\n';
		res = max(res, f(i, 0));
	}
	printf("%d\n", res);
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	