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
	int n;
    cin>>n;
    vi text(n);
    int largo = 0;
    int su = -1;
    fore(i, 0, n)
    {
        string s;
        cin>>s;
        text[i] = sz(s);
        largo = max(largo, sz(s));
        su += text[i] + 1;
    }
    ii res(0, -largo);
    while(true)
    {
        vector<vi> paga;
        int sisi = largo;
        int nuevo = MOD;
        // cout<<largo<<'\n';
        for(int x : text)
        {
            if(x + sisi > largo)
            {
                if(!paga.empty())
                    nuevo = min(nuevo, sisi + x);
                paga.pb(vi());
                sisi = 0;
            }
            paga[sz(paga) - 1].pb(x);
            sisi += x + 1;
        }
        // cout<<"#######"<<largo<<"******\n";
        // fore(i, 0, sz(paga))
        // {
        //     for(int x : paga[i])
        //         cout<<x<<' ';
        //     cout<<'\n';
        // }
        // cout<<"#######******\n";
        vii pasto, actual;
        int maxus = 0;
        fore(i, 0, sz(paga))
        {
            int riva = 0;
            actual.clear();
            // cout<<i<<'\n';
            int pos = 0;
            fore(j, 0, sz(paga[i]) - 1)
            {
                riva += paga[i][j] + 1;
                int mega = 1;
                if(pos < sz(pasto))
                {
                    while(pos < sz(pasto) && pasto[pos].f < riva - 1)
                        pos++;
                    if(pos < sz(pasto) && pasto[pos].f <= riva + 1)
                        mega = max(mega, pasto[pos].s + 1);
                    if(pos < sz(pasto) - 1 && pasto[pos + 1].f == riva + 1)
                        mega = max(mega, pasto[pos + 1].s + 1);
                }
                actual.pb({riva, mega});
                res = max(res, {mega, -largo});
                maxus = max(maxus, mega);
                // cout<<riva<<' '<<actual[riva]<<'\n';
            }
            swap(pasto, actual);
        }
        largo = nuevo;
        if(sz(paga) == 1) break;
        // cout<<largo<<' '<<maxus<<'\n';
    }  
    cout<<-res.s<<' '<<res.f<<'\n';
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
// Take a sad song and make it better
