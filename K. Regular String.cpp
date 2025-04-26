#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
// vector<vector<int>> table;
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
  // table.pb(col);
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
    swap(col, col1); 
    // table.pb(col);
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
    lcp[k] = z; z = max(z-1, 0);
  }
  return lcp;
}
struct node
{
  int val;
};
int ar[tam];
int t[4 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = ar[b];
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = min(t[l], t[r]);
}
int query(int b, int e, int node, int pos, int val)
{
    // cout<<b<<' '<<e<<' '<<pos<<' '<<t[node]<<'\n';
    if(b > e) exit(0);
    if(b >= pos && t[node] >= val) return e;
    if(b == e) return -1;
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < pos)
		return query(mid + 1, e, r, pos, val);
    int va = query(b, mid, l, pos, val);
    if(va == mid)
        return max(va, query(mid + 1, e, r, pos, val));
    return va;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k == 0)
    {
        cout<<1<<'\n';
        return 0;
    }
    s += (char)('a' - 1);
    vi sa = suffixa(s);
    vi lc = lcp(s, sa);
    fore(i, 0, n + 1)
        ar[i] = lc[i];
    init(0, n, 0);
    // fore(i, 0, n + 1)
    //     cout<<sa[i]<<' ';
    // cout<<'\n';
    // fore(i, 0, n + 1)
    //     cout<<lc[i]<<' ';
    // cout<<'\n';
    int resto = n - k;
    int res = 1;
    fore(i, 2, resto + 1)
    {
        if(resto % i == 0 && i - 1 <= k)
        {
            // cout<<i<<' '<<resto<<'\n';
            int di = resto / i;
            // cout<<di<<'\n';
            fore(j, 1, n)
            {
                if(lc[j] < di) continue;
                // cout<<i<<' '<<j<<' '<<lc[j]<<' '<<sa[j]<<' '<<di<<'\n';
                // return 0;
                int ri = query(0, n, 0, j, di);
                ri++;
                // cout<<"EEE "<<i<<' '<<j<<' '<<ri<<'\n';
                vi ar;
                fore(i, j, ri + 1)
                    ar.pb(sa[i]);
                j = ri;
                // cout<<"EEE "<<i<<' '<<j<<'\n';
                sort(all(ar));
                // for(int x : ar)
                //     cout<<x<<' ';
                // cout<<'\n';
                int can = 0, la = -MOD;
                for(int x : ar)
                {
                    if(x - di > la)
                        can++, la = x;
                }
                if(can >= i)
                    res = i;
            }
        }
    }
    cout<<res<<'\n';
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
