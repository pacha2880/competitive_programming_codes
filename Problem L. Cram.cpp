#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
//vector<vector<int>> table;
vector<int> suffixa(string &s){
  int n = s.size(), cc, ax;
  vector<int> sa(n), sa1(n), col(n), col1(n), head(n);
  fore(i, 0, n) sa[i] = i;
  auto cmp = [&](int a, int b){ return s[a] < s[b]; };
  stable_sort(sa.begin(), sa.end(), cmp);
  head[0] = col[sa[0]] = cc = 0;
  fore(i, 1, n){
    if(s[sa[i]] != s[sa[i-1]])
      cc++, head[cc] = i;
    col[sa[i]] = cc;
  }
  //table.pb(col);
  for(int k = 1; k < n; k *= 2){
    fore(i, 0, n){
      ax = (sa[i] - k + n) % n;
      sa1[head[col[ax]]++] = ax;
    }
    swap(sa, sa1);
    col1[sa[0]] = head[0] = cc = 0;
    fore(i, 1, n){
      if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
        cc++, head[cc] = i;
      col1[sa[i]] = cc;
    }
    swap(col, col1);//table.pb(col);
    if(col[sa[n - 1]] == n - 1) break;
  }
  return sa;
}
vector<int> lcp(string &s, vector<int> &sa){
  int n = s.size(), k, z = 0;
  vector<int> sa1(n), lcp(n);
  fore(i, 0, n) sa1[sa[i]] = i;
  fore(i, 0, n){
    k = sa1[i];
    if(k < n - 1)
      while(s[i + z] == s[sa[k+1] + z])
        z++;
    lcp[k] = z; z = max(z-1, 0ll);
  }
  return lcp;
}
int ar[2][tam];
int t[2][4 * tam];
void init(int b, int e, int node, int ban)
{
    if(b == e)
    {
        t[ban][node] = ar[ban][e];
        return;
    }
    index;
    init(b, mid, l, ban);
    init(mid + 1, e, r, ban);
    t[ban][node] = min(t[ban][l], t[ban][r]);
}
int query(int b, int e, int node, int i, int j)
{
    if(b >= i && e <= j)
        return t[1][node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return min(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
int queryl(int b, int e, int node, int i, int j, int val)
{
    if(b == e)
    {
        if(t[0][node] < val)
            return b;
        return -1;
    }
    index;
    if(b >= i && e <= j)
    {
        if(t[0][node] >= val)
            return -1;
        if(t[0][l] < val)
            return queryl(b, mid, l, i, j, val);
        return queryl(mid + 1, e, r, i, j, val);
    }
    if(mid >= j)
        return queryl(b, mid, l, i, j, val);
    if(mid < i)
        return queryl(mid + 1, e, r, i, j, val);
    int res = queryl(b, mid, l, i, j, val);
    if(res == -1)
        return queryl(mid + 1, e, r, i, j, val);
    return res;
}
int queryr(int b, int e, int node, int i, int j, int val)
{
    if(b == e)
    {
        if(t[0][node] < val)
            return b;
        return -1;
    }
    index;
    if(b >= i && e <= j)
    {
        if(t[0][node] >= val)
            return -1;
        if(t[0][r] < val)
            return queryr(mid + 1, e, r, i, j, val);
        return queryr(b, mid, l, i, j, val);
    }
    if(mid >= j)
        return queryr(b, mid, l, i, j, val);
    if(mid < i)
        return queryr(mid + 1, e, r, i, j, val);
    int res = queryr(mid + 1, e, r, i, j, val);
    if(res == -1)
        return queryr(b, mid, l, i, j, val);
    return res;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    string s;
    getline(cin, s);
    // cout<<sz(s)<<'\n';
    char cha = (char)(0);
    s += cha;
    vi sa = suffixa(s);
    vi lc = lcp(s, sa);
    int n = s.size();
    fore(i, 0, n)
        ar[0][i] = sa[i], ar[1][i] = lc[i];
    init(0, n - 1, 0, 0);
    init(0, n - 1, 0, 1);
    vi popo(n);
    fore(i, 0, n) popo[sa[i]] = i;
    vi dp(n);
    // fore(i, 0, n) cout<<sa[i]<<' ';
    // cout<<'\n';
    // fore(i, 0, n) cout<<lc[i]<<' ';
    // cout<<'\n';
    // cout<<n<<'\n';
    for(int i = n - 2; i > -1; i--)
    {
        int fid = queryl(0, n - 1, 0, popo[i], n - 1, i);
        int fii = queryr(0, n - 1, 0, 0, popo[i], i);
        int mimid = 0, mimii = 0;
        if(fid != -1)
            mimid = query(0, n - 1, 0, popo[i], fid - 1);
        if(fii != -1)
            mimii = query(0, n - 1, 0, fii, popo[i] - 1);
        // cout<<i<<' '<<popo[i]<<'\n';
        // cout<<fid<<' '<<fii<<' '<<mimid<<' '<<mimii<<'\n';
        mimid = max(mimid, mimii);
        if(mimid > 3)
            dp[i] = min(3 + dp[i + mimid], 1 + dp[i + 1]);
        else
            dp[i] = 1 + dp[i + 1];
        // cout<<dp[i]<<'\n';
    }
    cout<<dp[0]<<'\n';
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
