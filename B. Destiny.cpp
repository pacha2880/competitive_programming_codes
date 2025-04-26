    // Codeforces Round 429 (Div. 1)
    // D. Destiny
    // https://codeforces.com/problemset/problem/840/D
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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // rng
    const int tam = 200010;
    const int MOD = 1000000007;
    const int MOD1 = 998244353;
    const double DINF=1e100;
    const double EPS = 1e-9;
    const double PI = acos(-1); 
    const int sq = 700;
    signed main()
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        // freopen("asd.txt", "r", stdin);
        // freopen("qwe.txt", "w", stdout); 
        int n, q;
        cin>>n>>q;
        vi ar(n), frec(n), pofrec(n), freca(n);
        int canfre = 0;
        auto add = [&](int x){
            frec[x]++;
            if(frec[x] == 1)
            {
                pofrec[x] = canfre;
                freca[canfre] = x;
                canfre++;
            }
        };
        auto sub = [&](int x){
            frec[x]--;
            if(frec[x] == 0)
            {
                canfre--;
                if(canfre)
                {
                    int a = freca[canfre];
                    swap(freca[pofrec[x]], freca[canfre]);
                    pofrec[a] = pofrec[x];
                }
            }
        };
        fore(i, 0, n)
        {
            cin>>ar[i];
            ar[i]--;
        }
        vector<pair<ii, int>> que(q), quo;
        fore(i, 0, q)
        {
            int a, b, c;
            cin>>a>>b>>c;
            a--, b--;
            que[i] = {{a, b}, c};
            quo.pb({{a / sq, b}, i});
        }

        sort(all(quo));
        int le = 0, ri = -1;
        vi res(q);
        fore(i, 0, q)
        {
            int l = que[quo[i].s].f.f, r = que[quo[i].s].f.s, k = que[quo[i].s].s;
            while(ri < r)
            {
                ri++;
                add(ar[ri]);
            }
            while(ri > r)
            {
                sub(ar[ri]);
                ri--;
            }
            while(le < l)
            {
                sub(ar[le]);
                le++;
            }
            while(le > l)
            {
                le--;
                add(ar[le]);
            }
            int re = MOD, si = (r - l + 1) / k;
            // cout<<l<<' '<<r<<' '<<k<<' '<<si<<'\n';
            // fore(i, 0, canfre)
            //     cout<<i + 1<<' '<<frec[freca[i]]<<'\n';
            fore(i, 0, 80)
            {
                int nu = rng() % (r - l + 1) + l;
                if(frec[ar[nu]] > si)
                    re = min(re, ar[nu]);
            }
            if(re == MOD)
                res[quo[i].s] = -1;
            else
                res[quo[i].s] = re + 1;
        }
        for(int x : res)
            cout<<x<<'\n';
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
