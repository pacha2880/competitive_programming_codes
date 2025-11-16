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

// #pragma GCC optimization ("O2")
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
typedef vector<vector<int>> mat;
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
int vis[tam];
vi g[tam];
int dfs(int node){
    if(vis[node]) return 0;
    vis[node] = 1;
    int res = 1;
    for(int x : g[node])
        res += dfs(x);
    return res;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    set<ii> ari;
    fore(i, 0, n) fore(j, i + 1, n) ari.insert({i, j});
    int k;
    cin>>k;
    int las = -1;
    fore(i, 0, k){
        int a;
        cin>>a;
        a--;
        if(las == -1) {
            las = a;
            continue;
        }
        int b = las;
        las = a;
        if(a > b) swap(a, b);
        if(!ari.count({a, b})){
            cout<<"N\n";
            return 0;
        }
        ari.erase({a, b});
    }
    int les = -1;
    int l;
    cin>>l;
    int pri;
    int imp = 0;
    fore(i, 0, l){
        int a;
        cin>>a;
        a--;
        if(i == 0) pri = a;
        if(les == -1) {
            les = a;
            continue;
        }
        int b = les;
        les = a;
        if(a > b) swap(a, b);
        if(!ari.count({a, b})){
            cout<<"N\n";
            return 0;
        }
        ari.erase({a, b});
    }
    if(n % 2 == 0 && n > 2){
        cout<<"N\n";
        return 0;
    }
    if(l + k == 0){
        cout<<"Y\n";
        return 0;
    }
    if(l + k > n * (n - 1) / 2 + 1){
        cout<<"N\n";
        return 0;
    }
    vi in(n);
    set<int> sa;
    for(ii cat : ari){
        in[cat.f]++, in[cat.s]++;
        sa.insert(cat.f), sa.insert(cat.s);
        g[cat.f].pb(cat.s);
        g[cat.s].pb(cat.f);
    }
    
    if(sz(sa) && sz(sa) != dfs(*sa.begin()))
    {
        cout<<"N\n";
        return 0;
    }
    int carga = 1;
    if(l > 0 && l < n * (n - 1) / 2 + 1 && in[pri] == 0)
    {
        cout<<"N\n";
        return 0;
    }
    if(k > 0 && k < n * (n - 1) / 2 + 1 && in[las] == 0)
    {
        cout<<"N\n";
        return 0;
    }
    fore(i, 0, n){
        if(in[i] & 1) imp++;
        if(l > 0 && k > 0)
        if((in[i] & 1) && i != las && i != pri){
            cout<<"N\n";
            return 0;
        }
        if(l == 0){
            if((in[i] & 1) && i != las){
                if(!carga){
                    cout<<"N\n";
                    return 0;
                }
                carga--;
            }
        }
        if(k == 0){
            if((in[i] & 1) && i != pri){
                if(!carga){
                    cout<<"N\n";
                    return 0;
                }
                carga--;
            }
        }
    }
    if(imp == 0 && k > 0 && l > 0 && pri != las){
        cout<<"N\n";
    }
    else
    cout<<"Y\n";
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
