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
const int tam = 100010;
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
    int b;
    cin>>b;
    int p;
    cin>>p;
    vector<pair<int, string>> ps(p);
    fore(i, 0, p) cin>>ps[i].s>>ps[i].f;
    int g;
    cin>>g;
    vector<pair<int, string>> gs(g);
    fore(i, 0, g) cin>>gs[i].s>>gs[i].f;
    int s;
    cin>>s;
    vector<pair<int, string>> ss(s);
    fore(i, 0, s) cin>>ss[i].s>>ss[i].f;
    int f;
    cin>>f;
    vector<pair<int, string>> fs(f);
    fore(i, 0, f) cin>>fs[i].s>>fs[i].f;
    int c;
    cin>>c;
    vector<pair<int, string>> cs(c);
    fore(i, 0, c) cin>>cs[i].s>>cs[i].f;
    vector<pair<int, vector<string>>> team1;
    vector<pair<int, vector<string>>> team2;
    fore(i, 0, p)
    {
        fore(j, 0, g)
        {
            team1.pb({ps[i].f + gs[j].f, {ps[i].s, gs[j].s}});
        }
    }
    // team2 with the remaining
    fore(i, 0, s)
    {
        fore(j, 0, f)
        {
            fore(k, 0, c)
            {
                team2.pb({ss[i].f + fs[j].f + cs[k].f, {ss[i].s, fs[j].s, cs[k].s}});
            }
        }
    }
    sort(all(team2));
    sort(all(team1));
    pair<int, vector<string>> ans = {0, {}};
    fore(i, 0, sz(team1))
    {
        int l = 0, r = sz(team2) - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(team1[i].f + team2[mid].f <= b)
            {
                if(-team1[i].f - team2[mid].f <= ans.f)
                {
                    ans = min(ans, {-team1[i].f - team2[mid].f, {team1[i].s[0], team1[i].s[1], team2[mid].s[0], team2[mid].s[1], team2[mid].s[2]}});
                }
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    for(auto x : ans.s) cout<<x<<'\n';
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
