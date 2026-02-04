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
int n, m, mo;
vector<int> g[tam], gr[tam], gg[tam];
void add(int a, int b){
    int na = (a + n) % mo;
    int nb = (b + n) % mo;
    g[na].pb(b);
    g[b].pb(na);
    g[nb].pb(a);
    g[a].pb(nb);
}
vi ord;
int gru[tam], vis[tam], in[tam];
void dfs(int node){
    vis[node] = 1;
    for(int x : g[node])
        if(!vis[x])
            dfs(x);
    ord.pb(node);
}
void dfs1(int node, int ide){
    gru[node] = ide;
    for(int x : gr[node]){
        if(gru[x] < ide){
            if(gru[x])
                in[gru[x]]++,
                gg[ide].pb(gru[x]);
            else
                dfs1(x, ide);
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    cin>>n>>m;
    mo = 2 * n;
    while(m--){
        char ch1, ch2;
        int a, b;
        cin>>ch1>>a>>ch2>>b;
        a--, b--;
        if(ch1 == '-')
            a += n;
        if(ch2 == '-')
            b += n;
    }
    fore(i, 0, 2 * n)
        if(!vis[i])
            dfs(i);
    reverse(all(ord));
    int ide = 1;
    for(int x : ord){
        if(gru[x] == 0){
            dfs1(x, ide++);
        }
    }
    fore(i, 0, n)
        if(gru[i] == gru[i + n]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    queue<int> que;
    fore(i, 1, ide){
        
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
