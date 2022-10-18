	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n;
	cin>>n;
	int arr[n],mini = 300,maxi=-1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		mini = min(arr[i],mini);
		maxi = max(arr[i],maxi);
	}
	int mi,ma;
	bool t = true;
	for(int i=0;i<n;i++)
	{		if(t)
		{
			if(arr[i]==maxi)
			{	ma = i;
			t = false;}
		}
		if(arr[i]==mini)
			mi = i;
	}
	int res = n-1-mi + ma + (mi<ma?-1:0);
	cout<<res;

	return 0;
}