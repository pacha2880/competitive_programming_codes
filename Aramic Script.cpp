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
	set<set<char> > v;
	string s;
	set<char> st;
	cin>>s;
	for(int i=0;i<s.size();i++)
		st.insert(s[i]);
	v.insert(st);
	st.clear();
	for(int i=0;i<n-1;i++)
	{
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			st.insert(s[j]);
		}
		v.insert(st);
		st.clear();
	}
	cout<<v.size();
	return 0;
}