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
		int ar1[100010], ar2[100010];
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,m,a,cp=0,ci=0,cpp=0,cii=0;
			int pot[30];
			pot[0]=1;
			for(int i=1;i<30;i++)
				pot[i]=2*pot[i-1];
			map<int,int> ma1[30], ma2[30];
			cin>>n>>a;
			for(int i =0;i<n;i++)
			{
				cin>>ar1[i];
				for(int j=1;j<30;j++)
					ma1[j][ar1[i]%pot[j]]++;
			}
			cin>>m>>a;
			for(int i =0;i<m;i++)
			{
				cin>>ar2[i];
				for(int j=1;j<30;j++)
					ma2[j][ar2[i]%pot[j]]++;
			}
			if(n+m==2) {cout<<2; return 0;}
			map<int,int>::iterator it;
			int res = 0;
			for(int i = 1; i < 30; i++)
			{
				for(it = ma1[i].begin(); it != ma1[i].end(); it++)
				{
					res = max(res,it->second+ma2[i][it->first+pot[i-1]]);
				}
				for(it = ma2[i].begin(); it != ma2[i].end(); it++)
				{
					res = max(res,it->second+ma1[i][it->first+pot[i-1]]);
				}
			}
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS