#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp        make_pair
#define int 			long long
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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

typedef long long     ll;
typedef long double ld;  
typedef unsigned long long     ull;
typedef pair<int, int>  ii;
typedef vector<int>   vi;
typedef vector<ii>    vii;
typedef vector<ll>    vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[30];
int res = MOD * MOD;
vector<int> grupo1, grupo2;
void go(int po)
{
    if(po == -1)
    {
        int suma1 = 0, suma2 = 0;
        for(int x : grupo1)
          suma1 += x;
        for(int x : grupo2)
          suma2 += x;
        res = min(res, abs(suma1 - suma2));
        return;
    }
    grupo1.pb(ar[po]);
    go(po - 1);
    grupo1.pop_back();
    grupo2.pb(ar[po]);
    go(po - 1);
    grupo2.pop_back();
}
signed main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("asd.txt", "r", stdin);
  // freopen("qwe.txt", "w", stdout);
  int n;
  cin>>n;
  fore(i, 0, n) cin>>ar[i];
  go(n - 1);
  cout<<res<<'\n';
  return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
