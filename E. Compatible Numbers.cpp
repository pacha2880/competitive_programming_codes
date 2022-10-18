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
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n;
			cin>>n;
			if(n==1) {cout<<-1; return 0;}
			int ar[n],ma = 0;
			for(int i = 0; i < n; i++)
			{
				cin>>ar[i];
				ma = max(ma,ar[i]);
			}
			int N = ceil(log2(ma)) + 1;
			ll arr[1<<N];
			int ind[1<<N];
			memset(ind,-1,sizeof(ind));
			memset(arr,0,sizeof(arr));
			for(int i = 0; i < n; i++)
			{
				arr[ar[i]]++;
				ind[ar[i]]=ar[i];
			}
			for(int i = 0; i < N; i++) for(int mask = 0; mask < (1 << N); mask++)
			{
				if(mask & (1 << i))
				{
					arr[mask] += arr[mask ^ (1 << i)];
					if(ind[mask ^ (1 << i)]!=-1)
					{
						ind[mask] = ind[mask ^ (1 << i)];
					}
				}
			}
			for(int i = 0; i < n; i++)
			{
				if(i>0) cout<<' ';
				cout<<ind[(1<<N)-1-ar[i]];
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS