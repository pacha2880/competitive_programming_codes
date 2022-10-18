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
		pair<int,string> p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].s;
			p[i].f=p[i].s.size();
		}
		sort(p,p+n);
		bool t;
		for(int i=1;i<n;i++)
		{
			t = true;
			for(int j=0;j<=p[i].f-p[i-1].f;j++)
			{
				if(p[i-1].s==p[i].s.substr(j,p[i-1].f))
				{
					t=false;
					break;
				}
			}
			if(t)
			{
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
			cout<<p[i].s<<endl;
		return 0;
	}