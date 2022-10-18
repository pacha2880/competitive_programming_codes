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
	int n;
	bool pal;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		set<char> st;
		pal = true;
		for(int i = 0; i<s.size()/2; i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				pal = false;
				break;
			}
			st.insert(s[i]);
			st.insert(s[s.size()-1-i]);
		}
		st.insert(s[s.size()/2]);

		if(pal)
		{
			if(st.size() == 1)
				s = "-1";
			else
			{
				for(int i = s.size()/2; i < s.size(); i++)
				{
					if(s[i]!=s[0])
					{
						char ax = s[0];
						s[0] = s[i];
						s[i] =ax;
						break;
					}
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS