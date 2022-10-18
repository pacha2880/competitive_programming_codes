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
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;

vector<int> G[tam];
int dpMin[tam], dpMax[tam];
int leafVal[tam];

void initDP(int v, int p)
{
	if (G[v].size() == 0) 
	{
		dpMin[v] = dpMax[v] = leafVal[v];
		return;
	}
	dpMin[v] = INT_MAX;
	dpMax[v] = -1;
	for (int u : G[v])
	{
		if (u == p) continue;
		initDP(u, v);
		dpMin[v] = min(dpMin[v], dpMin[u]);
		dpMax[v] = max(dpMax[v], dpMax[u]);
	}
}

int getMin(int v, int k)
{
	if (G[v].size() == 0) return leafVal[v];
	if (k == 0) return dpMax[v];
	int bestChild = INT_MAX;
	if (G[v].size() == 1) 
	{
		bestChild = getMin(G[v][0], k);
		return bestChild;
	}
	for (int u : G[v])
	{
		bestChild = min(bestChild, getMin(u, k-1));
	}
	return bestChild;
}

int getMax(int v, int k)
{
	if (G[v].size() == 0) return leafVal[v];
	if (k == 0) return dpMin[v];
	int bestChild = -1;
	if (G[v].size() == 1) 
	{
		bestChild = getMax(G[v][0], k);
		return bestChild;
	}
	for (int u : G[v])
	{
		bestChild = max(bestChild, getMax(u, k-1));
	}
	return bestChild;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		G[p].pb(i);
	}
	int l = 0;
	fore(i, 0, n) l += (G[i].size() == 0);
	fore(i, 0, n) cin >> leafVal[i];
	initDP(0, -1);
	cout << getMin(0, k) << ' ' << getMax(0, n-k-l) << '\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2