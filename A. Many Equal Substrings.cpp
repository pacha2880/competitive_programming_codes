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
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int a,b;
			cin>>a>>b;
			string s, res;
			cin>>s;
			int from = -1;bool t;			if(a>1)
			{
				for(int i = 1;i<a;i++)
				{
					t=true;
					for(int j = i;j<a;j++)
					{
						if(s[j-i]!=s[j])
						{
							t=false;
							break;
						}
					}
					if(t)
					{
						from = i;
						break;
					}
				}
				if(from!=-1)
				{
					cout<<s;
					b--;
					while(b--)
						cout<<s.substr(a-from);
				}
				else
				{
					while(b--)
						cout<<s;
				}

			}
			else
				while(b--)
					cout<<s;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS