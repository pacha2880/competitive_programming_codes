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
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
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
const ll tam = 2010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll ara[tam], arb[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll n, m;
	cin>>n;
	ll dif = 0;
	fore(i, 0, n) {cin>>ara[i]; dif += ara[i];}
	cin>>m;
	fore(i, 0, m) {cin>>arb[i]; dif -= arb[i];}
	set<pair<ll, pair<ll, ll>>> st;
	set<pair<ll, pair<ll, ll>>>::iterator popo;
	pair<ll, pair<pair<ll, ll>, pair<ll, ll>>> res = {abs(dif), {{-1, -1}, {-1 , -1}}};
	ll ax;
	pair<ll, pair<ll, ll>> papa;
	fore(i, 0, n)
	fore(j, 0, m)
		res = min(res, {abs(dif - 2 * ara[i] + 2 * arb[j]), {{i + 1, j + 1}, {-1, -1}}});
	fore(i, 0, n - 1)
	fore(j, i + 1, n)
	{
		st.insert({2 * (ara[i] + ara[j]), {i + 1, j + 1}});
	}
	fore(i, 0, m - 1)
	fore(j, i + 1, m)
	{
		ax = dif + 2 * (arb[i] + arb[j]);
		popo = st.upper_bound({ax, {-1, -1}});
		if(popo != st.end())
		{
			papa = *popo;
			res = min(res, {abs(ax - papa.f), {{papa.s.f, papa.s.s}, {i + 1, j + 1}}});
		}
		if(popo != st.begin())
		{
			popo--;
			papa = *popo;
			res = min(res, {abs(ax - papa.f), {{papa.s.f, papa.s.s}, {i + 1, j + 1}}});	
		}
	}
	cout<<res.f<<'\n';
	if(res.s.f.f == -1)
		cout<<0<<'\n';
	else if(res.s.s.f == -1)
		cout<<1<<'\n'<<res.s.f.f<<' '<<res.s.f.s<<'\n';
	else
		cout<<2<<'\n'<<res.s.f.f<<' '<<res.s.s.f<<'\n'<<res.s.f.s<<' '<<res.s.s.s<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	