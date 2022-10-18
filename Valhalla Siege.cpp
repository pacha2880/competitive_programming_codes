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
	int n,q;
	cin>>n>>q;
	set<ll> st;
	map<ll,int> mp;
	ll a,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
		st.insert(sum);
		mp[sum] = n-i;
	}
	sum = 0;
	set<ll>::iterator it;
	for(int i=0;i<q;i++)
	{
		cin>>a;
		sum+=a;
		it = st.upper_bound(sum);
		if(it==st.end())
		{
			sum = 0;
			cout<<n<<endl;
		}
		else
		{
			cout<<mp[*it]<<endl;
		}
	}
	return 0;
}	