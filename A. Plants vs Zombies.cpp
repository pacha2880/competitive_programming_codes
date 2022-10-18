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
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<'\n'
#define RAYA cerr<<"=============================="<<'\n'
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
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<ll, ll> ar[tam], er[tam];
ll pre[tam];
int ind[tam];
ll res[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n, m, v, k, d;
	cin>>n>>m>>v>>k>>d;
	fore(i, 0, n) {
		cin>>ar[i].f>>ar[i].s;
		ar[i].f--;
	}
	fore(i, 0, n) ind[i] = i;
	sort(ind, ind + n, [&](int a, int b){
		return ar[a].f == ar[b].f ? a < b : ar[a].f < ar[b].f;
	});
	fore(i, 0, m) cin>>er[i].f>>er[i].s;
	sort(er, er + m);
	set<pair<ll, ll>> st;
	st.insert({-1ll * MOD * MOD, 0});
	fore(i, 0, m)
	{
		pre[i + 1] = pre[i] + er[i].s;
		st.insert({er[i].f, i + 1});
		// cout<<"--"<<er[i].f<<' '<<i + 1<<'\n';
	}
	ll x = -1, pea = 0, reset = 0;
	ll t, h;
	ll lo, hi, mid, re;
	fore(i, 0, n)
	{
		// cout<<"ind "<<ind[i]<<' '<<x<<'\n';
		t = ar[ind[i]].f, h = ar[ind[i]].s;
		if(x <= t)
		{
			h += t * k * d;
		}
		else
		{
			h += pea;
		}
		lo = 0, hi = 1;
		while(hi * k * d <= h)
			hi *= 2;
		// cout<<lo<<' '<<hi<<' '<<v * t<<' '<<h<<'\n';
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(mid * k * d + pre[(--st.upper_bound({-v * t + mid * v, MOD}))->s] < h)
				re = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		// cout<<"bobo "<<re * k * d<<' '<<(--st.upper_bound({-v * t + (re) * v, MOD}))->s<<'\n';
		// cout<<re<<' '<<re * k * d + pre[(--st.upper_bound({-v * t + (re) * v, MOD}))->s]<<'\n';
		res[ind[i]] = re + 1;
		h -= re * k * d + pre[(--st.upper_bound({-v * t + (re + 1) * v, MOD}))->s];
		// cout<<h<<'\n';
		pea = re * k * d + (h > 0 ? h / d : 0) * d;
		// cout<<pea<<'\n';
		x = re + 1;
	}
	fore(i, 0, n)
	{
		if(i > 0) cout<<' ';
		cout<<res[i];
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
