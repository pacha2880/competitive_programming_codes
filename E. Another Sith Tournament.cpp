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
		double posi[18][18], dp[18][1<<18];
		int n;
		double f(int mask, int sith)
		{
			if(mask + 1 == (1 << n) - 1) return posi[0][sith];
			if(dp[sith][mask] != -1) return dp[sith][mask];
			double res = 0,x;
			for(int i = 1; i < n; i++)
			{
				if((mask & (1<<i)) == 0)
				{
					x=posi[sith][i]*f((mask|(1<<i)),sith);
					x+=posi[i][sith]*f((mask|(1<<i)),i);
					res = max(res,x);
				}
			}
			dp[sith][mask] = res;
			return res;
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			for(int i = 0; i<18;i++)
				for(int j = 0; j<(1<<18);j++)
					dp[i][j]=-1;
			cin>>n;
			if(n==1)
			{
				cout<<1;
				return 0;
			}
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					cin>>posi[i][j];
				}
			double res = 0,x;
			for(int i = 1; i < n; i++)
			{
				x=f((1 << i), i);
				res = max(res, x);
			}
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS