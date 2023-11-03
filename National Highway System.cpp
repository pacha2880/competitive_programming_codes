#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 500010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int Log2Tam = (log(tam)/log(2)) + 3;

vector< vii > g(tam);
int dp[tam][Log2Tam], depth[tam];
int mini[tam][Log2Tam];
int n, root; // nodos, aristas, raiz del arbol

void initDFS(int v, int p, int d, int pre)
{
	dp[v][0] = p; // padre inmediato
    mini[v][0] = pre;
	depth[v] = d;
	for (ii u : g[v])
	{
		if (u.f == p) continue;
		initDFS(u.f, v, d+1, u.s);
	}
}

void initLCA()
{
	mem(dp, -1);
	initDFS(root, -1, 0, 0);
	for (int pot = 1; pot < Log2Tam; pot++)
	{
		for (int v = 0; v < n; v++)
		{
			if (dp[v][pot-1] == -1) continue;
			dp[v][pot] = dp[ dp[v][pot-1] ][pot-1];
            mini[v][pot] = max(mini[v][pot-1], mini[dp[v][pot-1]][pot-1]);
		}
	}
}

int LCA(int a, int b)
{
	// b siempre debajo o al mismo nivel que a
	if (depth[a] > depth[b]) swap(a, b);
	
	int diff = depth[b] - depth[a];
    int res = 0;
	for (int pot = Log2Tam-1; pot >= 0; pot--)
	{
		if ( ( diff & (1 << pot) ) )
		{
            res = max(res, mini[b][pot]);
			b = dp[b][pot];
		}
	}
	if (a == b) return res;
	for (int pot = Log2Tam-1; pot >= 0; pot--)
	{
		if (dp[a][pot] != dp[b][pot])
		{
            res = max(res, mini[a][pot]);
			a = dp[a][pot];
            res = max(res, mini[b][pot]);
			b = dp[b][pot];
		}
	}
	return max(res, max(mini[a][0], mini[b][0]));
}
struct unionFind {
  vi p;
  unionFind(int n) : p(n, -1) {}
  int findParent(int v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	// int n;
    cin>>n;
    vector<pair<pair<string, string>, int>> ar(n);
    map<string, int> ma;
    int can = 0;
    fore(i, 0, n)
    {
        string a, b;
        int c;
        cin>>a>>b>>c;
        if(!ma.count(a))
            ma[a] = can++;
        if(!ma.count(b))
            ma[b] = can++;
        ar[i] = {{a, b}, c};
    }
    vector<pair<pair<int, int>, int>> ari(n);
    fore(i, 0, n)
    {
        ari[i] = {{ma[ar[i].f.f], ma[ar[i].f.s]}, ar[i].s};
    }
    sort(all(ari), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        return a.s < b.s;
    });
    unionFind uni(can);
    int ans = 0;
    vector<pair<pair<int, int>, int>> otras;
    int jons = 0;
    for(auto cat : ari)
    {
        if(uni.join(cat.f.f, cat.f.s))
            ans += cat.s, g[cat.f.f].pb({cat.f.s, cat.s}), g[cat.f.s].pb({cat.f.f, cat.s}), jons++;
        else
            otras.pb(cat);
    }
    if(jons < can - 1)
    {
        cout<<"-1\n";
        return 0;
    }
    root = 0;
    initLCA();
    n = can;
    // cout<<ans<<'\n';
    for(auto cat : otras)
    {
        // cout<<cat.f.f<<' '<<cat.f.s<<' '<<cat.s<<' '<<LCA(cat.f.f, cat.f.s)<<'\n';
        if(LCA(cat.f.f, cat.f.s) == cat.s)
        {
            ans += cat.s;
        }
    }
    cout<<ans<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
