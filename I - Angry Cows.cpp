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

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout); 
	int n;
    cin>>n;
    vi ar(n);
    fore(i, 0, n) cin>>ar[i];
    sort(all(ar));
    vi lef(n), ris(n);
    fore(i, 1, n)
    {
        if(ar[i] == ar[i - 1])
            lef[i] = lef[i - 1];
        else
        {
            int lo = 1, hi = MOD, mid;
            while(lo <= hi)
            {
                mid = (lo + hi) / 2;
                int in = lower_bound(all(ar), ar[i] - mid) - ar.begin();
                if(in - i && lef[in] + 1 <= mid)
                    lef[i] = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
    }
    for(int i = n - 2; i > -1; i--)
    {
        if(ar[i] == ar[i + 1])
            ris[i] = ris[i + 1];
        else
        {
            int lo = 1, hi = MOD, mid;
            while(lo <= hi)
            {
                mid = (lo + hi) / 2;
                int in = --upper_bound(all(ar), ar[i] + mid) - ar.begin();
                if(in > i && ris[in] + 1 <= mid)
                    ris[i] = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
    }
    double lo = 0, hi = 1e9, mid;
    // fore(i, 0, n) cout<<lef[i]<<' '<<ris[i]<<'\n';
    fore(i, 0, 40)
    {
        mid = (lo + hi) / 2;
        bool bo = false;
        fore(i, 0, n - 1)
        {
            int l = i, r = n - 1, midi, res = i;
            while(l <= r)
            {
                // a <= b con doubles
                // a < b + EPS
                // a < b
                // a < b - EPS
                // a == b
                // fabs(a - b) < EPS
                midi = (l + r) / 2;
                if((ar[midi] - ar[i]) / 2.0 < mid + EPS)
                    res = midi, l = midi + 1;
                else
                    r = midi - 1;
            }
            if(res > i)
                bo |= lef[i] < max(0.0, mid -1) + EPS && ris[res] < max(0.0, mid - 1) + EPS;
        }
        if(bo)
            hi = mid;
        else
            lo = mid;
    }
    cout<<fixed<<setprecision(1)<<mid<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
