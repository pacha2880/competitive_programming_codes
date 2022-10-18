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
const int tam = 86400;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
ll pot(ll b, ll e, ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	ll x, y, fi, m, re, be, e;
	while(n--)
	{
		cin>>x>>y;
		m = pot(10, y, MOD);
		fi = m / 10 * 4;
		re = pot(x, fi, m), be = 1;
		ll mini = re;
		for(int i = 1; i <= min(86400ll, fi-1); i++)
		{
			//cout<<"asdas"<<i<<' '<<be<<' '<<x<<' '<<m<<' '<<mini<<'\n';;
			be =  be * x % m;
			mini = min(mini, re * be % m);
		}
		cout<<mini<<'\n';
	}
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2