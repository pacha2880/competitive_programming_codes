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
vi t[4*tam];
int ar[tam];
void build(int node, int b, int e) {
  if (b == e) { t[node].pb(ar[b]); return; }
  build(2*node, b, (b+e)/2);
  build(2*node+1, (b+e)/2+1, e);
  merge(t[2*node].begin(), t[2*node].end(),
        t[2*node+1].begin(), t[2*node+1].end(),
        back_inserter(t[node]));
}
void clean(int node, int b, int e)
{
    t[node].clear();
    if(b == e) return;
    clean(2*node, b, (b+e)/2);
    clean(2*node+1, (b+e)/2+1, e);
}

int query(int node, int b, int e, int i, int j, int x, int y) {
  if (j < b || i > e) return 0;
  if (i <= b && j >= e)
    return upper_bound(t[node].begin(), t[node].end(), y) -
           lower_bound(t[node].begin(), t[node].end(), x);
  return query(2*node, b, (b+e)/2, i, j, x, y) +
         query(2*node+1, (b+e)/2+1, e, i, j, x, y);
}
vi g[tam];
int ini[tam], fini[tam];
int cono = 0;
void dfs(int node, int pa)
{
    ini[node] = cono++;
    for(int x : g[node])
        if(x != pa)
            dfs(x, node);
    fini[node] = cono - 1;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        cin>>n>>q;
        cono = 0;
        fore(i, 0, n - 1 )
        {
            int a, b;
            cin>>a>>b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0, -1);
        fore(i, 0, n)
        {
            int x;
            cin>>x;
            ar[i] = ini[x - 1];
        }
        build(1, 0, n - 1);
        while(q--)
        {
            int a, b, c;
            cin>>a>>b>>c;
            a--, b--, c--;
            if(query(1, 0, n - 1, a, b, ini[c], fini[c]))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        fore(i, 0, n) g[i].clear();
        clean(1, 0, n - 1);

        cout<<'\n';
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
