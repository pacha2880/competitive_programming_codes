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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ii mami[26][7000];
ii nivel[7000];
int us[3000][3000];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    vector<string> tab(n);
    fore(i, 0, n) cin>>tab[i];
    int pon = 1;
    nivel[0] = {0, 0};
    string res;
    res += tab[0][0];
    vi oliver(26); 
    int level = 1;
    fore(i, 0, 2 * n - 2){
        fore(i, 0, pon){
            int x = nivel[i].f, y = nivel[i].s;
            // cout<<x<<','<<y<<'\n';
            if(x < n - 1 && us[x + 1][y] != level){
                us[x + 1][y] = level;
                int cara = tab[x + 1][y] - 'A';
                // cout<<cara<<"#\n";
                mami[cara][oliver[cara]++] = {x + 1, y};
            }
            if(y < n - 1 && us[x][y + 1] != level){
                int cara = tab[x][y + 1] - 'A';
                us[x][y + 1] = level;
                // cout<<cara<<"@\n";
                mami[cara][oliver[cara]++] = {x, y + 1};
            }
        }
        level++;
        int ini = 0;
        // fore(i, 0, 26)
        //     cout<<oliver[i]<<' ';
        // cout<<'\n';
        while(!oliver[ini]) ini++;
        res += (char)(ini + 'A');
        fore(i, 0, oliver[ini])
            nivel[i] = mami[ini][i];
        pon = oliver[ini];
        fore(i, 0, 26) oliver[i] = 0;
    }
    cout<<res<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.