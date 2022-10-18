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
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<'\n'
#define RAYA cerr<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
// el table es para comparar substrings memoria nlogn
vector<vector<int>> table;
vector<int> suffixa(vi &s)
{
	int n = s.size(), cc, ax;
	vector<int> sa(n), sa1(n), col(n), col1(n), head(n);
	fore(i, 0, n) sa[i] = i;
	asd = s;
	stable_sort(sa.begin(), sa.end(), cmp);
	head[0] = col[sa[0]] = cc = 0;
	fore(i, 1, n)
	{
		if(s[sa[i]] != s[sa[i-1]])
			cc++, head[cc] = i;
		col[sa[i]] = cc;
	}
	table.pb(col);
	for(int k = 1; k < n; k *= 2)
	{
		fore(i, 0, n)
		{
			ax = (sa[i] - k + n) % n;
			sa1[head[col[ax]]++] = ax;
		}
		swap(sa, sa1);
		col1[sa[0]] = head[0] = cc = 0;
		fore(i, 1, n)
		{
			if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
				cc++, head[cc] = i;
			col1[sa[i]] = cc;
		}
		col = col1;
		table.pb(col);
	}
	return sa;
}
string ar[1010];
int ind[1010];
vi col;
int n;
bool compa(int x, int y, int i, int j)
{
	// cout<<"locos\n";
	// cout<<x<<' '<<y<<' '<<i<<' '<<j<<'\n';
	int co = n * n + 2;
	int a = x, b = y, c = i, d = j;
	while(ar[a][b] == ar[c][d] && co--)
	{
		b++;
		if(b == n)
			b = 0;
		if(b == y)
		{
			a++;
			if(a == n)
				a = 0;
		}
		d++;
		if(d == n)
			d = 0;
		if(d == j)
		{
			c++;
			if(c == n)
				c = 0;
		}
	}
	// cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
	// cout<<(ar[a][b] > ar[c][d])<<'\n';
	return ar[a][b] > ar[c][d];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin>>ar[0];
	n = ar[0].size();
	col.resize(n);
	fore(i, 1, n)
	{
		cin>>ar[i];
	}
	fore(i, 0, n) ind[i] = i;
	sort(ind, ind + n, [&](int a, int b){
		return ar[a] < ar[b];
	});
	int co = 0;
	string com = ar[ind[0]];
	fore(i, 0, n)
	{
		if(com != ar[ind[i]])
		{
			com = ar[ind[i]];
			co++;
		}
		col[ind[i]] = co;
	}
	int x = 0, y = 0;
	fore(i, 0, n)
	{
		int ix = n - i - 1;
		vi sa = suffixa(col);
		// cout<<"cols\n";
		// fore(i, 0, n) cout<<col[i]<<' ';
		// cout<<'\n';
		// cout<<"suf\n";
		// fore(i, 0, n) cout<<sa[i]<<' ';
		// cout<<'\n';
		if(compa(x, y, sa[0], (ix + 1)%n))
			x = sa[0], y = (ix + 1)%n;
		sort(ind, ind + n, [&](int a, int b){
			return mp(ar[a][ix], col[a]) < mp(ar[b][ix], col[b]);
		});
		auto comp = mp(ar[ind[0]][ix], col[ind[0]]);
		co = 0;
		fore(i, 0, n)
		{
			if(comp != mp(ar[ind[i]][ix], col[ind[i]]))
			{
				comp = mp(ar[ind[i]][ix], col[ind[i]]);
				co++;
			}
			col[ind[i]] = co;
		}
	}
	fore(i, 0, n)
	{
		string a = "";
		fore(j, 0, n)
			a += ar[(x + i) % n][(y + j) % n];
		cout<<a<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
