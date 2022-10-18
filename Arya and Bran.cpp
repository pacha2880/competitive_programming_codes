
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

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n, k, can, days, sum, aca=0;
	days=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>can;
		sum=can+aca;
		if(sum<=8)
			{k-=sum; aca = 0;}
		else
		{
			aca= sum-8;
			k-=8;
		}
		if(k<1) {days=i; i=n+1;}
	}
	cout<<days;
	return 0;
}