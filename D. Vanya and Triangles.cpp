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
// sort(all(v), [](int a, int b){ return a > b; });


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
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000000;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
typedef vector<vector<ll>> mat;
mat ans;
void mult(mat m1, mat m2)
{
	assert(m1[0].size() == m2.size());
	ans.clear();
	ll answer = 0;
	fore(i, 0, m1.size())
	{
		vector<ll> fila;
		fore(j, 0, m2[0].size())
		{
			answer = 0;
			fore(k, 0, m2.size())
				answer = (answer + m1[i][k] * m2[k][j]) % MOD;
			fila.pb(answer);
		}
		ans.pb(fila);
	}
}
void pot(mat base, ll exp)
{
	mat res(base.size(), vector<ll>(base.size(), 0));
	fore(i, 0, base.size())
	res[i][i] = 1;
	while(exp)
	{
		if(exp & 1)
		{
			mult(res, base);
			res = ans;
		}
		mult(base, base);
		base = ans;
		exp /= 2;
	}
	ans = res;
}
mat ma;
int n;
void gen(int fro, int pos, int to)
{
	if(pos == n)
		ma[fro][to]++;
	else if(fro & (1<<pos))
		gen(fro, pos + 1, to);
	else
	{
		gen(fro, pos + 1, to);
		gen(fro, pos + 1, to | (1<<pos));
		if(pos < n - 1 && (~fro & (1<<(pos + 1))))
			gen(fro, pos + 2, to);
	}
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll m;
	cin>>n>>m;
	ma.assign(1<<n, vll(1<<n));
	fore(i, 0, 1<<n)
	{
		gen(i, 0, 0);
	}
	pot(ma, m);
	cout<<ans[0][0]<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
