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
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		ll n,h,pr;
		cin>>n>>h;
		ll lo = 1,d=2,u=1,hi = sqrt(d*n),mid,res;
		while(lo<=hi)
		{
			mid = (lo+hi)/d;
			if((hi<=h?mid*(mid+u)/d<=n:mid*(mid+u)-mid-h*(h-u)/d<=n))
			{
				res = mid;
				lo = mid +1;
			}
			else
				hi = mid - 1;
		}
		mid = n-(res<=h?res*(res+u)/d:res*(res+u)-res-h*(h-u)/d);
		bool t = false;
		if(mid-res>0) t = true; 
		if(res>h)
			res = 2*res-h;
		if(mid)
			res++;
		if(t)
			res++;
		cout<<res;
		return 0;
	}