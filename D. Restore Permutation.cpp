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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll tam = 100010;
const ll MOD = 1e9+7;
const double EPS = 1e-9;
ll bit[300000];
ll n;
void update(ll pos, ll val)
{
	pos++;
	while(pos <= n)
	{
		bit[pos] += val;
		pos += (pos & -pos);
	}
}
ll query(ll pos)
{
	pos++;
	ll res = 0;
	while(pos > 0)
	{
		res += bit[pos];
		pos -= (pos & -pos);
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n;
	ll ar[n];
	fore(i, 0, n) cin>>ar[i];
	ll su = 0;
	map<ll,ll> ma;
	ll sums[n+1];
	fore(i, 0, n+1) {
		ma[su] = i;
		sums[i] = su;
		su += i;
	}
	ll re[n];
	ll sus = 0;
	ll lo, hi, mid, res, rere, lolo, hihi, midi;
	for(ll i = n-1; i > -1; i--)
	{
		lolo = 1, hihi = n;
		//cout<<'\n';
		while(lolo <= hihi)
		{
			//cout<<'\n';
			midi = (lolo + hihi) / 2;
			//cout<<midi<<" midi\n";
			lo = 1, hi = midi, res = 0;
			//cout<<hi<<'\n';
			while(lo <= hi)
			{
				mid = (lo + hi) / 2;
				//cout<<mid<<'\n';
				//cout<<ar[i] + query(mid)<<' '<<sums[mid]<<'\n';
				if(ar[i] + query(mid) <= sums[mid])
					res = mid, hi = mid - 1;
				else
					lo = mid + 1;
			}
			//cout<<' '<<res<<'\n';
			if(res == 0)
			{
				lolo = midi + 1;
				continue;
			}
			if(ar[i] + query(res) == sums[res])
			{
				update(res, res);	
				break;
			}
			if(ar[i] + query(res) < sums[res])
				hihi =midi - 1;
			else
				lolo = midi +1;
		}
				re[i] = res;
	}
	int asd[n+1];
	mem(asd, 0);
	fore(i, 1, n) asd[re[i]] = 1;
	fore(i, 1, n+1) if(asd[i] == 0) re[0] = i;
	fore(i, 0, n)
	{
		if(i > 0) cout<<' ';
		cout<<re[i];
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2