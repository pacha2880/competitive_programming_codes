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
ll maxi(ll n)
{
	vector<ll> v;
	while(n>0ll)
	{
		v.push_back(n%10);
		n/=10ll;
			}
	sort(v.begin(),v.end());

	for(int i=v.size()-1;i>-1;i--)
	{
		n*=10ll;
		n+=v[i];
	}
	return n;
}
ll mini(ll n)
{
	vector<ll> v;
	int cer=0;
	while(n>0ll)
	{
		if(n%10ll==0) cer++;
		else
			v.push_back(n%10ll);
		n/=10ll;
	}
	sort(v.begin(),v.end());
	n=v[0];
	while(cer--)n*=10ll;
	for(int i=1;i<v.size();i++)
	{
		n*=10ll;
		n+=v[i];
	}
	return n;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	
	ll s,a,b;
	while(cin>>s)
	{
		a = maxi(s);
		b = mini(s);
		cout<<a<<" - "<<b<<" = "<<a-b<<" = 9 * "<<(a-b)/9<<endl;
	}

	return 0;
}