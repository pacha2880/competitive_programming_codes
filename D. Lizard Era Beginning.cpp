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
vector<pair<ii, ii>> gen(vector<vi> ar, int n, bool bo)
{
	int nu = 1;
	fore(i, 0, n) nu *= 3;
	vector<pair<ii, ii>> res(nu);
	fore(i, 0, nu)
	{
		vi ax(3);
		int axi = i;
		fore(i, 0, n)
		{
			int mo = axi % 3;
			fore(j, 0, 3)
				if(j != mo)
					ax[j] += ar[i][j];
			axi /= 3;
		}
		if(bo)
			res[i] = {{ax[0] - ax[1], ax[1] - ax[2]}, {ax[0] + ax[1] + ax[2], i}};
		else 
			res[i] = {{ax[1] - ax[0], ax[2] - ax[1]}, {ax[0] + ax[1] + ax[2], i}};
	}
	sort(all(res));
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	int nl = n / 2, nr = n - n / 2;
	vector<vi> vl(nl, vi(3)), vr(nr, vi(3));
	fore(i, 0, nl)
		fore(j, 0, 3)
			cin>>vl[i][j];
	fore(i, 0, nr)
		fore(j, 0, 3)
			cin>>vr[i][j];
	vector<pair<ii, ii>> le = gen(vl, nl, 1), ri = gen(vr, nr, 0);
	int i = 0, j = 0;
	pair<int, ii> res = {-MOD, {0, 0}};
	while(i < sz(le) && j < sz(ri))
	{
		if(le[i].f == ri[j].f)
		{
			res = max(res, {le[i].s.f + ri[j].s.f, {le[i].s.s, ri[j].s.s}});
			i++, j++;
		}
		else if(le[i] > ri[j])
			j++;
		else
			i++;
	}
	if(res.f != -MOD)
	{
		int nu = res.s.f;
		string s[] = {"MW", "LW", "LM"};
		fore(i, 0, nl)
		{
			cout<<s[nu % 3]<<'\n';
			nu /= 3;
		}
		nu = res.s.s;
		fore(i, 0, nr)
		{
			cout<<s[nu % 3]<<'\n';
			nu /= 3;
		}
	}
	else
	cout<<"Impossible\n";
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
