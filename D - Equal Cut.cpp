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
	ll val[3][200050];
	ll vol[3][200050];
	ll suf[200050];
	ll sufe;
	ll pre[200050];
	ll preme;
ll f(int mid)
{
	ll ma = max(pre[mid-1] - preme, val[0][mid]);
	ll mi = min(pre[mid-1] - preme, val[0][mid]);
	return ma - mi;
}
ll f1(int mid)
{
	ll ma = max(pre[mid+1] - preme, vol[0][mid]);
	ll mi = min(pre[mid+1] - preme, vol[0][mid]);
	return ma - mi;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	//cout<<abs(1e16)<<'\n'<<llabs(1e16);
	int n;
	cin>>n;
	ll ar[n];
	fore(i, 0, n) cin>>ar[i];
	int lo, hi, mid, res;
	val[0][n-1] = ar[n-1];
	for(int i = n-2; i > -1; i--)
		val[0][i] = val[0][i+1] + ar[i];
	pre[0] = ar[0];
	fore(i, 1, n) pre[i] = pre[i-1] + ar[i];
	fore(i, 0, n-1)
	{
		lo = i + 1, hi =  n-1, res = lo;
		preme = i > 0 ? pre[i-1] : 0;
		//cout<<i<<'\n';
		while(lo < hi)
		{
			mid = (lo + hi) / 2;
			//cout<<lo<<' '<<hi<<' '<<abs(pre[mid-1] - preme - val[0][mid])<<' '<<abs(pre[mid] - preme - val[0][mid + 1])<<'\n';
			if(f(mid) < f(mid+1))
			{
				if(f(mid) <= f(res))
				res = mid; hi = mid -1;
			}
			else
			{
				if(f(mid+1) <= f(res))
				res = mid + 1; lo = mid + 1;
			}
		}
		val[0][i] = val[0][res];
		val[1][i] = pre[res-1] - preme;
	}
	vol[0][0] = ar[0];
	for(int i = 1; i < n; i++)
		vol[0][i] = vol[0][i-1] + ar[i];
	pre[n-1] = ar[n-1];
	for(int i = n - 2; i > -1; i--) pre[i] = pre[i+1] + ar[i];
	for(int i = n-1; i > 0; i--)
	{
		hi = i - 1, lo =  0, res = hi;
		preme = i < n-1 ? pre[i+1] : 0;
		//cout<<i<<'\n';
		while(lo < hi)
		{
			mid = (lo + hi) / 2;
			//cout<<lo<<' '<<hi<<' '<<abs(pre[mid-1] - preme - val[0][mid])<<' '<<abs(pre[mid] - preme - val[0][mid + 1])<<'\n';
			if(f1(mid) < f1(mid-1))
			{
				if(f1(mid) <= f1(res))
				res = mid; lo = mid +1;
			}
			else
			{
				if(f1(mid-1) <= f1(res))
				res = mid - 1; hi = mid - 1;
			}
		}
		vol[0][i] = vol[0][res];
		vol[1][i] = pre[res+1] - preme;
	}
	ll re = 1e16;
	preme = 0;
	ll ma, mi;
	fore(i, 1, n-2)
	{
		
		ma = max(max(vol[0][i], vol[1][i]), max(val[0][i+1], val[1][i+1]));
		mi = min(min(vol[0][i], vol[1][i]), min(val[0][i+1], val[1][i+1]));
		re = min(re, ma - mi);
	}
	cout<<re<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2