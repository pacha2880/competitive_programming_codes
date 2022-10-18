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
bitset<200000> bi;
vi primos;
vector<ll> pric;
void criba()
{
	bi.set();
	for(int i=2;i<200000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<200000;j+=i)
				bi[j]=0;
			primos.push_back(i);
			pric.push_back((ll)i*(ll)i);
		}
}
map<int,int> fac(int n)
{
	map<int,int> res;
	for(int i=0;pric[i]<=n;i++)
	{
		while(n%primos[i]==0)
		{
			n/=primos[i];
			res[primos[i]]++;
		}
	}
	if(n!=1) res[n]++;
	return res;
}
int cant(int a, int b)
{
	ll t=a,res=0;

	while(t<=b)
	{
		res+=b/t;
		t*=a;
	}
	return res;

}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd", "w", stdout);
	int a,b;
	bool t;
	criba();

	map<int,int>mp;
	while(cin>>a)
	{
		cin>>b;
		mp=fac(b);
		t=false;
		for(map<int,int>::iterator it= mp.begin();it!=mp.end();it++)
			if(it->second>cant(it->first,a)) {cout<<b<<" does not divide "<<a<<'!'<<endl; t=true; break;}
		if(!t) cout<<b<<" divides "<<a<<'!'<<endl;
	}
	return 0;
}