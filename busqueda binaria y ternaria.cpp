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
const double EPS = 1e-7;
const double PI = acos(-1); 

bool existe(vector<int> &ar, int x)
{
    // **[lo, hi]**   [lo, hi), (lo, hi)
    int lo = 0, hi = (int)ar.size() - 1, mid, res = -1;
    // encontrar el primer mayor o igual
    // 1, 2, 3, 5, 7  x es 5
    // 0  0  0  1  1
    // 1  + 100 -> 101    medio 50
    // 0 1 medio 0

    // 00000000111111111
    //             ^
    // 000000001111_____
    //     ^
    // _____0001111_____
    //         ^
    // _____000_________
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(ar[mid] >= x)
            res = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    // encontrar el ultimo menor o igual
    // 1, 2, 3, 5, 7  x es 5
    // 1  1  1  1  0
    lo = 0, hi = (int)ar.size() - 1;
    // 111111000000000000
    //          ^
    // 111111000_________
    //     ^
    // _____1000_________
    //       ^
    // _____1____________
    //      ^
    // __________________
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(ar[mid] <= x)
        {
            res = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    if(res == -1)
        return 0;
    else
        ar[res] == x;
}
int mas_cercano(vi &ar, int x)
{
    sort(all(ar));
    int n = ar.size();
    pair<int, int> res = {2e9, 0};
    fore(i, 0, n - 1)
    {
        int lo = i + 1, hi = n - 1, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(ar[i] + ar[mid] >= x)
            {
                res = min(res, {ar[i] + ar[mid] - x, ar[i] + ar[mid]});
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        lo = i + 1, hi = n - 1;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            int suma = ar[i] + ar[mid];
            if(suma <= x)
            {
                // pair<int, int> p;
                // p.f = x - suma;
                // p.s = suma;
                // if(res.f > p.f)
                // {
                //     res.f = p.f;
                //     res.s = p.s;
                // }
                // else if(res.f == p.f)
                //     res.s = min(res.s, p.f);
                res = min(res, {x - suma, suma});
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
    }
    return res.s;
}
int f(int x)
{
    return 0;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    // lista prohibida
	// int x;
    // lo = 0, hi = x;
    // while(lo + hi)
    // {
    //     mid = (lo + hi) / 2;

    //     if(existen_disponibles_entre(mid, x))

    //     if(existen_disponibles_entre(x, mid))
    // }


    // ternary
    int n = 100;
    int lo = 0, hi = n - 1, mid, res;
    // 0,0,0  0, 0, 0, 1,1,1
    // -,-, -, 0,0 0, + , +, +
    // 2, 3, 4,5,5,5,5, 3, 2, 1, 0 
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(f(mid) - f(mid + 1) > 0)
            res = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    // 0, 0, 0, 0,0,0,1,1,1
    // +,+, +, 0,0 0,- ,-, -
    // 5, 4, 3,2,2,2,2, 3, 4, 5 
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(f(mid) - f(mid + 1) < 0)
            res = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    // reales
    // el pasito 0.0000001
    // max(f(x)) / el_pasito > presicion
    // el_pasito deberia ser mas grande 
    // for(int i = 0; i < 60; i++)
    while(lo < hi - EPS)
    {
        mid = (lo + hi) / 2;
        if(f(mid) - f(mid + EPS) > 0)
            res = mid, hi = mid - EPS;
        else
            lo = mid + EPS;
    
    double l, r, res;
    fore(i, 0, 50)
    {
        double a = l + (r - l) / 3;
        double b = l + (r - l) * 2 / 3;
        if(f(a) < f(b))
            l = a;
        else
            r = b;
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
