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
	int n,c,mini=INT_MAX;
	cin>>n;
	map<int,vi> mp;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		mp[c].push_back(i);
		mini=min(mini,c);
	}
	c=INT_MAX;
	for(int i=1;i<mp[mini].size();i++)
	{
		c=min(c,mp[mini][i]-mp[mini][i-1]);
	}
	cout<<c;
	return 0;
}