#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long      ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define mt                make_tuple
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)     for(ll i=(ll)b,o_o=e;i<(ll)o_o;++i)
#define forr(i,b,e)     for(ll i=(ll)b,o_o=e;i<(ll)o_o;++i)
#define deb(x)        cerr << "# " << (#x) << " = " << (x) << endl;
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

ll add(ll a, ll b, const ll m) {
  if (a > m) a %= m;
  if (b > m) b %= m;
  return (a+b>=m ? a+b-m : a+b);
}

ll mul(ll a, ll b, const ll m) {
  return 1LL * a * b % m;
}

ll sub(ll a, ll b, const ll m) {
  if (a > m) a %= m;
  if (b > m) b %= m;
  return (a-b<0 ? a-b+m : a-b); 
}

ll m;
string s;

ll pot10[5555];

ll f(ll diff, ll sd, ll pos, ll men) {
  if (pos == s.size()) {
    return (diff==0);
  }
  ll &res = dp[diff][sd][pos][men];
  if (res != -1) return res;
  res = 0;
  ll ax;
  fore(d, 0, 10) {
    if (d > s[pos]-'0' && !men) continue;
    int newMen = (men | (d < s[pos]-'0'));
    ll pot = s.size()-pos-1;
    ll addX = pot10[pot] * d % m;
    ll addF = d * sd % m;
    
    ll newDiff = diff + addX - addF;
    newDiff = newDiff >= m ? newDiff - m : newDiff < 0 ? newDiff + m : newDiff;
    ax = sd + d;
    ax = ax >= m ? ax - m : ax;
    res = res + f(newDiff, ax, pos+1, newMen);
    res = res > mod ? res - mod : res;
    //res = (res + f((diff + addX - addF + m+m)%m, (sd+d)%m, pos+1, newMen)) % mod;
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
  res = f(0,0,0,0);
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
  res = sub(res, f(0,0,0,0), mod);
  //cerr << s << " hay " << f(0,0,0,0) << '\n';
  //cerr << '\n';
  assert(res >= 0);
  return res;
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
    //cout << solveBrute(l, r, m) << '\n';
  }
  return 0;
}
// Dinosaurs are cool!