#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 3030;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
bitset<2 * tam> mat[tam];

signed main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int n, m, p;
    cin>>n>>m>>p;
    vector<pair<ii, int>> ar(n);
    vi len(n), su(n), chi(n), par(n, -1);
    fore(i, 0, m)
    {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        ar[i] = {{a, b}, c};
        len[i] = a - b + 1;
        su[i] = (p - c) % p;
    }
    set<int> lib;
    fore(i, 0, n)
        lib.insert(i);
    set<ii> st;
    vi res(n);
    fore(i, 0, m)
    {
        fore(j, 0, m)
        {
            if(i != j || ar[i].f.f > ar[j].f.f || ar[i].f.s < ar[j].f.s)
                continue;
            if(len[i] == len[j])
            {
                if(i < j) {if(par[j] != -1) chi[par[j]]--; par[j] = i; chi[i]++;}
            }
            else if(par[j] == -1) {par[j] = i; chi[i]++;}
            else if(len[par[j]] > len[i]) {chi[par[j]]--; par[j] = i; chi[i]++;}
        }
    }
    fore(i, 0, m)
    {
        if(chi[i] == 0)
            st.insert({ar[i].f.s, i});
    }
    // cout<<'\n';
    while(!st.empty())
    {
        // fore(i, 0, n) cout<<res[i]<<' ';
        // cout<<'\n';

        int yo = st.begin()->s;
        st.erase(st.begin());
        su[yo] = (su[yo] % p + p) % p;
        // cout<<yo<<' '<<su[yo]<<'\n';
        if(su[yo] % p != 0)
        {
            
            auto it = lib.lower_bound(ar[yo].f.s + 1);
            if(it == lib.begin())
            {
                cout<<"None\n";
                return 0;
            }
            it--;
            if(*it < ar[yo].f.f)
            {
                cout<<"None\n";
                return 0;
            }
            // cout<<yo<<' '<<su[yo]<<' '<<*it<<'\n';
            res[*it] = p - su[yo];
            fore(i, 0, m)
            {
                if(*it >= ar[i].f.f && *it <= ar[i].f.s)
                {
                    su[i] += res[*it];
                }
            }
            if(par[yo] != -1)
            {
                chi[par[yo]]--;
                if(chi[par[yo]] == 0)
                    st.insert({ar[par[yo]].f.s, par[yo]});
            }
        }

        auto it = lib.lower_bound(ar[yo].f.f);
        while(it != lib.end() && *it <= ar[yo].f.s)
            it = lib.erase(it);
    }
    fore(i, 0, n)
        cout<<res[i]<<' ';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
