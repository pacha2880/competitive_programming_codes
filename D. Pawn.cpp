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
int dp[200][200][20], ma[200][200], n, m, k;
int f(int x, int y, int mo)
{
	if(y < 0 || y == m) return -2;
	if(x == 0)
	{
		if(ma[x][y] % k == mo)
			return dp[x][y][mo] = ma[x][y];
		else
			return dp[x][y][mo] = -2;
	}
	if(dp[x][y][mo] != -1) return dp[x][y][mo];
	int le = f(x - 1, y - 1, md(mo - ma[x][y], k));
	int ri = f(x - 1, y + 1, md(mo - ma[x][y], k));
	if(max(le, ri) == -2) return dp[x][y][mo] = -2;
	return dp[x][y][mo] = ma[x][y] + max(le, ri);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n>>m>>k;
	k++;
	string s;
	fore(i, 0, n)
	{
		cin>>s;
		fore(j, 0, m)
		{
			ma[i][j] = s[j] - '0';
		}
	}
	mem(dp, -1);
	int res = -2, po = 0;;
	fore(i, 0, m)
	{
		if(f(n-1, i, 0) > res)
		{
			res = f(n-1, i, 0);
			po = i;
		}
	}
	if(res == -2)
	{
		cout<<-1<<'\n';
		return 0;
	}
	cout<<res<<'\n'<<po+1<<'\n';
	int lev = n-1, mo = 0, momo = 0;
	while(lev > 0)
	{
		mo = md(mo - ma[lev][po], k);
		if(po == 0)
		{
			cout<<'R';
			po++;
			lev--;
		}
		else if(po == m-1)
		{
			cout<<'L';
			po--;
			lev--;
		}
		else
		{
			//cout<<lev<<' '<<dp[lev-1][po+1][mo]<<' '<<dp[lev-1][po-1][mo]<<'\n';
			if(dp[lev-1][po+1][mo] > dp[lev-1][po-1][mo])
			{
				cout<<'R';
				po++;
			}
			else
			{
				cout<<'L';
				po--;
			}
			lev--;
		}
	}
	cout<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	