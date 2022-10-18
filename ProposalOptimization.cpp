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


class ProposalOptimization {
	ll ros[400][400];
	ll tul[400][400];
	ll cos[400][400];
	int n, m;
	pair<ll, ll> f(int x, int y, int k)
	{
		if(k < 0 || x == - 1 || y == -1) return {-1, 1};
		if(x == 0 && y == 0) return {0, 1};
		pair<ll, ll> a = f(x - 1, y, k - cos[x][y]),
			b = f(x, y - 1, k - cos[x][y]);
		if(a.f * b.s < a.s * b.f)
			swap(a, b);
		if(a.f == -1) return a;
		return {a.f + ros[x][y], (a.f == 0 ? 0 : a.s) + tul[x][y]};
	}
public:
	double bestPath(int R, int C, int K, vector <int> roses, vector <int> tulips, vector <int> costs) {
		n = R;
		m = C;
		cout<<roses.size()<<'\n';
		fore(i, 0, R)
		{
			fore(j, 0, C)
			{
				ros[i][j] = roses[i * C + j];
				tul[i][j] = tulips[i * C + j];
				cos[i][j] = costs[i * C + j];
				//cout<<')'<<ros[i][j]<<','<<tul[i][j]<<") ";
				//cout<<ros[i][j]<<','<<tul[i][j]<<' ';
			}
			//cout<<'\n';
		}
		pair<ll, ll> res = f(n - 1, m - 1, K);
		cout<<res.f<<' '<<res.s<<'\n';
		return 1.0 * res.f / res.s;	
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	return 0;
}
