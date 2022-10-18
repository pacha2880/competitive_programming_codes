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
bool dp[510][510];
bool vis[510][510];
int n, k;
bool lockos[510];
int ar[510];
vector<int> posos, pasas;
bool locko;
bool f(int pos, int su)
{
	//cout<<pos<<' '<<su<<'\n';
	if(lockos[pos]) return f(pos + 1, su);
	if(pos == n)
	{
		if(su == k)
		{
			if(locko)
			{
				pasas = posos;
				locko = false;
			}
			return true;	
		} 
		else
			return false;
	} 
	if(su > k) return false;
	if(vis[pos][su]) return dp[pos][su];
	vis[pos][su] = 1;
	posos.pb(pos);
	bool res = f(pos + 1, su + ar[pos]);
	posos.pop_back();
	bool ras = f(pos + 1, su);
	return ras || res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n>>k;
	int ax = k;
	fore(i, 0, n) cin>>ar[i];

	set<int> res;
	res.insert(0);
	double TLE = 0.9;
	double t = clock();
	while((clock() - t) / CLOCKS_PER_SEC < TLE)
	{		
		random_shuffle(ar, ar + n);
		fore(i, 1, ax)
		{
			locko = true;
			k = i;
			mem(vis, 0);
			if(f(0, 0))
			{
				//cout<<i<<'\n';
				for(auto a : pasas)
				{
					lockos[a] = 1;
					//cout<<ar[a]<<' ';
				}
				//cout<<'\n';
				k = ax - i;
				mem(vis, 0);
				if(f(0,0))
					{res.insert(i); res.insert(ax - i);}
				mem(lockos, 0);
			}
		}
	}
	res.insert(ax);
	cout<<res.size()<<'\n';
	for(auto a : res)
		cout<<a<<' ';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2