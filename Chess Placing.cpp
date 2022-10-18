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
		int n,x=0,y=0;
		cin>>n;
		int a[n/2];
		for(int i = 0;i<n/2;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n/2);
		for(int i=1;i<=n/2;i++)
		{
			x+=abs(i*2-a[i-1]);
			y+=abs(i*2-1-a[i-1]);
		}
		cout<<min(x,y);
		return 0;
	}