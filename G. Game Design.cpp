#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
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

typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll INF = 1234567890;

// d^2+2x ; d ; pos
ll dp[60][60][5001][2];
const ll mod = 1e9+7;

// ll add(ll a, ll b, const ll m) {
//   //a %= m;
//   //b %= m;
//   //return (a+b>m ? a+b-m : a+b);
//   return (0LL+(a%m)+(b%m))%m;
// }

// ll mul(ll a, ll b, const ll m) {
//   return (1LL*(a%m)*(b%m)) % m;
// }

// ll sub(ll a, ll b, const ll m) {
//   //return (a-b<0 ? a-b+m : a-b);
//   return (0LL+(a%m)-(b%m)+m)%m;
// }

ll m;
string s;

ll pot10[5555];

ll getpot10(ll e){
  if (e == 0) return 1;
  if (pot10[e] != -1) return pot10[e];
  //return mul(10, getpot10(e-1), m);
  return (10LL * getpot10(e-1)) % m;
}

ll f(ll xdd, ll d, ll pos, ll men) {
  //cerr << xdd << " " << d << " " << pos << " " << men << '\n';
  //xdd %= m;
  //d %= m;
  assert(xdd < m);
  assert(d < m);
  if (pos == s.size()) {
    //return (mul(d,d,m) == xdd ? 1 : 0);
    return ((d*d)%m == xdd ? 1 : 0);
  }
  assert(pos < s.size());
  ll &res = dp[xdd][d][pos][men];
  if (res != -1) return res;
  res = 0;
  fore(dig, 0, 10) {
    if (dig > s[pos]-'0' && !men) continue;
    
    ll newMen = (men | (dig < s[pos]-'0'));
    
    ll pot = s.size()-1-pos;
    //ll xd = add(xdd, mul(dig,dig, m), m);
    //xd = add(xd, mul(2, mul(dig, getpot10(pot), m), m), m);
    ll xd = (xdd + dig*dig + 2*dig*pot10[pot]) % m;
    
    //ll newD = add(d, dig, m);
    ll newD = (d + dig) % m;

    //res = add(res, f(xd, newD, pos+1, newMen), mod);
    res = (res + f(xd, newD, pos+1, newMen)) % mod;
  }
  return res;
}

ll solve(string l, string r, int m) {
  // LIMPIAR DP  Y POTENCIAS DE 10
  auto limpiar = [&](string &str) {
    pot10[0] = 1%m;
    fore(i, 1, str.size()+1) pot10[i] = (10LL * pot10[i-1]) % m;
    fore(i, 0, m) {
      fore(j, 0, m) {
        fore(k, 0, str.size()) {
          fore(men, 0, 2) {
            dp[i][j][k][men] = -1;
          }
        }
      }
    }
  };
  ll res = 0;
  // para r
  s = r;
  limpiar(s);
  res = f(0,0,0,0)%mod;
  //cerr << s << " hay " << f(0,0,0,0) << '\n';
  // para l-1
  s = l;
  for(ll i = s.size()-1; i >= 0; i--) {
    if (s[i] == '0') {
      s[i] = '9';
    }
    else {
      s[i]--;
      break;
    }
  }
  while (s[0] == '0') s = s.substr(1);
  limpiar(s);
  //res = sub(res, f(0,0,0,0), mod);
  res = (res - f(0,0,0,0)%mod + mod) % mod;
  //cerr << s << " hay " << f(0,0,0,0) << '\n';
  //cerr << '\n';
  return res;
}

bool brutef(int x) {
  ll sum = 0;
  ll res = 0;
  while (x > 0) {
    int d = x % 10;
    x /= 10;
    res += sum * d;
    sum += d;
  }
  return res;
}

ll solveBrute(string l, string r, int m) {
  stringstream ss;
  ss << l << " " << r;
  ll L, R;
  ss >> L >> R;
  ll res = 0;
  fore(x, L, R+1) {
    res += (x%m == brutef(x)%m);
  }
  assert(res < 0);
  return res;
}

void stress() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  fore(i, 0, 10000) {
    int l = rng() % 5000;
    int r = rng() % 5000;
    l += 10;
    r += 10;
    if (l > r) swap(l, r);
    string L, R;
    stringstream ss;
    ss << l << " " << r;
    ss >> L >> R;
    m = rng()%61;
    if (m < 2) m = 2;
    //cerr << L << " " << R << " " << m << "\n";
    ll res = solve(L, R, m);
    ll bruteRes = solveBrute(L, R, m);
    if (res != bruteRes) {
      cout << "MAL\n";
      cout << L << " " << R << " " << m << "\n\n";
    }
  }
}

int main()
{
  std::ios::sync_with_stdio(false); cin.tie(0);
  //freopen("","r",stdin);
  //freopen("","w",stdout);
  //stress(); return 0;
  ll t;
  cin >> t;
  while (t--) 
  {
    string l, r;
    cin >> l >> r;
    cin >> m;
    cout << solve(l, r, m) << '\n';
  }
  return 0;
}
// Dinosaurs are cool!