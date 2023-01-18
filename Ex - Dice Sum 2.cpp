#include <bits/stdc++.h>
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
#define RAYA cerr<<"=============================="<<endl
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, k;
    cin>>n>>k;
    vector<pair<ii, int>> ar(n);
    fore(i, 0, n)
        cin>>ar[i].f.s;
    auto pot = [&](int a, int b){
        int r = 1;
        while(b){
            if(b & 1)
                r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    };
    fore(i, 0, n)
    {
        fore(j, 0, 6)
        {
            int x;
            cin>>x;
            ar[i].f.f += x;
        }
    }
    sort(all(ar));
    reverse(all(ar));
    fore(i, 0, k)
    {
        ar[i].s = ar[i].f.f * ar[i].f.f - ar[i].f.s;
        fore(j, 0, k)
            if(i != j)
                ar[i].s += 2 * ar[i].f.f * ar[j].f.f;
    }
    fore(i, 0, 10)
    fore(i, k, n)
    {
        int ind = 0;
        ar[i].s = ar[i].f.f * ar[i].f.f - ar[i].f.s;
        fore(j, 0, k)
            ar[i].s += 2 * ar[i].f.f * ar[j].f.f;
        ii swas = {0, -1};
        fore(j, 1, k)
            if(ar[i].s - 2 * ar[i].f.f * ar[j].f.f > ar[j].s)
                swas = max(swas, {ar[i].s - 2 * ar[i].f.f * ar[j].f.f - ar[j].s, j});
        if(swas.s != -1)
        {
            int ind = swas.s;
            fore(j, 0, k)
                if(j != ind)
                    ar[j].s += 2 * ar[i].f.f * ar[j].f.f - 2 * ar[ind].f.f * ar[j].f.f;
            ar[i].s -= 2 * ar[i].f.f * ar[ind].f.f;
            swap(ar[i], ar[ind]);
        }
    }
    int nega = 0, res = 0;
    fore(i, 0, k)
    {
        res = (res + ar[i].f.f) % MOD, nega = (nega + MOD - ar[i].f.s) % MOD;
    }
    cout<<res<<' '<<MOD - nega<<'\n';
    cout<<pot(6, MOD - 2)<<'\n';
    cout<<res * res % MOD * pot(6, MOD - 2) % MOD * pot(6, MOD - 2) % MOD<<'\n';
    cout<<(res * res % MOD * pot(6, MOD - 2) % MOD * pot(6, MOD - 2) + nega)% MOD<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
