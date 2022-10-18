#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
//#define sz(a)			(int)a.size()
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

ll n, m, k, s;
pair<int, int> resp[2 * tam];
pair<pair<ll, int>, pair<ll, int>> gut[2 * tam];
vector<pair<int, int>> gua, gub;
bool cal(int x)
{
	ll su = 0;
	int ina = 0, inb = 0;
	bool bo;
	ll a, b;
	fore(i, 0, k)
	{
		if(ina < gua.size() && inb < gub.size())
			bo = gua[ina].f * gut[x].f.f < gub[inb].f * gut[x].s.f;
		else 
			bo = ina < gua.size();
		if(bo)
		{
			resp[i] = {gua[ina].s, gut[x].f.s};
			su += gua[ina].f * gut[x].f.f;
			ina++;
		}
		else
		{
			resp[i] = {gub[inb].s, gut[x].s.s};
			su += gub[inb].f * gut[x].s.f;
			inb++;	
		}
	}
	return su <= s;
}
int ara[2 * tam], arb[2 * tam];
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n>>m>>k>>s;
	ll a, b;
	pair<ll, int> mia = {MOD, 0}, mib = {MOD, 0};
	fore(i, 0, n) cin>>ara[i];
	fore(i, 0, n) cin>>arb[i];
	fore(i, 0, n)
	{
		a = ara[i], b = arb[i];
		mia = min({a, i}, mia);
		mib = min({b, i}, mib);
		gut[i] = {mia, mib};
	}
	int x, y;
	fore(i, 0, m)
	{
		cin>>x>>y;
		if(x == 1)
			gua.pb({y, i});
		else
			gub.pb({y, i});
	}
	sort(all(gua));
	sort(all(gub));
	int lo = 0, hi = n - 1, mid, res = -1;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(cal(mid))
			res = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}
	if(res == -1)
		cout<<-1<<'\n';
	else
	{
		cout<<res + 1<<'\n';
		cal(res);
		fore(i, 0, k) cout<<resp[i].f + 1<<' '<<resp[i].s + 1<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	