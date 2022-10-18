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
char grid[20][20];
bool visited[20][20];
int to[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
string mov = "DURL";
bool valid(int x, int y)
{
	return x > 0 && y > 0 && x < 13 && y < 13 && !visited[x][y] && grid[x][y] != '*';
}
int xx, yy;
string dfs(int x, int y)
{
	//cout<<x<<' '<<y<<'\n';
	string res = "";
	visited[x][y] = 1;
	if(grid[x][y] == '+')
		return "*";
	string a;
	int x1, y1;
	fore(i, 0, 4)
	{
		x1 = x + to[0][i], y1 = y + to[1][i];
		if(valid(x1, y1))
		{
			a = dfs(x1, y1);
			if(a.size() > 0)
			{
				a += mov[i];
				return a;
			}
		}
	}
	return "";
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	grid[3][3] = '+';
	grid[3][10] = '+';
	grid[10][3] = '+';
	grid[10][10] = '+';
	grid[6][6] = '*';
	grid[6][7] = '*';
	grid[7][6] = '*';
	grid[7][7] = '*';
	grid[9][2] = '*';
	grid[9][3] = '*';
	grid[10][2] = '*';
	grid[9][10] = '*';
	grid[9][11] = '*';
	grid[10][11] = '*';
	int n, x, y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		mem(visited, 0);
		string a = dfs(x, y);
		reverse(all(a));
		a.pop_back();
		cout<<a.size()<<'\n'<<a<<'\n';
	}
	return 0;	
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	