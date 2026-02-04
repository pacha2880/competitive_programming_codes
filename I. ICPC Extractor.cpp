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
	int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = sz(s);
        int lo = 1, hi = n / 4, mid, res = 0;
        vi is, ces, pes;
        fore(i, 0, n) if(s[i] == 'I') is.pb(i); else if(s[i] == 'C') ces.pb(i); else pes.pb(i);
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            vi pucs;
            int i = 0, c = 0, p = 0;
            bool can = true;
            vi usado(n);
            if(mid > sz(is) || mid > sz(pes) || mid * 2 > sz(ces)){
                hi = mid - 1; continue;
            }
            fore(i, 0, mid){
                while(c < sz(ces) && ces[c] < is[i])
                    c++;
                if(c == sz(ces)){
                    can = false; break;}   
                pucs.pb(ces[c]);
                usado[ces[c]] = 1;
                c++;
            }
            if(!can){
                hi = mid - 1; continue;
            }
            c = 0;
            fore(i, 0, mid){
                while(p < sz(pes) && pes[p] < pucs[i]) p++;
                if(p == sz(pes)){
                    can = false;
                    break;
                }
                while(c < sz(ces) && (ces[c] < pes[p] || usado[ces[c]])) c++;
                if(c == sz(ces)) {
                    can = false;
                    break;
                }
                c++;
                p++;
            }
            if(can) lo = mid + 1, res = mid;
            else
                hi = mid - 1;
        }
        cout<<res<<'\n';
        mid = res;
        vi pucs;
        mat reri(res, vi());
        vi usado(n);
        int i = 0, c = 0, p = 0;
        fore(i, 0, mid){
            while(ces[c] < is[i])
                c++;
            reri[i].pb(is[i] + 1);
            reri[i].pb(ces[c] + 1);
            pucs.pb(ces[c]);
            usado[ces[c]] = 1;
            c++;
        }
        c = 0;
        fore(i, 0, mid){
            while(pes[p] < pucs[i]) p++;
            while(ces[c] < pes[p] || usado[ces[c]]) c++;
            reri[i].pb(pes[p] + 1);
            reri[i].pb(ces[c] + 1);
            c++;
            p++;
        }
        fore(i, 0, res)
        {
            fore(j, 0, 4)
                cout<<reri[i][j]<<' ';
            cout<<'\n';
        }
    }
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
