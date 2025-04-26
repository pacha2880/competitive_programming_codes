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
#define forev(i, e, b) for(int i = e; i > b; i--)
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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int p = 31, p1 = 37;
struct node
{
  int b, e, re1, re2, pal, ha, harev;
//   ii ha, harev;
};
string s;
int po[tam];
node join(node a, node b)
{
    int n = a.e - a.b + 1, m = b.e - b.b + 1;
    if(a.re1 && b.re1 && s[a.b] == s[b.b])
    {

    }
    else 
        a.re1 = 0;
    if(a.re2 && b.re2)
    {
        if(n == 1 && m == 1)
        {
            
        }
        else if(n == 1)
        {
            if(s[a.b] != s[b.b + 1])
                a.re2 = 0;
        }
        else if(m == 1)
        {
            if(s[a.e - 1] != s[b.b])
                a.re2 = 0;
        }
        else if(s[a.e] == s[b.b + 1] && s[a.e - 1] == s[b.b])
        {

        }
        else
            a.re2 = 0;
    }
    else 
        a.re2 = 0;
    a.ha = (a.ha * po[m] + b.ha) % MOD;
    a.harev = (a.harev + b.harev * po[n]) % MOD;
    if(a.ha == a.harev)
        a.pal = 1;
    else
        a.pal = 0;
    a.e = b.e;
    return a;
}
node t[4 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = {b, b, 1, 1, 1, s[b], s[b]};
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
node query(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
		return t[node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	if(mid >= j)
		return query(b, mid, l, i, j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    po[0] = 1;
    fore(i, 1, tam) po[i] = po[i - 1] * p % MOD;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cin>>s;
        init(0, n - 1, 0);
        while(m--)
        {
            int a, b;
            cin>>a>>b;
            auto re = query(0, n - 1, 0, a - 1, b - 1);
            int can = b - a + 1;
            // cout<<re.re1<<' '<<re.re2<<' '<<re.pal<<'\n';
            if(re.re1)
                cout<<0<<'\n';
            else if(re.re2)
            {
                can /= 2;
                cout<<can * (can + 1)<<'\n';
            }
            else if(re.pal)
                cout<<can * (can - 1) / 2 - 1<<'\n';
            else
                cout<<can * (can + 1) / 2 - 1<<'\n';
        }
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
