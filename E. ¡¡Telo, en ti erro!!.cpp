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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[tam], t[4 * tam];
void init(int b, int e, int node)
{
    if(b == e){
        t[node] = ar[b];
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = min(t[l], t[r]);
}
int query(int b, int e, int node, int pos, int val)
{
    if(e <= pos || t[node] >= val) return -1;
    if(b == e) return b;
    index;
    int x = query(b, mid, l, pos, val);
    if(x != -1)
        return x;
    return query(mid + 1, e, r, pos, val);
}
// primero contando desde la izq, yendo hacia la derecha
// if(t[0] < val)
//     query(0, n - 1, 0, val);
int query(int b, int e, int node, int val)
{
    if(b == e) return b;
    index;
    int x = query(b, mid, l, val);
    if(t[l] < val)
        return query(b, mid, l, val);
    return query(mid + 1, e, r, val);
}
// primero contando desde la der, yendo hacia la der
// if(t[0] < val)
//     query(0, n - 1, 0, val);
int query(int b, int e, int node, int val)
{
    if(b == e) return b;
    index;
    int x = query(b, mid, l, val);
    if(t[r] < val)
        return query(mid + 1, e, r, val);
    return query(b, mid, l, val);
}
// se puede igual BIT ???? cuenta la leyenda
// pero usualmente es barato el BIT así que es 
// raro que necesites eso para el BIT
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    vi energia(n);
    fore(i, 0, n) cin>>ar[i];
    fore(i, 0, n) cin>>energia[i];
    init(0, n - 1, 0);
    vi res;
    fore(i, 0, n)
    {
        int pos = query(0, n - 1, 0, i, ar[i]);
        if(pos == -1 || energia[pos] < energia[i])
            res.pb(i + 1);
    }
    cout<<sz(res)<<'\n';
    for(int x : res)
        cout<<x<<' ';
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
