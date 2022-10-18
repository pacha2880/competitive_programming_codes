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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll c1[tam * 3],c2[tam * 3];  // tam must be power of 2 !!
void fht(ll* p, int n, bool inv){
	for(int l = 1; 2 * l <= n; l *= 2)
	for(int i = 0; i < n; i += 2 * l)
	fore(j, 0, l)
	{
		ll u = p[i + j], v = p[i + l + j];
		//if(!inv) p[i + j] = u + v, p[i + l + j] = u - v; // XOR
		//else p[i + j] = (u + v) / 2,p[i + l + j] = (u - v) / 2;
		if(!inv) p[i + j] = v, p[i + l + j] = u + v; // AND
		else p[i + j] = -u + v, p[i + l + j] = u;
		//if(!inv) p[i + j] = u + v, p[i + l + j] = u; // OR
		//else p[i + j] = v, p[i + l + j] = u - v;
	}
}
void fht(vector<ll>& p, bool inv)
{
    fore(i, 0, sz(p)) c1[i] = p[i];
    fht(c1, sz(p), inv);
    fore(i, 0, sz(p)) p[i] = c1[i];
}
int ar[1000100];
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	vector<ll> v(1000001, 0);
	while(sz(v) & (sz(v) - 1)) v.pb(0);
	int sa = v.size();
	int a;
	fore(i, 0, n) {cin>>a; v[a] = 1;}
	fht(v, 0);
	fore(i, 0, sa) v[i] = pot(v[i], n);
	fht(v, 1);
	int res = 0;
	v[0] = 1;
	fore(i, 0, sa) res += v[i] != 0;
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	