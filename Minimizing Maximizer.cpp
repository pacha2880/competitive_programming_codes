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

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,ar,so,pi,co,a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ar>>so;
		if(i>0) cout<<endl;
		pi=0;
		int arr[ar];
		for(int j=0;j<ar;j++)
			arr[j]=INT_MAX;
		co=0;
		while(cin>>a&&a!=1)
		{
			cin>>b;
			co++;
		}
		cin>>b;
		co++;
		for(int j=0;j<b;j++)
			arr[j]=1;
		pi=b;
		for(int j=co;j<so;j++)
		{
			cin>>a>>b;
			if(a<=pi)
			{
				pi=max(pi,b);
				if(a==1){
				while(arr[b-1]>1)
					{
						arr[b-1]=1;
						b--;
					}}
				else
				while(arr[b-1]>arr[a-2])
				{
					arr[b-1]=arr[a-2]+1;
					b--;
				}
			}
		}
				cout<<arr[ar-1]<<endl;

	}
	return 0;
}