#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[tam];

int n;
const int Log2Tam = (log(tam)/log(2)) + 3;
vector<vi> dp(tam, vi(Log2Tam, -1));
int depth[tam];
int paro[tam];
int root = 0; // nodos, aristas, raiz del arbol

void initDFS(int v, int p, int d)
{
    paro[v] = p;
	dp[v][0] = p; // padre inmediato
	depth[v] = d;
	for (int u : g[v])
	{
		if (u == p) continue;
		initDFS(u, v, d+1);
	}
}

void initLCA()
{
	initDFS(root, -1, 0);
	for (int pot = 1; pot < Log2Tam; pot++)
	{
		for (int v = 0; v < n; v++)
		{
			if (dp[v][pot-1] == -1) continue;
			dp[v][pot] = dp[ dp[v][pot-1] ][pot-1];
		}
	}
}

int LCA(int a, int b)
{
	// b siempre debajo o al mismo nivel que a
	if (depth[a] > depth[b]) swap(a, b);
	
	int diff = depth[b] - depth[a];
	for (int pot = Log2Tam-1; pot >= 0; pot--)
	{
		if ( ( diff & (1 << pot) ) )
		{
			b = dp[b][pot];
		}
	}
	if (a == b) return a;
	for (int pot = Log2Tam-1; pot >= 0; pot--)
	{
		if (dp[a][pot] != dp[b][pot])
		{
			a = dp[a][pot];
			b = dp[b][pot];
		}
	}
	int lca = dp[a][0];
	return lca;
}

vi ar(tam);
vii ask[tam];
struct base
{
    vi las;
    vi bas;
    base() {bas = vi(20);}
    bool add(int x)
    {
        bool res = 0;
        fore(i, 0, 20)
            if(x & (1<<i))
            {
                if(bas[i])
                    x ^= bas[i];
                else
                {
                    bas[i] = x;
                    las.pb(i);
                    res = 1;
                    break;
                }
            }
        return res;
    }
    void popo()
    {
        bas[las.back()] = 0;
        las.pop_back();
    }
};
struct baso{
    vi bas;
    baso() {bas = vi(20);}
    void merge(vi & b)
    {
        for(int x : b)
            fore(i, 0, 20)
                if(x & (1<<i))
                {
                    if(bas[i])
                        x ^= bas[i];
                    else
                    {
                        bas[i] = x;
                        break;
                    }
                }
    }
    bool can(int x)
    {
        
        fore(i, 0, 20)
            if(x & (1<<i))
            {
                if(bas[i])
                    x ^= bas[i];
                else
                {
                    return false;
                }
            }
        return true;
    }
};
base bases[tam];
baso respo[tam];
void dfs(int node, int par)
{
    vi acto;
    int ax = node;
    // cout<<"### "<<node<<' '<<par<<'\n';
    while(ax != -1)
    {
        // cout<<"in "<<ax<<'\n';
        if(bases[ax].add(ar[node]))
            acto.pb(ax);
        else
            break;
        ax = paro[ax];
    }
    for(ii cat : ask[node])
    {
        // cout<<cat.f<<' '<<cat.s<<'\n';
        respo[cat.s].merge(bases[cat.f].bas);
    }
    for(int x : g[node])
        if(x != par)
            dfs(x, node);
    for(int x : acto)
    {
        // cout<<"out "<<x<<'\n';
        // cout<<bases[x].bas.size()<<'\n';
        bases[x].popo();
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    // int n;
    cin>>n;
    fore(i, 0, n) cin>>ar[i];
    fore(i, 0, n - 1)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int q;
    cin>>q;
    initLCA();
    vi ques;
    fore(i, 0, q)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        int lc = LCA(a, b);
        // cout<<a + 1<<' '<<b + 1<<' '<<lc + 1<<'\n';
        ask[a].pb({lc, i});
        ask[b].pb({lc, i});
        ques.pb(c);
    }
    dp.clear();
    dfs(0, -1);
    fore(i, 0, q)
    {
        // fore(j, 0, 4) cout<<j<<' '<<respo[i].bas[j]<<'\n';
        if(respo[i].can(ques[i]))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
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
