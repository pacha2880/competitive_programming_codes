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
		ll pu[400040];
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n;
			cin>>n;
			map<ll,ll> ma,mb,add;
			set<ll> st;
			ll a,b;
			for(int i = 0; i < n; i++)
			{
				cin>>a>>b;
				if(a==b)
				{
					add[a]++;
				}
				else
				{
					ma[a]++;
					mb[b]++;
				}
					st.insert(a);
					st.insert(b);	
				
			}
			set<ll>::iterator it;
			ll con = 0,me=0,la=-1;
			memset(pu,0,sizeof(pu));
			for(it = st.begin();it!=st.end();it++)
			{
				if(la!=-1&&con>0)
					pu[con-1]+=*it-la-1;
				pu[ma[*it]+max(mb[*it],con)-1+add[*it]]++;
				con+=ma[*it];
				con-= mb[*it];
				la = *it;
			}
			for(int i = 0; i < n; i++)
			{
				if(i>0) cout<<' ';
				cout<<pu[i];
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS