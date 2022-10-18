#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ll b, k, x1, y1, x2, y2;
        cin>>b>>k>>x1>>y1>>x2>>y2;
        vector<pair<ll, pair<ll, ll>>> fi;
        if(x1 % b == 0 || y1 % b == 0)
            fi.pb({0, {x1, y1}});
        else
            fi.pb({x1 % b * k, {x1 - x1 % b, y1}}),
            fi.pb({(b - x1 % b) * k, {x1 + b - x1 % b, y1}}),
            fi.pb({y1 % b * k, {x1, y1 - y1 % b}}),
            fi.pb({(b - y1 % b) * k, {x1, y1 + b - y1 % b}});
        vector<pair<ll, pair<ll, ll>>> se;
        if(x2 % b == 0 || y2 % b == 0)
            se.pb({0, {x2, y2}});
        else
            se.pb({x2 % b * k, {x2 - x2 % b, y2}}),
            se.pb({(b - x2 % b) * k, {x2 + b - x2 % b, y2}}),
            se.pb({y2 % b * k, {x2, y2 - y2 % b}}),
            se.pb({(b - y2 % b) * k, {x2, y2 + b - y2 % b}});
        ll res = abs(x1 - x2) * k + abs(y1 - y2) * k;
        fore(i, 0, fi.size())
            fore(j, 0, se.size())
            {
                ll su = fi[i].f + se[j].f;
                pair<ll, ll> p = fi[i].s, q = se[j].s;
                if(p.f == q.f && p.f % b == 0)
                {
                    res = min(res, su + abs(p.s - q.s));
                    continue;
                }
                else if(p.s == q.s && p.s % b == 0)
                {
                    res = min(res, su + abs(p.f - q.f));
                    continue;
                }
                vector<pair<ll, pair<ll, ll>>> fa;
                if(p.f % b == 0 && p.s % b == 0)
                    fa.pb({0, p});
                else if(p.f % b == 0)
                    fa.pb({p.s % b, {p.f, p.s - p.s % b}}),
                    fa.pb({b - p.s % b, {p.f, p.s + b - p.s % b}});
                else
                    fa.pb({p.f % b, {p.f - p.f % b, p.s}}),
                    fa.pb({b - p.f % b, {p.f + b - p.f % b, p.s}});
                vector<pair<ll, pair<ll, ll>>> sa;
                if(q.f % b == 0 && q.s % b == 0)
                    sa.pb({0, q});
                else if(q.f % b == 0)
                    sa.pb({q.s % b, {q.f, q.s - q.s % b}}),
                    sa.pb({b - q.s % b, {q.f, q.s + b - q.s % b}});
                else
                    sa.pb({q.f % b, {q.f - q.f % b, q.s}}),
                    sa.pb({b - q.f % b, {q.f + b - q.f % b, q.s}});
                fore(i, 0, fa.size())
                    fore(j, 0, sa.size())
                    {
                        pair<ll, ll> p1 = fa[i].s, q1 = sa[j].s;
                        res = min(res, su + fa[i].f + sa[j].f + abs(p1.f - q1.f) + abs(p1.s - q1.s));
                    }
            }
        cout<<res<<'\n';
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
