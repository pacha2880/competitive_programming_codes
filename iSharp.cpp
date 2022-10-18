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
			string s,ori,pru;
			bool t = false;
			int pos;
			while(cin>>s)
			{
				if(t) cout<<endl;
				t=true;
				ori = s;
				while(true)
				{
					cin>>s;
					pru = ori;
					pos = s.size()-1;
					for(int i = s.size()-2;s[i]==']'||s[i]=='*'||s[i]=='&';i--)
					{
						if(s[i]==']')
						{
							i--;
							ori+="[]";
						}
						else
							ori+=s[i];
						pos=i;
					}
					cout<<ori<<' '<<s.substr(0,pos)<<';'<<'\n';
					ori = pru;
					if(s[s.size()-1]==';') break;
				}
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS