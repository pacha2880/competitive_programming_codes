#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef pair<pair<ll, ll>, ll> iii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const ll tam = 100'010;
const ll MOD = 1'000'000'007;
const ll INF = MOD * MOD;
const ll MOD1 = 998'244'353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

ll mat[550][550];
ll a[260][260]; // matriz de costos, 1-index
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n)
		fore(j, 0, n)
		{
			cin>>mat[i][j];
			if(i%2 == 1 && j % 2 == 0)
			{
				a[j / 2 + 1][i / 2 + 1] += mat[i][j];
				if(i < n - 1)
					a[j / 2 + 1][(i + 1) / 2 + 1] += mat[i][j];
			}
		}
	n = (n + 1) / 2;
	// fore(i, 0, n + 1)
	// {
	// 	fore(j, 0, n + 1)
	// 		cout<<a[i][j]<<',';
	// 	cout<<'\n';
	// }
	int m = n;
	vector<ll> u(n+1), v(m+1), p(m+1), way(m+1);
	for (ll i = 1; i <= n; i++) {
		p[0] = i;
		ll j0 = 0;
		vector<ll> minv(m + 1, INF);
		vector<char> used(m + 1, false); 
		do {
			used[j0] = true;
			ll i0 = p[j0], delta = INF, j1;
			for (ll j = 1; j <= m; ++j)
				if ( !used[j] ) {
					ll cur = a[i0][j] - u[i0] - v[j];
					if ( cur < minv[j] )
						minv[j] = cur, way[j] = j0;
					if ( minv[j] < delta )
						delta = minv[j], j1 = j;
				}
			for (ll j = 0; j <= m; ++j)
				if ( used[j] )
					u[ p[j] ] += delta, v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		} while ( p[j0] != 0 );
		do {
			ll j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while ( j0 ) ;
	}

	vector<ll> ans(n+1); // Para cada fila, en que columna esta el resultado.
	for (ll j = 1; j <= m; ++j)
		ans[ p[j] ] = j;

	ll res = 0;
	fore(i, 1, n + 1)
		res+= a[i][ans[i]];
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
