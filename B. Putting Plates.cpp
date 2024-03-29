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
int tab[22][22];
int n, m;
int dir[2][8] = {{-1, 0, 1, -1, 1, -1, 0, 1}, {-1, -1, -1, 0, 0, 1, 1, 1}};
bool can(int i, int j)
{
	bool res = (i == 0 || i == n - 1 || j == 0 || j == m - 1) && tab[i][j] == 0;
	int x, y;
	if(res)
	{
		fore(k, 0, 8)
		{
			x = i + dir[0][k];
			y = j + dir[1][k];
			if(x >= 0 && x < n && y >= 0 && y < m)
				if(tab[x][y] == 1) return 0;
		}
	}
	return res;
}
int llen(int x, int y)
{
	int res = 0;
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			if(can((x + i)%n, (y + j)%m))
			{
				res++;
				tab[(x + i)%n][(y + j)%m] = 1;
			}
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		pair<int, pair<int, int>> res(0, mp(0, 0));
		fore(i, 0, n)
		{
			fore(j, 0, m)
			{
				if((i == 0 || i == n - 1) || (j == 0 || j == m - 1))
				{
					mem(tab, 0);
					res = max(res, {llen(i, j), {i, j}});
				}
			}
		}
		// cout<<res.f<<'\n';
		mem(tab, 0);
		llen(res.s.f, res.s.s);
		fore(i, 0, n)
		{
			fore(j, 0, m)
				cout<<tab[i][j];
			cout<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
