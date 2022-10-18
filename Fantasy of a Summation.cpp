#include <bits/stdc++.h>
#define PI 			acos(-1)
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
ll potmod(ll b, ll e, ll mod)
{
	if(e==0ll) return 1ll;
	return ((potmod((b*b)%mod,e/2ll,mod)%mod)*(e&1?b:1ll))%mod;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll s,c,n,k,mod,t;
	cin>>c;
	for(int i=1ll;i<=c;i++)
	{
		cout<<"Case "<<i<<": ";
		cin>>n>>k>>mod;
		s = 0ll;
		for(int j=0ll;j<n;j++)
		{
			cin>>t;
			s = (s+t%mod)%mod;
		}
		cout<<(s*potmod(n,k-1ll,mod)*k)%mod<<endl;
	}
	return 0;
}