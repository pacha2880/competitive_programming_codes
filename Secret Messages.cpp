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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[tam];
vector<vi> par(tam), dispa(tam);
vector<vi> bits(tam);
void add(int node, int pro, int val)
{
    while(pro < sz(bits[node]))
        bits[node][pro] += val, pro += pro & -pro;
}
int query(int node, int pro)
{
    int res = 0;
    pro = min(pro, sz(bits[node]) - 1);
    while(pro > 0)
    {
        res += bits[node][pro];
        pro -= pro & -pro;
    }
    return res;
}
vi siz(tam), cintra(tam);
int sisi(int node, int pa, int dis, int papazo)
{
    int res = 1;
    if(papazo != -1)
        par[node].pb(papazo), dispa[node].pb(dis);
    siz[node] = 1;
    for(int x : g[node])
        if(x != pa && !cintra[x])
            res += sisi(x, node, dis + 1, papazo), siz[node] += siz[x];
    return res;
}
int centruida(int node, int pa, int simp)
{
    for(int x : g[node])
        if(x != pa && !cintra[x])
            if(siz[x] > simp / 2)
                return centruida(x, node, simp);
    return node;
}
vi res(tam);
void calco(int node, int pa, int dis, int papito, int addo)
{
    // cout<<papito<<' '<<node<<' '<<dis<<' '<<addo<<'\n';
    add(papito, dis, addo);
    for(int x : g[node])
        if(x != pa && !cintra[x])
            calco(x, node, dis + 1, papito, addo);
}
int k;
void centauros(int node, int pa = -1)
{
    // cout<<"asdfsdfgsgd\n";
    // cout<<node<<' '<<pa<<'\n';
    int tato = sisi(node, -1, 1, pa);
    int centris = centruida(node, -1, siz[node]);
    // cout<<centris<<'\n';
    cintra[centris] = 1;
    bits[centris].resize(tato + 2);
    calco(centris, -1, 1, centris, 1);
    int di = 0;
    fore(i, 0, sz(par[centris]))
    {
        // cout<<i<<' '<<di<<' '<<query(par[centris][i], k + 1 - dispa[centris][i])<<'\n';
        res[centris] += query(par[centris][i], k + 1 - dispa[centris][i]);
    }
    res[centris] += query(centris, k + 1);
    // cout<<query(centris, k + 1)<<'\n';
    // cout<<res[centris]<<'\n';
    for(int x : g[centris])
        if(!cintra[x])
        {
            calco(x, centris, 2, centris, -1);
            centauros(x, centris);
            calco(x, centris, 2, centris, 1);
        }
    cintra[centris] = 0;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n>>k;
    fore(i, 0, n - 1)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    centauros(0);
    fore(i, 0, n)
        cout<<res[i]<<'\n';
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
