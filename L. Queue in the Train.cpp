#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef pair<pair<ll, ll>, ll> iii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n;
    ll p;
    cin>>n>>p;
    set<ll> choclo;
    set<int> chaclo;
    queue<int> coco;
    set<pair<ll, ll>> eve;
    fore(i, 0, n)
    {
        ll x;
        cin>>x;
        eve.insert({x, i});
    }
    vll res(n);
    while(!eve.empty())
    {
        auto cat = *eve.begin();
        // cout<<cat.f<<' '<<cat.s<<'\n';
        // for(int x: choclo)
        //     cout<<x<<' ';
        // cout<<'\n';
        // for(int x: chaclo)
        //     cout<<x<<' ';
        // cout<<'\n';
        eve.erase(eve.begin());
        if(cat.s >= n)
        {
            res[cat.s - n] = cat.f;
            chaclo.erase(cat.s - n);
            // cout<<'%'<<cat.s<<'\n';
            if(coco.empty())
            {
                if(!choclo.empty())
                {
                    int nac = *choclo.begin();
                    choclo.erase(nac);
                    eve.insert({cat.f + p, nac + n});
                    chaclo.insert(nac);
                }
            }
            else
            {
                int nov = coco.front();
                coco.pop();
                chaclo.erase(nov);
                eve.insert({cat.f + p, nov + n});
                chaclo.insert(nov);
                if(chaclo.empty())
                {
                    if(!choclo.empty())
                    {
                        int nac = *choclo.begin();
                        choclo.erase(nac);
                        chaclo.insert(nac);
                        coco.push(nac);
                    }
                }
                else if(!choclo.empty() && *chaclo.begin() > *choclo.begin())
                {
                    int nac = *choclo.begin();
                    choclo.erase(nac);
                    chaclo.insert(nac);
                    coco.push(nac);
                }
            }
        }
        else
        {
            if(chaclo.empty())
            {
                eve.insert({cat.f + p, cat.s + n});
                // cout<<'#'<<cat.s + n<<'\n';
                chaclo.insert(cat.s);
            }
            else if(chaclo.upper_bound(cat.s) == chaclo.begin())
                coco.push(cat.s), chaclo.insert(cat.s);
            else
                choclo.insert(cat.s);
        }
    }
    fore(i, 0, n)
        cout<<res[i]<<' ';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
