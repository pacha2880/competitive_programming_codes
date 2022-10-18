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
bitset<1000000> bi;
vi primos;
void criba()
{
	bi.set();
	bi[0]=0,bi[1]=0;
	for(int i=2;i<1000000;i++)
		if(bi[i])
		{
			for (int j = i+i; j < 1000000; j+=i)
				bi[j]=0;
			primos.push_back(i);
		}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,i;
	criba();
	while(cin>>n&&n)
	{
		i=0;
		while(!bi[n-primos[i]])
			i++;
		cout<<n<<" = "<<primos[i]<<" + "<<n-primos[i]<<endl;
	}
	return 0;
}