#include <bits/stdc++.h>
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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<pair<int, ll>> tab[tam];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, q;
    cin>>n>>q;
    vi ar(n);
    fore(i, 0, n) cin>>ar[i];
    fore(pas, 1, q + 1)
    {
        int a, b;
        cin>>a>>b;
        for(int i = 1; i * i <= a; i++)
        {
            if(a % i == 0)
            {
                if(i > 1)
                    tab[i].pb({pas, b});
                if(i * i != a)
                    tab[a / i].pb({pas, b});
            }
        }
        
    }
    fore(i, 0, tam)
    {
        fore(j, 1, tab[i].size())
            tab[i][j].s += tab[i][j - 1].s;
    }
    fore(i, 1, n + 1)
    {
        vi fac;
        int ax = i;
        for(int i = 2; i * i <= ax; i++)
        {
            if(ax % i == 0)
            {
                while(ax % i == 0) ax /= i;
                fac.pb(i);
            }
        }
        if(ax > 1) fac.pb(ax);
        int b = 1, e = q, mid, res = -1;
        while(b <= e)
        {
            mid = (b + e) / 2;
            ll su = 0;
            fore(i, 1, 1<<sz(fac))
            {
                int con = 0;
                int x = 1;
                fore(j, 0, fac.size())
                    if((i >> j) & 1)
                    {
                        x *= fac[j];
                        con++;
                    }
                auto it = lower_bound(all(tab[x]), mp(mid + 1, -1ll));
                if(it != tab[x].begin())
                {
                    it--;
                    su += it->s * (con & 1 ? 1 : -1);
                }
            }
            if(su >= ar[i - 1])
                res = mid, e = mid - 1;
            else
                b = mid + 1;
        }
        cout<<res<<'\n';
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
