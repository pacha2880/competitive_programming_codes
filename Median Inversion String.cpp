#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
ll dp[70][70][1000];

ll f(int pos, int bs, int inv)
{
	if(pos == -1) return inv == 0;
	if(inv < 0) return 0;
	ll &res = dp[pos][bs][inv];
	if(res != -1) return res;
	res = f(pos - 1, bs + 1, inv) + f(pos - 1, bs, inv - bs);
	return res;
}
string find(int pos, int bs, int inv, ll can)
{
	if(pos == -1) return "";
	ll a = f(pos - 1, bs, inv - bs), b = f(pos - 1, bs + 1, inv);
	if(a >= can)
		return "A" + find(pos - 1, bs, inv - bs, can);
	else
		return "B" + find(pos - 1, bs + 1, inv, can - a);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	mem(dp, -1);
	int a, b;
	cin>>a>>b;
	ll can = f(a - 1, 0, b);
	string s1, s2;
	if(can & 1)
	{
		s1 = find(a - 1, 0, b, can / 2 + 1);
		cout<<s1<<'\n';
	}
	else
	{
		s1 = find(a - 1, 0, b, can / 2);
		s2 = find(a - 1, 0, b, can / 2 + 1);
		cout<<s1<<'\n'<<s2<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	