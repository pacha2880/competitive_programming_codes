	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			firs
#define s 			second
#define MOD			1000000007
#define EPS			1e-9
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
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	string s;
	cin>>s;
	bool b = s[0]=='b';
	int con=0,cos=0;
	string res ="";
	if(s[0]=='b')
	{
		cos=1;
		b=true;
	}
	else
	{
		con=1;
		b=false;
	}
	for(int i=1;i<s.size();i++)
	{
		if(b)
		{
			if(s[i]=='b')
				cos++;
			else
			{
				b=false;
				for(int j=1;j<cos;j++)
					res+=" 0";
				res+=" 1";
				cos=0;
				con=1;
			}
		}
		else
		{
			if(s[i]=='b')
			{
				for(int j=1;j<con;j++)
					res+=" 0";
				res+=" 1";
				cos=1;
				con = 1;
				b=true;
			}
			else
			{
				con++;
			}
		}
	}
	if(b)
	{
		for(int i=0;i<cos;i++)
		{
			res+=" 0";
		}
	}
	else
	{
		for(int i=1;i<con;i++)
		{
			res+=" 0";
		}
		res+=" 1";
	}
	cout<<res.substr(1);
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS