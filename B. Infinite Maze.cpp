#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

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
char grid[4500][4500];
int n, m;
bool dfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push(mp(x, y));
	while(!que.empty())
	{
		x = que.front().f, y = que.front().s;
		que.pop();
		if(grid[(x + 1) % (3 * n)][y] != '#')
		{
			if(grid[(x + 1) % (3 * n)][y] == 'S')
				return true;
			grid[(x + 1) % (3 * n)][y] = '#';
			que.pb(mp((x + 1) % (3 * n), y));
		}
		if(grid[(x - 1 + 3 * n) % (3 * n)][y] != '#')
		{
			if(grid[(x - 1 + 3 * n) % (3 * n)][y] == 'S')
				return true;
			grid[(x - 1 + 3 * n) % (3 * n)][y] = '#';
			que.pb(mp((x - 1 + 3 * n) % (3 * n), y));
		}
		if(grid[x][(y + 1) % (3 * m)] != '#')
		{
			if(grid[x][(y + 1) % (3 * m)] == 'S')
				return true;
			grid[x][(y + 1) % (3 * m)] = '#';
			que.pb(mp(x, (y + 1) % (3 * m)));
		}
		if(grid[x][(y - 1 + 3 * m) % (3 * m)] != '#')
		{
			if(grid[x][(y - 1 + 3 * m) % (3 * m)] == 'S')
				return true;
			grid[x][(y - 1 + 3 * m) % (3 * m)] = '#';	
			que.pb(mp(x, (y - 1 + 3 * m) % (3 * m)));
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n>>m;
	int x, y;
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			cin>>grid[i][j];
			fore(k, 0, 3)
			{
				fore(l, 0, 3)
				{
					grid[k * n + i][l * m + j] = grid[i][j];
				}
			}
			if(grid[i][j] == 'S')
			{
				x = n + i, y = m + j;
				grid[n + i][m + j] = '.';
			}
		}
	}
	/*cout<<'\n';
	fore(i, 0, 3 * n)
	{
		fore(j, 0, 3 * m)
		cout<<grid[i][j];
		cout<<'\n';
	}*/
	if(dfs(x, y))
		cout<<"Yes\n";
	else
		cout<<"No\n";
	/*cout<<'\n';
	fore(i, 0, 3 * n)
	{
		fore(j, 0, 3 * m)
		cout<<grid[i][j];
		cout<<'\n';
	}*/
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	