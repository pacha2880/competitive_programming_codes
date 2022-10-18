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
bitset<20000000> bi;
vi primos;
void criba()
{
	bi.set();
	bi[0]=bi[1]=0;
	for(int i=2;i<20000000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<20000000;j+=i)
				bi[j]=0;
			primos.push_back(i);
		}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	vector<pair<int,int> > vp;
	for(int i=1;i<primos.size();i++)
		if(primos[i]-primos[i-1]==2)
			vp.push_back(make_pair(primos[i-1],primos[i]));
	int n;
	while(cin>>n)
		cout<<'('<<vp[n-1].first<<", "<<vp[n-1].second<<')'<<endl;
	return 0;
}