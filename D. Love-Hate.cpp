#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, p;
	cin>>n>>m>>p;
	int nn = n;
	string s;
	vector<string> v;
	ll a;
	fore(i, 0, n)
	{
		cin>>s;
		bool bo = false;
		for(char ch : s)
			if(ch == '1')
			{
				v.pb(s);
				break;
			}
	}
	n = v.size();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(all(v), rng);
	string ris = "";
	int res = 0, ras;
	fore(i, 0, m) ris += '0';
	string ax = ris;
	fore(k, 0, min(10, n))
	{
		vector<int> pos;
		fore(i, 0, m)
			if(v[k][i] == '1')
				pos.pb(i);
		int x = pos.size(), nu;
		vector<int> ar(1<<x), f(1<<x);
		fore(i, 0, n)
		{
			nu = 0;
			fore(j, 0, x)
			{
				nu *= 2;
				nu += v[i][pos[x - j - 1]] - '0';
			}
			ar[nu]++;
		}
		pair<int, int> risi(0, 0);
		for(int i = 0; i<(1<<x); ++i)
			f[i] = ar[i];
		for(int i = 0;i < x; ++i) for(int mask = (1<<x) - 1; mask > - 1 ; --mask){
			if(!(mask & (1<<i)))
				f[mask] += f[mask^(1<<i)];
		}
		fore(i, 0, 1<<x)
		{
			if(f[i] >= (nn + 1) / 2)
				risi = max(risi, {__builtin_popcount(i), i});
		}
		if(risi.f > res)
		{
			ris = ax;
			res = risi.f;
			fore(i, 0, x)
				if(risi.s & (1<<i))
					ris[pos[i]] = '1';
		}
	}
	cout<<ris<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	