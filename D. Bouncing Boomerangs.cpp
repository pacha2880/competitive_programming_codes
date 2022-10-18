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
#define forn(i, n)			for(int i = 0; i < n; i++)
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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int men = 0;
	set<pair<int, int>> uns, solos;
	vector<pair<int, int>> res;
	pair<int, int> ax;
	fore(i, 0, n) cin>>ar[i];
	for(int i = n - 1; i > -1; i--)
	{
		if(ar[i] == 1)
		{
			uns.insert({i, men});
			solos.insert({i, men});
			res.pb({i, men});
			men++;
		}
		if(ar[i] == 2)
		{
			if(uns.size())
			{
				ax = *uns.begin();
				uns.erase(ax);
				solos.erase(ax);
				ax.f = i;
				res.pb(ax);
				solos.insert(ax);
			}
			else
			{
				cout<<"-1\n";
				return 0;
			}
		}
		if(ar[i] == 3)
		{
			if(solos.size())
			{
				ax = *solos.begin();
				solos.erase(ax);
				uns.erase(ax);
				ax.s = men;
				res.pb(ax);
				ax.f = i;
				solos.insert(ax);
				res.pb(ax);
				men++;
			}
			else
			{
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	cout<<res.size()<<'\n';
	fore(i, 0, res.size())
	{
		cout<<n - res[i].s<<' '<<res[i].f + 1<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	