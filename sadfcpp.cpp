
#include <bits/stdc++.h>
using namespace std;
const int num=1000000,mo=1e9+7;
int a[num+5],f[num+5],i,j,n,x,ans=0;
int main()
{
	scanf("%d\n",&n);
	for (i=1;i<=n;++i) scanf("%d",&x),f[x]++;
	for (a[0]=i=1;i<=n;++i) a[i]=(a[i-1]<<1)%mo;
	for (j=0;j<20;++j)
		for (i=num;i>=0;--i)
			if (i&(1<<j)) (f[1<<j^i]+=f[i])%=mo;
	for(int i= 0; i<8;i++)
		cout<<f[i]<<endl;
	for (i=num;i>=0;--i)
	{
		x=1;
		for (j=0;j<20;++j)
			if (i&(1<<j)) x=-x;
		(ans+=1ll*x*(a[f[i]]-1))%=mo;
	}
	printf("%d\n",(ans+mo)%mo);
}