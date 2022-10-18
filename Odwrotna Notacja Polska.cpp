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
	string a;
	cin>>a;
	int t;
	t = atoi(a.c_str());
	string a;
	int st=0;
	int res,sec;
	while(cin>>a){
		if(st==0){
			if(a=="false")
				res=-1;
			else
			if(a=="true")
				res=-2;
			else
				res = atoi(a.c_str());
			st=1;
		}
		if(st==1){
			if(a=="false")
				sec=-1;
			else
			if(a=="true")
				sec=-2;
			else
				sec = atoi(a.c_str());
			st=2;

		}
		if(st==2){
			if(a=="+"){
				res+=sec;
			}
			else
			if(a=="*"){
				res*=sec;
			}
			else
			if(a=="=="){
				res = (res==sec?-2:-1);
			}
			else
			if(a=="and"){
				res = (res==-2&&sec==-2?-2:-1);
			}
			else
			if(a=="or"){
				res = (res==-2||sec==-2?-2:-1);
			}

			st=1;
		}
		cout<<res;
	}
	return 0;
}