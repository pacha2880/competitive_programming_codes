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
const int tam =310;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi id(tam);
vi tr[tam];
void dfs(int node, int idd = -1)
{
    id[node] = idd;
    for(int x : tr[node])
        dfs(x, idd == -1 ? x : idd);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m;
    cin>>n>>m;
    vector<vii> g(n);
    vector<pair<ii, int>> ars(m);
    map<ii, int> ids;
    fore(i, 0, m)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        if(a > b) swap(a, b);
        ids[{a, b}] = i;
        ars[i] = {{a, b}, c};
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    vi res(m, -1);
    fore(x, 0, n)
    {
        // cout<<x<<endl;
        vi dis(n, MOD * MOD), par(n, -1), dis2(n, MOD * MOD), vis(n);
        priority_queue<ii> que;
        dis[x] = 0;
        que.push({0, x});
        while(!que.empty())
        {
            int node = que.top().s;
            // cout<<node<<'\n';
            que.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            for(auto cat : g[node])
            {
                if(dis[cat.f] > dis[node] + cat.s)
                {
                    dis[cat.f] = dis[node] + cat.s;
                    par[cat.f] = node;
                    que.push({-dis[cat.f], cat.f});
                }
            }
        }
        // cout<<"###\n";
        fore(i, 0, n)
        {
            if(par[i] != -1)
                tr[par[i]].pb(i);
        }
        // cout<<"%%%\n";
        dfs(x, -1);
        // cout<<"**\n";
        fore(i, 0, n) tr[i].clear();
        // cout<<"_____\n";
        for(auto cat : ars)
        {
            int a = cat.f.f, b = cat.f.s, c = cat.s;
            // cout<<a<<' '<<b<<' '<<c<<'\n';
            if(b == x)
                swap(a, b);
            if(a != x && par[a] == -1 || par[b] == -1) continue;
            if(a == x)
            {
                if(id[b] != b)
                    dis2[id[b]] = min(dis2[id[b]], dis[b] - dis[id[b]] + c);
            }
            else
            {
                if(id[a] != id[b])
                {
                    dis2[id[b]] = min(dis2[id[b]], dis[b] - dis[id[b]] + dis[a] + c);
                    dis2[id[a]] = min(dis2[id[a]], dis[a] - dis[id[a]] + dis[b] + c);
                }
            }
        }
        // cout<<"$$$\n";
        for(auto y : g[x])
        {
            // cout<<x<<' '<<y.f<<' '<<y.s<<' '<<dis2[y.s]<<'\n';
            int a = min(x, y.f), b = max(x, y.f);
            int id = ids[{a, b}];
            if(par[y.f] != x)
                res[id] = dis[y.f];
            else if(dis2[y.f] != MOD * MOD)
                res[id] = dis2[y.f];
        }
        // cout<<"!!!!"<<endl;
    }
    fore(i, 0, m)
        cout<<res[i]<<'\n';
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
// Take a sad song and make it better
