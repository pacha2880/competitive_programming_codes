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
        
        set<ii> st1, st2;
        int ce = 0;
        fore(i, 0, n)
        {
            int x;
            cin>>x;
            st1.insert({x, i});
            st2.insert({i, x});
            if(x == 0)
                ce++;
        }
        if(ce != 1)
        {
            cout<<"NO\n";
            continue;
        }
        bool bo = 1;
        while(sz(st1) > 1)
        {
            // cout<<"#\n";
            // for(ii cat : st1)
            //     cout<<cat.f<<','<<cat.s<<' ';
            // cout<<'\n';
            // for(ii cat : st1)
            //     cout<<cat.f<<','<<cat.s<<' ';
            // cout<<'\n';
            auto cat = --st1.end();
            int nu = cat->f, po = cat->s;
            auto cot = st2.find({po, nu});
            cot++;
            bool ba = 1;
            if(cot != st2.end())
            {
                if(cot->s == nu - 1)
                {
                    cot--;
                    st2.erase(cot);
                    st1.erase(cat);
                    ba = 0;
                }
                else if(cot->s == nu)
                {
                    st1.erase({cot->s, cot->f});
                    st2.erase(cot);
                    continue;
                }
            }
            cot--;
            if(ba)
            {
                if(cot == st2.begin())
                {
                    bo = 0;
                    break;
                }
                cot--;
                if(cot->s == nu - 1)
                {
                    cot++;
                    st2.erase(cot);
                    st1.erase(cat);
                }
                else if(cot->s == nu)
                {
                    st1.erase({cot->s, cot->f});
                    st2.erase(cot);
                }
                else
                {
                    bo = 0;
                    break;
                }
            }
            
        }
        if(bo)
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
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
