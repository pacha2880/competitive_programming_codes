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
	cout<<"PERFECTION OUTPUT\n";
	int n,sum;
	while(cin>>n&&n)
	{
		sum=0;
		for(int i=1;i<=n/2;i++)
			if(n%i==0) sum+=i;
		for(int i=0;i<4-log10(n);i++)
			cout<<' ';
		cout<<n<<"  ";
		if(sum>n)
			cout<<"ABUNDANT\n";
		if(sum<n)
			cout<<"DEFICIENT\n";
		if(sum==n)
			cout<<"PERFECT\n";

	}	
	cout<<"END OF OUTPUT\n";
	return 0;
}