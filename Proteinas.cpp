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
ll dos[100020],d[100020], tres,cuatro,cinco,tr[100020],cu[1000020],ci[100020];
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	
	dos[0]=2;
	ll p=2, mod=1000000007;
	for(int i=1;i<100010;i+=2)
	{
		dos[i]=(dos[i-1]+p)%mod;
		dos[i+1]=(dos[i]+p)%mod;
		d[i]=d[i-1]=p;
		p*=2;
		p%=mod;
	}
	tres=2;
	cuatro=4;
	cinco=8;
	tr[0]=cu[0]=ci[0]=2;
	tr[1]=cu[1]=ci[1]=4;
	tr[2]=cu[2]=ci[2]=8;
	cu[3]=ci[3]=16;
	ci[4]=32;
	for(int i=1;i<100010;i+=2)
	{
		tres=(tres*2ll-1ll)%mod;
		cuatro=(cuatro*2ll-1ll)%mod;
		cinco=(cinco*2-1)%mod;
		tr[2+i]=(tr[1+i]+(tres*d[i])%mod)%mod;
		cu[3+i]=(cu[2+i]+(cuatro*d[i])%mod)%mod;
		ci[4+i]=(ci[3+i]+(cinco*d[i])%mod)%mod;
		tr[3+i]=(tr[2+i]+(tres*d[i+1])%mod)%mod;
		cu[4+i]=(cu[3+i]+(cuatro*d[i+1])%mod)%mod;
		ci[5+i]=(ci[4+i]+(cinco*d[i+1])%mod)%mod;
	}
	int n,k;
	cin>>n>>k;
	switch(k)
	{
		case 1: cout<<2; break;
		case 2: cout<<dos[n-1]; break;
		case 3:	cout<<tr[n-1]; break;
		case 4: cout<<cu[n-1]; break;
		case 5: cout<<ci[n-1];		
	}
	return 0;
}