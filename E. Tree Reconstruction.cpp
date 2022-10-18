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
			int ar[n],a,b;
			mem(ar,0);
			bool t=false;
			for(int i = 0; i < n-1; i++)
			{
				cin>>a>>b;
				if(a!=n&&b!=n)
					t=true;
				ar[a-1]++;
				ar[b-1]++;
			}
			vi v;
			if(t){cout<<"NO"; return 0;}
			for(int i = n-2;i>-1;i--)
				if(ar[i]==0)
					v.pb(i);
			vector<int> arr[n];
			int pos =0, ta=v.size();
			for(int i = n-2;i>-1;i--)
			{
				if(ar[i]>0)
				{
					for(int j = 1;j<ar[i];j++)
					{
						if(pos==ta)
						{
							cout<<"NO"; return 0;
						}
						if(i>v[pos])
							arr[i].pb(v[pos]);
						else
						{cout<<"NO"; return 0;}
						pos++;
					}
					arr[i].pb(i);
				}
			}
			int ax;
			cout<<"YES\n";
			for(int i =0;i<n;i++)
			{
				if(ar[i]>0)
				{
					ax = n;
					for(int j =0; j<arr[i].size();j++)
					{
						cout<<ax<<' '<<arr[i][j]+1<<'\n';
						ax = arr[i][j]+1;
					}
				}
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS 