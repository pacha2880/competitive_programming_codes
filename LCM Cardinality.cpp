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
bitset<150000> bi;
vi primos;
vector<long long> pric;
vector<pair<int,int> > factors;
vector<int> fac;
void criba()
{
	bi.set();
	for(int i=2;i<150000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<150000;j+=i)
				bi[i]=0;
			primos.push_back(i);
			pric.push_back(i*i);
		}
}
void far(int mul, int pos)
{
	if(pos==factors.size()) {fac.push_back(mul); return;}
	far(mul,pos+1);
	for(int i=0;i<factors[pos].second;i++)
		far(mul*=factors[pos].first,pos+1);

}
void factor(int n)
{
	factors.clear();
	for(int i=0;pric[i]<=n;i++)
	{
		if(n%primos[i]==0) factors.push_back(make_pair(primos[i],0));
		while(n%primos[i]==0) {n/=primos[i]; factors[factors.size()-1].second++;}
	}
	if(n!=1) factors.push_back(make_pair(n,1));

	far(1,0);
}
int gcd(int a, int b){return b==0? a: gcd(b,a%b);}
int lcm(int a, int b){return a*(b/gcd(a,b));}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,m;
	criba();
	while(cin>>n&&n)
	{
		fac.clear();
		factor(n);
		m=0;
		for(int i=0;i<fac.size();i++)
			for(int j=i;j<fac.size();j++)
				if(lcm(fac[i],fac[j])==n) m++;
		cout<<n<<' '<<m<<endl;
	}
	return 0;
}