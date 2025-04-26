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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi t[4 * tam], ocu[tam];
int si[4 * tam], ar[tam];
void merge(int l, int r, int b, int e, int node)
{
    int frec = si[node] / 5;
    int i = 0;
    for(int j = 0; j < sz(t[r]); j++)
    {
        while(i < sz(t[l]) && t[l][i] < t[r][j])
        {
            if(upper_bound(all(ocu[t[l][i]]), e) - lower_bound(all(ocu[t[l][i]]), b) > frec)
                t[node].pb(t[l][i]);
            i++;
        }
        if(i < sz(t[l]) && t[l][i] == t[r][j])
            i++;
        if(upper_bound(all(ocu[t[r][j]]), e) - lower_bound(all(ocu[t[r][j]]), b) > frec)
            t[node].pb(t[r][j]);
    }
    while(i < sz(t[l]))
    {
        if(upper_bound(all(ocu[t[l][i]]), e) - lower_bound(all(ocu[t[l][i]]), b) > frec)
            t[node].pb(t[l][i]);
        i++;
    }
}
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node].pb(ar[b]);
        si[node] = 1;
        return ;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    si[node] = si[l] + si[r];
    merge(l, r, b, e, node);
}
int res;
vi vis(tam), vas;
int l, r;
void query(int b, int e, int node, int i, int j, int k)
{
    if(e < i || b > j) return;
    if(b >= i && e <= j)
    {
        for(int x : t[node])
        {
            if(vis[x]) continue;
            vis[x] = 1, vas.pb(x);
            if(upper_bound(all(ocu[x]), j) - lower_bound(all(ocu[x]), i) > k)
                res = min(res, x);
        }
        return;
    }
    index;
    query(b, mid, l, i, j, k);
    query(mid + 1, e, r, i, j, k);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int n, q;
    cin>>n>>q;
    fore(i, 0, n) cin>>ar[i], ocu[ar[i]].pb(i);
    init(0, n - 1, 0);
    while(q--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        res = MOD;
        query(0, n - 1, 0, a, b, (b - a + 1) / c);
        if(res == MOD)
            cout<<-1<<'\n';
        else
            cout<<res<<'\n';
        for(int x : vas)
            vis[x] = 0;
        vas.clear();
    }
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
