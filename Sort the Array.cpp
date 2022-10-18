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
	int n,a,b,c,p;
	bool de=false,asd=true;
	a=b=1;
	vi ve;
	cin>>n;
	p=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		ve.push_back(c);
		if(asd)
		{
			if(de)
			{
				if(c<p)
					b=i;
				else
					asd=false;
			}
			else
			{
				if(c<p)
				{
					a=i-1;
					b=i;
					de=true;
				}
			}
		}
		p=c;

	}
	reverse(ve.begin()+a-1,ve.begin()+b);
	de=true;
	for(int i=1;i<n;i++)
	{
		if(ve[i]<ve[i-1])
		{
			de=false;
			break;
		}
	}
	if(de)
		cout<<"yes"<<endl<<a<<' '<<b;
	else
		cout<<"no";
	return 0;
}