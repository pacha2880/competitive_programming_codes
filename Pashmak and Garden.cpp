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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		if(a<0)
			cout<<a+abs(d-b)<<' '<<b<<' '<<c+abs(d-b)<<' '<<d;
		else
			cout<<a-abs(d-b)<<' '<<b<<' '<<c-abs(d-b)<<' '<<d;
	}
	else
		if(b==d)
		{
			if(b<0)
				cout<<a<<' '<<b+abs(a-c)<<' '<<c<<' '<<d+abs(a-c);
			else
				cout<<a<<' '<<b-abs(a-c)<<' '<<c<<' '<<d-abs(a-c);
		}
		else
			if(abs(a-c) == abs(b-d))
			{
				if(a-c==b-d)
					cout<<max(a,c)<<' '<<min(b,d)<<' '<<min(a,c)<<' '<<max(b,d);
				else
					cout<<max(a,c)<<' '<<max(b,d)<<' '<<min(a,c)<<' '<<min(b,d);
			}
			else
				cout<<-1;
	return 0;
}