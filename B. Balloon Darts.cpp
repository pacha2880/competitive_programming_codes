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
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll sq() {return x * x + y * y;}
	double abs() {return sqrt(sq());}
	ll operator ^(point p) {return x * p.y - y * p.x;}
  	ll operator *(point p) {return x * p.x + y * p.y;}
  	point operator *(ll a) {return point(x * a, y * a);}
	bool operator <(const point& p) const {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) >= 0;}
	ostream& operator<<(ostream& os) {
		return os << "("<< x << "," << y << ")";
	}

};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    vector<point> ar(n);
    fore(i, 0, n) cin>>ar[i].x>>ar[i].y;
    fore(asdf, 0, 220){
        int a = rand() % n;
        int b = rand() % n;
        while(a == b) b = rand() % n;
        // a es el origen
        point origen = ar[a];
        fore(i, 0, n) ar[i] = ar[i] - origen;
        int con = 0;
        fore(i, 0, n) if((ar[b] ^ ar[i]) == 0) con++;
        if(con < (n + 2) / 3) continue;
        vector<point> los_demas;
        // cout<<"--------------------\n";
        fore(i, 0, n) if((ar[b] ^ ar[i]) != 0) los_demas.pb(ar[i]);
        // else cout<<ar[i].x<<' '<<ar[i].y<<'\n';
        // cout<<"+++++++++\n";
        if(los_demas.size() < 4){
            // cout<<"1\n";
            cout<<"possible\n";
            return 0;
        }
        int m = sz(los_demas);
        fore(asdf, 0, 50){
            int a = rand() % m;
            int b = rand() % m;
            while(a == b) b = rand() % m;
            // a es el origen
            point origen = los_demas[a];
            fore(i, 0, m) los_demas[i] = los_demas[i] - origen;
            int con = 0;
            fore(i, 0, m) if((los_demas[b] ^ los_demas[i]) == 0) con++;
            if(con < (m + 1) / 2) continue;
            // cout<<con<<'\n';
            vector<point> los_demas_demas;
            // cout<<"#######\n";
            fore(i, 0, m) if((los_demas[b] ^ los_demas[i]) != 0) los_demas_demas.pb(los_demas[i]);
                            // else cout<<los_demas[i].x<<' '<<los_demas[i].y<<'\n';
                            
            // cout<<"@@@@@@@@@\n";
            if(sz(los_demas_demas) < 3){
            // cout<<"2\n";
                cout<<"possible\n";
                return 0;
            }
            else
            {
                int k = sz(los_demas_demas);
                // cout<<k<<'\n';
                point origen = los_demas_demas[0];
                fore(i, 0, k) los_demas_demas[i] = los_demas_demas[i] - origen;
                int con = 0;
                fore(i, 0, k) if((los_demas_demas[1] ^ los_demas_demas[i]) == 0) con++;
                // cout<<"asdf"<<con<<'\n';
                if(con == k)
                {
                    // cout<<"3\n";
                    cout<<"possible\n";
                    return 0;
                }
            }
            

        }

    }
    cout<<"impossible\n";
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
