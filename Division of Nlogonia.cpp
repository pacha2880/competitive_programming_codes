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
	int n,x,y,a,b;
	while(cin>>n&&n)
	{
		cin>>x>>y;
		while(n--)
		{
			cin>>a>>b;
			if(a==x||b==y)
				cout<<"divisa\n";
			else
				if(a>x)
				{
					if(b>y)
						cout<<"NE\n";
					else
						cout<<"SE\n";
				}
				else
				{
					if(b>y)
						cout<<"NO\n";
					else
						cout<<"SO\n";	
				}
		}
	}
	return 0;
}