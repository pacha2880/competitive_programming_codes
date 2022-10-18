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
			double d = 0,X=0,Y=0;
			vector<pair<pair<double,int>,pair<double,double> > > v(n);
			int res[n];
			for(int i = 0;i<n;i++)
			{
				cin>>v[i].s.f>>v[i].s.s;
				v[i].f.f = sqrt(v[i].s.f*v[i].s.f+v[i].s.s*v[i].s.s);
				v[i].f.s = i;
			}
			for(int i = 0; i < n; i++)
			{
				if(sqrt((X+v[i].s.f)*(X+v[i].s.f)+(Y+v[i].s.s)*(Y+v[i].s.s))>sqrt((X-v[i].s.f)*(X-v[i].s.f)+(Y-v[i].s.s)*(Y-v[i].s.s)))
				{
					res[v[i].f.s]=-1;
					X-=v[i].s.f;
					Y-=v[i].s.s;
				}
				else
				{
					res[v[i].f.s]=1;
					X+=v[i].s.f;
					Y+=v[i].s.s;
				}
			}
			if(sqrt(X*X+Y*Y)<=1500000.0)
			{
				for(int i = 0; i<n;i++)
				{
					cout<<res[i];
					if(i<n-1)
						cout<<' ';
				}
				return 0;
			}
			X=0,Y=0;
			sort(v.begin(),v.end());
			for(int i = 0; i < n; i++)
			{
				if(sqrt((X+v[i].s.f)*(X+v[i].s.f)+(Y+v[i].s.s)*(Y+v[i].s.s))>sqrt((X-v[i].s.f)*(X-v[i].s.f)+(Y-v[i].s.s)*(Y-v[i].s.s)))
				{
					res[v[i].f.s]=-1;
					X-=v[i].s.f;
					Y-=v[i].s.s;
				}
				else
				{
					res[v[i].f.s]=1;
					X+=v[i].s.f;
					Y+=v[i].s.s;
				}
			}
			for(int i = 0; i<n;i++)
			{
				cout<<res[i];
				if(i<n-1)
					cout<<' ';
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS