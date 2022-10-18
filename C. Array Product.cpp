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
			int ar[n];
			vi ce;
			vii ne;	
			for(int i = 0;i<n;i++)
			{
				cin>>ar[i];
				if(ar[i]==0)
					ce.pb(i);
				else
					if(ar[i]<0)
					{
						ne.pb(mp(-ar[i],i));
					}
			}
			sort(ne.begin(),ne.end());
			bool el=false; int ig;
			if(ce.size()&1)
			{
				if(!(ne.size()&1))
				{
					el = true;
					ig=ce[0];
				}
				else
				{
					if(ce.size()>1)
					cout<<1<<' '<<ce[0]+1<<' '<<ce[1]+1<<endl;
					else
						ar[ce[0]]=1;
				}
			}
				if(ne.size()&1)
				{
					el = true;
					ig = ne[0].s;
				}
			if(el)
				cout<<2<<' '<<ig+1<<'\n';
			for(int i = ce.size()&1; i< (int)ce.size()-1;i++)
				cout<<1<<' '<<ce[i]+1<<' '<<ce[i+1]+1<<'\n';
			if(ce.size()>1&&!el&&ce.size()<n)
				cout<<2<<' '<<ce[ce.size()-1]+1<<endl;
			int fr = 0;
			while(fr==ig || ar[fr]==0)
				fr++;
			bool tr=false;
			for(int i=fr+1;i<n;i++)
			{
				if(i==ig&&el) continue;
				if(ar[i]==0) continue;
				cout<<1<<' '<<fr+1<<' '<<i+1<<'\n';
				fr = i;

			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS