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
struct unionFind {
  vi p;
  unionFind(int n) : p(n, -1) {}
  int findParent(int v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
  cin>>t;
  fore(asd, 0, t)
  {
    int n, m, h;
    cin>>n>>m>>h;
    unionFind uf(min(n, m));
    int con = 0;
    vector<vi> mat(n, vi(m));
    forn(i, n) forn(j, m) cin>>mat[i][j];
    if(n < m)
    {
      vector<vi> mat2(m, vi(n));
      forn(i, n) forn(j, m) mat2[j][i] = mat[i][j];
      swap(mat, mat2);
      swap(n, m);
    }
    vector<vi> dif(m, vi(m, -1));
    bool bo = true;
    fore(i, 0, n)
    {
      forn(j, m)
      {
        fore(k, j + 1, m)
        {
          if(mat[i][j] != -1 && mat[i][k] != -1)
          {
            int di = ((mat[i][j] - mat[i][k]) % h + h) % h;
            if(dif[j][k] == -1) dif[j][k] = di;
            else bo &= dif[j][k] == di;
            con += uf.join(j, k);
          }
        }
      }
    }
    fore(i, 0, m)
    fore(j, i + 1, m)
    fore(k, j + 1, m)
      if(dif[i][j] != -1 && dif[j][k] != -1 && dif[i][k] != -1)
        bo &= (dif[i][j] + dif[j][k]) % h == dif[i][k];
      else if(dif[i][j] != -1 && dif[j][k] != -1)
        dif[i][k] = (dif[i][j] + dif[j][k]) % h;
    if(bo)
    {
      int res = 1;
      fore(i, con, m - 1) res = res * h % MOD;
      fore(i, 0, n)
      {
        int co = 0;
        forn(j, m) if(mat[i][j] == -1) co++;
        if(co == m)
          res = res * h % MOD;
      }
      cout<<res<<'\n';
    }
    else
      cout<<0<<'\n';
  }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
