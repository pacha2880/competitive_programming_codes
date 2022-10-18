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
		int n,a,b;
		cin>>n;
		ii v[n];
		for(int i=0;i<n;i++)
		{
			cin>>v[i].f>>v[i].s;
		}
		sort(v,v+n);
		a = v[0].s;
		for(int i=1;i<n;i++)
		{
			if(a>v[i].s)
			{
				cout<<"Happy Alex";
				return 0;
			}
			a= max(a,v[i].s);
		}
		cout<<"Poor Alex";
		return 0;
	}