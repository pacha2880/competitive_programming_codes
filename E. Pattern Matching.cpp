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
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
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
string su[tam];
ll pat[tam], s[tam];
int ar[tam];
vector<ll> gatos[tam];
bool vis[tam];
ll conv(string s)
{
	ll res = 0;
	ll mul = 1;
	fore(i, 0, s.size())
	{
		res += (s[i] == '_' ? 28 : s[i] - 'a') * mul;
		mul *= 30;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, k;
	cin>>n>>m>>k;
	set<ll> pats;
	vector<int> resa;
	vector<int> res;
	string s1, s2;
	map<ll, int> patos;
	fore(i, 0, n) {cin>>s1; pat[i] = conv(s1);}
	fore(i, 0, m) {cin>>su[i]; s[i] = conv(su[i]); cin>>ar[i]; ar[i]--; vis[ar[i]] = 1;}
	fore(i, 0, n)
	{
		if(!vis[i])
		{
			resa.pb(i);
		}
		else
			patos[pat[i]] = i;
	}
	map<ll, int> cuan;
	set<pair<int, ll>> cuant;
	map<ll, set<int>> ma;
	ll gato;
	string gata;
	int x;
	fore(i, 0, m)
	{
		fore(j, 0, (1<<k))
		{
			gata = su[i];
			fore(l, 0, k)
			{
				if((1<<l) & j)
					gata[l] = '_';
			}
			gato = conv(gata);
			if(patos.count(gato) != 0)
			{
				x = cuan[gato];
				if(ar[i] == patos[gato])
				{
					ma[gato].insert(i);
					cuant.insert({x, gato});
				}
				else
				{
					cuant.erase({x, gato});
					cuant.insert({x + 1, gato});
					cuan[gato]++;
				}
			}
			gatos[i].pb(gato);
		}
	}
	pair<int, ll> pa;
	// for(auto cat : cuant)
	// {
	// 	cout<<cat.f<<' '<<cat.s<<' '<<patos[cat.s]<<'\n';
	// }
	fore(i, 0, m)
	{
		// cout<<i<<'\n';
		if(cuant.size() == 0)
		{
			cout<<"NO\n";
			return 0;
		}
		pa = *cuant.begin();
		if(pa.f > 0)
		{
			cout<<"NO\n";
			return 0;
		}
		res.pb(patos[pa.s]);
		for(auto ind : ma[pa.s])
		{
			for(auto gato : gatos[ind])
			{
				if(ma.count(gato) && pat[ar[ind]] != gato)
				{
					x = cuan[gato];
					cuant.erase({x, gato});
					cuant.insert({x - 1, gato});
					cuan[gato]--;	
				}
			}
		}
		m -= ma[pa.s].size() - 1;
		cuant.erase(pa);
		ma[pa.s].clear();
	}
	cout<<"YES\n";
	fore(i, 0, res.size())
	{
		if(i > 0) cout<<' ';
		cout<<res[i] + 1;
	}
	fore(i, 0, resa.size())
	cout<<' '<<resa[i] + 1;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	