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
			ll res=1;
			map<int,ll> ma;
			int ar[n],in;

			for(int i = 0; i<n;i++)
			{
				cin>>ar[i];
				if(ar[i]==m)
					in = i;
			}
			ma[0]++;
			int con = 0;
			for(int i = in+1; i<n;i++)
			{
				if(ar[i]>m)
					con++;
				else
					con--;
				ma[con]++;
				res+=(con==0||con==1);
			}
			con=0;
			for(int i = in-1;i>-1;i--)
			{
				if(ar[i]>m)
					con++;
				else
					con--;
				res+=ma[0-con];
				res+=ma[1-con];
			}
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS