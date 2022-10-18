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
			char voc[] = {'a','e','i','o','u'};
			string s;
			cin>>s;
			s+='w';
			bool con;
			for(int i = 0; i<s.size()-1;i++)
			{
				if(s[i]=='n') continue;
				con=1;
				for(int j = 0; j<5;j++)
				{
					if(s[i]==voc[j])
					{
						con=0;
						break;
					}
				}
				if(con)
				{
					for(int j = 0; j<5;j++)
					{
						if(s[i+1]==voc[j])
						{
							con = 0;
							break;
						}
					}
					if(con)
					{
						cout<<"NO";
						return 0;
					}
				}
			}
			cout<<"YES";
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS