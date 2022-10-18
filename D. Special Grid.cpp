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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
int sums[4][1000][1000];
int n, m;
string ar[1000];
int cant(int a, int b, int c, int d)
{
	return sums[a][b][d + 1] - sums[a][b][c];
}
int trian(int x,  int y, int lar)
{
	int res = 0;
	//cout<<"mayo   "<<lar<<'\n';
	if(x + lar < n && y + lar < m)
	{
		res += (cant(0, x, y, y + lar) + cant(1, y, x, x + lar) + cant(3, y + x + lar, y, y + lar)) == 0;
		//cout<<"a "<<res<<' '<<x<<"   "<<y + x + 1<< ' '<<y<<' '<< y + lar<<' ';
	}
	if(x + lar < n && y - lar >= 0)
	{
		res += (cant(0, x, y - lar, y) + cant(1, y, x, x + lar) + cant(2, x - y + n + lar, y - lar, y)) == 0;
		//cout<<"b "<<res<<' ';
	}

	if(x - lar >= 0 && y + lar < m)
	{
		res += (cant(0, x, y, y + lar) + cant(1, y, x - lar, x) + cant(2, x - y + n - lar, y, y + lar)) == 0;
		//cout<<" c"<<res<<' ';
	}
	if(x - lar >= 0 && y - lar >= 0)
	{
		res += (cant(0, x, y - lar, y) + cant(1, y, x - lar, x) + cant(3, x + y - lar, y - lar, y)) == 0;
		//cout<<" d"<<res<<' ';

	}
	//cout<<'\n';
	return res;
}
int trian1(int x, int y, int lar)
{
	int res = 0;
	if(x + lar < n && y + lar < m && y - lar >= 0)
	{
		res += (cant(0, x + lar, y - lar, y + lar) + cant(2, x - y + n, y, y + lar) + cant(3, x + y, y - lar, y)) == 0;
	}
	if(x - lar >= 0 && y + lar < m && y - lar >= 0)
	{
		res += (cant(0, x - lar, y - lar, y + lar) + cant(2, x - y + n, y - lar, y) + cant(3, x + y, y, y + lar)) == 0;	
	}
	if(y + lar < m && x + lar < n && x - lar >= 0)
	{
		res += (cant(1, y + lar, x - lar, x + lar) + cant(2, x - y + n, y, y + lar) + cant(3, x + y, y, y + lar)) == 0;
	}
	if(y - lar >= 0 && x + lar < n && x - lar >= 0)
	{
		res += (cant(1, y - lar, x - lar, x + lar) + cant(2, x - y + n, y - lar, y) + cant(3, x + y, y - lar, y)) == 0;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n>>m;
	fore(i, 0, n) cin>>ar[i];
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			sums[0][i][j + 1] = sums[0][i][j] + (ar[i][j] == '1');
			sums[1][j][i + 1] = sums[1][j][i] + (ar[i][j] == '1');
			sums[2][i - j + n][j + 1] = sums[2][i - j + n][j] + (ar[i][j] == '1');
			//cout<<"cacha  "<<2<<' '<<i<<' '<<j<<' '<<sums[2][i - j + n][j + 1]<<'\n';
		}
	}
	for(int i = n - 1; i > -1; i--)
	{
		fore(j, 0, m)
		{
			sums[3][i + j][j + 1] = sums[3][i + j][j] + (ar[i][j] == '1');
			//cout<<"chacho  "<<i + j<<' '<<i<<' '<<j<<' '<<sums[3][i + j][j + 1] <<'\n';
		}
	}
	int res = 0;
	int lam = min(n, m);
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			//cout<<i<<','<<j<<" -> "<<res<<'\n';
			fore(k, 1, lam)
				res += trian(i, j, k) + trian1(i, j, k);
			//cout<<i<<','<<j<<" -> "<<res<<'\n';
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	