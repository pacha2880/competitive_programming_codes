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
			int n;
			cin>>n;
			map<int,int> ma;
			set<int> st;
			int ar[n];
			for(int i = 0;i<n;i++)
			{
				cin>>ar[i];
				st.insert(ar[i]);
				ma[ar[i]]++;
			}
			ll res = 0;
			bool used[n];
			mem(used,1);
			for(int i = 0;i<n;i++)
			{
					ma[ar[i]]--;
					if(ma[ar[i]]==0)
						st.erase(ar[i]);
					if(used[ar[i]])
					{
						res+=(ll)st.size();
						used[ar[i]]=0;
					}
			}
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS