#include <bits/stdc++.h>
#define PI 			acos(-1)
#define fi 			(1+sqrt(5))/2
#define Binet(n)	(pow(fi,n)-pow(-fi,-n))/sqrt(5)
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
ll dp[10][100][1<<10];
int a,b;
ll dom(int x, int y, int bitm)
{
	if(x==b) return bitm==0? 1:0;
	if(dp[y][x][bitm]!=-1) return dp[y][x][bitm];
	if(y==a-1) return dp[y][x][bitm]=dom(x+1,0,bitm^(1<<y));
	dp[y][x][bitm]= dom(x,y+1,bitm^(1<<y));
	if(!(bitm&(1<<(y+1)))&&!(bitm&(1<<y))) dp[y][x][bitm] += dom(x,y+1,bitm^(1<<(y+1)));
	return dp[y][x][bitm];
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int c;
	ll domi [100][100];
	memset(domi,-1,sizeof(domi));
	while(cin>>a)
	{
		cin>>c;
		b=max(a,c);
		a=min(a,c);
		if(domi[a][b]!=-1) cout<<domi[a][b]<<endl;
		else
		{
			memset(dp,-1,sizeof(dp));
			domi[a][b]=dom(0,0,0);
			cout<<domi[a][b]<<endl;
		}
		
	}
	return 0;
}