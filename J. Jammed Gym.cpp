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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
double dp[110][100], dist[110][110];
bool visited[110][110];
int seq[110],  ar[110];
int n, m;
double f(int pos, int nu)
{
	if(seq[pos] != ar[nu]) return MOD;
	if(pos == n - 1) return 0;
	if(visited[pos][nu]) return dp[pos][nu];
	visited[pos][nu] = 1;
	double &res = dp[pos][nu] = MOD;
	fore(i, 0, m)
	{
		res = min(res, f(pos + 1, i) + dist[nu][i]);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n;
	fore(i, 0, n) cin>>seq[i];
	cin>>m;
	fore(i, 0, m) cin>>ar[i];
	fore(i, 0, m)
	{
		fore(j, 0, m)
		{
			if(i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = sqrt(2 - 2 * cos(2 * PI / m * abs(i - j)));
		}
	}
	double res = MOD;
	fore(i, 0, m)
		res = min(res, f(0, i));
	cout<<fixed<<setprecision(6)<<res + 1<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	