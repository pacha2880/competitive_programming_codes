#include <bits/stdc++.h>
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
struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
};
struct line{
    double a, b, c;
    line() {}
    line(point p, point q){
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        double z = a < EPS ? -sqrt(a * a + b * b) : sqrt(a * a + b * b);
        a /= z;
        b /= z;
        c /= z;
    }
};
double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}
point intersect(line a, line b)
{
    point p;
    double d = -det(a.a, a.b, b.a, b.b);
    return point(det(a.c, a.b, b.c, b.b) / d, det(a.a, a.c, b.a, b.c) / d);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
    cin>>t;
    auto eq = [&](double a, double b) {
        return fabs(a - b) < EPS;
    };
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(t--)
    {
        point a, b;
        cin>>a.x>>a.y>>b.x>>b.y;
        line l1(a, b);
        point c, d;
        cin>>c.x>>c.y>>d.x>>d.y;
        line l2(c, d);
        if(eq(l1.a, l2.a) && eq(l1.b, l2.b))
        {
            if(eq(l1.c, l2.c))
                cout<<"LINE\n";
            else
                cout<<"NONE\n";
        }
        else
        {
            point p = intersect(l1, l2);
            cout<<"POINT "<<fixed<<setprecision(2)<<p.x<<" "<<p.y<<"\n";
        }
    }
    cout<<"END OF OUTPUT\n";
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
