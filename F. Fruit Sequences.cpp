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
const ll tam = 500010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

pair<ll, ll> cuans[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll su = 0, va = 0, me = 0;
	pair<ll, ll> mo;
	fore(i, 0, n)
	{
		if(s[i] == '1')
		{
			mo = cuans[me];
			va += mo.s * (me + 1) - mo.f + me + 1;
			cuans[me + 1].f += mo.s * (me + 1);
			cuans[me + 1].s += mo.s;
			cuans[me] = {0, 0};
			me++;
		}
		else
		{
			fore(i, 0, me + 1)
			{
				cuans[i].f += i;
				cuans[i].s++;
			}
			me = 0;
		}
		su += va;
	}
	cout<<su<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	