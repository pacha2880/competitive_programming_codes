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
#define forr(i, b, e)	fore(i, b, e)
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

typedef __int128 		ll;
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll n;
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e)
	{
		if(e & 1) res = res * b % n;
		b = b * b % n;
		e /= 2;
	}
	return res;
}
void _mod(ll &x,ll n)
{
    while(x>n)
        x-=n;

}
void meme(ll n,ll x,ll a,ll y,ll b)
{
    ll x0 = x*2; _mod(x0,n);
    vector<int> v1;v1.pb(x);
    bool ok  = 0;
    int p2,p1 = 0;
    while(x != x0)
    {
        v1.pb(x0);
        if (x0 == y) ok = 1,p2= v1.size() - 1;
        x0 = x0*2; _mod(x0,n);
    }
    if (ok)
    {
        forr(i,0,tam)
        {
            if (v1[p1] == v1[p2])
                {
                    cout<<i<<endl;
                    return ;
                }
            p1 += a;
            p1 %= (v1.size()),
            p2 += b;
            p2 %= (v1.size());
        }
        cout<<"-1\n";
    }
    else
        cout<<"-1\n";
    return ;
}
vector<ll> primos;
void criba(ll n)
{
    for (ll i= 2;i*i<=n;i++)
    {
        while(n%i == 0)
        {
            primos.pb(i);
            n/=i;
        }
    }
}
ll euler(ll n)
{
    ll res=n;
    forr(i,0,primos.size())
    {
        if(n%primos[i]==0)
        {
            res-= res/primos[i];
            while(n%primos[i]==0) n/=primos[i];
        }
    }
    if(n!=1) res-=res/n;
    return res;
}
ll phi = -1;
ll pot(ll b, ll e , ll mod)
{
    ll res = 1;
    while(e)
    {
        if (e&1)res*=b,res%=mod;
        b*=b,b%=mod;
        e/=2;
    }
    return res;
}
ll _inv(ll mod,ll numero)
{
    if (phi == -1)
        criba(mod), phi = euler(mod);
    return pot(numero, phi - 1, mod);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll x, y, a, b;
	long long xx, yy, aa, bb, nn;
	cin>>nn>>xx>>aa>>yy>>bb;
	n = nn, x = xx, a = aa, y = yy, b = bb;
	ll ax = x;
	if(x == y)
	{
		cout<<0<<'\n';
		return 0;
	}
	if(a == b)
	{
		cout<<-1<<'\n';
		return 0;
	}
	ll i = 1, co = 0;
	unordered_set<ll> st;
	while(i < n)
	{
		co++;
		st.insert(i);
		i *= 2;
	}
	if(i - 1 == n)
		meme(n, x, a, y, b);
	else
	{
		ll dos = pot(2, n - 2);
		ll mul = 1;
		fore(i, 0, co)
			mul = mul * dos % n;
		ll posx = 0;
		while(!st.count(x))
		{
			posx += co;
			x = x * mul % n;
		}
		while(x > 1)
		{
			x /= 2;
			posx++;
		}
		ll posy = 0;
		while(!st.count(y))
		{
			posy += co;
			y = y * mul % n;
		}
		while(y > 1)
		{
			y /= 2;
			posy++;
		}
		// cout<<posx<<' '<<posy<<'\n';
		ll g = __gcd(a, __gcd(b, __gcd(posx, __gcd(posy, n - 1))));
		a /= g;
		b /= g;
		posx /= g;
		posy /= g;
		n--;
		n /= g;
		if(__gcd(abs(b - a), n) != 1)
		{
			cout<<-1<<'\n';
			return 0;
		}
		ll q = ((posx - posy) * _inv(n, b - a) % n + n) % n;
		n++;
		ll six = pot(pot(2, a), q) * ax % n;
		cout<<(ll)q<<' '<<(ll)six<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
