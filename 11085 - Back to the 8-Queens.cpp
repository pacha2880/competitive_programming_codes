#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define mp				make_pair
#define pb				push_back
// #define all(a)			(a).begin(), (a).end()
// #define sz(a)			(int)a.size()
// #define eq(a, b)     	(fabs(a - b) < EPS)
// #define md(a, b)		((a) % b + b) % b
// #define mod(a)			md(a, MOD)
// #define _max(a, b) ((a) > (b) ? (a) : (b))
// #define srt(a)			sort(all(a))
// #define mem(a, h)		memset(a, (h), sizeof(a))
// #define f 				first
// #define s 				second
// #define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
// #define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
// #define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
// #define DBG(x) cerr<<#x<<" = "<<(x)<<endl
// #define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

// typedef long long 		ll;
// typedef long double ld;	
// typedef unsigned long long 		ull;
// typedef pair<int, int>  ii;
// typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
// typedef vector<ii>      vii;
// typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
// const int tam = 100'010;
// const int MOD = 1'000'000'007;
// const int MOD1 = 998'244'353;
// const double DINF=1e100;
// const double EPS = 1e-9;
// const double PI = acos(-1); 
int column[20], diag1[20], diag2[20];
int n = 8, con =0;
vi tab(8);
vector<vi> res;
void search(int y) {
	if (y == n) {
		con++;
		res.pb(tab);
		return;
	}
	for (int x = 0; x < n; x++) {
		if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		tab[x] = y;
		search(y+1);
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	search(0);
	vi ar(8);
	int x;
	int cas = 0;
	while(cin>>x)
	{
		cas++;
		ar[0] = x - 1;
		fore(i, 1, 8) cin>>ar[i], ar[i]--;
		int rus = 8;
		fore(i, 0, res.size())
		{
			int cand = 0;
			fore(j, 0, 8)
				cand += ar[j] != res[i][j];
			rus = min(rus, cand);
		}
		cout<<"Case "<<cas<<": "<<rus<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
