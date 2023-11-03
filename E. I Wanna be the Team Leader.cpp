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
int tra[tam], pro[tam];
vii harmo[30];
int n, m;
int dp[30][tam], can[30][tam];
int f(int cual, int pos)
{
    cout<<cual<<' '<<pos<<'\n';
    if(cual == m) return 0;
    if(pos == n) return MOD;
    if(dp[cual][pos] != -1) return dp[cual][pos];
    for(ii cat : harmo[cual])
    {
        int fro = max(cat.f, pos), to = fro + cat.s;
        cout<<cat.f<<'\n';
        cout<<'#'<<cual<<' '<<pos<<'\n';
        cout<<'%'<<fro<<' '<<to<<'\n';
        if(to <= n && f(cual + 1, to) != MOD)
        {
            can[cual][pos] = cat.s;
            cout<<"~~~~ "<<cual<<' '<<pos<<' '<<fro<<'\n';
            return dp[cual][pos] = fro;
        }
    }
    cout<<"!!!! "<<cual<<' '<<pos<<'\n';
    return dp[cual][pos] = MOD;
}
signed main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    mem(dp, -1);
    cin>>n>>m;
    vii traba(n), proj(m);
    fore(i, 0, n) cin>>traba[i].f, traba[i].s = i;
    fore(i, 0, m) cin>>proj[i].f, proj[i].s = i;
    sort(all(traba));
    fore(i, 0, n) tra[i] = traba[i].f;
    sort(all(proj));
    fore(i, 0, m) pro[i] = proj[i].f;
    fore(j, 0, m)
    {
        cout<<'@'<<pro[j]<<'\n';
        vii papa;
        for (int i = 1, la; ; i = la) {
            int david = (pro[j] + i - 1) / i;
            papa.pb({david, i});
            david--;
            if(david == 0) break;
            la = (pro[j] + david - 1) / david;
        }
        reverse(all(papa));
        int po = 0;
        for(ii cat : papa)
        {
            cout<<cat.f<<' '<<cat.s<<'\n';
            while(po < n && tra[po] < cat.f)
                po++;
            cout<<po<<'\n';
            if(po == n) break;
            if(po + cat.s <= n)
                harmo[j].pb({po, cat.s});
        }
    }
    fore(j, 0, m)
    {
        cout<<pro[j]<<'\n';
        for(ii cat : harmo[j])
            cout<<cat.f<<' '<<cat.s<<'\n';
    }
    vector<vi> res(m);
    int popo = 0;
    if(f(0, 0) == MOD)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    fore(i, 0, m)
    {
        // cout<<i<<' '<<popo<<' '<<dp[i][popo]<<' '<<can[i][popo]<<' '<<traba[i].s<<'\n';
        fore(j, dp[i][popo], dp[i][popo] + can[i][popo])
            res[proj[i].s].pb(traba[j].s);
        popo = dp[i][popo] + can[i][popo];
    }
    fore(i, 0, m)
    {
        cout<<sz(res[i]);
        for(int x : res[i])
            cout<<' '<<x + 1;
        cout<<'\n';
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
// Take a sad song and make it better
