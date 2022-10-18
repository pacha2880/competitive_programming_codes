#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<pair<int, int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
int times[300030];
vector<int> with[300030]; 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, p;
	cin>>n>>p;
	int a, b;
	fore(i, 0, n)
	{
		cin>>a>>b;
		a--;
		b--;
		with[a].pb(b);
		with[b].pb(a);
		times[a]++;
		times[b]++;
	}
	ordered_set st;
	fore(i, 0, n)
		st.insert({times[i], i});
	int k;
	ll res = 0;
	fore(i, 0, n - 1)
	{
		st.erase({times[i], i});
		fore(j, 0, with[i].size())
			if(with[i][j] > i)
			{
				k = with[i][j];
				st.erase({times[k], k});
				st.insert({--times[k], k});
			}
		res += st.size() - st.order_of_key({max(0, p - times[i]), -1});
		fore(j, 0, with[i].size())
			if(with[i][j] > i)
			{
				k = with[i][j];
				st.erase({times[k], k});
				st.insert({++times[k], k});
			}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	