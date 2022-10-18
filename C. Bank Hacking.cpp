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
int ar[400000], t[2000000];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = ar[b];
		return;
	}
	int l = node * 2 + 1, r = l + 1, mid = (b + e) / 2;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = max(t[l], t[r]);
}
void update(int b, int e, int node, int pos, int val)
{
	if(b == e)
	{
		t[node] += val;
		return;
	}
	int l = node * 2 + 1, r = l + 1, mid = (b + e) / 2;
	if(pos > mid)
		update(mid + 1, e, r, pos, val);
	else
		update(b, mid, l, pos, val);
	t[node] = max(t[l], t[r]);
}
vector<int> g[400000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	int n;
	cin>>n;
	fore(i, 0, n) {cin>>ar[i]; ar[i] += 2; }
	int a, b;
	fore(i, 0, n-1)
	{
		cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	init(0, n - 1, 0);
	int res = MOD, ras;
	fore(i, 0, n)
	{
		update(0, n - 1, 0, i, -2);
		fore(j, 0, g[i].size())
		{
			update(0, n - 1, 0, g[i][j], -1);
		}
		res = min(res, t[0]);
		update(0, n - 1, 0, i, 2);
		fore(j, 0, g[i].size())
		{
			update(0, n - 1, 0, g[i][j], 1);
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	