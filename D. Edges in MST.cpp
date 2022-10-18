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
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
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
pair<pair<int, int>, pair<int, int>> ar[100010], temp[100010];
int parent[100010];
vector<pair<int, int>> g[100010];
int find(int n)
{
	if(parent[n] == -1)
		return n;
	return parent[n] = find(parent[n]);
}
bool visited[100010];
int res[100010];
int times[100010];
void dfs(int node, int time, int par)
{
	visited[node] = true;
	times[node] = time;
	//cout<<"dfs "<<node<<' '<<time<<' '<<par<<' '<<visited[node]<<'\n';
	fore(i, 0, g[node].size())
	{
		if(g[node][i].s != par)
		{
			res[g[node][i].s] = 1;
			if(visited[g[node][i].f])
			{
				res[g[node][i].s] = 2;
				times[node] = min(times[node], times[g[node][i].f]);
			}
			else
			{
				dfs(g[node][i].f, time + 1, g[node][i].s);
				if(time >= times[g[node][i].f])
				{
					res[g[node][i].s] = 2;
					times[node] = min(times[node], times[g[node][i].f]);
				}
			}
		}
	}
}
pair<pair<int, int>, int> cha[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a, b, c;
	fore(i, 0, m)
	{
		cin>>a>>b>>c;
		ar[i] = {{c, i}, {a, b}};
	}
	sort(ar, ar + m);
	int val = ar[0].f.f, con = 0, can;
	mem(parent, -1);
	fore(i, 0, m + 1)
	{
		if(val != ar[i].f.f || i == m)
		{
			can = 0;
			fore(i, 0, con)
			{
				a = find(temp[i].s.f);
				b = find(temp[i].s.s);
				if(a != b)
				{
					cha[can++] = {{a, b}, temp[i].f.s};
				}
			}
			set<int> st;
			fore(i, 0, can)
			{
				st.insert(cha[i].f.f);
				st.insert(cha[i].f.s);
			}
			for(auto cat : st)
			{
				visited[cat] = 0;
				g[cat].clear();
			}
			fore(i, 0, can)
			{
				//cout<<cha[i].f.f<<' '<<cha[i].f.s<<' '<<cha[i].s<<" coco\n";
				g[cha[i].f.f].pb({cha[i].f.s, cha[i].s});
				g[cha[i].f.s].pb({cha[i].f.f, cha[i].s});
			}
			for(auto cat : st)
			{
				if(!visited[cat])
				{
					//cout<<"cha\n";
					dfs(cat, 0, -1);
				}
				//cout<<cat<<' '<<times[cat]<<'\n';
			}
			fore(i, 0, con)
			{
				a = find(temp[i].s.f);
				b = find(temp[i].s.s);
				if(a != b)
					parent[a] = b;
			}
			temp[0] = ar[i];
			val = ar[i].f.f;
			con = 1;
		}
		else
		{
			temp[con++] = ar[i];
		}
	}
	fore(i, 0, m)
		cout<<(res[i] == 0 ? "none" : res[i] == 1 ? "any" : "at least one")<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	