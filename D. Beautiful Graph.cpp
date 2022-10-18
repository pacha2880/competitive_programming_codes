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
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
vector<vi> g;
vi colores;
ll mod = 998244353ll;
pair<ll,ll> bicolor(int node, int color)
{
	pair<ll,ll> res(2,1),ax, ce(0,0);
	colores[node] = abs(color - 1);
	for(int i = 0; i < g[node].size(); i++)
	{
		if(colores[g[node][i]] == colores[node])
			return ce;
		if(colores[g[node][i]] == -1)
		{
			ax = bicolor(g[node][i],colores[node]);
			res.f *= ax.s;
			res.f %=mod;
			res.s *= ax.f;
			res.s %=mod;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int nn,n,m,a,b;
	cin>>nn;
	vi v;
	pair<ll,ll> res ;
	ll au;
	while(nn--)
	{
		cin>>n>>m;
		g.assign(n,v);
		colores.assign(n,-1);
		while(m--)
		{
			cin>>a>>b;
			g[a-1].pb(b-1);
			g[b-1].pb(a-1);
		}
		au = 1;
		for(int i= 0;  i<n; i++)
		{
			if(colores[i]==-1)
			{
				res = bicolor(i,0);
				au *= (res.f+res.s)%mod;
				au%=mod;
			}
		}
		cout<<au<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS