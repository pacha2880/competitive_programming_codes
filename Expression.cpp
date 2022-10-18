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
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==1)
	{
		a +=b;
		if(c==1)
			a +=1;
		cout<<a*c;
	}
	else

	if(b==1)
	{
		b +=min(a,c);
		if(max(a,c)==1)
			b = 3;
		cout<<b*max(a,c);
	}
	else

	if(c==1)
	{
		c +=b;
		if(a==1)
			c += a;

		cout<<c*a;
	}
	else
		cout<<a*b*c;

	return 0;
}