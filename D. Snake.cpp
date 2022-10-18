#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
char board[20][20];
pair<int, int> pos[10];
int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
char bobord[20][20];
int n, m;
bool find(int x, int y)
{
	//cout<<x<<' '<<y<<'\n';
	if(bobord[x][y] == '@')
		return true;
	bobord[x][y] = '#';
	int x1, y1;
	bool res = false;
	fore(i, 0, 4)
	{
		x1 = x + dir[0][i];
		y1 = y + dir[1][i];
		if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && bobord[x1][y1] != '#')
			res |= find(x1, y1);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n>>m;
	int moxo = 0, va;
	deque<pair<int, int>> v;
	int x, y;
	fore(i, 0, n)
	fore(j, 0, m)
	{
		cin>>board[i][j];
		if(board[i][j] >= '1' && board[i][j] <= '9')
		{
			va = board[i][j] - '1';
			moxo = max(moxo, va);
			pos[va] = mp(i, j);
			board[i][j] = '.';
		}
		else if(board[i][j] == '@')
		{
			x = i; y = j;
		}
	}
	fore(i, 0, n) fore(j, 0, m) bobord[i][j] = board[i][j];
	if(!find(pos[0].f, pos[0].s))
	{
		cout<<-1;
		return 0;
	}
	fore(i, 0, moxo + 1)
		v.pb(pos[i]);
	map<deque<pair<int, int>>, bool> visited;
	visited[v] = 1;
	priority_queue<pair<pair<int, int>, deque<pair<int, int>>>> que;
	que.push(mp(mp(0, 0), v));
	int pas;
	pair<int, int> ax, neo;
	while(!que.empty())
	{
		pas = que.top().f.s;
		if(pas < -300) break;
		v = que.top().s;
		que.pop();
		fore(i, 1, v.size() - 1)
			board[v[i].f][v[i].s] = '#';
		fore(i, 0, 4)
		{
			neo = {v.front().f + dir[0][i], v.front().s + dir[1][i]};
			if(neo.f >= 0 && neo.f < n && neo.s >= 0 && neo.s < m)
			{
				if(board[neo.f][neo.s] == '.')
				{
					ax = v.back();
					v.pop_back();
					v.push_front(neo);
					if(!visited[v])
					{
						que.push({{-abs(neo.f - x) - abs(neo.s - y) +  pas - 1, pas - 1}, v});
						visited[v] = 1;
					}
					v.pop_front();
					v.push_back(ax);
				}
				else if(board[neo.f][neo.s] == '@')
				{
					cout<<-pas + 1;
					return 0;
				}
				
			}
		}
		fore(i, 1, v.size() - 1)
			board[v[i].f][v[i].s] = '.';
	}
	cout<<"-1";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	