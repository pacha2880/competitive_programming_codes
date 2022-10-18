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
	const int tam = 500010;
	const int MOD = 1000000007;
	const int MOD1 = 998244353;
	const double EPS = 1e-9;
	const double PI = acos(-1); 
	pair<int, int> ar[tam];
	bool uns[tam], dios[tam];
	vector<int> cone[tam];
	int parent[tam];
	int find(int n)
	{
		if(parent[n] == -1) return n;
		return parent[n] = find(parent[n]);
	}
	void prop(int b)
	{
		fore(i, 0, cone[b].size())
		{
			if(!uns[cone[b][i]])
			{
				uns[cone[b][i]] = 1;
				prop(cone[b][i]);
			}
		}
		cone[b].clear();
	}
	int main()
	{
		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		//freopen("asd.txt", "r", stdin);
		//freopen("qwe.txt", "w", stdout);
		mem(parent, -1);
		int n, m;
		cin>>n>>m;
		int a, b, c;
		vector<int> res;
		fore(i, 0, n)
		{
			cin>>a>>b;
			if(a == 1)
			{
				if(!uns[b])
				{
					uns[b] = 1;
					prop(b);
					res.pb(i);
				}
			}
			else
			{
				cin>>c;
				if(find(b) != find(c) && (!uns[b] || !uns[c]))
				{
					if(uns[b])
					{
						uns[c] = 1;
						prop(c);
					}
					else if(uns[c])
					{
						uns[b] = 1;
						prop(b);
					}
					else
					{
						cone[b].pb(c);
						cone[c].pb(b);
					}
					b = find(b);
					c = find(c);
					if(b != c);
						parent[b] = c;
					res.pb(i);
				}
			}
		}
		ll po = 1;
		fore(i, 0, res.size())
			po = po * 2 % MOD;
		cout<<po<<' '<<res.size()<<'\n';
		sort(all(res));
		fore(i, 0, res.size())
		{
			if(i > 0) cout<<' ';
			cout<<res[i] + 1;
		}
		cout<<'\n';
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	