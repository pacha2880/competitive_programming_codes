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
const double EPS = 1e-9;
const double PI = acos(-1); 
int tab[110][110];
vector<pair<int, int>> ras(3);
vector<vector<pair<int, int>>> res;
void op(vector<pair<int, int>> v)
{
	fore(i, 0, 3)
		tab[v[i].f][v[i].s] = !tab[v[i].f][v[i].s];
}
void solv(int x, int y)
{
	vector<pair<int, int>> oc, lib;
	fore(i, 0, 2) fore(j, 0, 2)
	{
		if(tab[x + i][y + j])
			oc.pb({x + i, y + j});
		else
			lib.pb({x + i, y + j});
	}
	if(oc.size() > 0)
	{
		if(oc.size() == 3)
		{
			op(oc);
			res.pb(oc);
		}
		else if(oc.size() == 2)
		{
			lib.pb(oc[0]);
			op(lib);
			res.pb(lib);
			lib.pop_back();
			lib.pb(oc[1]);
			op(lib);
			res.pb(lib);
		}
		else if(oc.size() == 1)
		{
			oc.pb(lib[2]);
			oc.pb(lib[1]);
			op(oc);
			res.pb(oc);
			lib[2] = oc[0];
			op(lib);
			res.pb(lib);
			lib[1] = oc[1];
			op(lib);
			res.pb(lib);
		}
		else if(oc.size() == 4)
		{
			lib.pb(oc[3]);
			oc.pop_back();
			op(oc);
			res.pb(oc);
			swap(oc, lib);
			oc.pb(lib[2]);
			oc.pb(lib[1]);
			op(oc);
			res.pb(oc);
			lib[2] = oc[0];
			op(lib);
			res.pb(lib);
			lib[1] = oc[1];
			op(lib);
			res.pb(lib);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int cas;
	cin>>cas;
	int n, m;
	while(cas--)
	{
		cin>>n>>m;
		int axn = n, axm = m;
		res.clear();
		string s;
		fore(i, 0, n)
		{
			cin>>s;
			fore(j, 0, m) tab[i][j] = s[j] - '0';
		}
		if(n & 1)
		{
			fore(i, 0, m - 1)
			{
				if(tab[n - 1][i])
				{
					ras[0] = {n - 1, i};
					ras[1] = {n - 2, i};
					ras[2] = {n - 2, i + 1};
					op(ras);
					res.pb(ras);
				}
			}
			if(tab[n - 1][m - 1])
			{
				ras[0] = {n - 1, m - 1};
				ras[1] = {n - 2, m - 1};
				ras[2] = {n - 2, m - 2};
				op(ras);
				res.pb(ras);
			}
			n--;
		}
		if(m & 1)
		{
			fore(i, 0, n - 1)
			{
				if(tab[i][m - 1])
				{
					ras[0] = {i, m - 1};
					ras[1] = {i, m - 2};
					ras[2] = {i + 1, m - 2};
					op(ras);
					res.pb(ras);
				}
			}
			if(tab[n - 1][m - 1])
			{
				ras[0] = {n - 1, m - 1};
				ras[1] = {n - 1, m - 2};
				ras[2] = {n - 2, m - 2};
				op(ras);
				res.pb(ras);
			}
			m--;
		}
		forg(i, 0, n, 2)
		forg(j, 0, m, 2)
		{
			solv(i, j);
		}
		cout<<res.size()<<'\n';
		fore(i, 0, res.size())
		{
			fore(j, 0, 3)
			{
				if(j > 0)
					cout<<' ';
				cout<<res[i][j].f + 1<<' '<<res[i][j].s + 1;
			}
			cout<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	