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
	double n;
	int c;
	cin>>c;
	bool t=false;
	while(c--)
	{
		cin>>n;
		if(t) cout<<endl;
		t=true;
		if(n==1) cout<<"0.000"<<endl;
		else cout<<fixed<<setprecision(3)<<(n-1)*4+sqrt(2)*(n-2)*(n-2)<<endl;
	}
	return 0;
}