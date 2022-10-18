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
				string a;
				char t = '0', c;
				cin>>a;
				int sum = 0,res=0,par;
				bool mo1=false,mo2=false;
				for(int i = 0; i< a.size(); i++)
				{
					c = a[i]-t;
					sum +=c;
					par = c;
					if(sum % 3 == 0 || par%3==0)
					{
						res++;
						sum = 0;
						mo1=0;
						mo2=0;
					}
					else
					if(sum%3==1&&mo1||sum%3==2&&mo2)
					{
						res++;
						sum=0;
						mo1=0;
						mo2=0;
					}
					else
					{
					if(par%3==1)
						mo1=true;
					if(par%3==2)
						mo2=1;}
				}
				cout<<res;
				return 0;
			}

		// read the question correctly (is y a vowel? what are the exact constraints?)
		// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS