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

typedef unsigned long long 		ll;
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
	ll a;
	set<ll> st;
	set<ll>::iterator it;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>a;
		st.insert(a);
	}
	for(int i=0;i<n;i++)
	{
		if(i>0) cout<<' ';
		for(it=st.begin();it!=st.end();it++)
		{
			{
				if(*it%2==0)
				{
					if(st.find(*it*3)==st.end()&&st.find(*it/2)==st.end())
					{
						cout<<*it;
						st.erase(it);
						break;
					}
				}
				else
				{
					if(st.find(*it*3)==st.end())
					{
						cout<<*it;
						st.erase(it);
						break;
					}
				}
			}
		}
	}
	return 0;
}