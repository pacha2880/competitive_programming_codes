#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(ll i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(ll i = b, asdz = e, frz; i < asdz; i+=frz)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](ll a, ll b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll tam = 200010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<pair<ll, ll>> nivu[tam];
vector<ll> g[tam];
ll pre[tam];
ll dp[tam];
ll par[tam];
ll nibu;
void dfs(ll node, ll niv)
{
	for(ll x : g[node])
	{
		nibu = max(nibu, niv);
		par[x] = node;
		nivu[niv].pb({pre[x], x});
		dfs(x, niv + 1);
	}
}
void solve()
{
	ll n, a;
	cin>>n;
	fore(i, 1, n)
	{
		cin>>a;
		g[a - 1].pb(i);
	}
	fore(i, 1, n)
		cin>>pre[i];
	nibu = 0;
	dfs(0, 0);
	dp[0] = 0;
	fore(i, 0, nibu + 1)
	{
		vector<ll> grop;
		set<ll> valos;
		sort(all(nivu[i]));
		ll lasto = nivu[i][0].f;
		ll difo = 0;
		for(auto cat : nivu[i])
		{
			if(lasto == cat.f)
			{
				valos.insert(dp[par[cat.s]] - difo);
				grop.pb(cat.s);
			}
			else
			{
				for(auto x : grop)
				{
					dp[x] = max(max(lasto - nivu[i][0].f, nivu[i].back().f - lasto) + dp[par[x]],
								*(--valos.end()) + difo);
				}
				difo += cat.f - lasto;
				valos.insert(dp[par[cat.s]] - difo);
				lasto = cat.f;
				grop.assign(1, cat.s);
			}
		}
		for(auto x : grop)
		{
			dp[x] = max(max(lasto - nivu[i][0].f, nivu[i].back().f - lasto) + dp[par[x]],
						*(--valos.end()) + difo);
		}
		reverse(all(nivu[i]));

		grop.clear();
		valos.clear();
		lasto = nivu[i][0].f;
		difo = 0;
		for(auto cat : nivu[i])
		{
			if(lasto == cat.f)
			{
				valos.insert(dp[par[cat.s]] - difo);
				grop.pb(cat.s);
			}
			else
			{
				for(auto x : grop)
				{
					dp[x] = max(dp[x], *(--valos.end()) + difo);
				}
				difo += lasto - cat.f;
				valos.insert(dp[par[cat.s]] - difo);
				lasto = cat.f;
				grop.assign(1, cat.s);
			}
		}
		for(auto x : grop)
		{
			dp[x] = max(dp[x], *(--valos.end()) + difo);
		}
	}
	ll res = 0;
	for(auto cat : nivu[nibu])
		res = max(res, dp[cat.s]);
	cout<<res<<'\n';
	fore(i, 0, n)
	{
		nivu[i].clear();
		g[i].clear();
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll cas;
	cin>>cas;
	while(cas--)
		solve();
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	