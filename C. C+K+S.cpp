#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int 			long long
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
// template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
int modo[2][tam];
int vis[2][tam];
vi g[2][tam];
int modi;
void dfs(int node, int valu, int gra)
{
    modo[gra][node] = valu;
    vis[gra][node] = 1;
    for(int x : g[gra][node])
        if(!vis[gra][x])
            dfs(x, (valu + 1) % modi, gra);
}
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
        cin>>n>>modi;
        vi vals1(n), vals2(n);
        int sali1 = 0, sali2 = 0;
        int x, y;
        fore(i, 0, n) cin>>vals1[i], sali1+= vals1[i];
        int m;
        cin>>m;
        fore(i, 0, m)
        {
            int a, b;
            cin>>a>>b;
            g[0][a - 1].pb(b - 1);
        } 
        fore(i, 0, n)
            cin>>vals2[i], sali2+=vals2[i];
        cin>>m;
        fore(i, 0, m)
        {
            int a, b;
            cin>>a>>b;
            g[1][a - 1].pb(b - 1);
        }
        // cout<<sali1<<' '<<sali2<<'\n';
        if(sali1 + sali2 != n)
        {
            cout<<"NO\n";
            continue;
        }
        if(!sali1 || !sali2)
        {
            cout<<"YES\n";
            continue;
        }
        vi blancos1, blancos2, negros1, negros2;
        fore(i, 0, n) fore(j, 0, 2) vis[j][i] = 0;
        fore(i, 0, n)
        {
            if(vals1[i])
                x = i;
            if(!vals2[i])
                y = i;
        }
        dfs(x, 0, 0);
        dfs(y, 0, 1);
        fore(i, 0, n)
        {
            if(vals1[i])
                blancos1.pb(modo[0][i]);
            else
                negros1.pb(modo[0][i]);
            if(vals2[i])
                negros2.pb(modo[1][i]);
            else
                blancos2.pb(modo[1][i]);
        }
        int k = sz(blancos1);
        vii ala1(k), ala2(k);
        fore(i, 0, k)
        {
            ala1[i] = {(blancos1[(i + 1) % k] - blancos1[i] + modi) % modi, blancos1[i]};
            ala2[i] ={(blancos2[(i + 1) % k] - blancos2[i] + modi) % modi, blancos2[i]};
        }
        sort(all(ala1));
        sort(all(ala2));
        if(ala1 != ala2)
        {
            cout<<"NO\n";
            continue;
        }
        k = sz(negros1);
        fore(i, 0, k)
        {
            negros1[i] = (negros1[i] - ala1[0].s + modi) % modi;
            negros2[i] = (negros2[i] - ala2[0].s + modi) % modi;
        }
        sort(all(negros1));
        sort(all(negros2));
        if(negros1 == negros2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
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
// Ya que no se tiene información perfecta, tomar riesgos.
// Si se decide trabajar en un problema grande, empezar a hacerlo lo antes posible.
// La suerte siempre tiene su rol en las competencias y hay que vivir con eso.
