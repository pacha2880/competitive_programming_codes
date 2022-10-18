#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                push_back
#define mp    make_pair
#define sz(a)   a.size()
#define mods(a, m)   ((a % m + m) % m)
#define md(a)    mods(a, MOD)
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)   for (int i = b; i < e; i++)
#define forr(i, b, e)     for (int  i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
typedef long double       ld;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
bool visited[210][210][210];
int dp[210][210][210], vals[210][210], ors[210][210], vers[210][210], vars[210][210];
int n, m;
int f(int ar, int ab, int lo)
{
  //cout<<ar<<' '<<ab<<' '<<lo<<'\n';
  if(ab < ar) return -INF;
  if(ab > n) return -INF;
  if(lo == m)
    return -vers[n][m] * 2 + vers[ar][m] + vers[ab][m];
  if(visited[ar][ab][lo]) return dp[ar][ab][lo];
  visited[ar][ab][lo] = 1;
  if(ar == n) return dp[ar][ab][lo] = -ors[ar][lo] * 2 + f(ar, ab, lo + 1);
  int res = max(f(ar, ab + 1, lo) - vars[ab + 1][lo],
              f(ar + 1, ab, lo) - vars[ar + 1][lo]);
  res = max(res, -ors[ar][lo] - ors[ab][lo] + vals[ab][lo] - vals[ar][lo] + f(ar, ab, lo + 1));
  return dp[ar][ab][lo] = res;
}
int main()
{
  std::ios::sync_with_stdio(false); cin.tie(0);
  //freopen("asd.txt","r",stdin);
  //freopen("","w",stdout);
  cin>>n>>m;
  fore(i, 1, n+1) fore(j, 0, m) cin>>vals[i][j];
  fore(i, 1, n + 1) fore(j, 0, m) vals[i][j] += vals[i - 1][j];
  fore(i, 0, n+1) fore(j, 0, m) cin>>ors[i][j];
  fore(j, 0, m+1) fore(i, 1, n + 1)  cin>>vers[i][j];
  fore(j, 0, m + 1) fore(i, 1, n + 1) vars[i][j] = vers[i][j];
  fore(i, 1, n + 1) fore(j, 0, m + 1) vers[i][j] += vers[i-1][j];
  /*fore(i, 0, n + 1)
  {
    fore(j, 0, m)
    cout<<vers[i][j]<<' ';
    cout<<'\n';
  }*/
  cout<<f(0,0,0)<<'\n';
  return 0;
}
// PLUS ULTRA!
//You have n clothes and a washer. The washer is large enough to wash all clothes at once. However, we should worry about color transfer:  if we put clothes of different colors in the washer, the dye from one may stain another. Precisely, let ri, gi, bi denote the amount of red, green, blue color of the i-th clothes. When n clothes are washed together, the color transfer c is defined by