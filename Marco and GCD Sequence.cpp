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
	int r;
	cin>>r;
	bitset<2000000> bi,ti;
	bi.set();
	ti.set();
	int arr[r];
	for(int i=0;i<r;i++)
		{
			cin>>arr[i];
			ti[arr[i]]=0;
		}
	for(int i=0;i<r-1;i++)
		for(int j=i+1;j<r;j++)
			if(ti[__gcd(arr[i],arr[j])])
			{
				cout<<-1;
				return 0;
			}
	vector<int>res;
	for(int i=r-1;i>-1;i--){
		if(bi[arr[i]]){
			res.push_back(arr[i]);
			for(int j=0;j<res.size();j++){
				bi[__gcd(arr[i],res[j])]=0;
			}
		}
	}
	cout<<res.size()<<endl;
	for(int i=res.size()-1;i>-1;i--)
	{
		if(i<res.size()-1) cout<<' ';
		cout<<res[i];
	}
	return 0;
}