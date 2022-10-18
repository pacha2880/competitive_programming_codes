#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define count(x)        __builtin_popcountll(x)
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
ll ar[40], val[40], n, m;
ll res = 0;
ll bino[50][50];
void repa(int pos, ll ocu, ll mask, ll inter, int pre, int can, int prendi);
void go(int pos, ll ocu, ll mask, int prendi)
{
	// cout<<pos<<' '<<ocu<<' '<<mask<<' '<<prendi<<' '<<n - count(ocu)<<'\n';
	if(pos == m)
	{
		// cout<<n - count(ocu)<<' '<<prendi<<'\n';
		// cout<<"!!!!!!"<<bino[n - count(ocu)][prendi]<<'\n';
		res += bino[n - count(ocu)][prendi];
		return;
	}
	int va = count((~ar[pos] ^ mask) & ocu);
	// cout<<va<<'\n';
	if(va <= val[pos])
	{
		val[pos] -= va;
		ll inter = (ar[pos] ^ ar[pos - 1]) & ~ocu;
		int can = count(inter), dif = abs(val[pos] - val[pos - 1]);
		// cout<<'#'<<ar[pos]<<' '<<ar[pos - 1]<<' '<<inter<<' '<<can<<' '<<dif<<'\n';
		// cout<<val[pos]<<' '<<val[pos - 1]<<'\n';
		if(can >= dif && can - dif <= 2 * min(val[pos], val[pos - 1]) && (can - dif) % 2 == 0)
		{	int pren;
			if(val[pos] > val[pos - 1])
				pren = dif + (can - dif) / 2;
			else
				pren = (can - dif) / 2;
			val[pos] -= pren;
			repa(pos, ocu | inter, mask, inter, pren, can, val[pos]);
			val[pos] += pren;
		}

		val[pos] += va;
	}
}
void repa(int pos, ll ocu, ll mask, ll inter, int pre, int can, int prendi)
{
	if(can == 0 && pre == 0)
		go(pos + 1, ocu, mask, prendi);
	else if(pre <= can)
	{
		ll bit = inter & -inter;
		if(pre)
			repa(pos, ocu, mask + (bit & ar[pos]), inter - bit, pre - 1, can - 1, prendi);
		repa(pos, ocu, mask + (bit & (bit ^ ar[pos])), inter - bit, pre, can - 1, prendi);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	fore(i, 0, 50) bino[i][0] = 1;
	fore(i, 1, 50)
		fore(j, 1, 50) bino[i][j] = bino[i - 1][j] + bino[i - 1][j - 1];
	cin>>n>>m;
	fore(i, 0, m)
	{
		string s;
		cin>>s;
		cin>>val[i];
		fore(j, 0, n)
			if(s[j] == '1')
				ar[i] += 1ll<<j;
	}
	go(1, 0, 0, val[0]);
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
