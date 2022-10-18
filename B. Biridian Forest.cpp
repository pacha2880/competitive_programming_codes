#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define EPS			1e-9
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
int n, m;
bool visited[1001][1001];
	string ar[1001];
bool valid(int x, int y)
{
	if (x < 0 || x == n || y < 0 || y == m)
		return false;
	return !visited[x][y] && ar[x][y] != 'T';
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int x1,y1,x2,y2,pro,x,y;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>ar[i];
		for(int j = 0; j < m; j++)
		{
			if(ar[i][j] == 'S')
				x1 = i, y1 = j;
			if(ar[i][j] == 'E')
				x2 = i, y2 = j;
		}
	}
	queue<pair<int,pair<int,int>>> que;
	int dist[n*m];
	mem(dist,0);
	que.push(mp(0,mp(x2,y2)));
	mem(visited,0);
	int profi;
	while(!que.empty())
	{
		pro = que.front().f, x = que.front().s.f, y = que.front().s.s;
		que.pop();
		//cout<<x<<' '<<y<<endl<<'$'<<endl;;
		if(!valid(x,y))
			continue;
		//cout<<x<<' '<<y<<endl;
		visited[x][y] = 1;
		if(ar[x][y] < 'A')
			dist[pro] += ar[x][y] - '0';
		if(ar[x][y] == 'S')
			profi = pro;
		que.push(mp(pro+1, mp(x+1, y)));
		que.push(mp(pro+1, mp(x-1, y)));
		que.push(mp(pro+1, mp(x, y+1)));
		que.push(mp(pro+1, mp(x, y-1)));
	}
	int res = 0;
	for(int i = 1; i <= profi; i++)
	{
		//cout<<i<<' '<<dist[i]<<endl;
		res += dist[i];
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS