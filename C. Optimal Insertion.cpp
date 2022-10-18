#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;

int can;
int ar[tam], br[tam], re[tam], cr[2 * tam], bit[2 * tam];
void update(int pos, int val)
{
	while(pos < tam * 2)
	{
		bit[pos] += val;
		pos += pos&-pos;
	}
}
int query(int pos)
{
	int res = 0;
	while(pos)
	{
		res += bit[pos];
		pos -= pos&-pos;
	}
	return res;
}
void dc(int b, int e, int l, int r)
{
	if(b > e) return;
	int mid = (b + e) / 2;
	ii res(MOD, -1);
	int may = 0, men = 0;
	fore(i, l, r)
		men += br[mid] > ar[i];
	fore(i, l, r + 1)
	{
		// cout<<i<<' '<<may<<' '<<men<<'\n';
		res = min(res, {may + men, i});
		men -= br[mid] > ar[i];
		may += br[mid] < ar[i];
	}
	re[mid] = res.s;
	// cout<<mid<<' '<<l<<' '<<r<<' '<<res.f<<' '<<res.s<<'\n';
	dc(b, mid - 1, l, res.s);
	dc(mid + 1, e, res.s, r);
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
		int n, m;
		cin>>n>>m;
		fore(i, 0, n) cin>>ar[i];
		fore(i, 0, m) cin>>br[i];
		sort(br, br + m);
		dc(0, m - 1, 0, n);
		int po = 0, pa = 0;
		fore(i, 0, m)
		{
			while(re[i] > pa && pa < n)
				cr[po++] = ar[pa++];
			cr[po++] = br[i];
		}
		while(pa < n)
			cr[po++] = ar[pa++];
		set<int> st;
		map<int, int> ma;
		fore(i, 0, po)
			st.insert(cr[i]);
		int xi = 0;
		for(int x : st)
			ma[x] = xi++;
		fore(i, 0, po)
			cr[i] = ma[cr[i]];
		ll res = 0;
		fore(i, 0, n + m + 1) bit[i] = 0;
		for(int i = n + m - 1; i > -1; i--)
		{
			res += query(cr[i]);
			update(cr[i] + 1, 1);
		}
		cout<<res<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil