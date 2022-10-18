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
	string s;
    cin>>s;
    ll res = 0;
    ll la = -1, acu = 0;
    fore(i, 0, s.size())
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            if(la != -1)
                la++;
            acu = acu * 10 + (s[i] - '0');
        }
        else if(s[i] == '.')
            la = 0;
        else
        {
            if(la != 2)
                acu *= 100;
            res += acu;
            acu = 0;
            la = -1;
        }
    }
    if(la != 2)
    {
        acu *= 100;
        res += acu;
    }
    if(la == 2)
        res += acu;
    s = "";
    // cout<<res<<'\n';
    if(res % 100 != 0)
    {
        s += (char)(res % 10 + '0');
        res /= 10;
        s += (char)(res % 10 + '0');
        res /= 10;
        s += '.';
    }
    else
        res /= 100;
    if(res == 0)
        s += '0';
    else
    {
        ll con = 0;
        while(res > 0)
        {
            if(con == 3)
            {
                con = 0;
                s += '.';
            }
            s += (char)(res % 10 + '0');
            res /= 10;
            con++;
        }
    }
    
    reverse(all(s));
    cout<<s<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
