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
	int n,k,a;
	cin>>n>>k;
	map<ll,ll> mp;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		mp[a]++;
	}
	map<ll,ll>::iterator it;
	ll con=0;
	if(k==0) {if(mp[1]) cout<<-1; else cout<<1; return 0;}
	for(it=mp.begin();it!=mp.end();it++)
	{
		con+=it->second;
		if(con==k)
		{
			cout<<it->first;
			return 0;
		}
		if(con>k)
		{
			cout<<-1;
			return 0;
		}
	}

	cout<<-1;
	return 0;
}