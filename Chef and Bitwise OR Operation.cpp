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
	int n,k;
	ll arr[5050],sum[5050][5050];

	ll dp(int pos, int left,ll sum)
	{
		if(pos == n) return sum;
		if(sum[pos][left] != -1) return sum[pos][left];
		
	}

	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int m;
		cin>>m;
		while(m--)
		{
			cin>>n>>k;
			memset(sum,-1,sizeof(sum));
			for(int i = 0; i < n; i++)
			{
				cin>>arr[i];
			}
			cout<<dp(1,k-1,arr[0])<<endl;
		}
		return 0;
	}