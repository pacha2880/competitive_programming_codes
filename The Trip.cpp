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
	//freopen("asd.txt", "w", stdout);
	double sum,n,ti,a,b,c,d,res;
	while(cin>>n&&n){
		double cost[(int)n];
		sum=0;
		for(int i=0;i<n;i++){
			cin>>cost[i];
			sum+=cost[i];
		}
		sum/=n;
		sum*=100;
		sum=round(sum);
		sum/=100;
		res=10000000;

		for(double j=sum-0.02;j<=sum+0.02;j+=0.01){

		a=b=c=d=0;
		for(int i=0;i<n;i++){
			if(j>cost[i]){
				a+=j-cost[i];
			}
			if(j>cost[i]+0.01){
				b+=j-cost[i]-0.01;
			}
			if(j<cost[i]){
				c+=cost[i]-j;
			}
			if(j+0.01<cost[i]){
				d+=cost[i]-j-0.01;
			}
		}
		res=min(min(max(a,d),max(b,c)),res);
		}
		cout<<'$'<<fixed<<setprecision(2)<<res<<endl;

	}
	return 0;
}