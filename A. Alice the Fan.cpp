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
const int MOD1 = 998234353;
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
        int a, b;
        cin>>a>>b;
        int ax = a, bx = b;
        bool bo = false;
        if(a == 75 && b <= 23 * 3)
        {
            cout<<"3:0\n";
            cout<<"25:"<<min(23ll, b)<<' ';
            b = max(0ll, b - 23);
            cout<<"25:"<<min(23ll, b)<<' ';
            b = max(0ll, b - 23);
            cout<<"25:"<<min(23ll, b)<<'\n';
            continue;
        }
        fore(i, 25, 200)
        {
            a -= i, b -= i - 2;
            if(a == 50 && b >= 0 && b <= 23 * 2)
            {
                cout<<"3:0\n";
                cout<<i<<":"<<i - 2<<' ';
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"25:"<<min(23ll, b)<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        if(a >= 75 && a - 75 <= 23 && b >= 25 && b - 25 <= 23 * 3)
        {
            a -= 75, b -= 25;
            cout<<"3:1\n";
            cout<<a<<":25"<<' ';
            cout<<"25:"<<min(23ll, b)<<' ';
            b = max(0ll, b - 23);
            cout<<"25:"<<min(23ll, b)<<' ';
            b = max(0ll, b - 23);
            cout<<"25:"<<min(23ll, b)<<'\n';
            continue;
        }
        fore(i, 25, 200)
        {
            a -= i, b -= i - 2;
            if(a >= 50 && a - 50 <= 23 && b >= 25 && b - 25 <= 23 * 2)
            {
                a -= 50, b -= 25;
                cout<<"3:1\n";
                cout<<a<<":25"<<' ';
                cout<<i<<":"<<i - 2<<' ';
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"25:"<<min(23ll, b)<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        
        fore(i, 25, 200)
        {
            a -= i - 2, b -= i;
            if(a == 75 && b >= 0 && b <= 23 * 3)
            {
                cout<<"3:1\n";
                cout<<i - 2<<":"<<i<<' ';
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"25:"<<min(23ll, b)<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        if(a >= 65 && a - 65 <= 2 * 23 && b >= 50 && b - 50 <= 2 * 23 + 13)
        {
            a -= 65, b -= 50;
            cout<<"3:2\n";
            cout<<min(23ll, a)<<":25"<<' ';
            a = max(0ll, a - 23);
            cout<<min(23ll, a)<<":25"<<' ';
            cout<<"25:"<<min(23ll, b)<<' ';
            b = max(0ll, b - 23);
            cout<<"25:"<<min(23ll, b)<<' ';
            b = max(0ll, b - 23);
            cout<<"15:"<<min(13ll, b)<<'\n';
            continue;
        }
        fore(i, 25, 200)
        {
            a -= i, b -= i - 2;
            if(a >= 40 && a - 40 <= 2 * 23 && b >= 50 && b - 50 <= 23 + 13)
            {
                a -= 40, b -= 50;
                cout<<"3:2\n";
                cout<<min(23ll, a)<<":25"<<' ';
                a = max(0ll, a - 23);
                cout<<min(23ll, a)<<":25"<<' ';
                cout<<i<<":"<<i - 2<<' ';
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"15:"<<min(13ll, b)<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        fore(i, 25, 200)
        {
            a -= i - 2, b -= i;
            if(a >= 65 && a - 65 <= 23 && b >= 25 && b - 25 <= 2 * 23 + 13)
            {
                a -= 65, b -= 25;
                cout<<"3:2\n";
                cout<<min(23ll, a)<<":25"<<' ';
                cout<<i - 2<<":"<<i<<' ';
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"25:"<<min(23ll, b)<<' ';
                b = max(0ll, b - 23);
                cout<<"15:"<<min(13ll, b)<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        swap(a, b), swap(ax, bx);
        if(a >= 65 && a - 65 <= 2 * 23 && b >= 50 && b - 50 <= 2 * 23 + 13)
        {
            a -= 65, b -= 50;
            cout<<"2:3\n";
            cout<<"25:"<<min(23ll, a)<<' ';
            a = max(0ll, a - 23);
            cout<<"25:"<<min(23ll, a)<<' ';
            cout<<min(23ll, b)<<":25"<<' ';
            b = max(0ll, b - 23);
            cout<<min(23ll, b)<<":25"<<' ';
            b = max(0ll, b - 23);
            cout<<min(13ll, b)<<":15"<<'\n';
            continue;
        }
        fore(i, 25, 200)
        {
            a -= i, b -= i - 2;
            if(a >= 40 && a - 40 <= 2 * 23 && b >= 50 && b - 50 <= 23 + 13)
            {
                a -= 40, b -= 50;
                cout<<"2:3\n";
                cout<<"25:"<<min(23ll, a)<<' ';
                a = max(0ll, a - 23);
                cout<<"25:"<<min(23ll, a)<<' ';
                cout<<i - 2<<":"<<i<<' ';
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(13ll, b)<<":15"<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        fore(i, 25, 200)
        {
            a -= i - 2, b -= i;
            if(a >= 65 && a - 65 <= 23 && b >= 25 && b - 25 <= 2 * 23 + 13)
            {
                a -= 65, b -= 25;
                cout<<"2:3\n";
                cout<<"25:"<<min(23ll, a)<<' ';
                cout<<i<<":"<<i - 2<<' ';
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(13ll, b)<<":15"<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        if(a >= 75 && a - 75 <= 23 && b >= 25 && b - 25 <= 23 * 3)
        {
            a -= 75, b -= 25;
            cout<<"1:3\n";
            cout<<"25:"<<a<<' ';
            cout<<min(23ll, b)<<":25"<<' ';
            b = max(0ll, b - 23);
            cout<<min(23ll, b)<<":25"<<' ';
            b = max(0ll, b - 23);
            cout<<min(23ll, b)<<":25"<<'\n';
            continue;
        }
        fore(i, 25, 200)
        {
            a -= i, b -= i - 2;
            if(a >= 50 && a - 50 <= 23 && b >= 25 && b - 25 <= 23 * 2)
            {
                a -= 50, b -= 25;
                cout<<"1:3\n";
                cout<<"25:"<<a<<' ';
                cout<<i - 2<<":"<<i<<' ';
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(23ll, b)<<":25"<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        fore(i, 25, 200)
        {
            a -= i - 2, b -= i;
            if(a == 75 && b >= 0 && b <= 23 * 3)
            {
                cout<<"1:3\n";
                cout<<i<<":"<<i - 2<<' ';
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(23ll, b)<<":25"<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        if(a == 75 && b <= 23 * 3)
        {
            cout<<"0:3\n";
            cout<<min(23ll, b)<<":25"<<' ';
            b = max(0ll, b - 23);
            cout<<min(23ll, b)<<":25"<<' ';
            b = max(0ll, b - 23);
            cout<<min(23ll, b)<<":25"<<'\n';
            continue;
        }
        fore(i, 25, 200)
        {
            a -= i, b -= i - 2;
            if(a == 50 && b >= 0 && b <= 23 * 2)
            {
                cout<<"0:3\n";
                cout<<i - 2<<":"<<i<<' ';
                cout<<min(23ll, b)<<":25"<<' ';
                b = max(0ll, b - 23);
                cout<<min(23ll, b)<<":25"<<'\n';
                bo = true;
                break;
            }
            a = ax, b = bx;
        }
        if(bo) continue;
        cout<<"Impossible\n";
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
