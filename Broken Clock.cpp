#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
const ll rev = 360ll * 12 * 10000000000ll;
const ll nue = 1000000000;
ll nanoboto;
bool can(ll h, ll a, ll m, ll b, ll s, ll c, bool ba = false)
{
	a += rev;
	b += rev;
	c += rev;
	ll da, db, dc;
	ll ar[] = {a, b, c};
	pair<ll, int> er[] = {mp(a, 0), mp(b, 1), mp(c, 2)};
	sort(er, er + 3);
	bool bo  = false;
	fore(i, 0, 3)
	{
		if(i > 0) ar[er[i - 1].s] += rev;
		da = ar[0] - h;
		db = ar[1] - m;
		dc = ar[2] - s; 
		if(ba)
			cout<<da<<' '<<db<<' '<<dc<<'\n';
		if(db >= da && db - da < 11000000000ll && (db - da) % 11 == 0 && dc >= da && dc - da < 719000000000ll && (dc - da) % 719 == 0 && dc >= db && dc - db < 708000000000ll && (dc - db) % 708 == 0)
		{
			bo = true;
			nanoboto = (db - da) / 11;
		}
	}
	return bo;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int cas;
	cin>>cas;
	fore(i, 1, cas + 1)
	{
		ll h = 0, m = 0, s = 0, n = 0;
		ll ar[3];
		int per[3] {0, 1, 2};
		fore(i, 0, 3) cin>>ar[i];
		do
		{
			ll a = ar[per[0]], b = ar[per[1]], c = ar[per[2]];
			h = 0, m = 0, s = 0;
			int con = 0;
			while(!can(h, a, m, b, s, c) && con < 3600 * 12)
			{
				con++;
				s += 720ll * 1000000000;
				m += 12ll * 1000000000;
				h += 1000000000;
				s %= rev;
				m %= rev;
				h %= rev;
				// if(m % (12ll * 1000000000 * 30 * 60) == 0 && false)
				// {
				// 	cout<<"caca  "<<s<<' '<<m<<' '<<h<<' '<<a<<' '<<b<<' '<<c<<'\n';
				// 	cout<<"Case #"<<i<<": "<<h / (1000000000 * 3600ll)<<' '<<h % (1000000000 * 3600ll) / (1000000000 * 60ll)<<' '<<h % (1000000000 * 60ll) / 1000000000<<' '<<n<<'\n';
				// 	cout<<can(h, a, m, b, s, c, true)<<'\n';
				// }
			}
		// 	if(can(h, a, m, b, s, c)){
		// cout<<"caca  "<<s<<' '<<m<<' '<<h<<' '<<a<<' '<<b<<' '<<c<<'\n';
		// cout<<can(h, a, m, b, s, c, true)<<'\n';
		// 	}
			if(can(h, a, m, b, s, c)) break;
		}
		while(next_permutation(per, per + 3));
		// cout<<h/1000000000<<'\n';
		cout<<"Case #"<<i<<": "<<h / (1000000000 * 3600ll)<<' '<<h % (1000000000 * 3600ll) / (1000000000 * 60ll)<<' '<<h % (1000000000 * 60ll) / 1000000000<<' '<<nanoboto<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	 