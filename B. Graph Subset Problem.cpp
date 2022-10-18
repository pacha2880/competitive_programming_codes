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
void solve()
{
	int n, m, k, a, b;
	cin>>n>>m>>k;
	vector<unordered_set<int>> ma(n + 1);
	vector<vector<int>> g(n + 1);
	vector<int> deg(n + 1);
	vector<bool> active(n + 1, true);
	while(m--)
	{
		cin>>a>>b;
		a--;
		b--;
		ma[a].insert(b);
		ma[b].insert(a);
		g[a].pb(b);
		g[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	set<pair<int, int>> st;
	fore(i, 0, n)
		st.insert({deg[i], i});
	int key;
	while(st.size())
	{
		key = st.begin()->s;
		st.erase(*st.begin());
		active[key] = 0;
		vector<int> vec;
		if(deg[key] >= k)
		{
			fore(i, 0, n) if(active[i] || key == i) vec.pb(i);
				cout<<"1 "<<sz(vec)<<"\n";
				fore(i, 0, vec.size())
				{
					if(i > 0) cout<<' ';
					cout<<vec[i] + 1;
				}
				cout<<'\n';
			return;
		}
		else if(deg[key] == k - 1)
		{
			for(int x : g[key])
			{
				if(active[x])
					vec.pb(x);
			}
			bool bo = true;
			fore(i, 0, k - 1)
			{
				a = vec[i];
				fore(j, i + 1, k - 1)
				{
					if(!ma[a].count(vec[j]))
					{
						bo = false;
						i = MOD;
						j = MOD;
					}
				}
			}
			if(bo)
			{
				cout<<"2\n";
				cout<<key + 1;
				for(int i = 0; i < k - 1; i++)
				{
					cout<<' '<<vec[i] + 1;
				}
				cout<<'\n';
				return;
			}
		}
		for(int x : g[key])
		{
			if(active[x])
			{
				st.erase({deg[x], x});
				deg[x]--;
				st.insert({deg[x], x});
			}
		}
	}
	cout<<"-1\n";
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--)
	{
		solve();
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	