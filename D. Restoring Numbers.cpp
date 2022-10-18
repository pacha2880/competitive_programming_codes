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
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll resa[200], resb[200];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll n, m;
	cin>>n>>m;
	ll ar[n][m], ari[n][m];
	ll mod = -1;
	ll maxo = -1;
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			cin>>ar[i][j];
			maxo = max(maxo, ar[i][j]);
			if(i == 0)
			{
				resb[j] = ar[i][j];
			}
		}
	}
	resa[0] = 0;
	fore(i, 1, n)
	{
		ll pos = -1, neg = 1;
		fore(j, 0, m)
		{
			if(ar[0][j] > ar[i][j])
				neg = ar[i][j] - ar[0][j];
			else
				pos = ar[i][j] - ar[0][j];
		}
		if(pos != -1 && neg != 1)
		{
			mod = pos - neg;
			resa[i] = pos;
		}
		else if(pos != -1)
			resa[i] = pos;
		else
			resa[i] = neg;
	}
	if(mod == -1)
		mod = maxo + 1;
	fore(i, 0, n)
		if(resa[i] < 0)
			resa[i] += mod;
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			if(ar[i][j] != (resa[i] + resb[j]) % mod)
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n"<<mod<<'\n';
	fore(i, 0, n)
	{
		if(i > 0)
			cout<<' ';
		cout<<resa[i];
	}
	cout<<'\n';
	fore(i, 0, m)
	{
		if(i > 0)
			cout<<' ';
		cout<<resb[i];
	}
	cout<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	