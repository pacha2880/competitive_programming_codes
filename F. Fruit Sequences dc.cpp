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
string s;
int res = 0;
void f(int b, int e)
{
    if(b == e){
        res += s[b] == '1';
        // cout<<'#'<<b<<' '<<e<<' '<<res<<'\n';
        return;
    }
    int mid = (b + e) / 2;
    vi su1(mid - b + 1), pre1(e - mid);
    vi su2(mid - b + 1), pre2(e - mid);
    int can = 0;
    su1[0] = su2[0] = s[mid] == '1';
    can = s[mid] == '1';
    for(int i = mid - 1; i >= b; i--)
    {
        if(s[i] == '1')
            can++;
        else
            can = 0;
        su2[mid - i] = max(su2[mid - i - 1], can);
        su1[mid - i] = su1[mid - i - 1];
        if(can + i > mid)
            su1[mid - i] = can;
    }
    pre1[0] = pre2[0] = s[mid + 1] == '1';
    can = s[mid + 1] == '1';
    fore(i, mid + 2, e + 1)
    {
        if(s[i] == '1')
            can++;
        else
            can = 0;
        pre2[i - mid - 1] = max(pre2[i - mid - 2], can);
        pre1[i - mid - 1] = pre1[i - mid - 2];
        if(i - can == mid)
            pre1[i - mid - 1] = can;
    }
    vi sas1 = pre1, sas2 = pre2;
    fore(i, 1, sz(sas1))
        sas1[i] += sas1[i - 1], sas2[i] += sas2[i - 1];
    
    int le = 0, ri = 0;
    int n = sz(pre1);
    // cout<<b<<' '<<mid<<' '<<e<<'\n';
    // fore(i, 0, n)
    //     cout<<pre1[i]<<' '<<pre2[i]<<'\n';
    fore(i, 0, sz(su1))
    {
        // cout<<su1[i]<<' '<<su2[i]<<' ';
        while(le < n && max(su1[i] + pre1[le], pre2[le]) <= su2[i])
            le++;
        ri = max(ri, le);
        while(ri < n && max(su1[i] + pre1[ri], su2[i]) > pre2[ri])
            ri++;
            // cout<<le<<' '<<ri<<'\n';
        res += le * su2[i];
        
        // cout<<i<<' '<<res<<'\n';
        res += (ri - le) * su1[i] + (ri > 0 ? sas1[ri - 1] : 0) - (le > 0 ? sas1[le - 1] : 0);
        
        // cout<<i<<' '<<res<<'\n';
        res += sas2.back() - (ri > 0 ? sas2[ri - 1] : 0);
        // cout<<i<<' '<<res<<'\n';
    }
    f(b, mid); f(mid + 1, e);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n>>s;
    f(0, n - 1);
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
