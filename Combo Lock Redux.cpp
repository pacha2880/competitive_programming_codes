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
const int tam = 1000010;
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi g[tam];
ll dp[tam];
ll f(int node)
{
    if(node == 0) return 1;
    if(dp[node] != -1) return dp[node];
    ll ans = 0;
    for(int vec : g[node])
    {
        ans += f(vec);
        ans %= MOD;
    }
    // cout<<node<<' '<<dp[node]<<'\n';
    return dp[node] = ans;
}
struct unionFind {
  vi p;
  unionFind(int n) : p(n, -1) {}
  int findParent(int v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    while(t--)
    {
        ll n, t, h, a, b, q;
        int toto = 1;

        cin>>n>>t>>h>>a>>b>>q;
        fore(i, 0, n) toto *= 10;
        vector<vi> bicis(toto);
        fore(node, 0, toto)
        {
            int po = 1;
            fore(i, 0, n)
            {
                int dig = (node / po) % 10;
                // cout<<'!'<<i<<' '<<dig<<'\n';
                if(dig > 0)
                    bicis[node].pb(node - po);
                else
                    bicis[node].pb(node + 9 * po);
                if(dig < 9)
                    bicis[node].pb(node + po);
                else
                    bicis[node].pb(node - 9 * po);
                po *= 10;
            }
        }
        unionFind uni(toto);
        unordered_set<int> seq;
        vi can(tam);
        can[t] = 1;
        can[0] = 1;
        bool bo = false;
        do
        {
            // cout<<h<<' ';
            int c = h % toto;
            if(!can[c])
            {
                can[c] = 1;
                for(int x : bicis[c])
                {
                    if(can[x])
                    {
                        uni.join(c, x);
                    }
                }
            }
            if(uni.findParent(0) == uni.findParent(t))
            {
                bo = true;
                break;
            }
            seq.insert(h);
            h = ((h * a + b) % q);

        } while (!seq.count(h));
        // cout<<"\n23423sweewt\n";
        can[t] = can[0] = 1;
        fore(i, 0, toto) g[i].clear();
        queue<int> que;
        vi dis(tam, -1);
        que.push(t);
        dis[t] = 0;
        while(!que.empty())
        {
            int node = que.front();
            // cout<<"@@@ "<<node<<' '<<dis[node]<<'\n';
            que.pop();
            int po = 1;
            for(int x : bicis[node])
            {
                if(can[x])
                {
                    if(dis[x] == -1)
                    {
                        dis[x] = dis[node] + 1;
                        g[node].pb(x);
                        que.push(x);
                    }
                    else if(dis[x] == dis[node] + 1)
                    {
                        g[node].pb(x);
                    }
                }
            }
        }
        if(dis[0] == -1)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            mem(dp, -1);
            cout<<dis[0]<<' '<<f(t)<<'\n';
        }
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
