#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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

char resi[tam];
int ar[tam];
bool cmp(int a, int b)
{
	return resi[a] < resi[b];
}
int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t, a, b;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<int, vector<int>> ma;
		fore(i, 0, n)
		{
			resi[i] = 0;
			cin>>ar[i];
			ma[ar[i]].pb(i);
		}
		bool bo = false;
		for(auto x : ma)
		{
			if(x.s.size() > 2)
				bo = true;
			if(x.s.size() == 2)
			{
				resi[x.s[0]] = '1';
				resi[x.s[1]] = '2';
			}
		}
		if(bo)
		{
			cout<<0<<'\n';
			cout<<1;
			fore(i, 1, n)
				cout<<2;
			cout<<'\n';
			continue;
		}
		int res = 1<<30;
		fore(i, 1, 31)
		{
			// cout<<i<<'\n';
			ma.clear();
			fore(j, 0, n)
			{
				ma[ar[j]>>i].pb(j);
			}
			for(auto x : ma)
			{
				if(x.s.size() > 2)
				{
					bo = true;
					sort(all(x.s), cmp);
					if(x.s.size() == 3)
					{
						a = ar[x.s[0]] ^ ar[x.s[1]];
						b = ar[x.s[0]] ^ ar[x.s[2]];
						if(a > b)
						{
							res = min(res, a);
							resi[x.s[0]] = resi[x.s[1]];
						}
						else
						{
							res = min(res, b);
							resi[x.s[0]] = resi[x.s[2]];
						}
					}
					else
					{
						if((ar[x.s[0]]>>(i - 1)) != (ar[x.s[2]]>>(i - 1)))
							swap(x.s[0], x.s[1]);
						assert((ar[x.s[0]]>>(i - 1)) == (ar[x.s[2]]>>(i - 1)));
						assert((ar[x.s[1]]>>(i - 1)) == (ar[x.s[3]]>>(i - 1)));
						a = min(ar[x.s[0]] ^ ar[x.s[1]], ar[x.s[2]] ^ ar[x.s[3]]);
						b = min(ar[x.s[0]] ^ ar[x.s[3]], ar[x.s[2]] ^ ar[x.s[1]]);
						if(a > b)
							res = min(res, a);
						else
						{
							res = min(res, b);
							swap(resi[x.s[0]], resi[x.s[2]]);
						}
					}
				}
				if(x.s.size() == 2)
				{
					resi[x.s[0]] = '1';
					resi[x.s[1]] = '2';
				}
			}
			if(bo)
				break;
		}
		cout<<res<<'\n';
		fore(i, 0, n)
			cout<<(resi[i] == 0 ? '1' : resi[i]);
		cout<<'\n';

	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	