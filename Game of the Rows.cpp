#include <bits/stdc++.h>
#define PI 			acos(-1)
#define fi 			(1+sqrt(5))/2
#define Binet(n)	(pow(fi,n)-pow(-fi,-n))/sqrt(5)
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
	int n, k, t, mod[]={0,0,0},m;
	cin>>n>>k;
	m=2*n;
	while(k--)
	{
		cin>>t;
		if(t%4==3)
		{
			mod[1]++; mod[2]++;
		}
		else mod[t%4]++;
		mod[0]+=t/4+(t%4==0? -1:0);
	}
	if(n<mod[0]){mod[2]+=(mod[0]-n)*2; n=0; } else n-=mod[0]; 
	if(m<mod[2]){mod[2]-=m; m=0; } else {m-=mod[2]; mod[2]=0;}
	if(m<mod[1]){mod[1]-=m; m=0; } else {m-=mod[1]; mod[1]=0;} 
	t=min(mod[1],mod[2]); 
	mod[1]-=t; mod[2]-=t; n-=t; 
	n-=mod[2]-mod[2]/3;  n-=mod[1]/2+mod[1]%2;
	if(n<0) cout<<"NO";
	else cout<<"YES";
	return 0;
}