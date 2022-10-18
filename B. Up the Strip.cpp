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

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
const int tam = 4000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll dp[tam], poso[tam];
vector<int> getDiv(int n)
{
	vector<int> res;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			if(i > 1)
			res.pb(i);
			if(i * i != n)
				res.pb(n / i);
		}
	}
	return res;
}
int cr[tam]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,tam)if(cr[i]<0)for(ll j=1LL*i*i;j<tam;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> r;
	while(cr[n]>=0)r[cr[n]]++,n/=cr[n];
	if(n>1)r[n]++;
	return r;
}

void div_rec(vector<ll>& r, vector<pair<ll,int> >& f, int k, ll c){
	if(k==f.size()){r.pb(c);return;}
	fore(i,0,f[k].s+1)div_rec(r,f,k+1,c),c*=f[k].f;
}
vector<ll> divisors(vector<pair<ll,int> > f){
	vector<ll> r;
	div_rec(r,f,0,1);
	return r;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	init_sieve();
	poso[2] = 1;
	ll n, m;
	cin>>n>>m;
	ll sus = 1;
	fore(i, 3, n + 1)
	{
		map<int,int> f=fact(i);
		vector<ll> d=divisors(vector<pair<ll,int> >(f.begin(),f.end()));
		vll di = vector<ll>(d.begin() + 1, d.end());
		// cout<<"$"<<dp[i - 1]<<' '<<sus<<'\n';
		dp[i] = dp[i - 1] - sus + dp[i - 1];
		for(int x : di)
		{
			// cout<<x<<' '<<poso[x]<<'\n';
			dp[i] -= dp[poso[x]];
			poso[x]++;
			dp[i] += dp[poso[x]];
			dp[i] = (dp[i] % m + m) % m;
		}
		dp[i] = (dp[i] + sus) % m;
		sus = (sus + dp[i]) % m;
		// cout<<"hola "<<i<<' '<<dp[i]<<' '<<sus<<'\n';
	}
	cout<<dp[n]<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
