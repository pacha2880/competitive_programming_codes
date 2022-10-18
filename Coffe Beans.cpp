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
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	double c[100050],d[100050],r[10050];
	int times,n,m;
	double cal(double lam)
	{
		double res = 0;
		for(int i=0;i<m;i++)
		{
			if(c[i]+r[i]<lam)
			{
				res += (lam-c[i]-r[i])/(2.0*d[i]);
			}
		}
		return res;
	}
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		cin>>times;
		double lo,hi,res,mid,val;
		while(times--)
		{
			cin>>n>>m;
			for(int i=0;i<m;i++)
			{
				cin>>c[i]>>d[i]>>r[i];
			}
			val = 7.0*n/16.0;
			lo = 0, hi = 1000000000000000000;
			while(lo<=hi)
			{
				mid = (lo+hi)/2.0;
				if(cal(mid)>=val)
				{
					res = mid;
					hi = mid - 0.0000000001;
				}
				else
					lo = mid + 0.0000000001;
			}
			val = 0;
			for(int i=0;i<m;i++)
			{
				if(c[i]+r[i]<res)
				{
					lo = (res-c[i]-r[i])/(2.0*d[i]);
					val+=lo*(c[i]+r[i])+lo*lo*d[i];
				}
			}
			hi = (n*7.0*2.5-val);
			cout<<fixed<<setprecision(2)<<hi<<endl;
		}
	}