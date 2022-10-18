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
		int ar[300040],ma[15000050];
		vi pri;
		bitset<20000000> bi;
		void criba()
		{
			bi.set();
			bi[0]=bi[1]=0;
			for(int i = 2;i*i<16000010;i++)
			{
				if(bi[i])
				{
					for(int j = i+i; j<16000010;j+=i)
						bi[j]=0;
					pri.pb(i);
				}
			}
		}
		int main()
		{
			ios::sync_with_stdio(false);
    cin.tie(0);

			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n;
			int g =0;
			mem(ma,0);
			criba();
			cin>>n;
			int pos =0;
			for(int i =0;i<n;i++)
			{
				cin>>ar[i];
				g = __gcd(g,ar[i]);
			}
			for(int i =0;i<n;i++)
			{
				ar[i]/=g;
			}
			int res = 0;
			for(int i =0;i<n;i++)
			{
				pos=0;
				if(bi[ar[i]])
				{
					ma[ar[i]]++;
				}
				else
				{
					for(int j = 0; pri[j]*pri[j] <= ar[i];j++)
					{
						if(ar[i]%pri[j]==0)
						{
							ma[pri[j]]++;
							while(ar[i]%pri[j]==0)
								ar[i]/=pri[j];
						}
					}	
					if(ar[i]>1) ma[ar[i]]++;
				}
			}
			for(int it = 0;it<15000005;it++)
			{
				res = max(res,ma[it]);
			}
			if(res==0) cout<<-1;
			else
				cout<<n-res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS