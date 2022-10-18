#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int a,b;
	vi v;
	v.push_back(1);
	v.push_back(1);
	while(v[v.size()-1]<=10000000)
		v.push_back(v[v.size()-1]+v[v.size()-2]);
			cin>>a>>b;
	int c=0;
	bool t;
	for(int i=a;i<=b;i++)
	{
		t=true;
		for(int j=2;j<36;j++)
		{
			if(i%v[j]==0) {t=false;break;}
		}
		if(t) c++;
	}
	cout<<c<<endl;
	return 0;
}