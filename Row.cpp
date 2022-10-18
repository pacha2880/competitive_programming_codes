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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int con[n];
	memset(con,0,sizeof(con));
	if(n == 1)
	{
		if(s[0]=='1')
			cout<<"yes";
		else
			cout<<"no";
	}
	else
	{
		if(s[0]=='1')
		{
			con[0]+=2;
			con[1]++;
		}
		if(s[n-1]=='1')
		{
			con[n-1]+=2;
			con[n-2]++;
		}
		for(int i=1;i<n-1;i++)
		{
			if(s[i]=='1')
			{
				con[i]+=2;
				con[i-1]++;
				con[i+1]++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(con[i]==0||con[i]>2)
			{
				cout<<"no";
				return 0;
			}
		}
		cout<<"yes";
	}
	return 0;
}