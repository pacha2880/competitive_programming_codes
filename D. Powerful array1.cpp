#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](ll a, ll b){ return a > b; });


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
const ll tam = 400010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<pair<int, int>, int> qwe[200020];
ll res[200020];
int frec[1000010];
int ar[200030];
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if(a.f.f / 450 == b.f.f / 450)
		return a.f.s < b.f.s;
	return a.f.f < b.f.f;
}
ll rus;
void add(ll x)
{
	rus -= x * frec[x] * frec[x];
	frec[x]++;
	rus += x * frec[x] * frec[x];
}
void sub(ll x)
{
	rus -= x * frec[x] * frec[x];
	frec[x]--;
	rus += x * frec[x] * frec[x];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	int m, a, b;
	cin>>n>>m;
	fore(i, 0, n) cin>>ar[i];
	fore(i, 0, m)
	{
		cin>>a>>b;
		qwe[i] = {{a - 1, b - 1}, i};
	}
	sort(qwe, qwe + m, comp);
	rus = ar[0];
	int l = 0, r = 0, x, y;
	frec[ar[0]] = 1;

	fore(i, 0, m)
	{
		x = qwe[i].f.f;
		y = qwe[i].f.s;
		while(l > x)
		{
			l--;
			add(ar[l]);
		}
		while(r < y)
		{
			r++;
			add(ar[r]);
		}
		while(l < x)
		{
			sub(ar[l]);
			l++;
		}
		while(r > y)
		{
			sub(ar[r]);
			r--;
		}
		res[qwe[i].s] = rus;
	}
	fore(i, 0, m) cout<<res[i]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	