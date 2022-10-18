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
	int n,b;
	bool err;
	vector<bool> num;
	vi ball;
	while(cin>>n&&n)
	{
		err=false;
		cin>>b;
		num.assign(n,0);
		ball.resize(b);
		for(int i=0;i<b;i++)
		{
			cin>>ball[i];
			for(int j=0;j<i;j++)
			{
				if(abs(ball[j]-ball[i])<=n)
					num[abs(ball[j]-ball[i])-1]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!num[i])
				{
					err=true;
					break;
				}
		}
		if(err)
			cout<<'N'<<endl;
		else
			cout<<'Y'<<endl;
	}
	return 0;
}