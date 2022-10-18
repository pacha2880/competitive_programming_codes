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
	string a;
	int con,b,e,n,sen=1;
	bool t,tt;
	set<char> st;
	st.insert('a');
	st.insert('e');
	st.insert('i');
	st.insert('o');
	st.insert('u');
	while(cin>>a)
	{
		n = a.size();
		if(st.find(a[0])==st.end())
		{
			t = true;
			for(int i = 1; i < n;i++)
			{
				if(st.find(a[i])!=st.end())
				{
					t = false;
					break;
				}
			}
			if(t)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else
		{
			con=1;

			for(int i = 1; i < n;i++)
			{
				if(st.find(a[i])!=st.end())
					con++;
			}
			sen=1;
			b = 0; e = n-1;
			while(con>1)
			{
				if(st.find(a[e])==st.end())
				{
					e-=sen;
				}
				else
				{
					b+=sen;
					swap(b,e);
					sen*=-1;
					con--;
				}
			}
			cout<<abs(b-e)+1<<endl;
		}
	}
	return 0;
}