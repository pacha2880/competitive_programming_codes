#include <bits/stdc++.h>
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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

// extended euclid
int xz, yz, d;
void extendedEuclid(int a, int b)//ecuacion diofantica ax + by = d
{
	if(b==0) {xz=1; yz=0; d=a; return;}
	extendedEuclid(b,a%b);
	int x1=yz;
	yz = xz-(a/b)*yz;
	xz=x1;
}/*
a = 25, b = 18
extendedEuclid(25, 18) produces x = −5, y = 7, d = 1; or 25 × (−5) + 18 × 7 = 1.
Multiply the left and right hand side of the equation above by 839/gcd(25, 18) = 839:
25 × (−4195) + 18 × 5873 = 839.
Thus x = −4195 + (18/1)n and y = 5873 − (25/1)n.
Since we need to have non-negative x and y (non-negative number of apples and oranges),
we have two more additional constraints:
−4195 + 18n ≥ 0 and 5873 − 25n ≥ 0, or
4195/18 ≤ n ≤ 5873/25, or
233.05 ≤ n ≤ 234.92.
*/

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> tab(n);
        fore(i, 0, n) cin>>tab[i];
        vector<vi> lin(n, vi(n, -1)), hasp(n, vi(n));
        int per = 0, x = 0, y = 0;
        while(lin[x][y] == -1)
        {
            lin[x][y] = per;
            if(tab[x][y] == 'v') x++;
            else if(tab[x][y] == '>') y++;
            else if(tab[x][y] == '^') x--;
            else y--;
            per++;
        }
        // cout<<"$$$$$$$$$"<<n<<'\n';
        // if(n == 3) return 0;
        int len = per - lin[x][y];
        int ax = x, ay = y;
        do
        {
            // cout<<x<<' '<<y<<'\n';
            hasp[x][y] = 1;
            if(tab[x][y] == 'v') x++;
            else if(tab[x][y] == '>') y++;
            else if(tab[x][y] == '^') x--;
            else y--;
        } while (x != ax || y != ay);
        // fore(i, 0, n)
        // {
        //     fore(j, 0, n)
        //         cout<<lin[i][j]<<','<<hasp[i][j]<<' ';
        //     cout<<'\n';
        // }
        int m;
        cin>>m;
        ll res = 1ll * MOD * MOD;
        fore(i, 0, m)
        {
            int a, b;
            cin>>a>>b;
            // cout<<"########### "<<i<<'\n';
            // cout<<a<<' '<<b<<' '<<i<<' '<<lin[a][b]<<'\n';
            if(lin[a][n] != -1)
            {
                if(i == lin[a][b])
                {
                    res = min(res, i);
                }
                else if(!hasp[a][b] && lin[a][b] != -1)
                {
                    if(i < lin[a][b] && (lin[a][b] - i) % m == 0)
                        res = min(res, lin[a][b]);
                }   
                else
                {
                    // cout<<a<<' '<<b<<' '<<i<<' '<<lin[a][b]<<'\n';   
                    int ax = a, bx = b;                 
                    int a = len, b = -m, c = i - lin[ax][bx];
                    // cout<<a<<' '<<b<<' '<<c<<" -> \n";
                    extendedEuclid(a, b);
                    // cout<<d<<' '<<xz<<' '<<yz<<'\n';
                    if(c % d == 0)
                    {
                        x = xz * (c / d);
                        y = yz * (c / d);
                        // cout<<x<<' '<<y<<" && \n";
                        int k = 0;
                        // cout<<x<<' '<<y<<' '<<a<<' '<<b<<'\n';
                        if(b > 0)
                        {
                            if(x < 0)
                            k = ceil(-x * 1.0 / b);
                            else
                            k = ceil(x * 1.0 / b);
                        }
                        else
                        {
                            if(x > 0)
                            k = -ceil(x * 1.0 / b);
                            else
                            k = ceil(-x * 1.0 / b);
                        }
                        // cout<<k<<'\n';
                        // cout<<1ll * (x + b * k) * a + lin[ax][bx]<<'\n';
                            res = min(res, 1ll * (x + b * k) * a + lin[ax][bx]);
                        // cout<<res<<'\n';
                        // cout<<k<<'\n';
                    }
                }
            }
        }
        if(res == 1 * MOD * MOD)
            cout<<"never\n";
        else
            cout<<res<<'\n';
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
