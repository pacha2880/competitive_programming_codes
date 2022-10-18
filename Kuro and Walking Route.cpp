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
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int f,bee;
vector<vector<int> > g;
bool visited[400000];
pair<ll,bool> dfs(int node)
{
	visited[node]=1;
	ll a=1;
	pair<ll,bool> p;
	for(int i =0;i<g[node].size();i++)
	{
		if(!visited[g[node][i]])
		{
			p = dfs(g[node][i]);
			if(p.second)
				return p;
			else
				a+=p.first;
		}
	}
	if(node == bee)
	{
		return make_pair(a,1);
	}
	else
		return make_pair(a,0);
}
ll fdfs()
{
	visited[f] = 1;
	pair<ll,bool> p;
	ll a = 0,b=1;
	for(int i=0;i<g[f].size();i++)
	{
		p = dfs(g[f][i]);
		if(p.second)
			a = p.first;
		else
			b+= p.first;
	}
	return b * a;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,a,b;
	cin>>n>>f>>bee;
	if(n==1) {cout<<0; return 0;}
	f--;
	bee--;
	vi v;
	g.assign(n,v);
	memset(visited,0,sizeof(visited));
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll t = n*(n-1ll), re = fdfs(), res= t-re;
	cout<<res;
	return 0;
}