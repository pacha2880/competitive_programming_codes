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
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll cost(ll len, ll div)
{
	ll x = len / div;
	return (x + 1) * (x + 1) * (len % div) + x * x * (div - len % div);
}
struct zan
{
	ll len;
	ll div;
	ll incr () const
	{
		return cost(len, div) - cost(len, div + 1);
	}
	bool operator <(const zan& x) const
	{
		return incr() < x.incr();
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int k, n;
	cin>>k>>n;
	ll a;
	priority_queue<zan> que;
	fore(i, 0, k)
	{
		cin>>a;
		que.push({a, 1});
	}
	zan ba;
	fore(i, k, n)
	{
		ba = que.top();
		que.pop();
		que.push({ba.len, ba.div + 1});
	}
	ll res = 0;
	while(!que.empty())
	{
		res += cost(que.top().len, que.top().div);
		que.pop();
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	