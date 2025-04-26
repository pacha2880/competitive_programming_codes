#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int tab[1010][1010];
int vis[1010][1010];
ii dp[1010][1010];
int n;
ii f(int fro, int pos)
{
    if(vis[fro][pos]) return dp[fro][pos];
    vis[fro][pos] = 1;
    if(pos >= n)
    {
        if(fro == pos)
            return dp[fro][pos] = {0, 1};
        else
            return dp[fro][pos] = {0, 0};
    }
    int maxo = 0, can = 0;
    ii cat = f(fro, pos + 1);
    maxo = cat.f, can = cat.s;
    cat = f(pos + 2, pos + 2);
    cat.f += tab[fro][pos];
    if(maxo < cat.f || can == 0)
        maxo = cat.f, can = cat.s;
    else if(maxo == cat.f)
        can += cat.s;
    if(fro == pos)
    {
        cat = f(fro + 1, pos + 1);
        if(maxo < cat.f || can == 0)
            maxo = cat.f, can = cat.s;
        else if(maxo == cat.f)
            can += cat.s;
    }
    // cout<<fro<<' '<<pos<<' '<<dp[fro][pos]<<'\n';
    return dp[fro][pos] = {maxo, min(5000, can)};
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
        int k;
        cin>>n>>k;
        fore(i, 0, n)
            fore(j, i, n)
                cin>>tab[i][j];
        fore(i, 0, n + 2) fore(j, 0, n + 2) vis[i][j] = 0;
        // ii cat = f(0, 0);
        priority_queue<vi> que;
        que.push({f(0, 0).f, 0, 0, 0, 1});
        // cout<<"asdfasdfasf\n";
        // int mayo = MOD;
        while(true)
        {
            // cout<<'@'<<sz(que)<<'\n';
            int bala = que.top()[0], fro = que.top()[1], pos = que.top()[2], agregor = que.top()[3], pri = que.top()[4];
            // cout<<bala<<' '<<fro<<' '<<pos<<' '<<agregor<<' '<<pri<<'\n';
            que.pop();
            ii cat = f(fro, pos);
            // cout<<"cuantos "<<cat.s<<'\n';
            if(pri)
            {
                fore(i, 0, min(k, cat.s))
                    // cout<<'$',
                    cout<<bala<<' ';
                k -= cat.s;
            }
            // cout<<'#'<<k<<'\n';
            if(k <= 0)
                break;
            // if(cat.s == (1<<(n - pos)))
            // {
            //     cout<<cat.s<<'\n';
            // cout<<bala<<' '<<fro<<' '<<pos<<' '<<agregor<<' '<<pri<<'\n';
            // }
            if(n - pos < 20 && cat.s == (1<<(n - pos))) continue;
            // mayo = bala;
            if(pos >= n) continue;
            ii cut = f(fro, pos + 1);
            // cout<<"hola "<<cut.f<<' '<<cut.s<<' '<<fro<<' '<<pos + 1<<'\n';
            if(cut.s)
                que.push({cut.f + agregor, fro, pos + 1, agregor, cut.f < cat.f});

            cut = f(pos + 2, pos + 2);
            cut.f += tab[fro][pos];
            // cout<<cut.f<<' '<<cat.f<<'\n';
            if(cut.s)
                que.push({cut.f + agregor, pos + 2, pos + 2, agregor + tab[fro][pos], cut.f < cat.f});

            if(fro == pos)
            {
                cut = f(fro + 1, pos + 1);
                if(cut.s)
                    que.push({cut.f + agregor, fro + 1, pos + 1, agregor, cut.f < cat.f});
            }
        }
        cout<<'\n';
    }
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
