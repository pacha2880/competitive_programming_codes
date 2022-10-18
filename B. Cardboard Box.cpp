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
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<pair<ll, ll>, int> par[tam], ax[tam];
ll ar[tam];
struct item
{
	int can;
	ll su;
	item() : can(0), su(0) {}
	item(int can, ll su) : can(can), su(su) {}
};
item join(item a, item b)
{
	a.can += b.can;
	a.su += b.su;
	return a;
}
item t[4 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = {1, ar[b]};
		return;
	}
	index;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
void update(int b, int e, int node, int pos)
{
	if(b == e)
	{
		t[node] = {0, 0};
		return;
	}
	index;
	if(pos <= mid)
		update(b, mid, l, pos);
	else
		update(mid + 1, e, r, pos);
	t[node] = join(t[l], t[r]);
}
ll query(int b, int e, int node, int k)
{
	if(t[node].can == k)
		return t[node].su;
	index;
	if(t[l].can >= k)
		return query(b, mid, l, k);
	return t[l].su + query(mid + 1, e, r, k - t[l].can);
}
struct comp
{
	bool operator ()(const int &a, const int &b) const
	{
		return ax[a].f.s < ax[b].f.s;
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, w;
	cin>>n>>w;
	fore(i, 0, n)
	{
		cin>>par[i].f.s>>par[i].f.f;
		par[i].s = i;
	}
	sort(par, par + n);
	fore(i, 0, n) ax[i] = par[i], ar[i] = par[i].f.f;
	init(0, n - 1, 0);
	multiset<int, comp> st;
	fore(i, 0, n) st.insert(i);
	pair<ll, int> res(1ll * MOD * MOD, 0);
	ll acu = 0;
	int in, ux = w;
	fore(i, 0, 2 * n)
	{
		// cout<<"#"<<i<<'\n';
		if(w % 2 == 0 && t[0].can >= w / 2)
		{
			res = min(res, {acu + query(0, n - 1, 0, w / 2), i});
			// cout<<res.f<<'\n';
		}
		w--;
		in = *st.begin();
		st.erase(st.begin());
		acu += ax[in].f.s;
		ax[in].f.s = ax[in].f.f - ax[in].f.s;
		update(0, n - 1, 0, in);
		ax[in].f.f = 2 * MOD;
		st.insert(in);
		if(w == 0)
		{
			res = min(res, {acu, i + 1});
			// cout<<res.f<<'\n';
			break;
		}
	}
	cout<<res.f<<'\n';
	st.clear();
	fore(i, 0, n) ax[i] = par[i];
	fore(i, 0, n) st.insert(i);
	string ans = "";
	fore(i, 0, n) ans += '0';
	w = ux;
	fore(i, 0, res.s)
	{
		w--;
		in = *st.begin();
		// cout<<in<<'\n';
		ans[ax[in].s]++;
		st.erase(st.begin());
		ax[in].f.s = ax[in].f.f - ax[in].f.s;
		ax[in].f.f = 2 * MOD;
		st.insert(in);
	}
	int po = 0;
	while(w)
	{
		if(ans[ax[po].s] == '0')
		{
			w -= 2;
			ans[ax[po].s] = '2';
		}
		po++;
	}
	cout<<ans<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
