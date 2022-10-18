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
		ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		ll p = 1;
		vector<ll> po;
		while(p<6000000000)
		{
			po.pb(p);
			p*=2ll;
		}
		int n;
		cin>>n;
		ll num[n];
		map<int,bool> mp;
		for(int i=0;i<n;i++)
			{
				cin>>num[i];
				mp[num[i]]=true;
			}
		sort(num,num+n);
		int res = 1;
		vll ress;
		ress.pb(num[0]);
		for(int i=0;i<n;i++)
		{
			int j=0;
			while(num[i]+po[j]<=1000000000ll)
			{
				if(mp[num[i]+po[j]])
				{
					if(res == 1)
					{
						res = 2;
						ress.clear();
						ress.pb(num[i]);
						ress.pb(num[i]+po[j]);
					}
					if(mp[num[i]+po[j+1]]&&res == 2)
					{
						res = 3;
						ress.clear();
						ress.pb(num[i]);
						ress.pb(num[i]+po[j]);	
						ress.pb(num[i]+po[j+1]);	
					}
				}
				j++;
			}
		}
		cout<<res<<endl;
		for(int i=0;i<res;i++)
		{
			if(i>0)
				cout<<' ';
			cout<<ress[i];
		}
		return 0;
	}