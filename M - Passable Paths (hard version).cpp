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
const int tam = 600010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[tam];
vi ino(tam), fino(tam);
int pozo;
vi ar(tam), t(4 * tam);
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = ar[b];
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = min(t[l], t[r]);
}
int query(int b, int e, int node, int i, int j)
{
    if(b >= i && e <= j)
        return t[node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return min(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
int cuan;
vi lle(tam);
void dfs(int node, int par = -1)
{
    lle[node] = cuan++;
    ar[pozo] = lle[node];
    ino[node] = pozo++;
    for(int x : g[node])
        if(x != par)
            ar[pozo++] = lle[node], dfs(x, node);
    ar[pozo] = lle[node];
    fino[node] = pozo++;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    fore(i, 0, tam) ar[i] = MOD;
	int n;
    cin>>n;
    fore(i, 0, n - 1)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    init(0, pozo - 1, 0);
    int q;
    cin>>q;
    while(q--)
    {
        int m;
        cin>>m;
        vector<pair<ii, int>> ar;
        fore(i, 0, m)
        {
            int x;
            cin>>x;
            x--;
            ar.pb({{ino[x], 1}, x});
            ar.pb({{fino[x], -1}, x});
        }
        sort(all(ar));
        // for(auto cat : ar) cout<<cat.f.f<<' '<<cat.f.s<<' '<<cat.s<<'\n';
        int can = 0, po = 0;
        vi cana(sz(ar));
        cana[0] = 1;
        fore(i, 1, sz(ar) - 1)
        {
            cana[i] = cana[i - 1] + ar[i].f.s;
            if(ar[i].f.s == -1 && ar[i + 1].f.s == 1)
                can++, po = i;
        }
        // cout<<can<<' '<<po<<'\n';
        // fore(i, 0, sz(ar))
        //     cout<<cana[i]<<'\n';
        if(can == 0)
            cout<<"YES\n";
        else if(can == 1)
        {
            if(cana[po] == 0)
                cout<<"YES\n";
            else if(cana[po] == 1)
            {
                int qu = query(0, pozo - 1, 0, ino[ar[po].s], fino[ar[po + 1].s]);
                if(qu == lle[ar[0].s])
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                cout<<"NO\n";
        }
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
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
