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
		int n,m;
		cin>>n>>m;
		if(n>m)
		{
			cout<<6-n+1+(n-m-1)/2<<' '<<!((n-m)&1)<<' '<<m+(n-m-1)/2;
		}
		else
			if(m>n)
			{
				cout<<n+(m-n-1)/2<<' '<<!((m-n)&1)<<' '<<6-m+1+(m-n-1)/2;
			}
			else
				cout<<"0 6 0";
		return 0;

	}