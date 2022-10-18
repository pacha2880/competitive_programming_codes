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
int cal(string s,int n)
{
	map<char,int> mp;
	map<char,int>::iterator itt;
	int t = s.size();
	for(int i=0;i<s.size();i++)
		mp[s[i]]++;
	set<int> st;
	for(itt=mp.begin();itt!=mp.end();itt++)
		st.insert(itt->second);
	set<int>::iterator it;
	int res = 0;
	int a;
	for(it=st.begin();it!=st.end();it++)
	{
		if(n&1==(t-*it)&1)
			a = t+n;
		else
			if(*it+n==t+1&&(n==1))
				a = t-1;
			else
				a = *it+n;
		res = max(res,a);
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,t,a,b,c;
	string sa,sb,sc;
	cin>>n>>sa>>sb>>sc;
	t = sa.size();
	a = cal(sa,n);
	b = cal(sb,n);
	c = cal(sc,n);
	if((a>=t&&b>=t)||(a>=t&&c>=t)||(b>=t&&c>=t)||(a==b&&a>=c)||(b==c&&c>=a)||(a==c&&c>=b))
		cout<<"Draw";
	else
	{
		if(a>b&&a>c)
			cout<<"Kuro";
		else
			if(b>c&&b>a)
				cout<<"Shiro";
			else
				cout<<"Katie";
	}
	return 0;
}