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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
const int tam = 300010;
const int logTam = 21;
int n; 
int ar[tam], table[logTam][tam];
void inispar()
{
	fore(i, 0, n) table[0][i] = ar[i];
	for(int k = 0; (1 << k) < n; k++)
		for(int i = 0; i + (1 << k) < n; i++)
			table[k + 1][i] = min(table[k][i], table[k][i + (1 << k)]);
}
int query(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return min(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
void inispor()
{
	fore(i, 0, n) table[0][i] = ar[i];
	for(int k = 0; (1 << k) < n; k++)
		for(int i = 0; i + (1 << k) < n; i++)
			table[k + 1][i] = max(table[k][i], table[k][i + (1 << k)]);
}
int queryo(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return max(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
int salde[tam], sali[tam], salman[tam], salmin[tam], salma[tam], salmi[tam], ax[tam];
int dp[tam];
int f(int pos)
{
	if(pos == n - 1) return 0;
	if(pos == n - 2) return 1;
	if(dp[pos] != -1) return dp[pos];
	return dp[pos] = 1 + min(f(salma[pos]), f(salmi[pos]));
}
vector<int> g[tam];
bool visited[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n;
	fore(i, 0, n) {cin>>ar[i]; ax[i] = ar[i];}
	inispar();
	int lo, hi, mid, res;
	fore(i, 0, n)
	{
		res = i;
		lo = i + 1, hi = n - 1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(query(i + 1, mid) > ar[i])
				res = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		salde[i] = res;
		res = i;
		lo = 0, hi = i - 1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(query(mid, i - 1) > ar[i])
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		sali[i] = res;
	}
	fore(i, 0, n) ar[i] = sali[i];
	inispar();
	int hil;
	fore(i, 0, n)
	{
		res = i;
		lo = i + 1, hi = min(salde[i] + 1, n - 1);
		hil = hi;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(query(mid, hil) <= i + 1)
				res = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		salma[i] = res;
	}
	fore(i, 0, n) ar[i] = salde[i];
	inispor();
	fore(i, 0, n)
	{
		res = i;
		hi = i - 1, lo = max(sali[i] - 1, 0);
		hil = lo;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(queryo(hil, mid) >= i - 1)
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		salman[i] = res;
	}
	fore(i, 0, n) ar[i] = ax[i];
	inispor();
	fore(i, 0, n)
	{
		res = i;
		lo = i + 1, hi = n - 1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(queryo(i + 1, mid) < ar[i])
				res = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		salde[i] = res;
		res = i;
		lo = 0, hi = i - 1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(queryo(mid, i - 1) < ar[i])
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		sali[i] = res;
	}
	fore(i, 0, n) ar[i] = sali[i];
	inispar();
	fore(i, 0, n)
	{
		res = i;
		lo = i + 1, hi = min(salde[i] + 1, n - 1);
		hil = hi;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(query(mid, hil) <= i + 1)
				res = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		salmi[i] = res;
	}
	fore(i, 0, n) ar[i] = salde[i];
	inispor();
	fore(i, 0, n)
	{
		res = i;
		hi = i - 1, lo = max(sali[i] - 1, 0);
		hil = lo;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(queryo(hil, mid) >= i - 1)
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		salmin[i] = res;
	}
	/*mem(dp, -1);
	cout<<f(0)<<'\n';
	return 0;*/
	fore(i, 0, n)
	{
		g[i].pb(salmi[i]);
		g[i].pb(salma[i]);
		g[salmin[i]].pb(i);
		g[salman[i]].pb(i);
	}
	queue<pair<int, int>> que;
	que.push({0, 0});
	visited[0] = 1;
	int node, pas;
	while(true)
	{
		node = que.front().f;
		pas = que.front().s;
		que.pop();
		if(node == n - 1)
		{
			cout<<pas<<'\n';
			return 0;
		}
		fore(i, 0, g[node].size())
		{
			if(!visited[g[node][i]])
			{
				visited[g[node][i]] = 1;
				que.push({g[node][i], pas + 1});
			}
		}
	}
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2		