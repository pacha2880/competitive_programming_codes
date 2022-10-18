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
			int n,m;
			cin>>n>>m;
			vi dife;
			int ara[n],arb[m];
			map<int,int>::iterator it;
			map<int,int> ma;
			for(int i = 0;i<n;i++)
			{
				cin>>ara[i];
			}
			for(int i = 0; i < m;i++)
			{
				cin>>arb[i];
			}
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<m;j++)
				{
					if(arb[j]>=ara[i])
						ma[arb[j]-ara[i]]++;
				}
			}
			ii res = mp(-1,-1000000009);
			for(it=ma.begin();it!=ma.end();it++)
				res=max(res,mp(it->second,-it->first));
			cout<<(res.s>-1000000001?-res.s:0)<<endl;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS