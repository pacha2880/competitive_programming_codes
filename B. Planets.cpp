#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
map<ll,ll> ma[200005];
vi g[200005];
vll gp[200005];
int n;
ll dij(int b, int e)
{
	ll dist[n];
	for(int i = 0; i < n; i++)
		dist[i] = 1e17;
	dist[0] = ma[0][0];
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	que.push(mp(ma[0][0],0));
	ll t;
	while(!que.empty())
	{
		e = que.top().f, b = que.top().s;
		//cout<<b<<endl;
		que.pop();
		for(int i = 0; i < g[b].size(); i++)
		{
			t = e + gp[b][i];
			if(ma[g[b][i]][t] && g[b][i] != n-1)
				t = ma[g[b][i]][t];
			if(dist[g[b][i]] > t)
			{
				dist[g[b][i]] = t;
				if(g[b][i]!= n-1)
					que.push(mp(t,g[b][i]));
			}
		}
	}
	return dist[n-1];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int m, a, b, c, fro,to;
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		cin>>a>>b>>c;
		a--,b--;
		g[a].pb(b);
		g[b].pb(a);
		gp[a].pb(c);
		gp[b].pb(c);
	}
	bool ba = false, be;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		ba = false;
		be = false;
		for(int j = 0; j < a; j++)
		{
			cin>>b;
			if(ba)
			{
				if(c + 1 == b)
				{
					if(!be)
					{
						be = true; fro = c;
					}
				}
				else
				{
					if(be)
					{
						to = c;
						be = false;
						for(int k = fro; k <= to; k++)
							ma[i][k] = c + 1;
					}
					else
						ma[i][c] = c + 1;
				}
			}
			ba = true;
			c = b;
		}
		if(a)
		{
			if(be)
			{
				to = c;
				be = false;
				for(int k = fro; k <= to; k++)
					ma[i][k] = c + 1;
			}
			else
				ma[i][c] = c + 1;
		}
	}
	ll res = dij(0,n-1);
	if(res  == 1e17)
		cout<<-1;
	else
		cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS