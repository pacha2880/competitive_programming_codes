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
	string a;
	cin>>a;
	int con=0;
	bool bi=true;
	for(int i =a.size()-1;i>-1;i--)
	{
		if(bi)
		{
			if(a[i]=='0')
			{
				con++;
				if(con==6){
					bi=false;
				}
			}
		}
		else
		{
			if(a[i]=='1')
			{
				bi=true;
				break;
			}
		}
	}
	cout<<(bi&&con==6?"yes":"no");
	return 0;
}