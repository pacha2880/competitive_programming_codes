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
bitset<10000> bi;
vi primos,pric;
void criba()
{
	bi.set();
	for(int i=2;i<10000;i++)
		if(bi[i])
			{
				for(int j=i+i;j<10000;j+=i)
					bi[j]=0;
				primos.push_back(i);
				pric.push_back(i*i);
			}

}
map<int,int> fac(int n)
{
	map<int,int> res;
	for(int i=0;pric[i]<=n;i++)
	{
		while(n%primos[i]==0)
		{
			res[primos[i]]++;
			n/=primos[i];
		}
	}
	if(n!=1) res[n]++;
	return res;
}
int pot(int b, int e)
{
	if(e==0) return 1;
	return pot(b,e/2)*pot(b,e/2)*(e&1?b:1);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);

	//freopen("asd", "w", stdout);
	map<int,int> da,db;
	int a,b,n;
	map<int,int>::iterator it;
	criba();
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(b%a!=0) {cout<<"NO SOLUTION\n"; continue;}
		da=fac(a);
		db=fac(b);
		for(it=da.begin();it!=da.end();it++)
			if(it->second==db[it->first])
				{
					db.erase(it->first);
				}
		a=1;
		for(it=db.begin();it!=db.end();it++)
			a*=pot(it->first,it->second);
		cout<<a<<'\n';


	}
	return 0;
}