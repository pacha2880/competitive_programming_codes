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

		typedef long long 		all;
		typedef unsigned long long 		ll;
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
			ll k;
			cin>>n>>k;
			ll ar[n], pot[11];
			pot[0]=1;
			for(int i = 1; i<11;i++)
				pot[i]=pot[i-1]*10ull;
			map<ll,ll> modus[10];
			for(int i = 0;i<n;i++)
			{
				cin>>ar[i];
				modus[(int)log10(ar[i])][ar[i]%k]++;
			}
			ll res =0;
			for(int i = n-1;i>-1;i--)
			{
				for(int j=0;j<10;j++)
				{
					ll e = (k-(ar[i]*pot[j+1])%k)%k;
					res += modus[j][e];
					if((int)log10(ar[i])==j)
						if(e==ar[i]%k)
							res--;
				}
			}
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS