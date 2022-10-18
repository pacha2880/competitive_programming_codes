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
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int a,b;
	while(cin>>a)
	{
		cin>>b;
		vector<pair<double,pair<int,int> > > ve;
		for(int i=1;i<=a;i++)
			for(int j=1;j<=i;j++)
			{
				if(__gcd(i,j)==1)
					ve.push_back(make_pair((double)j/(double)i,make_pair(j,i)));
			}
		sort(ve.begin(),ve.end());
		cout<<ve[b-1].second.first<<'/'<<ve[b-1].second.second<<'\n';
	}
	return 0;
}