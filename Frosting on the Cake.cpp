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
			int n;
			ll ce=0,un=0,dos=0,a=0,b=0,c=0,ax;
			cin>>n;
			for(int i = 1; i<=n;i++)
			{
				cin>>ax;
				if(i%3==0)
					ce+=ax;
				if(i%3==1)
					un+=ax;
				if(i%3==2)
					dos+=ax;
			}
			for(int i = 1; i<=n;i++)
			{
				cin>>ax;
				if(i%3==0)
				{
					a+=ax*ce;
					b+=ax*un;
					c+=ax*dos;
				}
				if(i%3==1)
				{
					a+=ax*dos;
					b+=ax*ce;
					c+=ax*un;
				}
				if(i%3==2)
				{
					a+=ax*un;
					b+=ax*dos;
					c+=ax*ce;
				}
			}
			cout<<a<<' '<<b<<' '<<c<<endl;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS