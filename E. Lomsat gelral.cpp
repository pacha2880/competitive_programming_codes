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
const ld PI = acosl(-1); 
vector<int> g[tam];
ll col[tam], res[tam];
map<ll, ll> sums[tam];
unordered_map<ll, ll> fre[tam];
void join (int a, int b)
{
	if(fre[a].size() < fre[b].size())
	{
		swap(fre[a], fre[b]);
		swap(sums[a], sums[b]);
	}
	ll x;
	for(auto cat : fre[b])
	{
		x = fre[a][cat.f];
		sums[a][x] -= cat.f;
		fre[a][cat.f] += cat.s;
		sums[a][x + cat.s] += cat.f;
	}
}
void dfs(int node, int par)
{
	sums[node][1] = col[node];
	fre[node][col[node]] = 1;
	int a, b;
	for(int x: g[node])
	{
		if(x != par)
		{
			dfs(x, node);
			join(node, x);
		}
	}
	res[node] = (--(sums[node].end()))->s;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, a, b;
	cin>>n;
	fore(i, 0, n) cin>>col[i];
	fore(i, 0, n - 1)
	{
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	fore(i, 0, n)
	{
		if(i > 0) cout<<' ';
		cout<<res[i];
	}
	cout<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	