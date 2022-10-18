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


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	ll x;
	fore(i, 0, n)
	{
		cin>>x;
		cout<<(x + 1) * (x + 1) - 1<<'\n';
	}
	return 0;
}
