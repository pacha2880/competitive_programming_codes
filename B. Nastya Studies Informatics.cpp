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
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		ll l,r,x,y;
		cin>>l>>r>>x>>y;
		y/=x;
		ll res = 0;
		ll we = sqrt(y);
		for(ll i = 1ll;i<=we;i++)
		{
			if(y%i==0)
			{
				ll con = y/i;
				if(i*x>=l&&i*x<=r&&con*x>=l&&con*x<=r&&i==con)
				{
					res++;
				}
				if(__gcd(con,i)==1ll&&(con>1ll))
				if(i*x>=l&&i*x<=r&&con*x>=l&&con*x<=r)
				{
					res+=2ll;
				}
			}
		}
		cout<<res;
		return 0;
	}