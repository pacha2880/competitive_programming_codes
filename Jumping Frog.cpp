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
	string a;
	while(cin>>a)
	{
		int n = a.size();
		bool t = true, div[n];
		for(int i=0;i<n;i++)
			{
				if(a[i]=='P')
				{
					t=false;
					break;
				}
			}
		if(t)
		{
			cout<<n-1<<endl;
			continue;
		}
		memset(div,0,sizeof(div));
		for(int i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
				for(int j = 0; j < i; j++)
				{
					t = 1;
					for(int k = 0; k < n / i; k++)
					{
						if(a[j+k*i]=='P')
						{
							t = false;
							k=n;
						}
					}
					if(t)
					{
						div[i] = 1;
						j=i;
					}
				}
			}
		}
		int res = 0;
		for(int i=2;i<n;i++)
			res += div[__gcd(n,i)];
		cout<<res<<endl;
	}
	return 0;
}