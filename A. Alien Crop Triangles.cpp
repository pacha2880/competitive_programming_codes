#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/extc++.h>
typedef int       ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define mt                make_tuple
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)		  for(ll i=(ll)b,o_o=e;i<(ll)o_o;++i)
#define forr(i,b,e)		  for(ll i=(ll)b,o_o=e;i<(ll)o_o;++i)
#define deb(x)			  cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x)             (ll)x.size()
ll faster_in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = numeric_limits<ll>::max() / 4;
const double EPS = 1e-7;
const ll tam = 1e7 + 11;

vector<ii> v;
ll dp[6][tam];

// ll f(ll pos, ll kg) {
//   if (kg <= 0) return 0;
//   if (pos >= v.size()) return INF;
//   ll &res = dp[pos][kg];
//   if (res != -1) return res;
//   res = INF;
//   res = f(pos+1, kg);
//   res = min(res, f(pos, kg-v[pos].first) + v[pos].second);
//   res = min(res, INF);
//   return res;
// }

#define _min(a,b) ((a)<(b)?(a):(b))

const double eps = 1e-9;

int main()
{
  //std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("","r",stdin);
  //freopen("","w",stdout);
  ll b, n;
  // cin >> b >> n;
  scanf("%d %d", &b, &n);
  v.resize(b);
  ll ceroP = false;
  ll conPeso = 0;
  for (int i = 0; i < b; ++i) {
    // cin >> v[i].first >> v[i].second;
    scanf("%d %d", &v[i].first, &v[i].second);
    conPeso += (v[i].first > 0);
    if (v[i].first == 0) {
      i--;
      b--;
    }
    else if (v[i].second == 0) {
      ceroP = true;
    }
  }
  v.resize(b);
  sort(all(v), [](ii a, ii b) {
    return a.first * b.second > b.first * a.second;
  });
  long long need = 0;
  long double tot = 0;
  fore(i, 0, n) {
    long double a, b, c;
    // cin >> a >> b >> c;
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    a = x; b = y; c = z;
    //cerr << a << " " << b << " " << c << '\n';
    long double s;
    s = (a + b + c) / 2.0;
    long double area = sqrt(s*(s-a)*(s-b)*(s-c));
    tot += area;
  }
  need = tot/30.0 + 1 - EPS;
  if (b == 0) {
    printf("-1\n");
    return 0;
  }
  if (ceroP) {
    printf("0\n");
    return 0;
  }
  if (n == 0) {
    printf("0");
    return 0;
  }
  assert(need < tam);
  // ll f(ll pos, ll kg) {
  //   if (kg <= 0) return 0;
  //   if (pos >= v.size()) return INF;
  //   ll &res = dp[pos][kg];
  //   if (res != -1) return res;
  //   res = INF;
  //   res = f(pos+1, kg);
  //   res = min(res, f(pos, kg-v[pos].first) + v[pos].second);
  //   res = min(res, INF);
  //   return res;
  // }
  for (ll pos = b-1; pos >= 0; --pos) {
    for (ll kg = 0; kg <= need; ++kg) {
      ll &res = dp[pos][kg];
      if (kg <= 0) {
        res = 0;
        continue;
      }
      res = INF;
      if (pos+1 < b) res = _min(res, dp[pos+1][kg]);
      if (kg <= v[pos].first) {
        res = _min(res, v[pos].second);
      }
      else {
        res = _min(res, v[pos].second + dp[pos][kg-v[pos].first]);
      }
      assert(res >= 0);
    }
  }
  // cout << dp[0][need] << '\n';
  printf("%d\n", dp[0][need]);
  return 0;
}
// Dinosaurs