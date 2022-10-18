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
			int n;
			cin>>n;
			ll ar[n];
			ll s=0,mi=MOD,ma=-MOD,nu;
			bool po = false, ne=false;
			if(n==1)
			{
				cin>>nu;
				cout<<nu;
				return 0;
			}
			for(int i = 0;i<n;i++)
			{
				cin>>nu;
				s += abs(nu);
				mi = min(mi,nu);
				ma = max(ma,nu);
				if(nu>0) po = true;
				if(nu<0) ne = true;
			}
			if(ne&&po)
				cout<<s;
			else
				if(ne)
					cout<<s+2*ma;
				else
					cout<<s-2*mi;

			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSSD. SlimeD. Slime