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
const int tam = 100010;


class TheSocialNetwork {
	ll pot(ll b, ll e)
	{
		ll res = 1;
		while(e > 0)
		{
			if(e & 1) res = res * b % MOD;
			b = b * b %  MOD;
			e /= 2;
		}
		return res;
	}
	int parent[1010];
	pair<int, pair<int, int>> ar[1010];
	int find(int n)
	{
		if(parent[n] == -1) return n;
		return parent[n] = find(parent[n]);
	}
public:
	int minimumCut(int n, int m, vector <int> u, vector <int> v, vector <int> l) {
		fore(i, 0, m)
		{
			ar[i] = {l[i], {u[i] - 1, v[i] - 1}};
		}
		sort(ar, ar + m);
		reverse(ar, ar + m);
		ll res = 0;
		int can = 0, a, b;
		fore(i, 0, m)
		{
			a = find(ar[i].s.f);
			b = find(ar[i].s.s);
			if(a != b)
			{
				if(can == n - 2)
				{
					res = (res + pot(2, ar[i].f)) % MOD;
				}
				else
				{
					can++;
					parent[a] = b;
				}
			}
		}
		return res;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	return 0;
}
