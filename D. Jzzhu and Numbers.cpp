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
		int N = 20;
		ll pot(ll b, ll e)
		{
			if(e == 0ll) return 1ll;
			return (pot((b*b)%MOD,e/2)*(e&1?b:1))%MOD;
		}

			ll ar[1<<20],po[1<<20]; 
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,a,ma=0;
			cin>>n;
			mem(ar,0);
			po[0]=1;
			for(int i = 1;i<(1<<N);i++) po[i]=(po[i-1]*2ll)%MOD;
				int arr[n];
			for(int i = 0;i<n;i++)
			{
				cin>>arr[i];
				ma = max(ma,arr[i]);
			}
			N = log2(ma)+1;
			for(int i = 0;i<n;i++)
			{
				ar[(1<<N)-1-arr[i]]++;
			}
			for(int i = 0; i < N; i++) for(int mask = 0; mask <= (1 << N); mask++)
			{
				if(mask & (1 << i))
				{
					ar[mask] += ar[mask ^ (1 << i)];
					ar[mask] %=MOD;
				}
			}
			ll res = 0;
			for(int i = 0;i<(1<<(N-1));i++)
			{
				swap(ar[i],ar[(1<<N)-i-1]);
			}
			for(int i = 0; i < (1<<N); i++)
			{
				res+=((__builtin_popcount(i)&1?-1ll:1ll)*(po[ar[i]]-1));
				res%=MOD;
			}
			cout<<(res%MOD +MOD)%MOD;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS