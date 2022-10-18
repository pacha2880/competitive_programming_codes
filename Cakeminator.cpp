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
		int n,m;
		char c;
		cin>>n>>m;
		set<int> fil,col;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>c;
				if(c=='S')
				{
					fil.insert(i);
					col.insert(j);
				}
			}

			int con=0;
		bool mar[n][m];
		mem(mar,0);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(fil.find(i)==fil.end())
				{
					mar[i][j]=1;
					con++;
				}
			}
		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(!mar[i][j]&&col.find(j)==col.end())
					con++;
			}
		}
		cout<<con;
		return 0;
	}