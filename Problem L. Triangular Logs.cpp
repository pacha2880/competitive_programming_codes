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
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int N = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi pozo;
vii ar;
vi nus;
vii st[4*N];

void build(int p, int l, int r) {
  if (l == r) { st[p].pb(ar[l]); return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p].resize(r-l+1);
  merge(st[2*p].begin(), st[2*p].end(),
        st[2*p+1].begin(), st[2*p+1].end(),
        st[p].begin());
}

int query(int p, int l, int r, int i, int j, int a, int b) {
  if (j < l or i > r) return 0;
  if (i <= l and j >= r)
    return upper_bound(st[p].begin(), st[p].end(), mp(b, MOD)) -
           lower_bound(st[p].begin(), st[p].end(), mp(a, 0));
  return query(2*p, l, (l+r)/2, i, j, a, b) +
         query(2*p+1, (l+r)/2+1, r, i, j, a, b);
}
void query1(int p, int l, int r, int i, int j, int a, int b) {
    // cout<<l<<' '<<r<<'\n';
    if(j < l || i > r) return;
    if(i <= l && j >= r)
    {
        auto it = lower_bound(all(st[p]), mp(a, 0));
        while(it != st[p].end() && it->f <= b)
        {
            nus.pb(it->s);
            it++;
        }
        return;
    }
    query1(2*p, l, (l+r)/2, i, j, a, b);
    query1(2*p+1, (l+r)/2+1, r, i, j, a, b);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int n, q;
    cin>>n>>q;
    map<int, vii> ma;
    fore(i, 0, n)
    {
        int a, b, c;
        cin>>a>>b>>c;
        ma[a].pb({b, c});
    }
    int po = 0;
    for(auto cat : ma)
    {
        for(ii y : cat.s)
        {
            pozo.pb(cat.f);
            ar.pb(y);
        }
    }
    // cout<<"#\n";
    build(1, 0, n - 1);
    // cout<<"$\n";
    while(q--)
    {
        // cout<<"*&*&"<<q<<'\n';
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int i = lower_bound(all(pozo), x1) - pozo.begin();
        int j = upper_bound(all(pozo), x2) - pozo.begin();
        // cout<<i<<' '<<j<<'\n';
        int val = i < j ? query(1, 0, n - 1, i, j - 1, y1, y2) : 0;
        // cout<<val<<'\n';
        if(val > 45)
            cout<<1<<'\n';
        else
        {
            nus.clear();
            if(i < j)
            query1(1, 0, n - 1, i, j - 1, y1, y2);
            sort(all(nus));
            bool bo = false;
            fore(i, 2, sz(nus))
                bo |= nus[i] < nus[i - 1] + nus[i - 2];
            cout<<bo<<'\n';
        }
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
