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
vi g[2005];
int pe[2005], d;
bool marc[2005], visited[2005];
ll dfs(int node, int val)
{
	if(pe[node] < val || (pe[node] == val && marc[node]) || pe[node] - val > d)
		return 0;
	ll tot = 1;
	visited[node] = 1;
	for(int i = 0; i < g[node].size(); i++)
	{
		if(!visited[g[node][i]])
			tot *= 1 + dfs(g[node][i], val), tot %= MOD;
	}
	return tot;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, a, b;
	cin>>d>>n;
	mem(marc,0);
	for(int i = 0; i < n; i++)
		cin>>pe[i];
	for(int i = 0; i < n-1; i++)
	{
		cin>>a>>b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		mem(visited, 0);
		res += dfs(i, pe[i]);
		res %= MOD;
		marc[i] = 1;
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS