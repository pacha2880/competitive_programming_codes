#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int 			long long
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
#define forev(i, e, b) for(int i = e; i > b; i--)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ii di[] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
ii listo[2][tam];
int can, pi;
unordered_set<int> vis;
int xx, yy, d;
void dfs(int x, int y)
{
    if(abs(xx - x) + abs(yy - y) != d || vis.count((x<<32) + y)) return;
    vis.insert((x<<32) + y);
    listo[pi][can++] = {x, y};
    fore(i, 0, 4)
        dfs(x + di[i].f, y + di[i].s);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    vector<vi> v(n, vi(3));
    fore(i, 0, n) fore(j, 0, 3) cin>>v[i][j];
    sort(all(v), [](vi &a, vi &b){return a[2] < b[2];});
    xx = v[0][0], yy = v[0][1], d = v[0][2];
     shuffle(v.begin() + 1, v.end(), rng);
    // if(n == 100000) {cout<<v[0][2]<<'\n';return 0;}
    // cin>>xx>>yy>>d;
    dfs(xx + d, yy);
    fore(i, 1, n)
    {
        int x, y, d;
        x = v[i][0], y = v[i][1], d = v[i][2];
        // cin>>x>>y>>d;
        int cana = 0;
        fore(i, 0, can)
            if(abs(listo[pi][i].f - x) + abs(listo[pi][i].s - y) == d)
                listo[pi^1][cana++] = listo[pi][i];
        can = cana;
        pi ^= 1;
    }
    sort(listo[pi], listo[pi] + can);
    fore(i, 0, can)
        cout<<listo[pi][i].f<<' '<<listo[pi][i].s<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasándola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Si te caes 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad.
// Take a sad song and make it better.

