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
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
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
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<vi> ar;
int mau[tam];
int ma(int i)
{
	if(mau[i] == -1)
		for(int x : ar[i])
			mau[i] = max(mau[i], x);
	return mau[i];
}
int sus[12][5000], dp[12][5000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		fore(i, 0, m)
			mau[i] = -1;
		ar.assign(m, vi(n));
		fore(i, 0, n)
			fore(j, 0, m) 
				cin>>ar[j][i];
		fore(i, 0, n)
		{
			fore(j, i, m)
			{
				if(ma(i) < ma(j))
				{
					swap(mau[i], mau[j]);
					swap(ar[i], ar[j]);
				}
			}
		}
		mem(sus, 0);
		mem(dp, 0);
		int tot = (1 << n) - 1, sa, anti;
		fore(i, 0, min(n, m))
		{
			fore(j, 0, tot + 1)
			{
				fore(k, 0, n)
				{
					sa = 0;
					fore(l, 0, n)
						if(j & (1 << l))
							sa += ar[i][(l + k) % n];
					sus[i][j] = max(sus[i][j], sa);
				}
				// cout<<i<<' ';
				string s = "";
				int ux = j;
				while(ux > 0)
				{
					s += (char)(ux%2 + '0');
					ux /= 2;
				}
				reverse(all(s));
				// cout<<s<<' '<<sus[i][j]<<'\n';
				dp[i][j] = max(dp[i][j], sus[i][j]);
				if(i > 0)
				{
					anti = tot ^ j;
					for(int mask = anti; mask > 0; mask = (mask - 1) & anti)
					{
						// cout<<mask<<' '<<dp[i - 1][mask]<<'\n';
						dp[i][mask|j] = max(dp[i][mask|j], sus[i][j] + dp[i - 1][mask]);			
					}
				}
				// cout<<'#';
			}
		}
		// cout<<"-------";
		cout<<dp[min(n, m) - 1][tot]<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil