#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	long double a, b;
	ll n;
	long double xa,xb,ya,yb,res;
	while(cin>>a)
	{
		cin>>b;
		n = sqrt(a)+1;
		if(n&1)
		{
			if((ll)a&1)
				res = 2;
			else
				res = 1;
		}
		else
		{
			if((ll)a&1)
				res = 1;
			else
				res = 2;	
		}
		xa = (n - res/3)*sqrt(3)/2;
		ya = (n*n-a-(n*n-(n-1)*(n-1)+1)/2)/2;
		n = sqrt(b)+1;
		if(n&1)
		{
			if((ll)b&1)
				res = 2;
			else
				res = 1;
		}
		else
		{
			if((ll)b&1)
				res = 1;
			else
				res = 2;	
		}
		xb = (n - res/3)*sqrt(3)/2;
		yb = (n*n-b-(n*n-(n-1)*(n-1)+1)/2)/2;
		ya = sqrt((ya-yb)*(ya-yb)+(xa-xb)*(xa-xb));
		cout<<fixed<<setprecision(3)<<(double)ya<<endl;
	}
	return 0;
}