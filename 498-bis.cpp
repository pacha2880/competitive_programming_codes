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
ll pot(ll b, ll e){
	if(e==0)return 1;
	return pot(b*b,e/2)*(e&1?b:1);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ll x,au;
	vector<ll> pol;
	string a;

	while(cin>>x){
		cin.ignore();
		getline(cin,a);
		stringstream st(a);
		pol.clear();
		while(st>>au)
			pol.push_back(au);
		au=0;
		for(int i=pol.size()-2;i>-1;i--){
			au+=pot(x,pol.size()-2-i)*pol[i]*(pol.size()-1-i);
		}
		cout<<au<<endl;
	}
	return 0;
}