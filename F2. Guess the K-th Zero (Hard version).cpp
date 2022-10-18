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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
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
int tree[8 * tam], lazy[8 * tam], res, x;
int dp[2 * tam];
int que = 60000;
void query(int node, int b, int e, int k)
{
	if(e < b)
		return;
	index
	if(dp[mid] == -1)
	{
		que--;
		assert(que >= 5);
		cout<<"? "<<1<<' '<<mid + 1<<endl;
		cin>>dp[mid];
		lazy[node] = 0;
	}
	else if(lazy[node])
	{
		dp[mid] += lazy[node];
		lazy[l] += lazy[node];
		lazy[r] += lazy[node];
		lazy[node] = 0;
	}
	// cout<<mid+1<<' '<<dp[mid]<<'\n';
	if(mid - dp[mid] + 1 >= k)
	{
		res = mid + 1, query(l, b, mid - 1, k);
		dp[mid]++;
		lazy[r]++;
	}
	else
		query(r, mid + 1, e, k);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, t, k;
	cin>>n>>t;
	mem(dp, -1);
	while(t--)
	{
		cin>>k;
		query(0, 0, n - 1, k);
		cout<<"! "<<res<<endl;	
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2		