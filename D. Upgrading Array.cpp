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
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
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
vector<int> pri;
vector<int> pric;
bitset<tam> bi;
criba()
{
	bi.set();
	fore(i, 2, tam)
	{
		if(bi[i])
		{
			pri.pb(i);
			pric.pb(i * i);
			forg(j, 1ll * i * i, tam, i)
			{
				bi[j] = 0;
			}
		}
	}
}
set<int> bad;
int f(int n)
{
	int res = 0;
	int au;
	for(int i = 0; pric[i] <= n; i++)
	{
		if(n % pri[i] == 0)
		{
			au = bad.count(pri[i]) ? -1 : 1;
			while(n % pri[i] == 0)
			{
				res += au;
				n /= pri[i];
			}
		}
	}
	if(n > 1)
		res += bad.count(n) ? -1 : 1;
	return res;
}
int num[5050], gs[5050];
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int g = 0;
	fore(i, 0, n)
	{
		cin>>num[i];
		g = __gcd(g, num[i]);
		gs[i] = g;
	}
	fore(i, 0, m)
	{
		cin>>g;
		bad.insert(g);
	}
	g = 1;
	int con, res = 0;
	criba();
	for(int i = n - 1; i > -1; i--)
	{
		gs[i] /= g;
		num[i] /= g;
		con = f(gs[i]);
		if(con < 0)
		{
			g *= gs[i];
			num[i] /= gs[i];
		}
		res += f(num[i]);
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	