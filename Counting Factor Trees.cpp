#include <bits/stdc++.h>
#include <string> 
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

int main()
{
	//freopen("we", "w", stdout);
	int x,y;
	long double a,b;
	while(cin>>x)
	{
		cin>>y;
		a=x,b=y;
		if(a<b)
		{
			cout<<"Coin cannot fit in tray."<<endl;
			continue;
		}
		if(a<2*b)
			{
				cout<<1<<" coin of size "<<y<<" will fit the inner rim of a tray of size "<<x<<"."<<endl;
				continue;
			}
				if(b/(a-b)==0.5)
					cout<<"6 coins of size "<<y<<" will fit the inner rim of a tray of size "<<x<<"."<<endl;
				else {
						int t=acos(-1)/asin(b/(a-b));
					cout<<t<<" coins of size "<<y<<" will fit the inner rim of a tray of size "<<x<<"."<<endl;}
			
			
	}
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);a
	return 0;
}