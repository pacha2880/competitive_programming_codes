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
	//freopen("asd", "w", stdout);
	
	double co,im;
	int res;
	while(cin>>co&&co>-1)
	{
		res=0;
		for(int i=2;i<30;i++)
		{
			im=co;
			for(int j=0;j<i;j++)
			{
				im=(im-1)*(i-1)/i;
			}
			im/=i;
			if(im-(int)im==0) res=i;
		}


		if(res)
			cout<<(int)co<<" coconuts, "<<res<<" people and 1 monkey\n";
		else
			cout<<(int)co<<" coconuts, no solution\n";
	}
	return 0;
}