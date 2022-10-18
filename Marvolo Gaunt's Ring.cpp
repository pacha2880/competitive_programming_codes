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
	ll n,p,q,r,res=0ll;
	cin>>n>>p>>q>>r;
	ll val[n];
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	ll re=0ll;
	int in=0,im;
	if (p>0)
		{for(int i=1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if(p<0)
	{
		for(int i=1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if (q>0)
		{for(int i=in+1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	if(q<0)
	{
		for(int i=in+1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	if (r>0)
		{for(int i=in+1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	if(r<0)
	{
		for(int i=in+1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	re=max(re,res);
	
	res=0ll;
	in=0;
	if (q>0)
		{for(int i=1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	if(q<0)
	{
		for(int i=1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	im=in;
	if (p>0)
		{for(int i=0;i<im;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if(p<0)
	{
		for(int i=0;i<im;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	in=im;
	if (r>0)
		{for(int i=im+1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	if(r<0)
	{
		for(int i=im+1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	re=max(re,res); res=0; in=0;
	if (p>0)
		{for(int i=1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if(p<0)
	{
		for(int i=1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	int ib=in;
	if (r>0)
		{for(int i=in+1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	if(r<0)
	{
		for(int i=in+1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	im=in;
	if (q>0)
		{for(int i=ib;i<im;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	if(q<0)
	{
		for(int i=ib;i<im;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	re=max(re,res); res=0; in =0;
	if (r>0)
		{for(int i=1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	if(r<0)
	{
		for(int i=1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	im =in;
	if (p>0)
		{for(int i=0;i<im;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if(p<0)
	{
		for(int i=0;i<im;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if (q>0)
		{for(int i=in+1;i<=im;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	if(q<0)
	{
		for(int i=in+1;i<=im;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	re=max(re,res); res=0;in=0;
	if (r>0)
		{for(int i=1;i<n;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	if(r<0)
	{
		for(int i=1;i<n;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*r;
	}
	im=in;
	if (q>0)
		{for(int i=0;i<im;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	if(q<0)
	{
		for(int i=0;i<im;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*q;
	}
	im=in;
	if (p>0)
		{for(int i=0;i<im;i++)
		{
			if(val[i]>val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	if(p<0)
	{
		for(int i=0;i<im;i++)
		{
			if(val[i]<val[in])
				in = i;
		}
		res+=val[in]*p;
	}
	re=max(re,res);
	cout<<re;

	return 0;
}