#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp        make_pair
#define pb        push_back
#define all(a)      (a).begin(), (a).end()
#define sz(a)      (int)a.size()
#define eq(a, b)     (fabs(a - b) < EPS)
#define md(a, b)    ((a) % b + b) % b
#define mod(a)      md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)      sort(all(a))
#define mem(a, h)    memset(a, (h), sizeof(a))
#define f         first
#define s         second
#define forn(i, n)      for(int i = 0; i < n; i++)
#define fore(i, b, e)  for(int i = b; i < e; i++)
#define forg(i, b, e, m)  for(int i = b; i < e; i+=m)
#define index  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long     ll;
typedef long double ld;  
typedef unsigned long long     ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>   vi;
typedef vector<ii>    vii;
typedef vector<ll>    vll;
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
int dp[19][2];
string nu;
int n;
int f(int pos, int flag)
{
  if(pos == n) return 1;
  if(dp[pos][flag] != -1) return dp[pos][flag];
  int res = 0;
  if(pos >= (n + 1) / 2)
  {
    if(flag)
      res = f(pos + 1, flag);
    else
      res = nu[pos] == nu[n - 1 - pos] ? f(pos + 1, flag) :
        nu[pos] > nu[n - 1 - pos] ? f(pos + 1, 1) : 0;
  }
  else if(flag)
    res = 10 * f(pos + 1, flag);
  else
    res = (pos == 0 ? nu[pos] - 1 : nu[pos]) * f(pos + 1, 1) + f(pos + 1, 0);

  return dp[pos][flag] = res;
}
int f(string x)
{
  n = sz(x);
  int po = 9, acu = 0;
  // cout<<'$'<<x<<' ';
  fore(i, 0, n)
  {
    if(i % 2 == 0 && i > 0)
      po *= 10;
    if(i < n - 1)
      acu += po;
    x[i] -= '0';
  }
  // cout<<acu<<"#\n";
  mem(dp, -1);
  nu = x;
  // cout<<f(0, 0)<<'\n';
  return f(0, 0) + acu;
}
signed main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("asd.txt", "r", stdin);
  // freopen("qwe.txt", "w", stdout); 
  int t;
  cin>>t;
  while(t--)
  {
    int i, j;
    cin>>i>>j;
    cout<<f(to_string(j)) - f(to_string(i - 1))<<'\n';
  }
  return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasándola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Si te caes 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad.
// Take a sad song and make it better.
