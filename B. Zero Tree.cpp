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
vi g[100001];
ll pe[100001];
bool visited[100001];
pair<ll,ll> dfs(int node)
{
	pair<ll,ll> res(0,0),r;
	visited[node] = 1;
	for(int i = 0; i < g[node].size(); i++)
	{
		if(!visited[g[node][i]])
		{
			r = dfs(g[node][i]);
			res.f = max(res.f, r.f);
			res.s = max(res.s, r.s);
		}
	}
	ll p = pe[node] + res.f - res.s;
	if(p > 0)
		res.s += p;
	else
		res.f -= p;
	//cout<<node<<' '<<res.f<<' '<<res.s<<endl;
	return res;
}	
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n,a,b;
	mem(visited,0);
	cin>>n;
	for(int i = 1; i < n; i++)
	{
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 0; i < n; i++)
		cin>>pe[i];
	pair<ll,ll> res;
	res = dfs(0);
	cout<<res.f + res.s;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS