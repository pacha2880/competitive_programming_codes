#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define EPS			1e-9
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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin>>ar[i];
	sort(ar, ar + n);
	vi nar;
	nar.pb(ar[0]);
	for(int i = 1; i < n; i++)
		if(ar[i] != nar[nar.size()-1]) nar.pb(ar[i]);
	if(nar.size() == 1)
		cout<<0;
	else
	{
		int res = 0, si = nar.size(), lo, hi, mid, po, ax;
		for(int i = 0; i < si-1; i++)
		{
			ax = nar[i];
			while(nar[i] < nar[si-1])
			{
				nar[i] += ax;
				lo = i + 1, hi = si - 1, po = -1;
				while(lo <= hi)
				{
					mid = (hi+lo)/2;
					if(nar[mid] < nar[i])
						lo = mid + 1, po = mid;
					else
						hi = mid - 1;
				}
				if(po != -1)
					res = max(res, nar[po] % ax);
			}
		}
		cout<<res;
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS