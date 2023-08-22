// Task Meteors (met)
// https://szkopul.edu.pl/problemset/problem/7JrCYZ7LhEK4nBR5zbAXpcmM/site/?key=statement
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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll bit[tam];
ll query(int pos)
{
    ll res = 0;
    while(pos > 0)
    {
        res += bit[pos];
        pos -= pos & -pos;
    }
    return res;
}
void update(int pos, int val)
{
    while(pos < tam)
        bit[pos] += val, pos += pos & -pos;
}
vector<pair<ii, int>> qs(tam);
vector<vi> lugs(tam);
vi meta(tam);
vi res(tam, -1);
int treepos = -1;
int updates = 0;
void dnc(int l, int r, vi &candi)
{
    // if(candi.empty()) return;
    if(l > r) return;
    int mid = (l + r) / 2;
    while(treepos < mid)
    {
        treepos++;
        updates++;
        int a = qs[treepos].f.f, b = qs[treepos].f.s, c = qs[treepos].s;
        if(a <= b)
            update(a, c), update(b + 1, -c);
        else
            update(a, c), update(1, c), update(b + 1, -c);      
    }
    while(treepos > mid)
    {
        updates++;
        int a = qs[treepos].f.f, b = qs[treepos].f.s, c = qs[treepos].s;
        if(a <= b)
            update(a, -c), update(b + 1, c);
        else
            update(a, -c), update(1, -c), update(b + 1, c);
        treepos--;
    }
    vi lef, rig;
    for(int x : candi)
    {
        ll su = 0;
        for(int y : lugs[x])
        {
            su += query(y);
            if(su >= meta[x]) break;
        }
        if(su >= meta[x])
            res[x] = mid + 1, lef.pb(x);
        else
            rig.pb(x);
    }
    candi.clear();
    dnc(l, mid - 1, lef);
    dnc(mid + 1, r, rig);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int n, m;
    cin>>n>>m;
    fore(i, 0, m)
    {
        int x;
        cin>>x;
        x--;
        lugs[x].pb(i + 1);
    }
    fore(i, 0, n) cin>>meta[i];
    int q;
    cin>>q;
    fore(i, 0, q)
    {
        int a, b, c;
        cin>>a>>b>>c;
        qs[i] = {{a, b}, c};
    }
    vi candi(n);
    fore(i, 0, n) candi[i] = i;
    dnc(0, q - 1, candi);
    fore(i, 0, n)
        if(res[i] == -1)
            cout<<"NIE\n";
        else
            cout<<res[i]<<'\n';
    cout<<updates<<'\n';
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