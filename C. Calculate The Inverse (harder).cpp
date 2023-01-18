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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int mu[tam], is_prime [tam];

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    vi pri;
	fore(i, 0, tam) mu[i]=is_prime[i]=1;
    fore(i, 2, tam) if(is_prime[i]) {
        pri.pb(i);
        forg(j, i, tam, i) {
            if(j > i) is_prime[j] = 0;
            if(j / i % i == 0) mu[j]=0;
            mu[j] = -mu[j];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        ll res = x * x - 3 * x + 2;
        vi facx;
        int ax = x;
        for(int i = 0; pri[i] * pri[i] <= x; i++)
        {
            if(x % pri[i] == 0)
            {
                facx.pb(pri[i]);
                while(x % pri[i] == 0) x /= pri[i];
            }
        }
        if(x > 1) facx.pb(x);
        x = ax;
        int n  = facx.size();
        fore(i, 1, 1<<n)
        {
            int nu = 1;
            int cnt = 0;
            fore(j, 0, n)
                if((i>>j) & 1)
                    cnt++, nu *= facx[j];
            nu = x / nu;
            if(cnt & 1) res -= nu * nu - 3 * nu + 2;
            else res += nu * nu - 3 * nu + 2;
        }
        cout<<res<<'\n';
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
