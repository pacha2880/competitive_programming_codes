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
#define index	int mid = (b + e) / 2, l = nod * 2 + 1, r = l + 1;
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct node
{
    vi basis;
    int si;
    node(){basis.assign(20, 0), si = 0;}
};
node join(node a, node b)
{
    fore(j, 0, 20)
        fore(i, 0, 20)
            if(b.basis[j] & 1 << i)
            {
                if(a.basis[i])
                    b.basis[j] ^= a.basis[i];
                else
                {
                    a.basis[i] = b.basis[j];
                    a.si++;
                    break;
                }
            }
    return a;
}
void join1(node & a, node b)
{
    // fore(i, 0, 20) cout<<a.basis[i]<<' '<<b.basis[i]<<'\n';
    fore(j, 0, 20)
        fore(i, 0, 20)
            if(b.basis[j] & 1 << i)
            {
                if(a.basis[i])
                    b.basis[j] ^= a.basis[i];
                else
                {
                    a.basis[i] = b.basis[j];
                    a.si++;
                    break;
                }
            }
}
int ar[tam];
node t[4 * tam];
void init(int b, int e, int nod)
{
    if(b == e)
    {
        if(!ar[b]) return;
        t[nod].basis.assign(20, 0);
        fore(i, 0, 20)
            if(ar[b] & 1 << i)
            {
                t[nod].basis[i] = ar[b];
                break;
            }
        // cout<<nod<<'\n';
        // fore(i, 0, 20) cout<<t[nod].basis[i]<<' ';
        // cout<<'\n';
        t[nod].si = 1;
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[nod] = join(t[l], t[r]);
}
int res = 0;
int la = 0;
void query(int b, int e, int nod, int le, node &bas)
{
    // cout<<b<<' '<<e<<' '<<nod<<' '<<le<<' '<<bas.si<<'\n';
    if(b == e)
    {
        // cout<<t[nod].si<<'\n';
        join1(bas, t[nod]);
        res = (res + (1<<(bas.si - 1)) * (b - la)) % MOD;
        la = b;
        // cout<<le<<' '<<b<<' '<<bas.si<<'\n';
        // cout<<res<<'\n';
        return;
    }
    index;
    if(mid < le)
    {
        if(mid + 1 == le)
        {
            node aux = join(bas, t[r]);
            if(aux.si > bas.si)
                query(mid + 1, e, r, le, bas);
            swap(aux, bas);
        }
        else
            query(mid + 1, e, r, le, bas);
    }
    else
    {
        if(b < le)
            query(b, mid, l, le, bas);
        else
        {
            node aux = join(bas, t[l]);
            if(aux.si > bas.si)
                query(b, mid, l, le, bas);
            swap(aux, bas);
        }
        node aux = join(bas, t[r]);
        if(aux.si > bas.si)
            query(mid + 1, e, r, le, bas);
        swap(aux, bas);
    }
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        fore(i, 0, n)
            cin>>ar[i];
        if(n == 1)
        {
            cout<<(1<<(ar[0] != 0))<<'\n';
            continue;
        }
        init(0, n - 1, 0);
        res = 0;
        // cout<<"asfasdsadf\n";
        fore(i, 0, n)
        {
            node bas = node();
            la = i;
            query(0, n - 1, 0, i, bas);
            // cout<<'@'<<la<<' '<<i<<' '<<bas.si<<'\n';
            res = (res + (1<<bas.si) * (n - la));
            // cout<<res<<'\n';
        }
        cout<<res<<'\n';
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
