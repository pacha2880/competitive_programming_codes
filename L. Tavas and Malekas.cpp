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
vector<int> alz(string s)
{
	int n = s.size();
	vector<int> z(n, 0);
	for(int i = 2, l = 0, r = 0; i < n; i++)
	{
		if(i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if(r < i + z[i] - 1)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
	string s;
	cin>>n>>m;
	cin>>s;
	string ax = s + "&"+ s;
	vi z = alz(ax);

	// cout<<"hola\n";
	// for(int x : z)
	// 	cout<<x<<' ';
	// cout<<'\n';
	int ta = n;
	ll res = 1;
	int ni = s.size();
	int la = -ni, a;
	while(m--)
	{
		cin>>a;
		a--;
		if(a + ni > n)
		{
			// cout<<"e\n";
			cout<<0;
			return 0;
		}
		if(la + ni < a)
		{
			ta -= ni;
		}
		else
		{
			// cout<<la<<' '<<a<<' '<<ni<<'\n';
			if(z[ni + 1 + a - la] == ni - a + la)
				ta -= a - la;
			else
			{
				// cout<<"sd\n";
				cout<<0<<'\n';
				return 0;
			}
		}
		la = a;
	}

	fore(i, 0, ta) res = res * 26ll % MOD;
	cout<<res<<'\n';
	// cout<<26 * 26 * 26<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
