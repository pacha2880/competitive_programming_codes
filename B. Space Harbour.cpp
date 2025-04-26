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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int ar[tam], t[4 * tam];

void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = ar[b];
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = t[l] + t[r];
}
int query(int b, int e, int node, int i, int j)
{
    if(b >= i && e <= j)
        return t[node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return query(b, mid, l, i, j) + query(mid + 1, e, r, i, j);
}

void update(int b, int e, int node, int pos, int val)
{
	if(b == e) {t[node] = val;return;}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < pos)
		update(mid + 1, e, r, pos, val);
	else
		update(b, mid, l, pos, val);
	t[node] = t[l] + t[r];
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, m, q;
    cin>>n>>m>>q;
    set<ii> portos;
    vii er(m);
    fore(i, 0, m)
    {
        cin>>er[i].f;
        er[i].f--;
    }
    fore(i, 0, m) cin>>er[i].s;
    sort(all(er));
    int la, le;
    fore(i, 0, m)
    {
        if(i > 0)
        {
            int cana = er[i].f - la - 1;
            ar[er[i].f] = cana * (cana + 1) / 2 * le;
        }
        la = er[i].f, le = er[i].s;
        portos.insert(er[i]);
    }
    // fore(i, 0, n) cout<<ar[i]<<' ';
    // cout<<'\n';
    init(0, n - 1, 0);
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            int x, v;
            cin>>x>>v;
            x--;
            auto it = portos.lower_bound({x, 0});
            int cana = it->f - x - 1;
            update(0, n - 1, 0, it->f, cana * (cana + 1) / 2 * v);
            it--;
            cana = x - it->f - 1;
            update(0, n - 1, 0, x, cana * (cana + 1) / 2 * it->s);
            portos.insert({x, v});
        }
        else
        {
            // cout<<"!!!!!!\n";
            int l, r;
            cin>>l>>r;
            l--, r--;
            int res = query(0, n - 1, 0, l, r);
            // cout<<res<<'\n';
            auto it = portos.lower_bound({r, 0});
            if(it->f > r)
            {
                int cana = it->f - r - 1;
                r = it->f;
                it--;
                res -= cana * (cana + 1) / 2 * it->s;
                // cout<<'$'<<cana * (cana + 1) / 2 * it->s<<' ';
                cana = r - it->f - 1;
                res += cana * (cana + 1) / 2 * it->s;
                // cout<<cana * (cana + 1) / 2 * it->s<<'\n';
            }
            it = portos.lower_bound({l, 0});
            if(it != portos.begin())
            {
                // cout<<(it->f)<<' '<<(it->s)<<'\n';
                int cana = it->f - l;
                l = it->f;
                it--;
                // cout<<"(("<<cana<<' '<<it->s<<'\n';
                res += cana * (cana + 1) / 2 * it->s;
                // cout<<'#'<<cana * (cana + 1) / 2 * it->s<<' ';
                cana = l - it->f - 1;
                res -= cana * (cana + 1) / 2 * it->s;
                // cout<<cana * (cana + 1) / 2 * it->s<<'\n';
            }
            cout<<res<<'\n';
        }
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
