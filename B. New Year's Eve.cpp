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
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n, m, r, k;
	cin>>n>>m>>r>>k;
	ll a = 1;
	vll va, vb;
	fore(i, 1, n + 1)
		va.pb(min((ll)i, min(n - r + 1, min(r, n - i + 1))));
	fore(i, 1, m + 1)
		vb.pb(min((ll)i, min(m - r + 1, min(r, m - i + 1))));
	sort(all(va));
	sort(all(vb));
	priority_queue<pair<ll, pair<int, int>>> que;
	int le = (int)va.size() - 1, ri = (int)vb.size() - 1;
	ll res = 0;
	set<pair<int, int>> st;
	st.insert({le, ri});
	que.push({va[le] * vb[ri], {le, ri}});
	while(true)
	{
		res += que.top().f;
		le = que.top().s.f;
		ri = que.top().s.s;
		// cout<<le<<' '<<ri<<' '<<" - "<<va[le]<<' '<<vb[ri]<<' '<<que.top().f<<'\n';
		que.pop();
		k--;
		if(k == 0)
			break;
		if(le > 0 && !st.count({le - 1, ri}))
		{
			st.insert({le - 1, ri});
			que.push({va[le - 1] * vb[ri], {le - 1, ri}});
		}
		if(ri > 0 && !st.count({le, ri - 1}))
		{
			st.insert({le, ri - 1});
			que.push({va[le] * vb[ri - 1], {le, ri - 1}});
		}
	}
	// cout<<res<<'\n';
	// cout<<(n - r + 1) * (m - r + 1)<<'\n';
	cout<<fixed<<setprecision(9)<<res / (1ll * (n - r + 1) * (m - r + 1) * 1.0)<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil