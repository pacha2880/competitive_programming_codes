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
const int tam = 2010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
char tab[tam][tam];
int su[tam][tam], dia[tam * 2][tam], hor[tam][tam];
int m, n;
int va(int i, int j)
{
    if(i < 0 || j < 0 || i >= n) return 0;
    return tab[i][j] == 'O';
}
int diag(int i, int j)
{
    if(i < 0 || j < 0) return 0;
    if(dia[i][j] != -1) return dia[i][j];
    return dia[i][j] = diag(i + 1, j - 2) + va(i - m + 1, j) + va(i - m + 1, j - 1) - va(i + 1, j - 2 * m) - va(i + 1, j - 2 * m - 1); 
}
int hori(int i, int j)
{
    if(i < 0 || j < 0) return 0;
    if(hor[i][j] != -1) return hor[i][j];
    return hor[i][j] = hori(i, j - 1) - va(i, j - 2 * m) + va(i, j);
}
int sum(int i, int j)
{
    if(i < 0 || j < 0) return 0;
    if(su[i][j] != -1) return su[i][j];
    int va = sum(i - 1, j) - diag(i - 1, j) + hori(i, j);
    return su[i][j] = sum(i - 1, j) - diag(i - 1, j) + hori(i, j);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	mem(su, -1);
    mem(dia, -1);
    mem(hor, -1);
    cin>>n>>m;
    fore(i, 0, n)
        fore(j, 0, n)
            cin>>tab[i][j];
    int q;
    cin>>q;
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        cout<<sum(a - 1, b - 1)<<'\n';
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
