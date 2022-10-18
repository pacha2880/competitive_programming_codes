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
	string s;
	set<string> st;
	cin>>n;
	cin>>s;
	for(int i=0;i<n-1;i++)
		st.insert(s.substr(i,2));
	set<string>::iterator it;
	pair<int,string> maxi = make_pair(0,"");
	int con=0;
	for(it=st.begin();it!=st.end();it++)
	{
		con=0;
		for(int i=0;i<n-1;i++)
		{
			if(*it==s.substr(i,2))
				con++;
		}
		maxi = max(maxi,make_pair(con,*it));
	}
	cout<<maxi.second;
	return 0;
}