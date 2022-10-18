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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll dis[100010];
ll ar[100010];
ll su[100010];
ll dp[110][100010];
pair<ll, ll> hull[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	dis[0] = 0;
	int n, m, p;
	cin>>n>>m>>p;
	ll a, b;
	fore(i, 1, n)
	{
		cin>>a;
		dis[i] = dis[i - 1] + a;
	}
	fore(i, 0, m)
	{
		cin>>a>>b;
		ar[i] = b - dis[a - 1];
	}
	sort(ar, ar + m);
	fore(i, 0, m) ar[m - i] = ar[m - i - 1];
	ar[0] = 0;
	su[0] = 0;
	fore(i, 1, m + 1)
	{
		dp[0][i] = 1ll * MOD * MOD;
		su[i] = su[i - 1] + ar[i];
	}
	ll val, x1, y1, x2, y2;
	pair<ll, ll> x, y;
	int fro, ba;
	fore(i, 1, p + 1)
	{
		hull[0] = {0, 0};
		fro = 0, ba = 1;
		fore(j, 1, m + 1)
		{
			while(ba - fro > 1)
			{
				if(hull[fro + 1].f + hull[fro + 1].s * ar[j] > hull[fro].f + hull[fro].s * ar[j])
					break;
				else
					fro++;
			}
			y = hull[fro];
			dp[i][j] = y.f + y.s * ar[j] + ar[j] * j - su[j];
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			a = dp[i - 1][j] + su[j], b = -j;
			while(ba - fro > 1)
			{
				x1 = -b + hull[ba - 2].s, y1 = -a + hull[ba - 2].f;
				x2 = -hull[ba - 1].s + hull[ba - 2].s, y2 = -hull[ba - 1].f + hull[ba - 2].f;
				if(x1 * y2 - x2 * y1 <= 0)
					ba--;
				else
					break;
			}
			hull[ba++] = {a, b};
		}
	}
	cout<<dp[p][m]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	