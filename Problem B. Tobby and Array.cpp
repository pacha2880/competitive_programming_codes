#include <bits/stdc++.h>
#define mp					make_pair
#define pb					push_back
#define f 					first
#define s 					second
#define sz(a)				a.size()
#define fore(i, b, e)		for(int i = b; i < e; i++)
#define forn(i, n)			for(int i = 0; i < n; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
using namespace std;
typedef long long 		ll;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int ar[1000010];
vector<int> t[4000040];
vector<int> merge(vector<int> &a, vector<int> &b)
{
	int sa = a.size(), sb = b.size();
	int n = a.size() + b.size(), pa = 0, pb = 0;
	vector<int> res(n);
	fore(i, 0, n)
	{
		if(pa < sa)
		{
			if(pb < sb)
			{
				if(a[pa] < b[pb])
					res[i] = a[pa++];
				else
					res[i] = b[pb++];
			}
			else
				res[i] = a[pa++];
		}
		else
			res[i] = b[pb++];
	}
}
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node].pb(ar[b]);
	}
	int mid = (b + e) / 2, l = 2 * node + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = merge(t[l], t[r]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	return 0;
}
