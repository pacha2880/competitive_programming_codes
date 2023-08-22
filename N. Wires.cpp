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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
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
        int m;
        cin>>m;
        vii ar(m);
        unordered_map<int, int> ma;
        unordered_set<int> st;
        fore(i, 0, m)
        {
            int a, b;
            cin>>a>>b;
            ar[i] = {a, b};
            st.insert(a);
            st.insert(b);
        }
        int n = 0;
        vi rev;
        for(int x : st)
            ma[x] = n++, rev.pb(x);
        vector<vi> gra(n);
        unionFind uni(n);
        vector<ii> pozo;
        fore(i, 0, m)
        {
            ar[i] = {ma[ar[i].f], ma[ar[i].s]};
            gra[ar[i].f].pb(i + 1);
            gra[ar[i].s].pb(i + 1);
            if(!uni.join(ar[i].f, ar[i].s))
                pozo.pb({i + 1, ar[i].f});
        }
        fore(i, 0, n)
        {
            if(i != uni.findParent(i) && sz(gra[i]) == 1)
                pozo.pb({gra[i][0], i});
        }
        st.clear();
        fore(i, 0, n) st.insert(uni.findParent(i));
        int can = sz(st) - 1;
        // assert(can <= sz(pozo));
        cout<<can<<'\n';
        while(can--)
        {
            int id = pozo.back().f, fro = pozo.back().s;
            pozo.pop_back();
            int par = uni.findParent(fro);
            st.erase(par);
            int to = uni.findParent(*st.begin());
            st.erase(st.begin());
            cout<<id<<' '<<rev[fro]<<' '<<rev[to]<<'\n';
            uni.join(fro, to);
            st.insert(uni.findParent(fro));
        }
        cout<<'\n';
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
