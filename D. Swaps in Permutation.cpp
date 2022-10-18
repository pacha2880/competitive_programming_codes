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
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[1000100];
bool visited[1000100];
int ar[1000100];
vector<pair<int, int>> cha;
void dfs(int node)
{
	visited[node] = 1;
	cha.pb({ar[node], node});
	fore(i, 0, g[node].size())
	{
		if(!visited[g[node][i]])
			dfs(g[node][i]);
	}
}
int pos[1000010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a, b;
	fore(i, 0, n) cin>>ar[i];
	while(m--)
	{
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	fore(i, 0, n)
	{
		if(!visited[i])
		{
			dfs(i);
			sort(all(cha));
			reverse(all(cha));
			fore(i, 0, cha.size())
			pos[i] = cha[i].s;
			sort(pos, pos + (int)cha.size());
			fore(i, 0, cha.size())
			{
				ar[pos[i]] = cha[i].f;
			}
			cha.clear();
		}
	}
	fore(i, 0, n)
	{
		if(i > 0)
			cout<<' ';
		cout<<ar[i];
	}
	cout<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	