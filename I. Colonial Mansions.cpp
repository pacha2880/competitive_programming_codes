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
struct node
{
  int l, r, val;
};
node join(node a, node b)
{
	a.val = max(max(a.val, b.val), abs(a.r- b.l));
	a.r = b.r;
  	return a;
}
int ar[tam];
node t[4 * tam];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node].val = 0;
		t[node].l = ar[b];
		t[node].r = ar[b];
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
node query(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
		return t[node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	if(mid >= j)
		return query(b, mid, l, i, j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}

void update(int b, int e, int node, int pos, int val)
{
	if(b == e) {t[node].l = t[node].r = val;return;}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < pos)
		update(mid + 1, e, r, pos, val);
	else
		update(b, mid, l, pos, val);
	t[node] = join(t[l], t[r]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, n) cin>>ar[i];
	init(0, n - 1, 0);
	fore(i, 0, m)
	{
		int a, b, c;
		cin>>a>>b>>c;
		if(a == 1)
			update(0, n - 1, 0, b - 1, c);
		else
		{
			b--;
			int r, l, mid, ini = b, fin = n - 1;
			while(ini <= fin)
			{
				mid = (ini + fin) / 2;
				if(query(0, n -1, 0, b, mid).val <= c)
					r = mid, ini = mid + 1;
				else
					fin = mid - 1;
			}
			ini = 0, fin = b;
			while(ini <= fin)
			{
				mid = (ini + fin) / 2;
				if(query(0, n -1, 0, mid, b).val <= c)
					l = mid, fin = mid - 1;
				else
					ini = mid + 1;
			}
			// cout<<l<<' '<<r<<'\n';
			cout<<r - l + 1<<'\n';
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
