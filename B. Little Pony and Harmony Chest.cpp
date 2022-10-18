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
		int v[100], mask[60], dp[100][1<<17],print[100][1<<16], n;
		bitset<60> pri;
		void primos()
		{
			mem(mask,0);
			pri.set();
			int con=-1;
			for(int i = 2; i < 57; i++)
			{
				if(pri[i])
				{
					con++;
					for(int j = i+i; j < 57; j+=i)
					{
						mask[j]|=(1<<con);
						pri[j]=0;
					}
					mask[i]|=(1<<con);
				}
			}
		}
		int f(int pos, int mascara)
		{
			if(pos == n)
				return 0;
			if(dp[pos][mascara]!=-1) return dp[pos][mascara];
			int mini = INT_MAX,par;
			for(int i = 1; i < 57; i++)
			{
				if((mask[i]&mascara) == 0)
				{
					par = abs(v[pos] - i)+ f(pos + 1, (mask[i] | mascara));
					if(mini>par)
					{
						mini = par;
						print[pos][mascara] = i;
					}
				}
			}
			dp[pos][mascara]=mini;
			return mini;
		}

		void imprime(int pos, int mascara)
		{
			if(pos == n)
				return;
			cout<<print[pos][mascara]<<' ';
			imprime(pos + 1,mascara|mask[print[pos][mascara]]);
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			cin>>n;
			primos();
			for(int i = 0; i < n; i++)
				cin>>v[i];
			mem(dp,-1);
			f(0,0);
			imprime(0,0);
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS