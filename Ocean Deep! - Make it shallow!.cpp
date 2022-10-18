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
	//freopen("asd", "w", stdout);
	string s,acu;
	int mod;
	while(cin>>s)
	{
		if(s[s.size()-1]!='#')
			while(cin>>acu&&acu[acu.size()-1]!='#')
				s+=acu;
		s+=acu;
		mod=0;
		for(int i=0;i<s.size()-1;i++)
		{
			mod*=2;
			mod+=(s[i]=='1'?1:0);
			mod%=131071;
		}
		if(mod==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}