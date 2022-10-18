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
	typedef unsigned long long 		ull;
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		string s;
		cin>>s;
		if(s.size()<3) {
			cout<<"No";
			return 0;
		}
		char a=s[0],b=s[1],c;
		int sum = 'A' + 'B' + 'C';
		for(int i = 2; i < s.size(); i++)
		{
			c = s[i];
			if(sum == a+b+c && a!=b)
			{
				cout<<"Yes";
				return 0;
			}
			a = b;
			b = c;
		}
		cout<<"No";
		return 0;
	}