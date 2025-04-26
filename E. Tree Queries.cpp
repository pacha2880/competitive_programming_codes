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
vi g[tam];
int ar[tam], t[ 4 * tam], laz[4 * tam];
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
    t[node] = max(t[r], t[l]);
}
void push(int node, bool lif)
{
    if(laz[node])
    {
        t[node] += laz[node];
        if(!lif)
            laz[node * 2 + 1] += laz[node], laz[node * 2 + 2] += laz[node];
        laz[node] = 0;
    }
}
void update(int b, int e, int node, int i, int j, int val)
{
    if(i > j) return;
    if(b > e) return;
    push(node, b == e);
    if(j < b || i > e) return;
    if(i <= b && j >= e)
    {
        laz[node] += val;
        push(node, b == e);
        return;
    }
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    update(b, mid, l, i, j, val);
    update(mid + 1, e, r, i, j, val);
    t[node] = max(t[l], t[r]);
}
int query(int b, int e, int node, int i, int j)
{
    push(node, b == e);
    if(i <= b && j >= e) return t[node];
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return max(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
int con = 0;
int ini[tam], fini[tam];
void dfs(int node, int pa = -1, int dep = 0)
{
    ar[con] = dep;
    ini[node] = con++;
    for(int x : g[node])
        if(x != pa)
            dfs(x, node, dep + 1);
    fini[node] = con - 1;
}
int res[tam];
vector<pair<int, vi>> ques[tam];
int ch[tam];
void calc(int node, int pa = -1)
{
    for(auto cat : ques[node])
    {
        vii sweep;
        for(int x : cat.s)
        {
            if(ini[x] <= ini[node] && fini[x] >= ini[node])
                sweep.pb({0, -1}), sweep.pb({ini[ch[x]], 1}), sweep.pb({fini[ch[x]] + 1, -1});
            else
                sweep.pb({ini[x], -1}), sweep.pb({fini[x] + 1, 1});

        }
        sort(all(sweep));
        int re = 0;
        int las = 0, val = 0;
        for(ii cat : sweep)
        {
            swap(cat.f, cat.s);
            if(val == 0 && cat.s > las)
                re = max(re, query(0, con - 1, 0, las, cat.s - 1));
            val += cat.f;
            las = cat.s;
        }
        if(val == 0 && las < con)
            re = max(re, query(0, con - 1, 0, las, con - 1));
        res[cat.f] = re;
    }
    for(int x : g[node])
    {
        if(x != pa)
        {
            update(0, con - 1, 0, 0, ini[x] - 1, 1);
            update(0, con - 1, 0, ini[x], fini[x], -1);
            update(0, con - 1, 0, fini[x] + 1, con - 1, 1);
            ch[node] = x;
            calc(x, node);
            update(0, con - 1, 0, 0, ini[x] - 1, -1);
            update(0, con - 1, 0, ini[x], fini[x], 1);
            update(0, con - 1, 0, fini[x] + 1, con - 1, -1);
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, q;
    cin>>n>>q;
    fore(i, 1, n)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    dfs(0);
    init(0, con - 1, 0);
    fore(i, 0, q)
    {
        int x, k;
        cin>>x>>k;
        x--;
        vi v(k);
        fore(i, 0, k) cin>>v[i], v[i]--;
        ques[x].pb({i, v});
    }
    calc(0);
    fore(i, 0, q) cout<<res[i]<<'\n';
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
