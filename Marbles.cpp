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
ll x,y,g;
void extendedEuclid(ll a, ll b)
{
	if(b==0) {x=1; y=0; g=a; return;}
	extendedEuclid(b,a%b);
	ll x1=y;
	y= x-(a/b)*y;
	x=x1;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll m,a,b,c,d,t,u;
	pair<ll, pair<ll,ll> > res;
	while(cin>>m&&m)
	{
		cin>>a>>b>>c>>d;
		extendedEuclid(b,d);
		if(m%g!=0) cout<<"failed\n";
		else
		{
			x*=m/g;
			y*=m/g;
			t = ceil(-(double)x/((double)d/(double)g));
			u = floor((double)y/((double)b/(double)g));
			if(x+u*d/g<0||y-u*b/g<0) {cout<<"failed\n"; continue;}
			if((double)a/(double)b<= (double)c/(double)d)
				cout<<x+u*d/g<<' '<<y-u*b/g<<endl;
			else
				cout<<x+t*d/g<<' '<<y-t*b/g<<endl;
		}
	}
	return 0;
}