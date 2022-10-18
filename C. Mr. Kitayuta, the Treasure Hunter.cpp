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
		vector<int> dp[30002];
		int ar[30002],gem[30002],
		n,mini,maxi;
		int f(int pos, int tam)
		{
			if(pos > ar[n-1] || tam == 0)
				return 0;
			if(dp[pos][tam-mini] != -1) return dp[pos][tam-mini];
			int res ;
			res = f(pos+tam-1,tam-1) + gem[pos];
			res = max(res,f(pos+tam,tam) + gem[pos]);
			res = max(res,f(pos+tam+1,tam+1) + gem[pos]);
			return dp[pos][tam-mini] = res;
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int d;
			cin>>n>>d;
			mem(gem,0);
			maxi = d, mini = d;
			int start = d;
			while(start<=30001)
			{
				maxi++;
				start += maxi;
			}
			start=d;
			while(start<=30001)
			{
				mini--;
				if(mini == 0) break;
				start += mini;
			}
			
			vector<int> v(maxi-mini+1,-1);
			for(int i = 0; i < n; i++)
			{
				cin>>ar[i];
				gem[ar[i]]++;
			}
			for(int i = 0; i< 30002; i++)
				dp[i] = v;
			cout<<(f(d,d));
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS