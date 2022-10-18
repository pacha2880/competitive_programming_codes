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
	//freopen("", "w", stdout);
	double a;
	int n,dif;
	while(cin>>a)
	{
		n=ceil((-1+sqrt(1+8*a))/2);
		cout<<"TERM "<<(int)a<<" IS ";
		dif = n*(n+1)/2-a;
		if(!(n&1))
			cout<<n-dif<<'/'<<1+dif<<endl;
		else
			cout<<1+dif<<'/'<<n-dif<<endl;
	}
	return 0;
}