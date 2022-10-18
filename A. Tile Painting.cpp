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
bitset<1000000> bi;
vector<ll> pri, pric;
void criba()
{
	bi.set();
	fore(i, 2, 1000000)
	{
		if(bi[i])
		{
			forg(j, i, 1000000, i)
				bi[j] = 0;
			pri.pb(i);
			pric.pb(i * (ll)i);
		}
	}
}
ll fac(ll n)
{
	ll con = 0, val =  -1;
	for(int i = 0; pric[i] <= n; i++)
	{
		if(n % pri[i] == 0)
		{
			if(con > 0)
				return 1;
			con++;
			val = pri[i];
			while(n % pri[i] == 0)
			{
				n /= pri[i];
			}
		}
	}
	if(n > 1)
	{
		if(con > 0)
			return 1;
		val = n;
	}
	return val;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n;
	cin>>n;
	criba();
	ll a;
	if(n == 1)
	{
		cout<<1<<'\n';
	}
	else
	{
		//cout<<"chacah";

		cout<<fac(n)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2