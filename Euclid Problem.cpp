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
int x, y, d;
void extendedEuclid(int a, int b)
{
	if(b==0) {x=1; y=0; d=a; return;}
	extendedEuclid(b,a%b);
	int x1=y;
	y = x-(a/b)*y;
	x=x1;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int a, b;
	while(cin>>a)
	{
		cin>>b;
		extendedEuclid(a,b);
		cout<<x<<' '<<y<<' '<<d<<'\n';
	}
	return 0;
}