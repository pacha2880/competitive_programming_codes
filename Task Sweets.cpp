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
const ll INF = 1ll * MOD * MOD;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<ll> par[2][1000000];
pair<ll, ll> pun[2][1000000];
int can[2];
ll ar[30];
void gen(vector<ll> v, int ind)
{
	int n = v.size();
	can[ind] = 0;
	int ax, tot = 1, con, mo;
	ll sa, sb, sc;
	fore(i, 0, n)
	{
		tot *= 3;
	}
	fore(i, 0, tot)
	{
		ax = i;
		con = 0;
		sa = sb = sc = 0;
		while(ax > 0)
		{
			mo = ax % 3;
			if(mo == 0)
				sa += v[con];
			else if(mo == 1)
				sb += v[con];
			else
				sc += v[con];
			con++;
			ax /= 3;
		}
		while(con < n)
			sa += v[con++];
		par[ind][can[ind]++] = {sa, sb, sc};
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n) cin>>ar[i];
	vector<ll> a, b;
	ll res = INF;
	if(n < 13)
	{
		fore(i, 0, n) a.pb(ar[i]);
		gen(a, 0);
		fore(i, 0, can[0])
		{
			sort(all(par[0][i]));
			res = min(res, par[0][i][2] - par[0][i][0]);
		}
		cout<<res<<'\n';
	}
	else
	{
		fore(i, 0, n / 2) a.pb(ar[i]);
		fore(i, n / 2, n) b.pb(ar[i]);
		gen(a, 0);
		gen(b, 1);
		fore(i, 0, can[0])
			pun[0][i] = {par[0][i][0] - par[0][i][1], par[0][i][1] - par[0][i][2]};
		fore(i, 0, can[1])
			pun[1][i] = {par[1][i][1] - par[1][i][0], par[1][i][2] - par[1][i][1]};
		set<pair<ll, ll>> st;
		set<pair<ll, ll>>::iterator it;
		sort(pun[0], pun[0] + can[0]);
		sort(pun[1], pun[1] + can[1]);
		int j = 0;
		fore(i, 0, can[0])
		{
			while(j < can[1] && pun[1][j].f <= pun[0][i].f)
			{
				it = st.lower_bound({pun[1][j].s, -INF});
				while(it != st.end() && (*it).f + (*it).s <= pun[1][j].f + pun[1][j].s)
					it = st.erase(it);
				st.insert({pun[1][j].s, pun[1][j].f});
				j++;
			}
			it = st.lower_bound({pun[0][i].s + 1, -INF});
			if(it != st.begin() && st.size() > 0)
			{
				it--;
				res = min(res, pun[0][i].f - (*it).s + pun[0][i].s - (*it).f);	
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	