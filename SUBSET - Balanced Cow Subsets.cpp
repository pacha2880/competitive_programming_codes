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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, x;
	cin>>n;
	vector<bool> can(1<<n);
	int a = n / 2, b = n - n / 2;
	vll va(a), vb(b);
	fore(i, 0, a) cin>>va[i];
	fore(i, 0, b) cin>>vb[i];
	map<ll, unordered_set<int>> st;
	fore(i, 0, 1<<b)
	{
		for(int j = i; j; j = (j - 1) & i)
		{
			ll su = 0;
			fore(k, 0, b)
				if(j & (1<<k))
					su += vb[k];
				else if(i & (1<<k))
					su -= vb[k];
			if(su == 0)
				can[i<<a] = 1;
			st[su].insert(i<<a);
		}
		// cout<<i<<":\n";
		// for(int x : st[i])
		// 	cout<<x<<' ';
		// cout<<'\n';
	}
	// cout<<'\n';
	// fore(i, 0, 1<<n) cout<<can[i]<<' ';
	// cout<<'\n';
	fore(i, 0, 1<<a)
	{
		// cout<<i<<":\n";
		for(int j = i; j; j = (j - 1) & i)
		{
			ll su = 0;
			fore(k, 0, a)
				if(j & (1<<k))
					su += va[k];
				else if(i & (1<<k))
					su -= va[k];
			if(su == 0)
				can[i] = 1;
			// cout<<su<<' ';
			for(auto cat : st[su])
				can[i | cat] = 1;
		}
		// cout<<'\n';
	}
	int res = 0;
	fore(i, 0, 1<<n)
		res += can[i];
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
