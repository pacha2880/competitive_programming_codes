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
int tabla[2020][2020];
int get(int x0, int y0, int x1, int y1)
{
	if(y0 > y1 || x0 > x1) return 0;
	return tabla[x1][y1] - tabla[x1][y0 - 1] - tabla[x0 - 1][y1] + tabla[x0 - 1][y0 - 1];
}
string tab[2020];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int can = 0;
	fore(i, 0, n) 
	{
		cin>>tab[i];
		fore(j, 0, m)
		{
			tabla[i + 1][j + 1] = tab[i][j] == 'w';
			can += tabla[i + 1][j + 1];
		}
	}
	fore(i, 0, 2)
	fore(j, 1, n + 1)
	fore(k, 1, m + 1)
	{
		if(i == 0)
			tabla[j][k] += tabla[j][k - 1];
		else
			tabla[j][k] += tabla[j - 1][k];
	}
	int lo, hi, mid, res, canti;
	int x, y, x0, y0;
	int lar = MOD;
	fore(i, 1, n + 1)
	fore(j, 1, m + 1)
	{
		lo = 1, hi = min(n - i + 1, m - j + 1), res = -1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(get(i, j, i + mid - 1, j + mid - 1) == can)
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		if(res != -1 && get(i + 1, j + 1, i + res - 2, j + res - 2) == 0)
		{
			if(res < lar)
			{
				lar = res;
				x = i - 1;
				y = j - 1;
			}
		}
	}
	if(lar == MOD)
		cout<<-1<<'\n';
	else
	{
		fore(i, 0, lar)
		{
			if(tab[x][y + i] != 'w')
				tab[x][y + i] = '+';
			if(tab[x + i][y] != 'w')
				tab[x + i][y] = '+';
			if(tab[x + lar - 1][y + i] != 'w')
				tab[x + lar - 1][y + i] = '+';
			if(tab[x + i][y + lar - 1] != 'w')
				tab[x + i][y + lar - 1] = '+';
		}
		fore(i, 0, n) cout<<tab[i]<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	