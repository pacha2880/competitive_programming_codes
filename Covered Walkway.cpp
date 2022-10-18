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
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 988244353;
const double EPS = 1e-9;
const double PI = acos(-1);
int n;
ll c;
ll dp[1000010];
ll ar[1000010];
pair<ll, ll> bag[1000100];
ll calcost(pair<ll, ll> ca, ll to)
{
	return (to - ca.s) * (to - ca.s) + ca.f;
}
ll inter(pair<ll, ll> caca, pair<ll, ll> coco)
{
	ll lo = coco.s, hi = coco.s, mid, res;
	while(calcost(caca, hi) < calcost(coco, hi))
		lo = hi + 1, hi *= 2;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(calcost(caca, mid) >= calcost(coco, mid))
			res = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("curling.in", "r", stdin);
	//freopen("curling.out", "w", stdout);
	cin>>n>>c;
	fore(i, 0, n)
	cin>>ar[i];

	ll lapre = 0;
	pair<ll, ll> candi;
	int ini = 0, fini = 0;
	fore(i, 0, n)
	{
		candi = mp(lapre + c, ar[i]);
		while(fini - ini >= 2 && inter(bag[fini - 2], bag[fini -1]) >= inter(bag[fini - 1], candi))
			fini--;
		bag[fini++] = candi;
		while(fini - ini >= 2 && calcost(bag[ini], ar[i]) >= calcost(bag[ini + 1], ar[i]))
			ini++;
		lapre = calcost(bag[ini], ar[i]);
	}
	cout<<lapre<<'\n';
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2