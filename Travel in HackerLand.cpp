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

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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

int col[tam];
struct unionFind {
    vi p;
    vector<unordered_set<int>> st;
    unionFind(int n) : p(n, -1), st(n){
        fore(i, 0, n) st[i].insert(col[i]);
    }
    int findParent(int v) {
        if (p[v] == -1) return v;
        return p[v] = findParent(p[v]);
    }
    bool join(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b) return false;
        if(sz(st[a]) > sz(st[b]))
            swap(a, b);
        for(int x : st[a])
            st[b].insert(x);
        p[a] = b;
        return true;
    }
};

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m, q;
    cin>>n>>m>>q;
    fore(i, 0, n) cin>>col[i];
    map<int, vii> ars;
    fore(i, 0, m)
    {
        int a, b, c;
        cin>>a>>b>>c;
        ars[c].pb({a - 1, b - 1});
    }

    vector<pair<ii, int>> ques(q);
    fore(i, 0, q)
    {
        int a, b, c;
        cin>>a>>b>>c;
        ques[i] = {{a - 1, b - 1}, c};
    }
    vi ls(q), rs(q, sz(ars) - 1);
    vector<vi> mids(sz(ars));
    vi res(q, -1);
    bool bo = true;
    while(bo)
    {
        bo = false;
        fore(i, 0, q)
        {
            if(ls[i] <= rs[i])
                mids[ls[i] + rs[i] >> 1].pb(i);
        }
        unionFind uf(n);
        int ind = 0;
        for(auto it = ars.begin(); it != ars.end(); it++, ind++)
        {
            for(ii cat : it->s)
                uf.join(cat.f, cat.s);
            // cout<<'#'<<'\n';
            for(int x : mids[ind])
            {
                // cout<<x<<'\n';
                bo = true;
                int a = ques[x].f.f, b = ques[x].f.s, c = ques[x].s;
                // cout<<a<<' '<<b<<' '<<c<<'\n';
                a = uf.findParent(a), b = uf.findParent(b);
                if(a == b && sz(uf.st[a]) >= c)
                    res[x] = it->f, rs[x] = ind - 1;
                else
                    ls[x] = ind + 1;
            }
            mids[ind].clear();
        }
    }
    fore(i, 0, q)
        cout<<res[i]<<'\n';
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
