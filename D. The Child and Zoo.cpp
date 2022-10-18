	#include <bits/stdc++.h>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int tam = 10000010;
pair<int, int> nods[100010];
set<int> g[100010];
int parent[100010];
int siz[100010];
int find(int n)
{
	if(parent[n] == -1) return n;
	return parent[n] = find(parent[n]);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, n)
	{
		cin>>nods[i].f;
		nods[i].s = i;
	}
	int a, b;
	mem(parent, -1);
	fore(i, 0, n) siz[i] = 1;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	fore(i, 0, n)
	{
		for(auto p : g[i])
		{
			if(nods[i].f <= nods[p].f)
				g[p].erase(i);
		}
	}
	sort(nods, nods + n);
	reverse(nods, nods + n);
	ll res = 0;
	int val, node;
	fore(i, 0, n)
	{
		//cout<<nods[i].s<<'\n';
		node = nods[i].s;
		val = nods[i].f;
		for(auto nod : g[node])
		{
			a = find(node), b = find(nod);
			//cout<<nod<<' '<<a<<' '<<b<<' '<<val<<'\n';
			if(a != b)
			{
				res += 1ll * val * siz[a] * siz[b];
				parent[a] = b;
				siz[b] += siz[a];
			}
			//cout<<"asf"<<res<<'\n';
		}
	}
	cout<<fixed<<setprecision(5)<<2.0*res/n/(n-1)<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2