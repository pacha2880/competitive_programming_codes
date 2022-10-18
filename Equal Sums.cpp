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
		cin>>n;
		map<ll,bool> mp;
		ll ax;
		map<ll,pair<int,int> > mpp;
		bool t = true;
		for(int k=1;k<=n;k++)
		{
			cin>>m;
			ll arr[m];
			ll sum=0;
			for(int i=0;i<m;i++)
			{
				cin>>arr[i];
				sum+=arr[i];
			}
			if(t)
			{
				for(int i=1;i<=m;i++)
				{
					ax = sum-arr[i-1];
					if(mp[ax]&&k!=mpp[ax].f)
					{
						cout<<"YES"<<endl<<mpp[ax].f<<' '<<mpp[ax].s<<endl
							<<k<<' '<<i;
						t = false;
						break;
					}
					mp[ax]=true;
					mpp[ax].f=k;
					mpp[ax].s=i;
				}
			}
		}
		if(t)
			cout<<"NO";
		return 0;
	}