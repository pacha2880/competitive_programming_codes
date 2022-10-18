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
ll grid[1000][1000], dist[4][1000][1000];
bool valid(int x, int y)
{
	return !(x<0 || x == n || y < 0 || y == m);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	mem(dist,-1);
	cin>>n>>m;
	//cout<<3<<endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin>>grid[i][j];
			for(int k = 0; k < 4; k++)
				dist[k][i][j] = grid[i][j];
		}
	//cout<<2<<endl;
	
	for(int i = 1; i < m; i++)
		dist[0][0][i] += dist[0][0][i-1];
	for(int i = 1; i < n; i++)
		dist[0][i][0] += dist[0][i-1][0];
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			dist[0][i][j] += max(dist[0][i][j-1], dist[0][i-1][j]);
	//cout<<4;
	for(int i = n-2; i > -1; i--)
		dist[1][i][0] += dist[1][i+1][0];
	for(int i = 1; i < m; i++)
		dist[1][n-1][i] += dist[1][n-1][i-1];
	for(int i = n-2; i > -1; i--)
		for(int j = 1; j < m; j++)
			dist[1][i][j] += max(dist[1][i][j-1], dist[1][i+1][j]);
	//cout<<5;
	for(int i = n - 2; i > -1; i--)
		dist[2][i][m-1] += dist[2][i+1][m-1];
	for(int i = m - 2; i > -1; i--)
		dist[2][n-1][i] += dist[2][n-1][i+1];
	for(int i = n - 2; i > -1; i--)
		for(int j = m - 2; j > -1; j--)
			dist[2][i][j] += max(dist[2][i][j+1], dist[2][i+1][j]);
	//cout<<6;
	for(int i = 1; i < n; i++)
		dist[3][i][m-1] += dist[3][i-1][m-1];
	for(int i = m - 2; i > -1; i--)
		dist[3][0][i] += dist[3][0][i+1];
	for(int i = 1; i < n; i++)
		for(int j = m - 2; j > -1; j--)
			dist[3][i][j] += max(dist[3][i][j+1], dist[3][i-1][j]);
	ll res = 0;
	//cout<<1<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//cout<<dist[3][i][j]<<'|';
			if(valid(i,j-1)&&valid(i+1,j)&&valid(i-1,j)&&valid(i,j+1))
				res = max(res, (ll)dist[0][i][j-1] + (ll)dist[1][i+1][j] + (ll)dist[3][i-1][j] + (ll)dist[2][i][j+1]);
			//cout<<dist[0][i][j-1] <<' '<< dist[1][i+1][j]<<' ';
			//cout<<resa<<' ';
			if(valid(i-1,j)&&valid(i,j-1)&&valid(i,j+1)&&valid(i+1,j))
				res = max(res, (ll)dist[0][i-1][j] + (ll)dist[1][i][j-1] + (ll)dist[3][i][j+1] + (ll)dist[2][i+1][j]);
			//cout<<dist[0][i-1][j] + dist[1][i][j-1]<<',';
			//cout<<'('<<resa<<','<<resb<<") ";

		}
		//cout<<endl;
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS