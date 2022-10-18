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
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
void go(int x, int y, int pas, vector<vector<int>> &vis, string &pat, int &res)
{
	// cout<<x<<' '<<y<<' '<<pas<<'\n';
	if((x % 6 == 0 ) && y > 0 && y < 6 && vis[x][y - 1] + vis[x][y + 1] == 0 || 
			(y % 6 == 0 ) && x > 0 && x < 6 && vis[x - 1][y] + vis[x + 1][y] == 0)
		return;
	vis[x][y] = 1;

	// fore(i, 0, 7)
	// {
	// 	fore(j, 0, 7)
	// 	cout<<vis[i][j]<<' ';
	// 	cout<<'\n';
	// }
	if(x == 0 && y == 6)
	{
		if(pas == 48)
			res++;
	}
	else
	{
		if(pat[pas] == '?')
		{
			if(x < 6 && vis[x + 1][y] == 0)
				go(x + 1, y, pas + 1, vis, pat, res);
			if(y < 6 && vis[x][y + 1] == 0)
				go(x, y + 1, pas + 1, vis, pat, res);
			if(x > 0 && vis[x - 1][y] == 0)
				go(x - 1, y, pas + 1, vis, pat, res);
			if(y > 0 && vis[x][y - 1] == 0)
				go(x, y - 1, pas + 1, vis, pat, res);
		}
		else
		{
			if(pat[pas] == 'R')
			{
				if(x < 6 && vis[x + 1][y] == 0)
					go(x + 1, y, pas + 1, vis, pat, res);
			}
			else if(pat[pas] == 'D')
			{
				if(y < 6 && vis[x][y + 1] == 0)
					go(x, y + 1, pas + 1, vis, pat, res);
			}
			else if(pat[pas] == 'L')
			{
				if(x > 0 && vis[x - 1][y] == 0)
					go(x - 1, y, pas + 1, vis, pat, res);
			}
			else
			{
				if(y > 0 && vis[x][y - 1] == 0)
					go(x, y - 1, pas + 1, vis, pat, res);	
			}
		}
	}
	vis[x][y] = 0;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	string pat;
	int res = 0;

	vector<vi> v(7, vi(7));
	cin>>pat;
	int fi = -1, la = -1;
	fore(i, 0, pat.size())
	{
		if(pat[i] != '?')
		{
			la = i;
			if(fi == -1)
				fi = i;
		}
	}
	if(fi > sz(pat) - 1 - la)
	{
		reverse(all(pat));
		fore(i, 0, pat.size())
		{
			if(pat[i] == 'L')
				pat[i] = 'R';
			else if(pat[i] == 'R')
				pat[i] = 'L';
		}
	}
	if(fi == -1)
		res = 88418;
	else
		go(0, 0, 0, v, pat, res);
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
