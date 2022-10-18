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
		int n,m,k;
		cin>>n>>m>>k;
		int last = 0;
		int blo[n],lib[3*n],prec[k];
		mem(lib,-1);
		bool bloc[3*n];
		mem(bloc,0);
		for(int i = 0;i<m;i++)
		{
			cin>>last;
			bloc[last]=true;
		}
		last = 0;
		for(int i = 0;i<3*n;i++)
		{
			if(!bloc[i]) 
				last = i;
			lib[i] = last;

		}
		bool t,tt=false;
		ll con,ax,res=LLONG_MAX;
		for(int i = 1; i <= k; i++)
		{
			cin>>ax;
			con = 0;
			t = true;
			int j = 0;
			while(j<n)
			{
				if(bloc[j+i])
				{
					if(lib[j+i]==j)
					{
						t = false;
						break;
					}
						j = lib[j+i];
				}
				else
					j+=i;
				con++;
			}
			if(t)
			{
				tt = true;
				res = min(res,con*ax);
			}
		}
		if(bloc[0]) 
		{
			cout<<-1;
			return 0;
		}
		if(tt)
			cout<<res;
		else
			cout<<-1;
		return 0;
	}