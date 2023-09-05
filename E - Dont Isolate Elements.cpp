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
bitset<1010> tab[1010], uns;
    int dirx[] = {0, 0, 1, -1}, diry[] = {1, -1, 0, 0};
	int n, m;
bool bad(int x, int y)
{
    fore(i, 0, 4)
    {
        int xx = x + dirx[i], yy = y + diry[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && tab[xx][yy] == tab[x][y])
            return false;
    }
    return true;
}
int dp[4][1010];
int f(int pos, int mask)
{
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int fi = mask & 1, fai = mask > 1;
    if(fi)
        tab[pos] ^= uns;
    if(fai)
        tab[pos - 1] ^= uns;
    if(pos == 1)
    {
        bool malo = 0;
        fore(i, 0, m)
            if(bad(0, i))
                malo = 1;
        if(malo)
        {
            if(fi)
                tab[pos] ^= uns;
            if(fai)
                tab[pos - 1] ^= uns;
            return dp[mask][pos] = MOD;
        }
    }
    if(pos == n - 1)
    {
        bool malo = 0;
        fore(i, 0, m)
            if(bad(pos, i))
                malo = 1;
        if(fi)
            tab[pos] ^= uns;
        if(fai)
            tab[pos - 1] ^= uns;
        if(malo)
            return dp[mask][pos] = MOD;
        return dp[mask][pos] = 0;
    }
    int res = MOD;
    bool malo1 = 0;
    fore(i, 0, m)
        if(bad(pos, i))
            malo1 = 1;
    tab[pos + 1] ^= uns;
    bool malo2 = 0;
    fore(i, 0, m)
        if(bad(pos, i))
            malo2 = 1;
    tab[pos + 1] ^= uns;
    if(fi)
        tab[pos] ^= uns;
    if(fai)
        tab[pos - 1] ^= uns;
    if(!malo1)
        res = min(res, 0 + f(pos + 1, fi * 2));
    if(!malo2)
        res = min(res, 1 + f(pos + 1, fi * 2 + 1));
    return dp[mask][pos] = res;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    uns.set();
    cin>>n>>m;
    fore(i, 0, n) fore(j, 0, m) 
    {
        int x;
        cin>>x;
        tab[i][j] = x;
    }
    mem(dp, -1);
    int res = min({f(1, 0), f(1, 1) + 1, f(1, 2) + 1, f(1, 3) + 2});
    if(res >= MOD)
        cout<<-1<<'\n';
    else
        cout<<res<<'\n';
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
