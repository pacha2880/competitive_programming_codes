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
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int n,m,cn,cnn;
		cin>>n>>m;
		string s[n];
		int con[m];
		memset(con,0,sizeof(con));
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
			for(int j=0;j<m;j++)
			{
				if(s[i][j]=='1')
					con[j]++;
			}
		}
		for(int i=0;i<n;i++)
		{
			cn=0, cnn=0;
			for(int j =0; j<m;j++)
			{
				if(s[i][j]=='1')
				{
					cn++;
					if(con[j]>1)
						cnn++;
				}
			}
			if(cn==cnn)
			{
				cout<<"YES";
				return 0;
			}
		}
		cout<<"NO";
		return 0;
	}