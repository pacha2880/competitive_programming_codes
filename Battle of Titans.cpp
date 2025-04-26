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
const int MOD = 1000000000 + 100000 - 1;
const int MOD1 = 998244353;
const int MOD2 = 1000000009;
const int MOD3 = 1000000007;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct node
{
  int val1, val2, val3, val4;
  ld logo;
  int su;
};
node join(node a, node b)
{
    a.val1 = (a.val1 * b.val1) % MOD;
    a.val2 = (a.val2 * b.val2) % MOD1;
    a.val3 = (a.val3 * b.val3) % MOD2;
    a.val4 = (a.val4 * b.val4) % MOD3;
    a.logo += b.logo;
    a.su += b.su;
    return a;
}
int ar[tam], br[tam];
node t[4 * tam];
ll pot(ll b, ll e, ll m)
{
    int res = 1;
    while(e)
    {
        if(e & 1)
            res = (res * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return res;
}
void init(int b, int e, int node)
{
	if(b == e)
	{
        // cout<<b<<' '<<ar[b]<<' '<<br[b]<<'\n';
		t[node].val1 = pot(ar[b], br[b], MOD);
        t[node].val2 = pot(ar[b], br[b], MOD1);
        t[node].val3 = pot(ar[b], br[b], MOD2);
        t[node].val4 = pot(ar[b], br[b], MOD3);
        t[node].logo = logl(ar[b]) * br[b];
        t[node].su = ar[b];
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
    // cout<<b<<' '<<e<<' '<<t[node].val1<<' '<<t[node].val2<<' '<<t[node].val3<<' '<<'\n';
}
node query(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
    {
        // cout<<b<<' '<<e<<' '<<t[node].val1<<' '<<t[node].val2<<' '<<t[node].val3<<' '<<'\n';
		return t[node];
    }
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	if(mid >= j)
		return query(b, mid, l, i, j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
void update1(int b, int e, int node, int pos, int val)
{
	if(b == e) {
        ar[b] = val;
		t[node].val1 = pot(ar[b], br[b], MOD);
        t[node].val2 = pot(ar[b], br[b], MOD1);
        t[node].val3 = pot(ar[b], br[b], MOD2);
        t[node].val4 = pot(ar[b], br[b], MOD3);
        t[node].logo = logl(ar[b]) * br[b];
        t[node].su = ar[b];
        return;
    }
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < pos)
		update1(mid + 1, e, r, pos, val);
	else
		update1(b, mid, l, pos, val);
	t[node] = join(t[l], t[r]);
}
void update2(int b, int e, int node, int pos, int val)
{
	if(b == e) {
        br[b] = val;
		t[node].val1 = pot(ar[b], br[b], MOD);
        t[node].val2 = pot(ar[b], br[b], MOD1);
        t[node].val3 = pot(ar[b], br[b], MOD2);
        t[node].val4 = pot(ar[b], br[b], MOD3);
        t[node].logo = log(ar[b]) * br[b];
        return;
    }
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < pos)
		update2(mid + 1, e, r, pos, val);
	else
		update2(b, mid, l, pos, val);
	t[node] = join(t[l], t[r]);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    fore(i, 0, n) cin>>ar[i], ar[i]++;
    fore(i, 0, n) cin>>br[i];
    init(0, n - 1, 0);
    int q;
    cin>>q;
    while(q--)
    {
        char ch;
        int a, b;
        cin>>ch>>a>>b;
        if(ch == 'U')
            update2(0, n - 1, 0, a - 1, b);
        if(ch == 'E')
            update1(0, n - 1, 0, a - 1, b + 1);
        if(ch == 'B')
        {
            int c, d;
            cin>>c>>d;
            // cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
            node x = query(0, n - 1, 0, a - 1, b - 1);
            node y = query(0, n - 1, 0, c - 1, d - 1);
            cout<<x.val1<<' '<<y.val1<<' ';
            if(x.val1 == y.val1 && x.val2 == y.val2 && x.val3 == y.val3 && x.val4 == y.val4)
                cout<<"*\n";
            else if(fabsl(x.logo - y.logo) < EPS)
            {
                if(x.su > y.su)
                    cout<<"Alice\n";
                else
                    cout<<"Bob\n";
            }
            else if(x.logo > y.logo)
                cout<<"Alice\n";
            else
                cout<<"Bob\n";
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
