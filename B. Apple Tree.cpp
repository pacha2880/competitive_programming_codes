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
vector<int> g[100010];
ll lef[100010];
pair<ll, pair<ll, ll>> bala[100010];
void reco(int node, int pa)
{
	//cout<<node + 1<<'\n';
	if(g[node].size() == 1 && node != 0)
	{
		bala[node] = mp(1, mp(lef[node], lef[node]));
		return;
	}
	ll mini = 1e17;
	bala[node] = mp(0, mp(0, 0));
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != pa)
		{
			reco(g[node][i], node);
			mini = min(mini, bala[g[node][i]].s.f);
			bala[node].s.s += bala[g[node][i]].s.s;
			//cout<<bala[g[node][i]].f<<' '<<bala[g[node][i]].s.f<<' '<<bala[g[node][i]].s.s<<'\n';
		}
	}
	//cout<<node + 1<<"#\n";
	ll mc = 1;
	fore(i, 0, g[node].size())
	{
		if(g[node][i] != pa)
		{
			mc = mc / __gcd(mc, bala[g[node][i]].f) * bala[g[node][i]].f;
			if(mc > mini)
			{
				bala[node].f = 1;
				bala[node].s.f = 0;
				return;
			}
		}
	}
	bala[node].f = mc * ((int)g[node].size() - (node != 0));
	bala[node].s.f = (mini - mini % mc) * ((int)g[node].size() - (node != 0));
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n) cin>>lef[i];
	int a, b;
	fore(i, 0, n-1)
	{
		cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	reco(0, -1);
	cout<<bala[0].s.s - bala[0].s.f<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2