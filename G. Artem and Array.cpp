#include <bits/stdc++.h>
// #include <ext/push_ds/assoc_container.hpp>
// #include <ext/push_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](ll a, ll b){ return a > b; });


using namespace std;
// using namespace __gnu_pushds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const ll tam = 500010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll ar[tam], pre[tam], suf[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	ll n;
	cin>>n;
	ll res = 0;
	pair<ll, ll> maxi(-1, 0);
	fore(i, 0, n)
	{
		cin>>ar[i];
		if(i == 0) pre[i] = ar[i];
		else pre[i] = max(pre[i - 1], ar[i]);
		maxi = max(maxi, mp(ar[i], i));
	}
	if(n <= 2)
	{
		cout<<0<<'\n';
		return 0;
	}
	suf[n - 1] = ar[n - 1];
	fore(i, 1, n)
		suf[n - i - 1] = max(suf[n - i], ar[n - i - 1]);
	queue<ll> le, ri;
	ll mi = MOD, su = 0;
	fore(i, maxi.s + 1, n - 1)
	{
		if(suf[i + 1] < suf[i])
		{
			if(mi != MOD)
				res += su - mi + ar[i];
			// cout<<suf[i]<<','<<su<<','<<mi<<' ';
			mi = MOD;
			su = 0;
			ri.push(suf[i]);
		}
		else
		{
			mi = min(mi, ar[i]);
			su += ar[i];
		}
	}
	if(maxi.s != n - 1)
	{
		if(mi != MOD)
		res += su - mi + ar[n - 1];
		ri.push(suf[n - 1]);
		// cout<<suf[n - 1]<<','<<su<<','<<mi<<'\n';
	}
	// else cout<<'\n';

	mi = MOD, su = 0;
	for(ll i = maxi.s - 1; i > 0; i--)
	{
		if(pre[i - 1] < pre[i])
		{
			if(mi != MOD)
				res += su - mi + ar[i];
			mi = MOD;
			su = 0;
			le.push(pre[i]);
			// cout<<pre[i]<<' ';
		}
		else
		{
			mi = min(mi, ar[i]);
			su += ar[i];
		}
	}
	if(maxi.s != 0)
	{
		if(mi != MOD)
		res += su - mi + ar[0];
		le.push(pre[0]);
		// cout<<pre[0]<<'\n';
	}
	// else cout<<'\n';
	// cout<<"hola "<<res<<'\n';
	if(sz(le) == 0 || sz(ri) == 0)
	{
		if(sz(le) == 0)
			swap(le, ri);
		le.pop();
		while(!le.empty())
		{
			// cout<<res<<'\n';
			res += le.front();
			le.pop();
		}
	}
	else{
		while(le.size() > 1 || ri.size() > 1)
		{
			// cout<<le.front()<<' '<<ri.front()<<'\n';
			res += min(le.front(), ri.front());
			if(le.size() == 1)
				ri.pop();
			else if(ri.size() == 1)
				le.pop();
			else if(le.front() > ri.front())
				le.pop();
			else
				ri.pop();
		}
		// cout<<le.front()<<' '<<ri.front()<<'\n';
		res += min(le.front(), ri.front());
	}
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
