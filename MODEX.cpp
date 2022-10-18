
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
int modpow(int b, int e, int mod)
{
	if(e==0) return 1;
	ll res = modpow(b,e/2,mod);
	return ((res*res)%mod*((e&1)?b:1))%mod;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int a, b, e, mod;
	cin>>a;
	while(a--)
	{
		cin>>b>>e>>mod;
		cout<<modpow(b,e,mod)<<endl;
	}
	return 0;
}