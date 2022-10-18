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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[550];
int con = 0;
set<pair<int, int>> backs[15];
pair<int, int> avo;
bool visited[550], proc[550];
int sal[550];
void llen(int node)
{
	visited[node] = 1;
	fore(i, 0, g[node].size())
	{
		if(node != avo.f || g[node][i] != avo.s)
		{
			if(!visited[g[node][i]])
			{
				//cout<<node + 1<<' '<<g[node][i] + 1<<'\n';
				sal[node] = g[node][i];
				llen(g[node][i]);
			}
			if(!proc[g[node][i]])
				backs[con].insert(mp(g[node][i], sal[g[node][i]]));
		}
	}
	proc[node] = 1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int a, b;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--; b--;
		g[a].pb(b);
	}
	vector<int> v(n);
	fore(i, 0, n) v[i] = i;
	srand(time(0));
	double TLE = 0.5;
	double t = clock();
	while((clock() - t) / CLOCKS_PER_SEC < TLE)
	{
		mem(visited, 0);
		mem(proc, 0);
		con = 0;
		random_shuffle(all(v));
			avo = mp(-1, -1);
		backs[0].clear();
		fore(i, 0, n)
		{
			if(!visited[v[i]])
				llen(v[i]);
		}
		if(backs[0].size() == 0)
		{
			cout<<"YES\n";
			return 0;
		}
		if(backs[0].size() <= 2)
		{
			//cout<<"cacan\n";
			for(auto pa : backs[0])
			{
				mem(visited, 0);
				mem(proc, 0);
				//cout<<"mi avo:  "<<pa.f + 1 << ' ' << pa.s + 1 << '\n';
				avo = pa;
				con++;
				backs[con].clear();
				fore(i, 0, n)
				{
					if(!visited[i])
					{
						//cout<<i + 1<<'\n';
						llen(i);
					}
				}
				//cout<<'\n';
				if(backs[con].size() == 0)
				{
					cout<<"YES\n";
					return 0;
				}
				//cout<<backs[con].size()<<'\n';
				//for(auto pu : backs[con])
				//	cout<<'('<<pu.f + 1 << ',' << pu.s + 1<<") ";
				//cout<<'\n';
			}
		}
	}
	cout<<"NO\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	