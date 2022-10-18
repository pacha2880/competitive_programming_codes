#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_nodo_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll mucor[2][100010];
ll res[100010], cort[100010];
vector<int> g[100010];
bool pin[100010];
void dfs(int node, int par)
{
	vector<int> go;
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != par)
		{
			dfs(g[node][i], node);
			if(pin[g[node][i]])
				go.pb(g[node][i]);
		}
	}
	if(pin[node])
	{
		cort[node] = 0;
		res[node] = 1;
		fore(i, 0, go.size())
		{
			res[node] = res[node] * (cort[go[i]] + res[go[i]]) % MOD;
		}
	}
	else
	{
		if(go.size() > 0)
		{
			int n = go.size();
			mucor[0][0] = (cort[go[0]] + res[go[0]]) % MOD;
			mucor[1][n - 1] = (cort[go[n - 1]] + res[go[n - 1]]) % MOD;
			fore(i, 1, n)
			{
				mucor[0][i] = mucor[0][i - 1] * ((cort[go[i]] + res[go[i]]) % MOD) % MOD;
				mucor[1][n - i - 1] = mucor[1][n - i] * 
							((cort[go[n - i - 1]] + res[go[n - i - 1]]) % MOD) % MOD;
			}
			fore(i, 0, n)
			{
				res[node] = (res[node] + (i > 0 ? mucor[0][i - 1] : 1) * res[go[i]]
					        % MOD * (i < n - 1 ? mucor[1][i + 1] : 1) % MOD) % MOD;
			}
			cort[node] = mucor[1][0];
		}
	}
	pin[node] |= go.size() > 0;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	int a;
	fore(i, 0, n - 1)
	{
		cin>>a;
		g[a].pb(i + 1);
		g[i + 1].pb(a);
	}
	int x;
	fore(i, 0, n)
	{
		cin>>x;
		pin[i] = x;
	}
	dfs(0, -1);
	cout<<res[0]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	