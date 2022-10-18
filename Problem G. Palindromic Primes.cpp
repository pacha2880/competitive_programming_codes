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

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
ll vol(ll x)
{
	ll res = 0;
	while(x)
	{
		res *= 10;
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll L, H;
	cin>>L>>H;
	int res = 0;
	fore(i, 1, 10)
	{
		// cout<<i<<'\n';
		if(i >= L && i <= H)
			res += rabin(i);
		if(10 * i + i >= L && 10 * i + i <= H)
			res += rabin(i* 10 + i);
	}
	// cout<<res<<'\n';
	ll d1 = 1, d2 = 1;
	ll ma = 0;
	fore(i, 1, 6)
	{
		d1 *= 100;
		d2 *= 10;
		forg(j, 1, 10, 2)
			if(j != 5)
			{
				ll nu = j * d1 + j;
				// cout<<nu<<' '<<d2<<'\n';
				fore(k, 0, d2)
				{
					ll can = k * 10 + d2 * 10 * (vol(d2/10 + k % (d2 / 10))/10);
					
					// ma = max(ma, nu + can);
					if(nu + can >= L && nu + can <= H)
					{
						// cout<<nu + can<<'\n';
						res += rabin(nu + can);
					}
				}
			}	
	}
	// cout<<ma<<'\n';
	// cout<<"#####\n";
	// cout<<res<<'\n';
	d1 = 10, d2 = 1;
	ll me = 0;
	fore(i, 1, 6)
	{
		d2 *= 10;
		d1 *= 100;
		forg(j, 1, 10, 2)
			if(j != 5)
			{
				ll nu = j * d1 + j;
				// cout<<nu<<'\n';
				fore(k, 0, d2)
				{
					ll can = k * 10 + d2 * 10 * (vol(d2 + k)/10);
					// me = max(ma, nu + can);
					if(nu + can >= L && nu + can <= H)
					{
						// cout<<nu + can<<'\n';
						res += rabin(nu + can);
					}
				}
			}	
	}
	// cout<<me<<'\n';
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
