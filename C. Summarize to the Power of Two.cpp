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
			int po[31];
			po[0]=1;
			for(int i = 1;i<31;i++)
				po[i]=po[i-1]*2;
			int n;
			cin>>n;
			if(n==0)
			{
				cout<<0;
				return 0;
			}
			if(n==1)
			{
				cout<<1;
				return 0;
			}
			int ar[n];
			map<int,int> st;	
			for(int i = 0; i<n;i++)
			{
				cin>>ar[i];
				st[ar[i]]++;
			}
			bool t;	
			int el=0;
			for(int i = 0; i<n;i++)
			{
				t=false;
				for(int j = 0; j<31;j++)
				{
					if(st[po[j]-ar[i]])
					{
						if(!(po[j]-ar[i]==ar[i]&&st[ar[i]]==1))
						{

						t=true;
						break;	
						}
					}
				}
				if(!t)
				{
					el++;
				}
			}
			cout<<el;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS