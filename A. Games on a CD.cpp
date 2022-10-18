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
ll pot(ll b, ll e , ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
struct Hash
{
	int p = 997, m[2], in[2];
	vector<int> h[2], inv[2];
	Hash(string s)
	{
		m[0] = 998244353, m[1] = 1000000009;
		fore(i, 0, 2)
		{
			in[i] = pot(p, m[i] - 2, m[i]);
			h[i].resize(s.size() + 1);
			inv[i].resize(s.size() + 1);
			ll acu = 1;
			h[i][0] = 0, inv[i][0] = 1;
			fore(j, 0, s.size())
			{
				h[i][j + 1] = (h[i][j] + acu * s[j]) % m[i];
				inv[i][j + 1] = (1ll * inv[i][j] * in[i]) % m[i];
				acu = (acu * p) % m[i];
			}
		}
	}
	ll get(int b, int e)
	{
		ll ha[2];
		fore(i, 0, 2)
			ha[i] = ((((h[i][e] - h[i][b]) * (ll)inv[i][b]) % m[i]) + m[i]) % m[i];
		return ((ha[0] << 32) | ha[1]);
	}
};
int res[1000010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	s += s;
	//cout<<s<<'\n';
	Hash hs(s);
	int g;
	cin>>g;
	map<ll, int> ma;
	string sa;
	fore(i, 1, g + 1)
	{
		cin>>sa;
		Hash te(sa);
		ma[te.get(0, k)] = i;
		//cout<<te.get(0, k)<<'\n';
	}
	int con;
	ll val;
	fore(i, 0, k)
	{
		set<ll> che;
		con = 0;
		fore(j, 0, n)
		{
			val = hs.get(j * k  + i, j * k + k + i);
			//cout<<val<<' '<<j * k  + i<<' '<<j * k + k + i<<'\n';
			if(ma.count(val) && che.count(val) == 0)
			{
				che.insert(val);
				res[con++] = ma[val];
			}
		}
		if(con == n)
		{
			cout<<"YES\n";
			fore(i, 0, n)
			{
				if(i > 0) cout<<' ';
				cout<<res[i];
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	