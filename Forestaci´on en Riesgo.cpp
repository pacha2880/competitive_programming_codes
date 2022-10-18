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
ll cal(pair<ll, pair<ll, ll>> pe, ll x)
{
	return pe.f * (x - pe.s.f) + pe.s.s;
}
ll mayu;
ld supe(pair<ll, pair<ll, ll>> pe, pair<ll, pair<ll, ll>> pa)
{
	pe.s.s -= pe.f * pe.s.f;
	pa.s.s -= pa.f * pa.s.f;
	return ((ld)pe.s.s - (ld)pa.s.s) / ((ld)pa.f - (ld)pe.f);
}
pair<ll, pair<ll, ll>> ar[1000010];
pair<ll, pair<ll, ll>> hull[1000010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	ll ma = 0;
	fore(i, 0, n) 
	{
		cin>>ar[i].f>>ar[i].s.f>>ar[i].s.s;
		ma = max(ma, ar[i].f);
	}
	mayu = 2 * ma;
	fore(i, 0, n)
		ar[i].f = ma - ar[i].f;
	sort(ar, ar + n);
	ll prev = 0;
	int ri = 1, le = 0;
	ld a, b;
	hull[0] = mp(0, mp(0, 0));
	pair<ll, pair<ll, ll>> neo;
	fore(i, 0, n)
	{
		while(ri - le > 1)
		{
			if(cal(hull[le], ar[i].f) < cal(hull[le + 1], ar[i].f))
				le++;
			else
				break;
		}
		neo = mp(ar[i].s.f, mp(ar[i].f, cal(hull[le], ar[i].f) - ar[i].s.s));
		while(ri - le > 1)
		{
			if(supe(hull[ri-1], neo) < supe(hull[ri-2], hull[ri-1]))
				ri--;
			else
				break;
		}
		hull[ri++] = neo;
	}
	ll res = 0;
	fore(i, le, ri)
	{
		res = max(res, cal(hull[i], ma));
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2