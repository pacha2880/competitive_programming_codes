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
	int n,a;
	priority_queue<pair<int,int> > que,que1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		que.push(mp(-a,i+1));
	}
	string s;
	cin>>s;
	for(int i=0;i<2*n;i++)
	{
		if(i>0) cout<<' ';
		if(s[i]=='0')
		{
			que1.push(mp(-que.top().f,que.top().s));
			cout<<que.top().s;
			que.pop();
		}
		else
		{
			cout<<que1.top().s;
			que1.pop();
		}
	}

	return 0;
}