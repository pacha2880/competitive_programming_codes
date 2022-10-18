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
double pors[300];
int bag[300];
double dp[220][220][220];
bool visited[220][220][220];
int n;
double f(int pos, int tow, int cap)
{
	if(pos == n)
	{
		if(tow <= 0) return 1;
		return 0;
	}
	if(visited[pos][tow][cap]) return dp[pos][tow][cap];
	visited[pos][tow][cap] = 1;
	if(bag[pos] == -1)
	{
		if(cap) dp[pos][tow][cap] += pors[pos] * f(pos+1,max(0,tow-1),cap-1);
		//else
		//	dp[pos][tow][cap] += pors[pos] * f(pos+1,tow,cap);
	}
	else
		dp[pos][tow][cap] += pors[pos] * f(pos+1,max(0,tow-1),min(n, cap+bag[pos]));	
	dp[pos][tow][cap] += (1 - pors[pos]) * f(pos + 1, tow, cap);
	return dp[pos][tow][cap];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l, k;
	cin>>n>>l>>k;
	pair<int, double> caca[n];
	fore(i, 0, n)
	{
		cin>>pors[i];
		pors[i] /= 100;
		caca[i].s = pors[i];
	}
	fore(i, 0, n) {cin>>bag[i];
		caca[i].f = bag[i];}
	sort(caca, caca + n);
	reverse(caca, caca + n);
	fore(i, 0, n)
	{
		pors[i] = caca[i].s;
		bag[i] = caca[i].f;
	}
	cout<<fixed<<setprecision(7)<<f(0, l, k)<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2