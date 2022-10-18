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
		int n,p;
		string s;
		cin>>n>>p>>s;
		bool t = false;
		char con;
		for(int i = 0; i < n - p; i++)
		{
			if(s[i]== '.')
			{
				if(s[i+p] == '.')
				{
					s[i]='1';
					s[i+p]='0';
				}
				else
				{
					if(s[i+p]=='1')
						s[i]='0';
					else
						s[i]='1';
				}
				t = true;
			}
			else
			{
				if(s[i]=='0')
					con = '1';
				else
					con='0';
				if(s[i+p]=='.')
				{
					s[i+p]=con;
					t = true;
				}
				else
				{
					if(s[i+p]==con)
						t = true;
				}
			}
		}
		for(int i = 0;i<n;i++)
			if(s[i]=='.')
				s[i]='0';
		if(t)
			cout<<s;
		else
			cout<<"No";	
		return 0;
	}