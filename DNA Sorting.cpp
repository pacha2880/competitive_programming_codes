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
	int n,cad,len,g;
	vector<ii> ve;
	cin>>n;
	for(int y=0;y<n;y++)
	{
		if(y) cout<<'\n';
		ve.clear();
		cin>>len>>cad;
		g=0;
		string cads[cad];
		for(int i=0;i<cad;i++)
			{
				g=0;
				cin>>cads[i];
				for(int j=0;j<len-1;j++)
				{
					for(int k=j+1;k<len;k++)
					{
						if(cads[i][k]<cads[i][j])
							g++;
					}
				}
				ve.push_back(make_pair(g,i));
			}
		sort(ve.begin(),ve.end());
		for(int i=0;i<cad;i++)
			cout<<cads[ve[i].second]<<'\n';
	}
	return 0;
}