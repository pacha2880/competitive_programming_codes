#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n,h;
	cin>>n>>h;
	ll ar[n],arr[n];

	for(ll i = 0; i < n; i++)
	{
		cin>>ar[i];
		arr[i] = ar[i];
	}
	ll su, res = 0;
	for(ll i = 0; i < n; i +=2)
	{
		for(ll i = 0; i < n; i++)
			ar[i] = arr[i];
		if(i < n-1)
		{
			su = 0;
			sort(ar,ar+i+2);
			for(ll j = 1; j < i + 2; j+=2)
			{
				su += ar[j];
			}
			//cout<<su<<' ';
			if(su <= h)
				res = max(res, i+2);
		}
		for(ll i = 0; i < n; i++)
			ar[i] = arr[i];
			sort(ar,ar+i+1);
			su = 0;
			for(ll j = 0; j < i ; j+=2)
			{
				su += ar[j];
			}
			su += ar[i];
			//cout<<su<<endl;
			if(su <= h)
				res = max(res, i+1);
	
	}
	if(n&1)
	{
			sort(ar,ar+n);
			su = 0;
			for(ll j = 0; j < n-1 ; j+=2)
			{
				su += ar[j];
			}
			su += ar[n-1];
			//cout<<su<<endl;
			if(su <= h)
				res = max(res, n);
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS