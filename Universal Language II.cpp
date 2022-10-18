	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int t,n,m;
	ll a,ax,an,in;
	string res;
	char al[27];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 0;i<n;i++)
			cin>>al[i];
		cin>>m;
		while(m--)
		{
			cin>>a;
			res="";
			ax = n;
			an = 1;
			while(a>0)
			{
				in = ((a-1)%ax)/an;
				res= al[in] + res;
				a-=ax;
				an = ax;
				ax*=n;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}