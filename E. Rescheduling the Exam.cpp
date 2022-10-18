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
int mindif(vi ar, int n)
{
	int res = MOD;
	res = ar[0] - 1;
	fore(i, 1, n)
		res = min(res, ar[i] - ar[i - 1] - 1);
	return res;
}
int d;
vi eli(vi ar, int pos, int n)
{
	vi nue;
	fore(i, 0, n)
		if(i != pos)
			nue.pb(ar[i]);
	ii mau = {nue[0] / 2 - 1, nue[0] / 2};
	fore(i, 1, n - 1)
	{
		mau = max(mau, {(nue[i] + nue[i - 1]) / 2 - nue[i - 1] - 1, (nue[i] + nue[i - 1]) / 2});
	}
	mau = max(mau, {d - nue[n - 2] - 1, d});
	ar[pos] = mau.s;
	return ar;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n>>d;
		vi ar(n);
		vii dif(n);
		fore(i, 0, n)
		{
			cin>>ar[i];
			if(i == 0)
				dif[i] = {ar[i] - 1, i};
			else
				dif[i] = {ar[i] - ar[i-1] - 1, i};
		}
		sort(all(dif));
		if(dif[0].s == 0)
		{
			vi er = eli(ar, 0, n);
			sort(all(er));
			cout<<mindif(er, n)<<'\n';
		}
		else
		{
			vi er = eli(ar, dif[0].s, n), ur = eli(ar, dif[0].s - 1, n);
			sort(all(er)); sort(all(ur));
			cout<<max(mindif(er, n), mindif(ur, n))<<'\n';
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
