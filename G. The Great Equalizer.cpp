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
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int, int> ma;
        multiset<int> deltas;
        auto add = [&](int x)
        {
            if(!ma.count(x))
            {
                auto it = ma.lower_bound(x);
                if(it != ma.end())
                    deltas.insert(it->f - x);
                auto at = it;
                if(at != ma.begin())
                {
                    at--;
                    deltas.insert(x - at->f);
                }
                if(it != ma.begin() && it != ma.end())
                    deltas.erase(deltas.find(it->f - at->f));
            }
            ma[x]++;
        };
        auto remove = [&](int x)
        {
            if(ma[x] > 1)
                ma[x]--;
            else
            {
                auto it = ma.find(x);
                auto le = it, ri = it;
                ri++;
                if(ri != ma.end())
                    deltas.erase(deltas.find(ri->f - x));
                if(it != ma.begin())
                {
                    le--;
                    deltas.erase(deltas.find(x - le->f));
                }
                if(it != ma.begin() && ri != ma.end())
                    deltas.insert(ri->f - le->f);
                ma.erase(x);
            }
        };
        vi ar(n);
        deltas.insert(0);
        fore(i, 0, n)
        {
            cin>>ar[i];
            add(ar[i]);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int a, b;
            cin>>a>>b;
            a--;
            remove(ar[a]);
            add(b);
            ar[a] = b;
            cout<<*--deltas.end() + (--ma.end())->f<<' ';
        }
        cout<<'\n';
    }
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
