#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
	ll re[200000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n, a, b;
	cin>>n>>a>>b;
	if(b >= n && a <= n)
	{
		cout<<"YES\n";
		cout<<n<<'\n';
		return 0;
	}
	ll siz = n / b + (n % b > 0);
	if(a > n / 2 || siz > 100000)
	{
		cout<<"NO\n";
		return 0;
	}
	ll lo, hi, mid, res;
	ll tot = b * siz;
	ll sa = 0;
	fore(i, 0, siz)
	{
		lo = max(a, b - tot + n);
		sa += lo;
		re[i] = lo;
		n -= lo;
		tot -= b;
	}
	if(n == 0)
	{
		cout<<"YES\n";
		fore(i, 0, siz)
		{
			if(i > 0) cout<<' ';
			cout<<re[i];
		}
	cout<<'\n';
	}
	else
		cout<<"NO\n";
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2