#include <bits/stdc++.h>
#define PI 			acos(-1)
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
map<int,bool> mp;
map<int,int> mpp;
vi sumas;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd", "w", stdout);
	int a,n,s;
	while(cin>>s&&s!=-1)
	{
		for(n = sqrt(2*s);n>0;n--)
		{
			if((a=2*s+n-n*n)%(2*n)==0)
				break;
		}
		a/=2*n;
		cout<<s<<" = "<<a<<" + ... + "<<a+n-1<<endl;

	}
	return 0;
}