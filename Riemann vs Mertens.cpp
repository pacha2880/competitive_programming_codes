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
typedef vector<int>		vi;
int crib[1000001],M[1000001],m[1000001];
bitset<1000001> bi;
void criba()
{
	M[1]=1;
	m[1]=1;
	mem(crib,0);
	bi.set();
	for(int i=2;i<1000001;i++)
	{
		if(crib[i]==0)
		{
			for(int j=i;j<1000001;j+=i)
				crib[j]++;
			for(ll j=(ll)i*(ll)i;j<1000001ll;j+=(ll)i*(ll)i)
				bi[j]=0;
		}
		if(!bi[i])
			{M[i]=M[i-1]; m[i]=0;}
		else
			{m[i]=(crib[i]&1?-1:1); M[i]=M[i-1]+m[i];}
	}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<7-log10(n);i++)
			cout<<' ';
		cout<<n;
			cout<<(m[n]<0?"      ":"       ");
		cout<<m[n];
		for(int i=0;i<7-(M[n]==0?0:log10(abs(M[n]))+(M[n]<0?1:0));i++)
			cout<<' ';
		cout<<M[n]<<'\n';
	}
	return 0;
}