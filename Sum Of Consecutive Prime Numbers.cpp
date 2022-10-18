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
vector<int> primes;
bitset<10000> bs;
void criba()
{
	bs.set();
	for(int i=2;i<=10000;i++)
	{
		if(bs[i])
		{
			for(int j=i+i;j<10000;j+=i)
				bs[j]=0;
			primes.push_back(i);
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	int a,s,pi,pj,sum,ways;
	s=primes.size();
	primes.push_back(0);
	while(cin>>a&&a)
	{
		sum=2;
		ways=0;
		pi=0;
		pj=0;
		while(pj<s&&primes[pj]<=a)
		{
			if(sum==a)
			{
				ways++;
				pj++;
				sum+=primes[pj];
				sum-=primes[pi];
				pi++;

			}
			else
				if(sum<a)
				{
					pj++;
					sum+=primes[pj];
				}
				else
				{
					sum-=primes[pi];
					pi++;
				}

		}
		cout<<ways<<endl;

	}
	return 0;
}