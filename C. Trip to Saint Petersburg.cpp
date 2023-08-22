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

int ar[tam];
ii t[4 * tam];
int l[4 * tam];
void push(int b, int e, int node)
{
    if(l[node])
    {
        t[node].f += l[node];
        if(b < e)
            l[node * 2 + 1] += l[node], l[node * 2 + 2] += l[node];
        l[node] = 0;
    }
}
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = {0, b};
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = max(t[l], t[r]);
}
ii query(int b, int e, int node, int i, int j)
{
    push(b, e, node);
    if(b >= i && e <= j)
        return t[node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return max(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
void update(int b, int e, int node, int i, int j, int val)
{
    if(b > e) return;
    push(b, e, node);
    if(e < i || b > j)
        return;
    if(b >= i && e <= j)
    {
        l[node] += val;
        push(b, e, node);
        return;
    }
    index;
    update(b, mid, l, i, j, val);
    update(mid + 1, e, r, i, j, val);
    t[node] = max(t[l], t[r]);
}
signed main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n, k;
    cin>>n>>k;
    vector<vi> ar(tam);
    vii ques(n);
    fore(i, 0, n)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        ques[i] = {a, c};
        ar[b].pb(i);
    }
    pair<int, ii> res = {0, {0, 0}};
    init(0, tam - 1, 0);
    fore(i, 0, tam)
    {
        // cout<<'@';
        update(0, tam - 1, 0, 0, i, -k);
        // cout<<i<<'\n';
        for(int x : ar[i])
            // cout<<x<<'\n',
            update(0, tam - 1, 0, 0, ques[x].f, ques[x].s);
        // cout<<i<<'\n';
        ii que = query(0, tam - 1, 0, 0, tam - 1);
        // if(i < 10)
        // cout<<i<<' '<<que.f<<' '<<que.s<<'\n';
        res = max(res, {que.f, {que.s, i}});
        // cout<<i<<'\n';
    }
    if(res.f == 0)
        cout<<0<<'\n';
    else
    {
        cout<<res.f<<' '<<res.s.f + 1<<' '<<res.s.s + 1<<' ';
        vi quien;
        fore(i, res.s.f, res.s.s + 1)
            for(int x : ar[i])
                if(ques[x].f >= res.s.f)
                    quien.pb(x + 1);
        cout<<sz(quien)<<'\n';
        for(int x : quien)
            cout<<x<<' ';
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
