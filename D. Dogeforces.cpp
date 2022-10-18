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
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
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
struct asd
{
	map<int, vector<int>> ma;
	int ind;
	asd() {}
	asd(map<int, vector<int>> a, int b) {ma = a; ind = b;}
	bool operator <(asd const &b) const
	{
		return mp(ma.begin()->f, ind) < mp(b.ma.begin()->f, b.ind);
	}
};
int mat[550][550];
int vals[10000];
int parent[10000];
int find(int n)
{
	if(parent[n] == -1) return n;
	return parent[n] = find(parent[n]);
}
vector<int> g[10000];
void dfs(int node)
{
	for(int x : g[node])
	{
		cout<<x + 1<<' '<<node + 1<<'\n';
		dfs(x);
	}
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, a, b, k;
	cin>>n;
	k = n;
	set<asd> st;
	mem(parent, -1);
	fore(i, 0, n)
	{
		map<int, vector<int>> ma;
		fore(j, 0, n)
		{
			cin>>a;
			if(i == j)
			{
				vals[i] = a;
				continue;
			}
			ma[a].pb(j);
		}
		st.insert(asd(ma, i));
	}
	int par = n;
	map<int, vector<int>>::const_iterator ut;
	set<asd>::iterator it, ti;
	set<int> er;
	asd ax;
	while(st.size() > 1)
	{
		it = st.begin();
		if(er.count(it->ind))
		{
			st.erase(it);
			continue;
		}
		ut = it->ma.begin();
		b = find(it->ind);
		// cout<<"afsd  "<<par<<' '<<b<<'\n';
		g[par].pb(b);
		parent[b] = par;
		vals[par] = ut->f;
		for(int x : ut->s)
		{
			a = find(x);
			if(a == par) continue;
			// cout<<a<<' '<<x<<'\n';;
			er.insert(a);
			g[par].pb(a);
			parent[a] = par;
		}
		// cout<<"-----\n";
		ax = *it;
		st.erase(it);
		if(ax.ma.size() > 1)
		{
			ax.ma.erase(ax.ma.begin());
			ax.ind = par;
			st.insert(ax);
		}
		par++;
	}
	cout<<par<<'\n';
	fore(i, 0, par)
	{
		if(i > 0) cout<<' ';
		cout<<vals[i];
	}
	cout<<'\n'<<par<<'\n';
	dfs(par - 1);
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	