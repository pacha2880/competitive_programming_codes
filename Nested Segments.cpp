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
	int n,a,b;
	cin>>n;
	vector<pair<int,pair<int,int> > > v;
	set<pair<int,pair<int,int> > > st;
	set<pair<int,pair<int,int> > >::iterator it;
	pair<int,pair<int,int> > p;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a,make_pair(-b,i)));
		st.insert(make_pair(b,make_pair(a,i)));
	}	
	sort(v.begin(),v.end());
	for(int i=0;i<n-1;i++)
	{
		p = make_pair(-v[i].second.first,make_pair(v[i].first,v[i].second.second));
		st.erase(p);
		it = st.begin();
		if((*it).first<=-v[i].second.first)
		{
			cout<<(*it).second.second + 1<<' '<<v[i].second.second + 1;
			return 0;
		}
	}
	cout<<-1<<' '<<-1;
	return 0;
}