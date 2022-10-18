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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int cas;
	ll x, y;
	cin>>cas;
	while(cas--)
	{
		cin>>x>>y;
		//para enviar debe ser __int128 pero no se porque no me compila :'v
		ll a = x, b = y, lo = 2, hi = 3e18, mid, res1, n, k;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(mid * (mid + 1) / 2 > a * (mid - 1) / b)
				res1 = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		n = res1;
		vector<pair<ll, ll>> res;
		fore(i, 0, 100)
		{
			if(a * (n - 1) % b == 0)
			{
				k = n * (n + 1) / 2 - a * (n - 1) / b;
				if(k <= n)
					res.pb({(ll)n, (ll)k});
			}
			n++;
		}
		cout<<res.size()<<'\n';
		fore(i, 0, res.size())	
		{
			cout<<res[i].f<<' '<<res[i].s<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2		