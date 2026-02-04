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
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int h, w, t;
    cin>>h>>w>>t;
    vector<string> tab(h);
    ii ini, fini;
    vii cara;
    fore(i, 0, h) {
        cin>>tab[i];
        fore(j, 0, w)
            if(tab[i][j] == 'S')
                ini = {i, j};
            else if(tab[i][j] == 'G')
                fini = {i, j};
            else if(tab[i][j] == 'o')
                cara.pb({i, j});
    }
    int n = sz(cara) + 2;
    mat g(n, vi(n, MOD));
    cara.insert(cara.begin(), ini);
    cara.pb(fini);
    int dir[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
    fore(i, 0, n){
        mat dis(h, vi(w, MOD));
        queue<ii> que;
        que.push({cara[i].f, cara[i].s});
        dis[cara[i].f][cara[i].s] = 0;
        while(!que.empty()){
            int x = que.front().f, y = que.front().s;
            que.pop();
            fore(i, 0, 4){
                int xx = x + dir[0][i], yy = y + dir[1][i];
                if(xx >= 0 && xx < h && yy >= 0 && yy < w && tab[xx][yy] != '#' && dis[xx][yy] == MOD)
                {
                    dis[xx][yy] = dis[x][y] + 1;
                    que.push({xx, yy});
                }
            }
        }
        fore(j, 0, n){
            g[i][j] = dis[cara[j].f][cara[j].s];
        }
    }
    // fore(i, 0, n) cout<<cara[i].f<<' '<<cara[i].s<<'\n';
    // fore(i, 0, n){
    //     fore(j, 0, n)
    //         cout<<g[i][j]<<' ';
    //     cout<<'\n';
    // }
    if(g[0][n - 1] > t)
        cout<<-1<<'\n';
    else{
        int res = 0;
        int k = n - 2;
        // cout<<k<<'\n';
        mat dp(k, vi(1<<k, MOD));

        fore(i, 1, k + 1)
        fore(mask, 0, 1<<k)
            if(__builtin_popcount(mask) == i){
                fore(in, 0, k)
                    if(mask >> in & 1){
                        if(i == 1){
                            dp[in][mask] = g[0][in + 1];
                        }
                        else {
                            int mesk = mask ^ (1<<in);
                            fore(an, 0, k){
                                if(an != in && (mask >> an & 1))
                                    dp[in][mask] = min(dp[in][mask], dp[an][mesk] + g[in + 1][an + 1]);
                            }
                        }
                        if(dp[in][mask] + g[n - 1][in + 1] <= t)
                            res = i;
                    }
            }
        cout<<res<<'\n';
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
