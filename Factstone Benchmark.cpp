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
	ll lim = 4, lims[21],curr=1;
	int pos=0;
	long double sum = 0;
	while(pos<21)
	{
		while(sum<lim){
			curr++;
			sum+=log2l((long double)curr);
		}
		lims[pos]=curr-1;
		pos++;
		lim*=2;
	}
	int a;
	while(cin>>a&&a){
		a-=1960;
		a/=10;
		cout<<lims[a]<<endl;
	}
	return 0;
}