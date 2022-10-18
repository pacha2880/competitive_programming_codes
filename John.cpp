#include <bits/stdc++.h>
#define PI 			acos(-1)
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
int c,n;


int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);a
	int n,m,a,con,nn;
	map<int,int> mp;
	map<int,int>::iterator it;
	cin>>n;
	bool b,te;
	for(int i=0;i<n;i++)
	{
		b=false;
		te=false;
		nn=0;
		mp.clear();
		cin>>m;
		for(int j=0;j<m;j++)
		{
			cin>>a;
			con=1;
			if(a>1) {te=true;}
			while(a>0)
			{
				if(a%2==1)
					mp[con]++;
				con++;
				a=a/2;
			}

		}
		if(te){
		for(it=mp.begin();it!=mp.end();it++)
			if(it->second&1)
				b=true;
		}
			else
				b=!(mp[1]&1);
		if(b)
			cout<<"John"<<endl;
		else
			cout<<"Brother"<<endl;

	}

	return 0;
}
