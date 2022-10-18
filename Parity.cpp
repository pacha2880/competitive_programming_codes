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
string bi(int a){
	string res="";
	char t;
	while(a>0){
		t = '0'+a%2;
		res= t+res;
		a/=2;
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,par;
	string bin;
	while(cin>>n&&n){
		bin=bi(n);
		par=0;
		for(int i=0;i<bin.size();i++)
			if(bin[i]=='1')
				par++;
		cout<<"The parity of "<<bin<<" is "<<par<<" (mod 2).\n";
	}
	return 0;
}