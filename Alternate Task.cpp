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
bitset<1000> bi;
vector<int> pric,primos;
void criba()
{
	bi.set();
	for(int i=2;i<1000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<1000;j+=i)
				bi[j]=0;
			primos.push_back(i);
			pric.push_back((ll)i*(ll)i);
		}
}
ll pot(int b, int e)
{
	if(e==0) return 1;
	return pot(b,e/2)*pot(b,e/2)*(e&1?b:1);
}
int sumfac(int n)
{
	int res=1,con;
	for(int i=0;pric[i]<=n;i++)
	{
		if(n%primos[i]==0)
		{
			con=1;
			while(n%primos[i]==0)
			{
				n/=primos[i];
				con++;
			}
			res*=(pot(primos[i],con)-1)/(primos[i]-1);
		}
	}
	if(n!=1) res*=(n+1);
	return res;
}

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int fac[1000];
	mem(fac,0);
	int t,n;
	criba();
	for(int i=1;i<1001;i++)
		{
			t=sumfac(i);
			if(t<=1000)
			{
				fac[t-1]=i;
				}
		}
		t=1;
		while(cin>>n&&n)
			cout<<"Case "<<t++<<": "<<(fac[n-1]?fac[n-1]:-1)<<'\n';

	return 0;
}