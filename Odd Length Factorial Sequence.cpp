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

	int len[3000067];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout)
	int c=1;
	double l = 1;
	int con = 1;
	len[0]=1;
	while(con<3000067){
		l+= log10((double)c);
		c++;
		if((int)l&1){
			len[con]=(int)l;
			con++;
		}
	}
	cin>>c;
	while(c--){
		cin>>con;
		cout<<len[con]<<'\n';
	}
	return 0;
}