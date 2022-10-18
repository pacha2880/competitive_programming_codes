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
ll pot[4000400];
string s[4000400];
int cans[4][2020][2020];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	pot[0] = 1;
	fore(i, 1, 4000400) pot[i] = pot[i - 1] * 2 % MOD;
	int h, w;
	cin>>h>>w;
	int can = 0, con;
	fore(i, 0, h)
	{
		cin>>s[i];
		con = 0;
		fore(j, 0, w)
		{
			if(s[i][j] == '.')
			{
				can++;
				con++;
				cans[0][i][j] = con;
			}
			else
				con = 0;
		}
		con = 0;
		for(int j = w - 1; j > -1; j--)
		{
			if(s[i][j] == '.')
			{
				con++;
				cans[1][i][j] = con;
			}
			else
				con = 0;
		}
	}
	fore(i, 0, w)
	{
		con = 0;
		fore(j, 0, h)
		{
			if(s[j][i] == '.')
			{
				con++;
				cans[2][j][i] = con;
			}
			else
				con = 0;
		}
		con = 0;
		for(int j = h - 1; j > -1; j--)
		{
			if(s[j][i] == '.')
			{
				con++;
				cans[3][j][i] = con;
			}
			else
				con = 0;
		}
	}
	ll res = 0, p;
	fore(i, 0, h)
	fore(j, 0, w)
	{
		if(s[i][j] == '.')
		{
			p = 0;
			fore(k, 0, 4) p += cans[k][i][j]; //cout<<cans[k][i][j]<<'\n';}
			p -= 3;
			//cout<<i<<' '<<j<<' '<<p<<' '<<can<<'\n';
			res = (res + (pot[p] - 1) * pot[can - p] % MOD) % MOD;
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	