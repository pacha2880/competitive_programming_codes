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
// int fib(int n)
// {
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     return fib(n - 1) + fib(n - 2);
// } 
int dp[tam];
bool vis[tam];
int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(vis[n]) return dp[n];
    vis[n] = 1;
    dp[n] = fib(n - 1) + fib(n - 2); 
    return dp[n];
}

int saltos(int n)
{
    if(n == 1) return 0;
    if(n <= 3) return 1;
    if(vis[n]) return dp[n];
    vis[n] = 1;
    dp[n] = fib(n - 2) + fib(n - 3); 
    return dp[n];
}

int m = 4;
vi costos({1, 1, 4, 1});
vi quesaltos({2, 5, 3, 7});
int indicesalto[50];
int saltos1(int pos)
{
    if(pos == 0) return 0;
    if(pos < 0) return 1e10;
    if(vis[pos]) return dp[pos];
    vis[pos] = 1;
    dp[pos] = 1e10;
    fore(i, 0, m)
    {
        int cost = saltos1(pos - quesaltos[i]) + costos[i];
        if(dp[pos] > cost)
        {
            dp[pos] = cost;
            indicesalto[pos] = i;
        }
    }
    return dp[pos];
}

void recuperar(int n)
{
    int res = saltos1(n);
    if(res == 1e10)
    {
        cout<<"no llegue";
    }
    else
    {
        while(n > 0)
        {
            cout<<quesaltos[indicesalto[n]]<<'\n';
            n -= quesaltos[indicesalto[n]];
        }
    }
}

int visi[50][50], dp1[50][50];
int saltosk(int escalones, int saltos)
{
    if(saltos < 0) return 0;
    if(escalones < 0) return 0;
    if(escalones == 0)
    {
        // comentar estas 2 lineas si es maximo k saltos
        if(saltos > 0) return 0;
        else 
        return 1;
    }
    // return saltosk(escalones - 1, saltos - 1) +
    //         saltosk(escalones - 2, saltos - 1);
    if(visi[escalones][saltos]) return dp1[escalones][saltos];
    visi[escalones][saltos] = 1;
    dp1[escalones][saltos] = saltosk(escalones - 1, saltos - 1) +
            saltosk(escalones - 2, saltos - 1);
    return dp1[escalones][saltos];
}

vi elementos(m);
// tomar o no tomar
bool mochila(int espacio, int pos)
{
    if(espacio == 0) return true;
    if(espacio < 0) return false;
    if(pos < 0) return false;
    if(visi[espacio][pos])
        return dp1[espacio][pos];
    visi[espacio][pos] = 1;
    dp1[espacio][pos] = mochila(espacio, pos - 1) | 
                mochila(espacio - elementos[pos], pos -1);
    return dp1[espacio][pos];
}

signed main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    fore(i, 0, 50)
    {
        cout<<fib(i)<<'\n';
    }
    // fibonacci iterativo
    vi fibo(50);
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < 50; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    // saltos de 2 y 3
    vi saltos(50);
    saltos[1] = 0;
    saltos[2] = 1;
    saltos[3] = 1;
    for(int i = 4; i < 50; i++)
        saltos[i] = saltos[i - 2] + saltos[i - 3];


    // hartos saltos
    saltos[0] = 1;
    fore(i, 1, 50)
        for(int x : quesaltos)
            if(i - x >= 0)
                dp[i] += dp[i - x];

    // saltos k
    dp1[0][0] = 1;
    // maximo k saltos
    // fore(i, 0, 50)
    //     dp1[0][i] = 1;
    fore(i, 1, 50)
        fore(j, 1, 50)
        {
            if(i > 1)
                dp1[i][j] += dp1[i - 2][j - 1];
            dp1[i][j] += dp1[i - 1][j - 1];
        }
    // subir 20 con 15 saltos
    cout<<dp1[20][15];
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
