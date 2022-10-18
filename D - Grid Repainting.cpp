	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	#define PI 				acos(-1)
	#define mp				make_pair
	#define pb				push_back
	#define all(a)			(a).begin(), (a).end()
	#define sz(a)			a.size()
	#define srt(a)			sort(all(a))
	#define mem(a, h)		memset(a, (h), sizeof(a))
	#define f 				first
	#define s 				second
	#define MOD1			998244353
	#define fore(i, b, e)	for(int i = b; i < e; i++)
	#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
	int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

	using namespace std;
	using namespace __gnu_pbds;

	typedef long long 		ll;
	typedef unsigned long long 		ull;
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
	const int tam = 100010;
	const int MOD = 1e9+7;
	const double EPS = 1e-9;

		int n, m;
		char grid[100][100];
		bool visited[100][100];
		bool valid(int x, int y)
		{
			if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == '.')
				return true;
			return false;
		}
	int main()
	{
		ios::sync_with_stdio(0); cin.tie(0);
		//freopen("qwe.txt", "r", stdin);
		//freopen("asd.txt", "w", stdout);
		cin>>n>>m;
		mem(visited, 0);
		int conbla = 0;
		fore(i, 0, n) 
		{
			cin>>grid[i];
			fore(j, 0, m)
				conbla += grid[i][j] == '#';
		}
		queue<pair<pair<int, int>,int>> que;
		que.push(mp(mp(0, 0), 1));
		int pasos = -1;
		int x, y, pas;
		int mover[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
		while(!que.empty())
		{
			x = que.front().f.f;
			y = que.front().f.s;
			pas = que.front().s;
			if(x == n-1 && y == m-1)
				pasos = pas;
			que.pop();
			fore(i, 0, 4)
			{
				if(valid(x + mover[0][i], y + mover[1][i]))
				{
					visited[x + mover[0][i]][y + mover[1][i]] = 1;
					que.push(mp(mp(x + mover[0][i], y + mover[1][i]), pas + 1));
				}
			}
		}
		if(pasos == -1)
			cout<<"-1\n";
		else
			cout<<n * m - pasos - conbla<<'\n';
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2