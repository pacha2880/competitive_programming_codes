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
		#define EPS			1e-9
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
			ll res;
			ll a,b;
			cin>>a>>b;
			int ar[6] = {0,1,2,3,2,1};
			if(a==1)
			{
					cout<<b-ar[b%6];
			}
			else
				if(b==1)
				{
					cout<<a-ar[a%6];
				}
			else
			if(a==2)
			{
				if(b<=2)
					cout<<0;
				else
				{
					if(b==7 or b==3)
						cout<<a*b-2;
					else
					{
					a=a*b-((a*b)&1ll);
					cout<<a;}
				}
			}
			else
				if(b==2)
				{
					if(a<=2)
						cout<<0;
					else
					{
						if(a ==7 or a ==3)
							cout<<a*b-2;
						else
							{
					a=a*b-((a*b)&1ll);
					cout<<a;}
					}
				}
				else
				{
					a=a*b-((a*b)&1ll);
					cout<<a;
				}

			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS