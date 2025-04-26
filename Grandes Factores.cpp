#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int 			long long
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
#define forev(i, e, b) for(int i = e; i > b; i--)
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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int susu[tam], facto[tam];
void criba()
{
    fore(i, 2, tam)
    {
        if(facto[i] == 0)
        {
            facto[i] = i;
            forg(j, i, tam, i)
            {
                int x = j;
                while(x % i == 0)
                    susu[j] += i, x /= i;
                facto[j] = i;
            }
        }
    }
}
int ar[tam], t[4 * tam], l[4 * tam];
void push(int b, int e, int node)
{
    if(l[node])
    {
        t[node] = susu[l[node]] * (e - b + 1);
        if(b < e)
            l[node * 2 + 1] += l[node], l[node * 2 + 2] += l[node];
        else
            ar[b] = l[node];
        l[node] = 0;
    }
}
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = susu[ar[b]];
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = t[l] + t[r];
}
int query(int b, int e, int node, int i, int j)
{
    push(b, e, node);
    if(b >= i && e <= j)
        return t[node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return query(b, mid, l, i, j) + query(mid + 1, e, r, i, j);
}
void updatelaz(int b, int e, int node, int i, int j, int val)
{
    if(b > e) return;
    push(b, e, node);
    if(e < i || b > j)
        return;
    if(b >= i && e <= j)
    {
        l[node] = val;
        push(b, e, node);
        return;
    }
    index;
    updatelaz(b, mid, l, i, j, val);
    updatelaz(mid + 1, e, r, i, j, val);
    t[node] = t[l] + t[r];
}
void update(int b, int e, int node, int pos)
{
    push(b, e, node);
    if(b == e)
    {
        if(facto[ar[b]])
            ar[b] /= facto[ar[b]];
        t[node] = susu[ar[b]];
        return;
    }
    index;
    if(pos <= mid)
        update(b, mid, l, pos);
    else
        update(mid + 1, e, r, pos);
    t[node] = t[l] + t[r];
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    criba();
	int n;
    cin>>n;
    fore(i, 0, n) cin>>ar[i];
    init(0, n - 1, 0);
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            int pos;
            cin>>pos;
            update(0, n - 1, 0, pos - 1);
        }
        else if(t == 2)
        {
            int l, r;
            cin>>l>>r;
            cout<<query(0, n - 1, 0, l - 1, r - 1)<<'\n';
        }
        else
        {
            int l, r, x;
            cin>>l>>r>>x;
            updatelaz(0, n - 1, 0, l - 1, r - 1, x);
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
