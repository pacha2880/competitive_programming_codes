#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
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
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
bool prim(int n)
{
	int div = 0;
	fore(i, 1, n + 1)
	div += n % i == 0;
	return div == 2;
}
typedef vector<vector<int>> mat;
// resuelve Ax = b, dada la matriz a de n * (m + 1), n ecuaciones y m variables, siendo la ultima columna el vector b
// The function returns the number of solutions of the system (0,1,or ∞). if there's at least a solution, it's in ans

const int INF = 2; // it doesn't actually have to be infinity or a big number
int gauss (mat &a) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    int ran = 0;
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (a[sel][col] == 0)
            continue;
        ran++;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                {
                    a[i][j] -= a[row][j] * c;
                    a[i][j] += 10;
                    a[i][j] %= 2;
                }
            }
        ++row;
    }
    return m - ran;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("rsa.in", "r", stdin);
	// freopen("rsa.out", "w", stdout);
	int t, n;
	cin>>t>>n;
	vi ar(n);
	fore(i, 0, n) cin>>ar[i];
	vi pri(t);
	int pra = 0, nu = 2;
	while(pra < t)
	{
		while(!prim(nu)) nu++;
		// cout<<nu<<'\n';
		pri[pra++] = nu++;
	}
	mat m(t, vi(n + 1));
	fore(i, 0, n)
	{
		fore(j, 0, t)
			while(ar[i] % pri[j] == 0)
				ar[i] /= pri[j], m[j][i] ^= 1;
	}
	// for(auto cat : m)
	// {
	// 	for(int x : cat)
	// 		cout<<x<<' ';
	// 	cout<<'\n';
	// }
	int ga = gauss(m);
	// assert(ga < 70);
	// cout<<ga<<'\n';
	__int128 nu = 1;
	while(ga)
	{
		ga--;
		nu *= 2;
	}
	nu--;
	print(nu);
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
