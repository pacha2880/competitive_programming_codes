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
ll x,y,d;
void extendedEuclid(ll a,ll b){
	if(b==0){x=1;y=0;d=a;return;}
	extendedEuclid(b,a%b);
	ll x1=y;
	y=x-(a/b)*y;
	x=x1;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll n,a,b;
	cin>>n>>a>>b;
	if(n%__gcd(a,b)!=0) {cout<<"NO"; return 0;}
	extendedEuclid(a,b);
	int t = n/d;
	x*=t;
	y*=t;
	double u,f;
	u = (-(double)x)/((double)b);
	f = ((double)y)/((double)a);
	u=ceil(u);
	f=floor(f);
	if(u<=f)
		cout<<"YES"<<endl<<x+b*(int)f<<endl<<y-a*(int)f<<endl;
	else
		cout<<"NO";
	return 0;
}