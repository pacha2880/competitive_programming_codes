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
	string s, w="WUB";
	cin>>s;
	string res="";
	bool p=false;
	for(int i=0;i<s.size();i++)
	{
		if(i<=s.size()-3)
		{
			if(s.substr(i,3)==w)
			{
				i+=2;
				if(p)
				{
					res+=' ';
				}
				p=false;
			}
			else
			{
				p=true;
				res+=s[i];
			}
		}
		else
		{
			res+=s[i];
			p=true;
		}
	}
	cout<<res;
	return 0;
}