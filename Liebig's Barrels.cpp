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
		int n,k;
		ll l,su=0;
		cin>>n>>k>>l;
		int ta = n*k;
		ll num[ta];
		for(int i=0;i<ta;i++)
			cin>>num[i];
		sort(num,num+ta);
		int po=ta;
		for(int i=1;i<ta;i++)
		{
			if(num[i]-num[0]>l)
				{
					po = i;
					break;

				}
		}
		if(po<n)
		{
			cout<<0;
			return 0;
		}
		int fal = n;
		for(int i = 0;i<po;i++)
		{
			su+=num[i];
			if(po-fal>i)
			{
				i+=k-1;
				if(i>=po-fal)
					i = po-fal;
			}
			fal--;
 
		}
		cout<<su;
		return 0;
	} 		