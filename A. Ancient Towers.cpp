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
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100'010;
const int MOD = 1'000'000'007;
const int MOD1 = 998'244'353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct point
{
	ll x, y;
	point () {}
	point(ll x, ll y) : x(x), y(y) {}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	point operator -(point p) {return {x - p.x, y - p.y};}
};
ll a[500];
vll t[2000];
void init(int b, int e, int node)
{
	t[node].clear();
	if(b == e)
	{
		t[node].pb(a[b]);
		return;
	}
	index;
	init(b, mid, l);
	init(mid + 1, e, r);
	merge(all(t[l]), all(t[r]), back_inserter(t[node]));
}
int query(int b, int e, int node, int i, int j, ll val)
{
	if(e < i || b > j) return 0;
	if(b >= i && e <= j)
		return t[node].end() - lower_bound(all(t[node]), val);
	index;
	return query(b, mid, l, i, j, val) + query(mid + 1, e, r, i,  j, val);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll s;
	int n;
	cin>>s>>n;
	s *= 2;
	vector<point> ar(n);
	fore(i, 0, n) cin>>ar[i].x>>ar[i].y;
	ll res = 0;
	fore(i, 0, n)
		fore(j, i + 1, n)
		{
			vector<point> le, ri;
			point ve = ar[j] - ar[i];
			fore(k, 0, n)
				if(k != i && k != j)
				{
					if((ve ^ (ar[k] - ar[i])) > 0)
						le.pb(ar[k]);
					else
						ri.pb(ar[k]);
				}	
			sort(all(le), [&](point &a, point &b){
				return ((b - ar[j]) ^ (a - ar[j])) > 0;
			});
			sort(all(ri), [&](point &a, point &b){
				return ((b - ar[j]) ^ (a - ar[j])) > 0;
			});
			int n = ri.size();
			if(n == 0) continue;
			ll va = ar[j] ^ ar[i];
			fore(k, 0, n)
				a[k] = va + (ar[i] ^ ri[k]) + (ri[k] ^ ar[j]);
			init(0, n - 1, 0);
			int e = 0;
			for(auto cat : le)
			{
				while(e < n && ((ri[e] - cat) ^ (ar[j] - cat)) < 0)
					e++;
				va = s - (ar[i] ^ ar[j])
						- (ar[j] ^ cat) - (cat ^ ar[i]);
				res += query(0, n - 1, 0, 0, e - 1, va);
				res += query(0, n - 1, 0, 0, n - 1, va);
			}


			sort(all(le), [&](point &a, point &b){
				return ((b - ar[i]) ^ (a - ar[i])) < 0;
			});
			sort(all(ri), [&](point &a, point &b){
				return ((b - ar[i]) ^ (a - ar[i])) < 0;
			});
			n = ri.size();
			va = ar[j] ^ ar[i];
			fore(k, 0, n)
				a[k] = va + (ar[i] ^ ri[k]) + (ri[k] ^ ar[j]);
			init(0, n - 1, 0);
			e = 0;

			for(auto cat : le)
			{
				while(e < n && ((ri[e] - cat) ^ (ar[i] - cat)) > 0)
					e++;
				va = s - (ar[i] ^ ar[j])
						- (ar[j] ^ cat) - (cat ^ ar[i]);
				res += query(0, n - 1, 0, 0, e - 1, va);
			}
		}
	cout<<res / 2<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
