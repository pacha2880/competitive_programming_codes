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
	int a[60] = {31,29,31,30,31,30,31,31,30,31,30,31,
				31,28,31,30,31,30,31,31,30,31,30,31,
				31,28,31,30,31,30,31,31,30,31,30,31,
				31,29,31,30,31,30,31,31,30,31,30,31,
				31,28,31,30,31,30,31,31,30,31,30,31};
	int n;
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++)
		cin>>b[i];
	bool u;
	for(int i=0;i<60-n;i++){
		u=true;
		for(int j=i;j<i+n;j++)
		{
			if(a[j]!=b[j-i])
			{
				u=false;
				break;
			}
		}
		if(u){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}