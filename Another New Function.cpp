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
int A[2000001], phi[2000001],N[8000004];
void criba()
{
	for(int i=0;i<2000001;i++) phi[i]=i;
	A[1]=0;
for(int i=2;i<2000001;i++)
	{
		if(phi[i]==i)
			for(int j=i;j<2000001;j+=i)
				phi[j]-=phi[j]/i;
		A[i]=A[phi[i]]+1;
	}
}
void init(int b, int e, int n)
{
	if(b==e){N[n]=A[b]; return;}
	int mid=(b+e)/2,l=n*2+1,r=l+1;
	init(b,mid,l);
	init(mid+1,e,r);
	N[n]=N[l]+N[r];
}
int query(int b, int e, int i, int j, int n)
{
	if(j<b||i>e) return 0;
	if(i<=b&&j>=e)return N[n];
	int mid=(b+e)/2, l=n*2+1, r=l+1;
	if(i>mid) return query(mid+1,e,i,j,r);
	if(j<=mid) return query(b,mid,i,j,l);
	return query(b,mid,i,j,l) + query(mid+1,e,i,j,r);
}

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	init(0,2000000,0);
	int n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		cout<<query(0,2000000,a,b,0)<<endl;
	}
	return 0;
}