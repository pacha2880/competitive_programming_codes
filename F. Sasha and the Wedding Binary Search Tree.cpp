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
const int tam = 500010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int pot(int b, int e)
{
    int res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
int countSum(int N, int L, int R)
{
    // cout<<N<<' '<<L<<' '<<R<<'\n';
    int n = N, c = R - L + 1;
    c += n - 1;
    int res = 1;
    // cout<<c<<' '<<n<<'\n';
    fore(i, 0, n)
    {
        res = res * pot(n - i, MOD - 2) % MOD;
        res = res * c % MOD;
        c--;
    }
    return res;
}
vi inord;
vi lf(tam), rs(tam), vals(tam);
void f(int node)
{
    // cout<<node<<'\n';
    if(node == -1) return;
    // cout<<'#'<<vals[node]<<'\n';
    f(lf[node]);
    inord.pb(vals[node]);
    f(rs[node]);
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
        // cout<<"####\n";
        int n, c;
        cin>>n>>c;
        fore(i, 0, n)
            cin>>lf[i + 1]>>rs[i + 1]>>vals[i + 1];
        inord.clear();
        f(1);
        int l = 1, r = c;
        int la = -1;
        int res = 1;
        // cout<<'\n';
        fore(i, 0, n)
        {
            // cout<<inord[i]<<'\n';
            if(inord[i] != -1)
            {
                if(i - la > 1)
                    res = res * countSum(i - la - 1, l, inord[i]) % MOD;
                l = inord[i];
                la = i;
            }
        }
        if(la != n - 1)
            res = res * countSum(n - la - 1, l, c) % MOD;
        cout<<res<<'\n';
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
