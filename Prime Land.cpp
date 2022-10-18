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
bitset<32768> bi;
vi primos, fact, ex;
void criba()
{
	bi.set();
	for(int i=2;i<32768;i++)
		if(bi[i])
		{
			for(int j=i+i;j<32768;j+=i)
				bi[j]=0;
			primos.push_back(i);
		}
}
void fac(int n)
{
	fact.clear();
	ex.clear();
	for(int i=0;i<primos.size();i++)
		if(n%primos[i]==0)
		{
			fact.push_back(primos[i]);
			ex.push_back(0);
			while(n%primos[i]==0)
			{
				ex[ex.size()-1]++;
				n/=primos[i];
			}
		}
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
	//freopen("", "w", stdout);
	string s;
	criba();
	int a, b, num;
	while(true)
	{
		getline(cin,s);
		if(s=="0") break;
		stringstream in(s);
		num=1;
		while(in>>a)
		{
			in>>b;
			num*=pot(a,b);
		}
		num--;
		fac(num);
		for(int i=fact.size()-1;i>-1;i--)
		{
			cout<<fact[i]<<' '<<ex[i];
			if(i>0) cout<<' '; 
		}
		cout<<'\n';
	}

	return 0;
}