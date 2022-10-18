#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

//typedef long long 		;
typedef unsigned long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
int msb(ll a)
{
	int res = 0;
	while(a > 0)
	{
		a /= 2;
		res++;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--){
	int n,k;
	cin>>n>>k;
	ll ar[n];
	vector<ll> buckets[65];
	fore(i, 0, n) cin>>ar[i];
	fore(i, 0, n)
	{buckets[msb(ar[i])].pb(ar[i]);}
	ll represent[65];
	mem(represent, 0);
	for(int i = 64; i > 0; i--)
	{
		if(buckets[i].size())
		{
			represent[i] = buckets[i][0];
			fore(j, 1, buckets[i].size())
			buckets[msb(buckets[i][j] ^ buckets[i][0])].pb(buckets[i][j] ^ buckets[i][0]);
		}
	}
	ll ans = k;
	for(int i = 64; i > 0; i--)
	{
		ans = max(ans, ans ^ represent[i]);
	}
	cout<<ans<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2