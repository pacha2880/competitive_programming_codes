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
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    vector<vector<vi>> ar(4);
    string s;
    cin>>s;
    fore(i, 0, sz(s)){
        char ch = s[i];
        int nu = ch - '0';
        vi asd = {nu, i, 0ll};
        ar[ch - '0'].pb(asd);
    }
    
    cin>>s;
    int po1 = 0, po2 = 0, po3 = 0;
    fore(i, 0, sz(s)){
        char ch = s[i];
        if(ch == '1'){
            vi asd = {1, i, 0ll};
            ar[1].pb(asd);
        }
        else{
            ar[3][po3++][2] = i;
        }
    }
    cin>>s;
    fore(i, 0, sz(s)){
        char ch = s[i];
        if(ch == '2'){
            ar[2][po2++][2] = i;
        }
        else
            ar[1][po1++][2] = i;
    }
    vector<vi> aro;
    fore(i, 1, 4)
        for(auto cat : ar[i])
            aro.pb(cat);
            
    sort(all(aro), [](vi &a, vi &b){
        if(a[0] == b[0])
            return a[1] < b[1];
        if(a[0] == 1 && b[0] == 2 || a[0] == 2 && b[0] == 1)
        {
            return a[2] < b[2];
        }
        if(a[0] == 1 && b[0] == 3) 
        {
            return a[1] < b[2];
        }
        if(a[0] == 3 && b[0] == 1)
            return a[2] < b[1];
        if(a[0] == 2 && b[0] == 3 || a[0] == 3 && b[0] == 2)
            return a[1] < b[1];  
    });
    // for(auto cat : aro){
    //     fore(i, 0, 3)
    //         cout<<cat[i]<<' '; cout<<'\n';}
    for(auto cat : aro)
        cout<<cat[0];
    cout<<'\n';

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
