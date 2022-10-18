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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	vi ar(n);
	fore(i, 0, n) cin>>ar[i];
	if(k == 0)
	{
		int ra = 0;
		int fru = -1;
		fore(i, 0, n)
		{
			if(ar[i] == 1)
			{
				if(fru == -1)
					fru = i;
				ra = max(ra, i - fru + 1);
			}
			else
				fru = -1;
		}
		cout<<ra<<'\n';
		fore(i, 0, n) cout<<ar[i]<<' ';
		return 0;
	}
	int fro = 0, to = -1;
	fore(i, 0, k)
	{
		while(to < n - 1 && ar[to + 1] == 1)
			to++;
		if(to < n - 1)
			to++;
		while(to < n - 1 && ar[to + 1] == 1)
			to++;
	}
	pair<int, pair<int, int>> res(to - fro + 1, {fro, to});
	// cout<<fro<<' '<<to<<'\n';
	while(to < n - 1)
	{
		to++;
		while(to < n - 1 && ar[to + 1] == 1) to++;
		while(fro < to && ar[fro] == 1) fro++;
		if(fro < to)
			fro++;
		// cout<<fro<<' '<<to<<'\n';
		res = max(res, mp(to - fro + 1, mp(fro, to)));
	}
	fore(i, res.s.f, res.s.s + 1)
		ar[i] = 1;
	cout<<res.f<<'\n';
	fore(i, 0, n) cout<<ar[i]<<' ';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
