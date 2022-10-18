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

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll fac[21];
	fac[0]=1;
	for(int i=1;i<21;i++)
		fac[i]=fac[i-1]*i;
	int n;
	cin>>n;
	map<char,int> mp;
	string s;
	ll res;
	for(int j=1;j<=n;j++){
		cin>>s;
		mp.clear();
		res=fac[s.size()];
		for(int i=0;i<s.size();i++)
		{
			mp[s[i]]++;
			res/=mp[s[i]];
		}
		cout<<"Data set "<<j<<": "<<res<<endl;
	}
	return 0;
}