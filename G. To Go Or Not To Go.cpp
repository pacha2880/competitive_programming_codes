#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
const int tam = 2010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll mino[2] = {1ll * MOD * MOD, 1ll * MOD * MOD};
ll mano = 1ll * MOD * MOD;
int lol = -1;
int n, m, w;
int ar[tam][tam];
bool vis[tam][tam];
int dir[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
bool can(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && ar[x][y] > -1;
}
pair<ll, pair<int, int>> que[tam * tam];
int pos = 0;
void dfs(int x, int y, int cas, ll pes)
{
	pos = 0;
	int pus = 0;
	que[pos++] = mp(0, mp(x, y));
	while(pos > pus)
	{
		x = que[pus].s.f;
		y = que[pus].s.s;
		pes = que[pus].f;
		pus++;
		if(cas == 0 && x == n - 1 && y == m - 1)
			mano = pes;
		if(ar[x][y] > 0)
			mino[cas] = min(mino[cas], pes + ar[x][y]);
		fore(k, 0, 4)
		{
			int a = x + dir[0][k], b = y + dir[1][k];
			if(can(a, b))
			{
				vis[a][b] = 1;
				que[pos++] = mp(pes + w, mp(a, b));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n>>m>>w;
	fore(i, 0, n)
	fore(j, 0, m)
	cin>>ar[i][j];
	dfs(0, 0, 0, 0);
	mem(vis, 0);
	dfs(n - 1, m - 1, 1, 0);
	ll info = 1LL * MOD * MOD;
	ll res = mano;
	// cout<<mano<<' '<<mino[0]<<' '<<mino[1]<<'\n';
	if(mino[0] != info && mino[1] != info)
		res = min(res, mino[0] + mino[1]);
	if(res == info)
		cout<<-1<<'\n';
	else
		cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	