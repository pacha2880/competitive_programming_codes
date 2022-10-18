		#include <bits/stdc++.h>
	#define PI 			acos(-1)
	#define mp			make_pair
	#define pb			push_back
	#define all(a)		(a).begin(), (a).end()
	#define srt(a)			sort(all(a))
	#define mem(a, h)	memset(a, (h), sizeof(a))
	#define f 			first
	#define s 			second
	#define MOD			1000000007
	int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

	using namespace std;

	typedef long long 		ll;
	typedef unsigned long long 		ull;
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	ll pot(ll b,ll e)
	{
		if(e == 0ll) return 1ll;
		return (pot((b*b)%1000000007ll,e/2ll)*(e&1?b:1ll))%1000000007ll;
	}
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		ll x,k;
		cin>>x>>k;
		if(x == 0)
			cout<<0;
		else
			if(k == 0)
				cout<<((2*x)%1000000007ll);
		else
		{
			ll res = (x*2-1)%1000000007ll;
			res = (res*pot(2,k-1))%1000000007ll;
			res = (res*2+1)%1000000007ll;
			cout<<res;
		}
		return 0;
	}