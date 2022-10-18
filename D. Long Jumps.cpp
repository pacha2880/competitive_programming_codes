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
const ll MOD = 1000000009;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll ar[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll n, l, x, y;
	cin>>n>>l>>x>>y;
	fore(i, 0, n) cin>>ar[i];
	ll a = 0, b = 0, c = 0, d = 0;
	bool ba = false, bb = false, bc = false, bd = false;
	ll lu, la;
	fore(i, 0, n)
	{
		while(a < n && ar[a] - ar[i] <= x)
			a++;
		while(b < n && ar[b] - ar[i] <= y)
			b++;
		while(c < n && ar[c] - ar[i] <= x + y)
			c++;
		while(d < n && ar[d] - ar[i] <= y - x)
			d++;
		a--;
		b--;
		c--;
		d--;
		if(ar[a] - ar[i] == x)
			ba = true;
		if(ar[b] - ar[i] == y)
			bb = true;
		if(ar[c] - ar[i] == x + y)
		{
			lu = i;
			bc = true;
		}
		if(ar[d] - ar[i] == y - x && (ar[i] >= x || l - ar[d] >= x))
		{
			la = i;
			bd = true;
		}
	}
	if(!ba && !bb && !bc && !bd)
		cout<<2<<'\n'<<x<<' '<<y<<'\n';
	else if(ba && bb)
		cout<<0<<'\n';
	else if(bc)
		cout<<1<<'\n'<<ar[lu] + x<<'\n';
	else if(bd)
		cout<<1<<'\n'<<(ar[la] >= x ? ar[la] - x : ar[la] + y)<<'\n';
	else if(ba)
		cout<<1<<'\n'<<y<<'\n';
	else
		cout<<1<<'\n'<<x<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	