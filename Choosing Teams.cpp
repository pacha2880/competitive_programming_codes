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
	int n,k,t,tri=0,res=0;
	cin>>n>>k;
	vi ve;
	while(n--)
	{
		cin>>t;
		ve.push_back(t);
		if(t<5)
			tri++;
		if(tri==3){
			res++;
			tri=0;
		}
	}
	tri=0;
	sort(ve.begin(),ve.end());
	for(int i=0;i<ve.size()&&i<res*3;i+=3)
	{
		if(max(ve[i],max(ve[i+1],ve[i+2]))+k>5)
		{
			break;
		}
		tri++;
	}
	cout<<tri;
	return 0;
}