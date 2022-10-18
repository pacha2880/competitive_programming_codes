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
	int n;
	cin>>n;
	ll as[n];
	bool vis[n];
	mem(vis,0);
	for(int i=0;i<n;i++){
		cin>>as[i];
		as[i]--;
	}
	vector<ll> tem;
	ll au,con;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			au=as[i];
			con=1;
			while(au!=i){
				vis[au]=1;
				au=as[au];
				con++;
			}
			tem.push_back(con);
		}
	}
	ll mcm = tem[0];
	for(int i=1;i<tem.size();i++){
		mcm = tem[i]*(mcm/__gcd(mcm,tem[i]));
	}
	cout<<mcm;
	return 0;
}