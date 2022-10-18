#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	ll ta;
	cin>>n>>ta;
	pair<ll,ll> pre[n], suf[n];
	ll masu[n], mapre[n];
	ll res = 0;
	fore(i, 0, n)
	{
		cin>>pre[i].f>>pre[i].s;
		suf[n - i - 1] = pre[i];
		suf[n - i - 1].f = ta - suf[n - 1 - i].f;
	}
	ll acu1 = pre[0].s, acu2 = suf[0].s;
	mapre[0] = max(0ll, pre[0].s - pre[0].f);
	masu[0] = max(0ll, suf[0].s - suf[0].f);
	fore(i, 1, n)
	{
		mapre[i] = max(mapre[i-1], acu1 + pre[i].s - pre[i].f);
		acu1 += pre[i].s;
		masu[i] = max(masu[i-1], acu2 + suf[i].s - suf[i].f);
		acu2 += suf[i].s;
	}	
	res = max(res, max(mapre[n-1], masu[n-1]));
	fore(i, 0, n-1)
	{
		res = max(res, mapre[i] - pre[i].f + masu[n - i - 2]);
		res = max(res, masu[i] - suf[i].f + mapre[n - i - 2]);
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2