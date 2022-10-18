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
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n;
	cin>>n;
	if(n%4==0){
		cout<<0<<endl<<n/2<<' ';
		for(int i =1;i<n/2;i+=2)
		{
			if(i>1)cout<<' ';
			cout<<i<<' '<<n-i+1;
		}
	}
	if(n%4==1){
		cout<<1<<endl<<n/2+1<<' '<<1;
		if(n>1) cout<<' ';
		for(int i =2;i<(n-1)/2+1;i+=2)
		{
			if(i>2)cout<<' ';
			cout<<i<<' '<<n-i+2;
		}1
	}
	if(n%4==2){
		cout<<1<<endl<<n/2<<' '<<2;
		if(n>2) cout<<' ';
		for(int i =3;i<(n-2)/2+2;i+=2)
		{
			if(i>3)cout<<' ';
			cout<<i<<' '<<n-i+3;
		}
	}
	if(n%4==3){
		cout<<0<<endl<<n/2<<' '<<3;
		if(n>3) cout<<' ';
		for(int i =4;i<(n-3)/2+3;i+=2)
		{
			if(i>4)cout<<' ';
			cout<<i<<' '<<n-i+4;
		}
	}
	return 0;
}