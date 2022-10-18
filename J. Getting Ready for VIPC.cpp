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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int dp[tam], l[tam], h[tam], d[tam];
int us[tam];
vector<vector<pair<int, int>>> dps;
vector<int> ds;
vector<vector<int>> fats;
vector<pair<int, int>> mixs;
vector<pair<int,int>> ad;
vector<int> af;
const int des = 30; 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, s, dt;
	cin>>n>>s>>dt;
	dp[0] = s;
	h[0] = s - dt;
	us[0] = -1;
	ad.pb({s, 0});
	int res = 0, ax;
	int lo, hi, mid, resp;
	int si, ac = -des;
	fore(i, 1, n + 1)
	{
		cin>>d[i]>>l[i]>>h[i];
		if(ac != d[i])
		{
			sort(all(ad));
			// cout<<ad.size()<<'\n';
			// cout<<"choco\n";
			vector<int> f(sz(ad));
			f.back() = h[ad.back().s] - dp[ad.back().s];
			for(int i = sz(f) - 2; i > -1; i--)
				f[i] = min(f[i + 1], h[ad[i].s] - dp[ad[i].s]);
			fats.pb(f);
			dps.pb(ad);
			ds.pb(ac);
			if(sz(mixs) > 0)
				mixs.pb(max(ad.back(), mixs.back()));
			else
				mixs.pb(ad.back());
			ac = d[i];
			ad.clear();
		}
		dp[i] = -MOD;
		si = dps.size();
		for(int j = si - 1; j > -1 && j > si - des; j--)
		{
			lo = 0, hi = sz(dps[j]) - 1, resp = -1;
			while(lo <= hi)
			{
				mid = (lo + hi) / 2;
				if(dps[j][mid].f >= l[i])
					resp = mid, hi = mid - 1;
				else
					lo = mid + 1;
			}
			if(resp != - 1)
			{
				ax = h[i] - ((fats[j][resp] + dt)>>(min(30, (d[i] - ds[j] - 1))));
				if(ax > dp[i])
				{
					dp[i] = ax;
					us[i] = dps[j][resp].s;
				}
			}
		}
		if(si >= des)
		{
			if(mixs[si - des].f >= l[i])
			{
				dp[i] = h[i];
				us[i] = mixs[si - des].s;
			}
		}
		ad.pb({dp[i], i});
		if(dp[i] > dp[res])
			res = i;
	}
	// cout<<res<<'\n';
	cout<<dp[res]<<' ';
	vector<int> used;
	while(us[res] != -1)
	{
		used.pb(res);
		res = us[res];
	}
	sort(all(used));
	cout<<sz(used)<<'\n';
	fore(i, 0, sz(used))
	{
		if(i > 0) cout<<' ';
		cout<<used[i];
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	