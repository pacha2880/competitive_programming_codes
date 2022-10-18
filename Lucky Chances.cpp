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
int k;
struct radi
{
	int maxl,maxr,maxu,maxd;
	radi(int a,int b,int c,int d)
	{
		maxl=a, maxr=b, maxu=c, maxd=d;
	}
	radi unir (radi b)
	{
		radi c (min(b.maxl,maxl),max(b.maxr,maxr),max(b.maxu,maxu),min(b.maxd,maxd));
		return c;
	}
	bool inside(radi a)
	{
		return min(abs(maxl-a.maxd),abs(maxd-a.maxl))+min(abs(maxu-a.maxd),abs(maxd-a.maxu))<=4*k;
	}

};
vector<int> parent;
int find(int a)
{
	if(parent[a]==-1) return a;
	return find(parent[a]);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);a
	int n,a,b;
	cin>>k>>n;
	parent.assign(n,-1);
	radi t(0,0,0,0);
	vector<radi> grupo;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		radi c(a,a,b,b);
		
		for(int j=0;j<grupo.size();j++)
		{
			t=grupo[find(j)];
			if(c.inside(t))
			{
				c=c.unir(t);
				parent[j]=i;
			}
			
		}
		grupo.pb(c);
	}
	vector<radi> res;
	for (int i = 0; i < n; ++i)
	{
		if(parent[i]==-1)
		{
			t=grupo[i];
			res.pb(t);
		}
	}
	int resp=0;
	for (int i = 0; i < res.size(); ++i)
	{
		
		resp+=2*(res[i].maxu-res[i].maxd)+2*(res[i].maxr-res[i].maxl)+8*k;
	}
	cout<<resp;

	return 0;
}


