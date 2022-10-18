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
#define f 				first
#define s 				second
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
typedef pair<int, int>  ii;
// typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
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
int t, n, con;
vi nums;
vector<vi> res;
vii ar(20);
void search(int pos, int sum) {
	if(sum > t)
		return;
	if (sum == t) {
		con++;
		res.pb(nums);
		return;
	}
	if(pos == n) return;
	search(pos + 1, sum);
	fore(i, 0, ar[pos].s)
	{
		nums.pb(ar[pos].f);
		sum += ar[pos].f;
		search(pos + 1, sum);
	}
	fore(i, 0, ar[pos].s)
		nums.pop_back();
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	while(true)
	{
		cin>>t>>n;
		if(t == 0) break;
		int las = -1;
		int po = -1;
		int x;
		map<int, int> ma;
		fore(i, 0, n) 
		{
			cin>>x;
			ma[x]++;
		}
		n = ma.size();
		x = n - 1;
		for(ii cat : ma)
		{
			ar[x] = cat;
			x--;
		}
		cout<<"Sums of "<<t<<":\n";
		
		res.clear();
		con = 0;
		search(0, 0);
		if(con == 0)
			cout<<"NONE\n";
		else
		{
			for(int i = ((int)res.size()) - 1; i > -1; i--)
			{
				cout<<res[i][0];
				fore(j, 1, res[i].size())
					cout<<'+'<<res[i][j];
				cout<<'\n';
			}
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
