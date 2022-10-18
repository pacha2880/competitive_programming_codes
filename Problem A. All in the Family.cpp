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
const int tam = 110;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[tam];
map<string, int> ma;
int par[tam], prof[tam];
void dfs(int node, int pro)
{
	prof[node] = pro;
	for(int x : g[node])
		dfs(x, pro + 1);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int con = 0, n, m, a, b;
	cin>>n>>m;
	string s, t;
	mem(par, -1);
	fore(i, 0, n)
	{
		cin>>s>>a;
		if(!ma.count(s))
			ma[s] = con++;
		while(a--)
		{
			cin>>t;
			if(!ma.count(t))
				ma[t] = con++;
			g[ma[s]].pb(ma[t]);
			par[ma[t]] = ma[s];
		}
	}
	int root;
	n = con;
	assert(ma.size() <= 100);
	fore(i, 0, n)
		if(par[i] == -1)
			root = i;
	dfs(root, 0);
	int x, y;
	while(m--)
	{
		cin>>s>>t;
		x = ma[s];
		y = ma[t];
		a = 0;
		b = 0;
		while(prof[x] != prof[y])
		{
			if(prof[x] > prof[y])
			{
				a++;
				x = par[x];
			}
			else
			{
				b++;
				y = par[y];
			}
		}
		while(x != y)
		{
			a++, b++;
			x = par[x];
			y = par[y];
		}
		if(a == 0 || b == 0)
		{
			if(a == 0)
			{
				swap(a, b);
				swap(s, t);
			}
			if(a == 1)
				cout<<s<<" is the child of "<<t<<'\n';
			else
			{
				cout<<s<<" is the ";
				while(a > 2) {cout<<"great "; a--;}
				cout<<"grandchild of "<<t<<'\n';
			}
		}
		else if(a == b)
		{
			if(a > b)
				swap(a, b);
			a--;
			int m = a > 20 ? a % 10 : a;
			if(a == 0)
				cout<<s<<" and "<<t<<" are siblings\n";
			else
				cout<<s<<" and "<<t<<" are "<<a<<(m == 1 ? "st" : m == 2 ? "nd" : m == 3 ? "rd" : "th")<<" cousins\n";
		}
		else
		{
			if(a > b)
				swap(a, b);
			a--;
			b--;
			int m = a > 20 ? a % 10 : a;
			cout<<s<<" and "<<t<<" are "<<a<<(m == 1 ? "st" : m == 2 ? "nd" : m == 3 ? "rd" : "th")<<" cousins, "
			<<b - a<<(b - a == 1 ? " time" : " times")<<" removed\n";
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil