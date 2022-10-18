			#include <bits/stdc++.h>
		#define PI 			acos(-1)
		#define mp			make_pair
		#define pb			push_back
		#define all(a)		(a).begin(), (a).end()
		#define srt(a)			sort(all(a))
		#define mem(a, h)	memset(a, (h), sizeof(a))
		#define f 			first
		#define s 			second
		#define MOD			998244353
		int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

		using namespace std;

		typedef long long 		ll;
		typedef unsigned long long 		ull;
		typedef pair<int, int>  ii;
		typedef vector<int>     vi;
		typedef vector<ii>      vii;
		typedef vector<ll>      vll;
		ll pas[1010][1010];
		void pascal()
		{
			memset(pas,0,sizeof(pas));
			for(int i = 0; i < 1010;i++)
				pas[i][0]=1;
			for(int i = 1;i<1010;i++)
				for(int j = 1; j<=i;j++)
					pas[i][j] = (pas[i-1][j]+pas[i-1][j-1])%MOD;
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			pascal();
			int n;
			cin>>n;
			int num[n];
			for(int i = 0;i <n;i++)
				cin>>num[i];
			ll pos[n];
			mem(pos,0);
			for(int i = n-2;i>=0;i--)
			{
				pos[i]=pos[i+1];
				if(num[i]>0&&i+num[i]<n)
				{
					for(int j = i+num[i];j<n-1;j++)
					{
						pos[i]+=pas[j-i-1][num[i]-1]*(pos[j+1]==0?1:pos[j+1]+1);
						pos[i]%=MOD;
					}
					pos[i]+=pas[n-2-i][num[i]-1];
					pos[i]%=MOD;
				}
			}
			cout<<pos[0];
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS