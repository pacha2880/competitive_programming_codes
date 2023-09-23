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
const int tam = 2000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int t[4 * tam];
void update(int b, int e, int node, int pos, int val)
{
    if(b == e)
    {
        t[node] = max(t[node], val);
        return;
    }
    index;
    if(pos <= mid)
        update(b, mid, l, pos, val);
    else
        update(mid + 1, e, r, pos, val);
    t[node] = max(t[l], t[r]);
}
int query(int b, int e, int node, int i, int j)
{
    if(i > j) return -MOD * MOD;
    if(b >= i && e <= j)
        return t[node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return max(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, s;
    int res = 0;
    cin>>n>>s;
    vector<pair<ii, int>> ar(n);
    set<int> st;
    fore(i, 0, n)
    {
        int a, b, c;
        cin>>a>>b>>c;
        st.insert(a); st.insert(b);
        ar[i] = {{a, b}, c};
    }
    sort(all(ar));
    map<int, int> ma;
    int can = sz(st) + 1;
    int po = 0;
    for(int x : st)
        ma[x] = po++;
    vi maxus(can);
    int las = can - 1;
    for(int i = n - 1; i > -1; i--)
    {
        int l = ar[i].f.f, r = ar[i].f.s, c = ar[i].s;
        int va = max((r - l + 1) * s + maxus[ma[r] + 1], 
                    -s * l + query(0, can - 1, 0, ma[l] + 1, ma[r])) - c;
        update(0, can - 1, 0, ma[l], va + l * s);
        res = max(res, va);
        fore(j, ma[l], las)
            maxus[j] = maxus[las];
        maxus[ma[l]] = max(va, maxus[ma[l]]);
        las = ma[l];
    }
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
// Take a sad song and make it better