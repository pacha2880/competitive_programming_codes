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

int table[2][4010][4010];
int val(int x1, int y1, int x2, int y2, int l)
{
	return table[l][x2][y2] - (x1 > 0 ? table[l][x1 - 1][y2] : 0) - (y1 > 0 ? table[l][x2][y1 - 1] : 0)
			+ (x1 > 0 && y1 > 0 ? table[l][x1 - 1][y1 - 1] : 0);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	int sk = 2 * k;
	char ch;
	int x, y;
	while(n--)
	{
		cin>>x>>y>>ch;
		table[ch == 'B'][x % sk][y % sk]++;
	}
	fore(i, 0, sk)
		fore(j, 0, sk)
			fore(l, 0, 2)
				fore(x, 0, 2)
					fore(y, 0, 2)
						table[l][i + x * sk][j + y * sk] = table[l][i][j];
	fore(l, 0, 2)
	fore(i, 0, 2 * sk)
	{
		fore(j, 0, 2 * sk)
		{
			if(i > 0)
				table[l][i][j] += table[l][i - 1][j];
			if(j > 0)
				table[l][i][j] += table[l][i][j - 1];
			if(i > 0 && j > 0)
				table[l][i][j] -= table[l][i - 1][j - 1];
		}

	}
	int res = 0, su;
	fore(i, 0, sk)
	fore(j, 0, sk)
	{
		fore(l, 0,  2)
		{
			su = val(i, j, i + k - 1, j + k - 1, l % 2 == 0);
			su += val(i + k , j + k, i + 2 * k - 1, j + 2 * k - 1, l % 2 == 0);
			su += val(i + k, j, i + 2 * k - 1, j + k - 1, l % 2 == 1);
			su += val(i, j + k, i + k - 1, j + 2 * k - 1, l % 2 == 1);
			res = max(res, su);
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2