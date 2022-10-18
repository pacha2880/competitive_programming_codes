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
#define forn(i, m)			for(int i = 0; i < n; i++)
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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
int g[5050];
bool visited[5050], pros[5050];
vector<int> gr[5050], ngr[5050];
int low[5050], us[5050];
int cont = 0, ncont = 0;
void tarjan(int node)
{
	low[node] = cont++;
	visited[node] = 1;
	fore(i, 0, gr[node].size())
	{
		if(!visited[gr[node][i]])
		{
			tarjan(gr[node][i]);
			low[node] = min(low[node], low[gr[node][i]]);
		}
		else if(!pros[gr[node][i]])
			low[node] = min(low[node], low[gr[node][i]]);
	}
	pros[node] = 1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, c;
	int a, b;
	cin>>n>>m>>c;
	c--;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--, b--;
		gr[a].pb(b);
	}
	fore(i, 0, n)
	{
		if(!visited[i])
			tarjan(i);
	}
	mem(us, -1);
	int cont = 0, node;
	set<int> st;
	fore(i, 0, n)
	{
		st.insert(low[i]);
	}
	for(auto a : st)
	{
		us[a] = cont++;
	}
	fore(i, 0, n)
	{
		low[i] = us[low[i]];
	}
	bool bo = true;
	fore(i, 0, n)
	{
		node = low[i];
		if(c == i && bo)
		{
			bo = false;
			c = node;
		}
		fore(j, 0, gr[i].size())
			if(low[i] != low[gr[i][j]])
				ngr[node].pb(low[gr[i][j]]);
	}
	int con = 0;
	fore(i, 0, cont)
	{
		//cout<<"node: "<<i<<'\n';
		fore(j, 0, ngr[i].size())
		{
			//cout<<ngr[i][j]<<' ';
			g[ngr[i][j]]++; 
		}
	}
	//cout<<'\n'<<c<<'\n';
	fore(i, 0, cont)
	{
		if(i != c)
			con += g[i] == 0;
	}
	cout<<con<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	