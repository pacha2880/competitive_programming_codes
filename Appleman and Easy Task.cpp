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
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int n;
		cin>>n;
		char bor[n+2][n+2];
		int con;
		mem(bor,1);
		for(int i=1;i<n+1;i++)
			for(int j=1;j<n+1;j++)
				cin>>bor[i][j];
		for(int i =1;i<n+1;i++)
			for(int j=1;j<n+1;j++)
			{
					con=0;
					if(bor[i+1][j]=='o')
						con++;
					if(bor[i][j-1]=='o')
						con++;
					if(bor[i][j+1]=='o')
						con++;
					if(bor[i-1][j]=='o')
						con++;
					if(con&1)
					{
						cout<<"NO";
						return 0;
					}
			}
			cout<<"YES";
		return 0;
	}