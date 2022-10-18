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
	ll ar[14],res[14];
	for(int i=0;i<14;i++)
		cin>>ar[i];
	ll r,maxi=0;
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
			res[j]=ar[j];
		r = ar[i];

		res[i]=0;
		for(int j=0;j<14;j++)
		{	
			res[j]+=r/14;
		}
		for(int j=0;j<r%14;j++)
			res[(i+j+1)%14]++;
		r=0;
		for(int j=0;j<14;j++)
			if(res[j]%2==0)
				r+=res[j];
		maxi=max(maxi,r);
	}
	cout<<maxi;
	return 0;
}