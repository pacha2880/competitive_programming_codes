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
			int n,a,b;
			cin>>n>>a>>b;
			if((a!=1&&b!=1)||(a==1&&b==1&&n<4&&n>1))
			{
				cout<<"NO";
			}
			else
			{
				if(n==1)
				{
					cout<<"YES"<<endl<<0;
					return 0;
				}
				cout<<"YES"<<endl;
				int mat[n][n];
				memset(mat,0,sizeof(mat));
				if(b==1)
				{
					for(int i = 0;i<n-a;i++)
					{
						mat[i][i+1]=1;
						mat[i+1][i]=1;
					}
				}
				else
				{
					for(int i = 0; i < b-1; i++)
					{
						for(int j = i+1;j<n;j++)
						{
							mat[i][j]=1;
							mat[j][i]=1;
						}
					}
				}
				for(int i = 0; i<n;i++)
				{
					for(int j = 0;j<n;j++)
						cout<<mat[i][j];
					cout<<endl;
				}
			}
			return 0;
		}