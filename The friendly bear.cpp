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
	ll a ;
	cin>>n;
	vector<ll> v1,v2;
	for(int i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		cin>>a;
		v2.push_back(a);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	long long sum=0;
	int r=n-1;
	for(int i=1;i<n;i++){
		sum+=(v1[i]-v1[i-1] +v2[i]-v2[i-1])*(n-i)*i;

	}
	cout<<sum;
	return 0;
}