#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
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
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
constexpr long long safe_mod(long long x, long long m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
  a = safe_mod(a, b);
  if (a == 0) return {b, 0};
  long long s = b, t = a;
  long long m0 = 0, m1 = 1;
  while (t) {
    long long u = s / t;
    s -= t * u;
    m0 -= m1 * u;
    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  if (m0 < 0) m0 += b / s;
  return {s, m0};
}
std::pair<long long, long long> crt(const std::vector<long long>& r,
                  const std::vector<long long>& m) {
  assert(r.size() == m.size());
  int n = int(r.size());
  long long r0 = 0, m0 = 1;
  for (int i = 0; i < n; i++) {
    assert(1 <= m[i]);
    long long r1 = safe_mod(r[i], m[i]), m1 = m[i];
    if (m0 < m1) {
      std::swap(r0, r1);
      std::swap(m0, m1);
    }
    if (m0 % m1 == 0) {
      if (r0 % m1 != r1) return {0, 0};
      continue;
    }
    long long g, im;
    std::tie(g, im) = inv_gcd(m0, m1);
    long long u1 = (m1 / g);
    if ((r1 - r0) % g) return {0, 0};
    long long x = (r1 - r0) / g % u1 * im % u1;
    r0 += x * m0;
    m0 *= u1;
    if (r0 < 0) r0 += m0;
  }
  return {r0, m0};
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	vi pris({4, 5, 9, 7, 11, 13, 17, 19, 23});
    int n = sz(pris);
    int m = 0;
    for(int x : pris) m += x;
    // int su = 0, mul = 1;
    // for(int x : pris)
    //     su += x, mul *= x;
    // cout<<su<<' '<<mul<<'\n';
    cout<<m<<'\n';
    cout.flush();
    int pozo = 0;
    vi printa(m);
    vi pozos;
    for(int x : pris)
    {
        pozos.pb(pozo);
        fore(i, pozo, pozo + x - 1)
            printa[i] = i + 1;
        printa[pozo + x - 1] = pozo;
        pozo += x;
    }
    for(int x : printa)
        cout<<x + 1<<' ';
    cout<<'\n';
    cout.flush();
    vi ar(m);
    fore(i, 0, m) cin>>ar[i];
    vi rem(n);
    fore(i, 0, n) rem[i] = ar[pozos[i]] - pozos[i] - 1;
    ii res = crt(rem, pris);
    cout<<res.f<<'\n';
    cout.flush();
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
