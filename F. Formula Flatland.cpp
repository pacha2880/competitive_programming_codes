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
const int tam = 400010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct pt{
	ll x, y;
	pt(){}
	pt(ll x, ll y): x(x), y(y){}
	pt operator -(pt p) { return {x - p.x, y - p.y}; }
	ll operator %(pt p) { return x * p.y - y * p.x; }
};

vi g[tam];int n; // input graph (must be connected)
vi gd[tam];int nd; // output graph
vi nodes[tam]; // nodes delimiting region (in CW order)
map<ii,int> ps,es;
void get_dual(vector<pt> &p, vi &nods){ // p: points corresponding to nodes
	ps.clear();es.clear();
	for(int x : nods){
        pt p1, p2;
        auto cmp = [&](int a, int b){
            p1 = p[a] - p[x], p2 = p[b] - p[x];
            a = p1.x > 0 && p1.y == 0 || p1.y > 0, b = p2.x > 0 && p2.y == 0 || p2.y > 0;
            if(a == b)
                return p1 % p2 > 0;
            return a < b;
        };
		sort(all(g[x]), cmp);
		fore(i,0,g[x].size())ps[{x,g[x][i]}]=i;
	}
	nd=0;
	for(int xx : nods)for(auto yy:g[xx])if(!es.count({xx,yy})){
		int x=xx,y=yy;gd[nd].clear();nodes[nd].clear();
		while(!es.count({x,y})){
			es[{x,y}]=nd;nodes[nd].pb(y);
			int z=g[y][(ps[{y,x}]+1)%g[y].size()];x=y;y=z;
		}
		nd++;
	}
	for(auto p:es){
		pair<int,int> q={p.f.s,p.f.f};
		assert(es.count(q));
		if(es[q]!=p.s)gd[p.s].pb(es[q]);
	}
	fore(i,0,nd){
		sort(all(gd[i]));
		gd[i].erase(unique(all(gd[i])),gd[i].end());
	}
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int m;
	cin>>n>>m;
	vector<pt> ponts(n);
	fore(i, 0, n) cin>>ponts[i].x>>ponts[i].y;
	while(m--){
		int a, b;
		cin>>a>>b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vi nods(n);
	fore(i, 0, n) nods[i] = i;
	get_dual(ponts, nods);
	int res = MOD;
	fore(i, 0, nd) res = min(res, sz(gd[i]));
	cout<<res<<'\n';
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
