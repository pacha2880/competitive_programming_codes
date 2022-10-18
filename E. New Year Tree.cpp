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
const ll tam = 400010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll col[62], ar[tam], t[4 * tam], laz[4 * tam];
vector<int> g[tam];
int ini[tam], fini[tam];
ll cols[tam];
int cont = 0;
void dfs(int node, int pa)
{
	ini[node] = cont;
	ar[cont++] = cols[node];
	for(auto x : g[node])
		if(x != pa)
			dfs(x, node);
	fini[node] = cont - 1;
}
#define caca int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = ar[b];
		return;
	}
	caca
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = t[l] | t[r];
}
void prop(int node, bool bo)
{
	if(laz[node])
	{
		t[node] = laz[node];
		if(bo)
		{
			laz[node * 2 + 1] = laz[node];
			laz[node * 2 + 2] = laz[node];
		}
		laz[node] = 0;
	}
}
ll query(int b, int e, int node, int i, int  j)
{
	// cout<<b<<' '<<e<<' '<<node<<'\n';
	if(b > e || b > j || e < i) return 0;
	prop(node, b != e);
	if(b >= i && e <= j)
		return t[node];
	caca
	return query(b, mid, l, i, j) | query(mid + 1, e, r, i, j);
}
void update(int b, int e, int node, int i, int j, ll val)
{
	if(b > e) return;
	if(b >= i && e <= j)
	{
		laz[node] = val;
		prop(node, b != e);
		return;
	}
	prop(node, b != e);
	if(b > j || e < i) return;
	caca
	update(mid + 1, e, r, i, j, val);
	update(b, mid, l, i, j, val);
	t[node] = t[l] | t[r];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, x;
	cin>>n>>m;
	col[0] = 1;
	fore(i, 1, 63) col[i] = col[i - 1] * 2;
	fore(i, 0, n) {cin>>x;cols[i] = col[x - 1];}
	int a, b;
	fore(i, 0, n - 1)
	{
		cin>>a>>b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	init(0, n - 1, 0);
	fore(i, 0, m)
	{
		// cout<<"chocho "<<i<<'\n';
		cin>>x>>a;
		a--;
		// cout<<a<<' '<<ini[a]<<' '<<fini[a]<<'\n';
		if(x == 2)
		{
			cout<<__builtin_popcountll(query(0, n - 1, 0, ini[a], fini[a]))<<'\n';
		}
		else
		{
			cin>>b;
			update(0, n - 1, 0, ini[a], fini[a], col[b - 1]);
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	