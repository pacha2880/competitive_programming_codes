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
struct punto{
    int x;
    int y;
    int rad;
    int id;
    punto(){}
    punto(int x, int y, int dia, int id): x(x), y(y), rad(dia / 2), id(id){}
    const bool operator <(const punto & otro){return y == otro.y ? id < otro.id : y < otro.y;}
};
struct asdf{
    const bool operator()(const punto & a, const punto & b){
        return a.y == b.y ? a.id < b.id : a.y < b.y;
    }
};
vi g[tam];
int vis[tam];
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
	int maxd = 2500;
    int dosinch = 508;
    int n;
    cin>>n;
    vector<punto> panto(n);
    fore(i, 0, n){
        int x, y, d;
        cin>>x>>y>>d;
        panto[i] = {x * 10, y * 10, d * 10, i};
    }
    sort(all(panto), [&](const punto &a, const punto &b){return a.x < b.x;});
    int lef = -1;
    set<punto, asdf> st;
    fore(i, 0, n){
        st.erase(panto[i]);
        lef = max(lef, i + 1);
        // cout<<i<<'\n';
        // cout<<panto[i].x<<' '<<panto[i].y<<' '<<panto[i].rad<<' '<<panto[i].id<<'\n';
        while(lef < n && panto[lef].x - maxd < panto[i].x) st.insert(panto[lef]), lef++;
        punto punti = {0, panto[i].y - maxd, 0, 0};
        auto it = st.lower_bound(punti);
        while(it != st.end() && it->y - maxd < panto[i].y){
            // cout<<'@'<<it->x<<' '<<it->y<<' '<<it->rad<<' '<<it->id<<'\n';
            int dx = it->x - panto[i].x;
            int dy = it->y - panto[i].y;
            int maxdi = dosinch + it->rad + panto[i].rad;
            if(dx * dx + dy * dy <= maxdi * maxdi)
                g[panto[i].id].pb(it->id), g[it->id].pb(panto[i].id);
            it++;
        }
    }
    // fore(i, 0, n)
    //     fore(j, 0, )
    // fore(i, 0, n)
    // {
    //     cout<<"#"<<i<<'\n';
    //     for(int x : g[i])
    //         cout<<x<<' ';
    //     cout<<'\n';
    // }
    if(dfs(0) == n){
        if(n < 7)
            cout<<"yes\n";
        else
        {
            bool bo = true;
            fore(i, 0, n) bo &= sz(g[i]) >= 2;
            if(bo)
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
    }
    else
        cout<<"no\n";
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
