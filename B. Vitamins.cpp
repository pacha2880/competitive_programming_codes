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
			int n;
			cin>>n;
			int a = 1000000,ab=1000000,abc=1000000,bc=1000000,ac=1000000,b=1000000,c=1000000;
			int p;
			string s;
			bool A,B,C;
			while(n--)
			{
				A=false, B=false, C=false;
				cin>>p>>s;
				for(int i =0;i<s.size();i++)
				{
					A |= s[i] =='A' ;
					B |= s[i] == 'B';
					C |= s[i] == 'C';
				}
				if(A)
				{
					if(B)
					{
						if(C)
						{
							abc = min(abc,p);
							a = min(a,p);
							ab=min(ab,p);
							ac = min(ac,p);
								bc = min(bc,p);
								b = min(b,p);
							c = min(c,p);
						}
						else
						{
							ab=min(ab,p);
							a = min(a,p);
								b = min(b,p);
						}
					}
					else
					{
						if(C)
						{
							ac = min(ac,p);
							a = min(a,p);
							c = min(c,p);
						}
						else
							a = min(a,p);
					}
				}
				else
					{
						if(B)
							if(C)
							{
								bc = min(bc,p);
								b = min(b,p);
							c = min(c,p);
							}
							else
								b = min(b,p);
						else
							c = min(c,p);
					}
			}
			int res = min(a+b+c,min(a+bc,min(b+ac,min(c+ab,abc))));
			if(res>=1000000)
				cout<<-1;
			else
				cout<<res;		
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS