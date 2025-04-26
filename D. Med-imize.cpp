#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
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
template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        set<vi> oliver, medians;
        vi ar(n);
        fore(i, 0, n)
        {
            cin>>ar[i];
        }
        if(k >= n)
        {
            sort(all(ar));
            cout<<ar[(n - 1) / 2]<<'\n';
            continue;
        }
        ordered_set<ii> st;
        map<int, int> frec;
        int su = 0;
        for(int i = n - 1; i > -1; i--)
        {
            st.insert({ar[i], frec[ar[i]]++});
            su += ar[i];
            if(sz(st) > k)
                st.erase({ar[i + k], --frec[ar[i + k]]}), su -= ar[i + k];
            if(sz(st) < k)
                oliver.insert({i, MOD, MOD});
            else
            {
                int med = st.find_by_order((k - 1) / 2) -> f;
                oliver.insert({i, su, med}), medians.insert({med, su, i});
            }
        }
        while(true)
        {
            auto cat = *medians.begin();
            // cout<<cat.s<<' '<<cat.f<<'\n';
            auto it = oliver.find({cat[2], cat[1], cat[0]});
            fore(i, 0, k)
            {
                vi ti = *it;
                medians.erase({ti[2], ti[1], ti[0]});
                it = oliver.erase(it);
            }
            if(sz(oliver) <= k)
                break;
            ordered_set<ii> st;
            map<int, int> frec;
            auto ut = it;
            queue<int> elefantes;
            int su = 0;
            fore(i, 0, k - 1)
            {
                if(ut == oliver.end())
                    break;
                int dir = (*ut)[0];
                st.insert({ar[dir], frec[ar[dir]]++});
                su += ar[dir];
                elefantes.push(dir);
                ut++;
            }
            ut = it;
            fore(i, 0, k - 1)
            {
                if(ut == oliver.begin())
                    break;
                ut--;
                vi ti = *ut;
                int dir = ti[0];
                st.insert({ar[dir], frec[ar[dir]]++});
                su += ar[dir];
                elefantes.push(dir);
                if(sz(st) > k)
                {
                    int sacar = elefantes.front();
                    elefantes.pop();
                    su -= ar[sacar];
                    st.erase({ar[sacar], --frec[ar[sacar]]});
                }
                medians.erase({ti[2], ti[1], dir});
                if(sz(st) == k)
                {
                    int med = st.find_by_order((k - 1) / 2) -> f;
                    oliver.erase(ut);
                    oliver.insert({dir, su, med}), medians.insert({med, su, dir});
                }
            }
            // for(vi cat : oliver)
            //     cout<<ar[cat[0]]<<' ';
            // cout<<'\n';
        }
        vi cucu;
        for(vi cat : oliver)
            cucu.pb(ar[cat[0]]);
        sort(all(cucu));
        cout<<cucu[(sz(cucu) - 1) / 2]<<'\n';
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
