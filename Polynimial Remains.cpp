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
	int n,k,p;
	while(cin>>n&&n!=-1){
		cin>>k;
		int pol[n+1];
		for(int i=0;i<=n;i++)
			cin>>pol[i];
		for(int i=n;i>=k;i--){
			pol[i-k]-=pol[i];
			pol[i]=0;
		}
		p=n;
		while(pol[p]==0)
			p--;
		if(p==-1)p=0;
		if(p==-1) p=0;
		for(int i=0;i<=p;i++)
		{
			if(i>0)cout<<' ';
			cout<<pol[i];
		}cout<<endl;
	}
	return 0;
}