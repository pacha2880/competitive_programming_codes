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
	long double t,l2,lp,lpp,p;
	while(cin>>p){
		t=floorl(log10l(p))+2;
		l2=logl(10)/logl(2);
		lp=logl(p)/logl(2);
		lpp=logl(p+1)/logl(2);
		while(floorl(lpp+t*l2)!=ceill(lp+t*l2))
			t++;
		cout<<(ll)floorl(lpp+t*l2)<<endl;
	}
	return 0;
}