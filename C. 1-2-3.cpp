#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, m)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<pair<int, int>> turs;
int mata[3][3], matb[3][3];
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll n;
	int a, b;
	cin>>n>>a>>b;
	a--;
	b--;
	fore(i, 0, 3) fore(j, 0, 3) {cin>>mata[i][j];mata[i][j]--;}
	fore(i, 0, 3) fore(j, 0, 3) {cin>>matb[i][j];matb[i][j]--;}
	turs.pb(mp(0,0));
	vector<pair<int, int>> hist;
	set<pair<int, int>> st;
	hist.pb(mp(a, b));
	st.insert(mp(a, b));
	if(a == b)
		turs.pb(mp(0,0));
	else if(a - b == -2 || a - b == 1)
		turs.pb(mp(1, 0));
	else
		turs.pb(mp(0, 1));
	int x = mata[a][b], y = matb[a][b];
	pair<int, int> last;
	n--;
	int ax;
	int resa = turs[1].f, resb = turs[1].s;
	while(st.count(mp(x, y)) == 0)
	{
		st.insert(mp(x, y));
		hist.pb(mp(x, y));
		//cout<<x<<' '<<y<<'\n';
		last = turs.back();
		if(x == y)
			turs.pb(last);
		else if(x - y == -2 || x - y == 1)
			turs.pb(mp(1 + last.f, last.s));
		else
			turs.pb(mp(last.f, 1 + last.s));
		n--;
		if(n >= 0)
			resa = turs.back().f, resb = turs.back().s;
		ax = x;
		x = mata[x][y];
		y = matb[ax][y];
	}
	//cout<<x<<' '<<y<<' '<<resa<<' '<<resb<<'\n';
	//cout<<n<<'\n';
	if(n > 0)
	{
	int fro = 0;
	while(hist[fro] != mp(x, y))
		fro++;
	vector<pair<int, int>> nas;
	nas.pb(mp(0,0));
	fore(i, fro + 1, turs.size())
		nas.pb(mp(turs[i].f - turs[fro].f, turs[i].s - turs[fro].s));
	turs = nas;
	cout<< resa + n / (turs.size() - 1) * turs.back().f + turs[n % (turs.size() -1)].f<<' '<<
			resb + n / (turs.size() - 1) * turs.back().s + turs[n % (turs.size() -1)].s<<'\n';}
	else
		cout<<resa<<' '<<resb<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	