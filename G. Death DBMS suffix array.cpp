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

// #pragma GCC optimization ("O2")
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
typedef vector<vector<int>> mat;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1);

const int logTam = 21;
int sas; 
int ar[tam], table[logTam][tam];
void inispar()
{
	fore(i, 0, sas) table[0][i] = ar[i];
	for(int k = 0; (1 << k) < sas; k++)
		for(int i = 0; i + (1 << k) < sas; i++)
			table[k + 1][i] = min(table[k][i], table[k][i + (1 << k)]);
}
int querys(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return min(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
int t[4 * tam];

void update(int b, int e, int node, int pos, int val) {
    if(b == e){
        t[node] = val;
        return;
    }
    index;
    if(pos > mid)
        update(mid + 1, e, r, pos, val);
    else
        update(b, mid, l, pos, val);
    t[node] = max(t[l], t[r]);
}


int query(int b, int e, int node, int i, int j){
    if(b >= i && e <= j) return t[node];
    index;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return max(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}


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

struct cueri{
    int type, a, b;
    string s;
};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int n, m;
    cin>>n>>m;
    string super;
    vi oliver(n);
    map<int, int> nico;
    fore(i, 0, n){
        string s;
        cin>>s;
        oliver[i] = sz(super);
        nico[sz(super)] = i;
        super += s;
        super += '$';
    }
    vi pozo(m);
    map<int, int> alex;
    vector<cueri> queso(m);
    fore(i, 0, m){
        int type;
        cin>>type;
        queso[i].type = type;
        if(type == 1)
            cin>>queso[i].a>>queso[i].b;
        else{
            cin>>queso[i].s;
            alex[sz(super)] = i;
            pozo[i] = sz(super);
            super += queso[i].s;
            super += '$';
        }
    }
    vi suff = suffixa(super);
    mem(t, -1);
    fore(i, 0, sz(suff)){
        if(nico.count(suff[i]))
            update(0, sz(suff) - 1, 0, i, 0),
            oliver[nico[suff[i]]] = i;
        if(alex.count(suff[i]))
            pozo[alex[suff[i]]] = i;
    }
    vi elcipi = lcp(super, suff);
    fore(i, 0, sz(suff))
        cout<<i<<' '<<elcipi[i]<<' ';
    cout<<'\n';
    fore(i, 0, n)
        cout<<oliver[i]<<' ';
    cout<<'\n';
    fore(i, 0, m) cout<<pozo[i]<<' ';
    cout<<'\n';
    sas = sz(elcipi);
    fore(i, 0, sas)
        ar[i] = elcipi[i];
    inispar();
    fore(i, 0, m){
        cueri que = queso[i];
        if(que.type == 1){
            update(0, sas - 1, 0, oliver[que.a - 1], que.b);
        }
        else{
            int reza = -1;
            fore(origen, pozo[i], pozo[i] + sz(que.s)){
                // int origen = pozo[i];
                int b = origen, e = sas - 1, mid, res = sas - 1;
                while(b <= e){
                    mid = (b + e) / 2;
                    if(querys(origen, mid) == 0)
                        res = mid, e = mid - 1;
                    else
                        b = mid + 1;
                }
                int derecha = res;
                b = 0, e = origen;
                while(b <= e) {
                    mid = (b + e) / 2;
                    if(querys(mid, origen) == 0)
                        res = mid, b = mid + 1;
                    else
                        e = mid - 1;
                }
                int izquierda = res + 1;

                if(izquierda <= derecha)
                    reza = max(reza, query(0, sas - 1, 0, izquierda, derecha));
                // cout<<izquierda<<' '<<derecha<<'\n';
            }
            cout<<reza<<'\n';
        }
    }
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
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
