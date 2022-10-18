	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	#define PI 				acos(-1)
	#define mp				make_pair
	#define pb				push_back
	#define all(a)			(a).begin(), (a).end()
	#define sz(a)			a.size()
	#define srt(a)			sort(all(a))
	#define mem(a, h)		memset(a, (h), sizeof(a))
	#define f 				first
	#define s 				second
	#define MOD1			998244353
	#define fore(i, b, e)	for(int i = b; i < e; i++)
	#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
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
	const int tam = 100010;
	const int MOD = 1e9+7;
	const double EPS = 1e-9;
	vector<int> g[100010], gp[100010];
	int posis[100010];
	bool dfs(int node)
	{
		bool res = true;
		fore(i, 0, g[node].size())
		{
			if(posis[g[node][i]] == -MOD)
			{
				posis[g[node][i]] = posis[node] + gp[node][i];
				res = res && dfs(g[node][i]);
			}
			else
				res = res && (posis[g[node][i]] == posis[node] + gp[node][i]);
		}
		return res;
	}
	int main()
	{
		ios::sync_with_stdio(0); cin.tie(0);
		//freopen("qwe.txt", "r", stdin);
		
		//freopen("asd.txt", "w", stdout);
		int n, m;
		cin>>n>>m;
		fore(i, 0, n) posis[i] = -MOD;
		int a, b, c;
		fore(i, 0, m)
		{
			cin>>a>>b>>c;
			a--, b--;
			g[a].pb(b);
			g[b].pb(a);
			gp[a].pb(c);
			gp[b].pb(-c);
		}
		bool res = true;
		fore(i, 0, n)
		{
			if(posis[i] == -MOD)
			{
				posis[i] = 0;
				res = res && dfs(i);
			}
		}
		cout<<(res?"Yes\n":"No\n");
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2