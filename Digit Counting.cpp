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
	int fre[10000][10],t;
	for(int i=0;i<10;i++) fre[0][i]=0;
		fre[0][1]=1;
	for(int i=1;i<10000;i++)
	{
		t=i+1;
		for(int j=0;j<10;j++) fre[i][j]=fre[i-1][j];
		while(t>0)
		{
			fre[i][t%10]++;
			t/=10;
		}
	}
	int n;
	cin>>n;
	while(n--)
	{
		cin>>t;
		for(int i=0;i<10;i++)
		{
			if(i>0) cout<<' ';
			cout<<fre[t-1][i];
		}
		cout<<endl;
	}
	return 0;
}