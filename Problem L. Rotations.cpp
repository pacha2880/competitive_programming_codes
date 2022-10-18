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
bool is[32];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	ll x;
	int lim;
	ll po;
	int a;
	while(n--)
	{
		cin>>x;

			fore(i, 0, 5)
			{
				if((x & (1ll << (31))) > 0)
				{
					x *= 2;
					x++;
				}
				else
					x *= 2;
			}
			fore(i, 0, 32) is[i] = false;
			//cout<<po<<' '<<lim<<'\n';
			fore(i, 4, 37)
			{
				a = ((x & ((1ll << (i + 1)) - 1)) >> (i - 4));
				//cout<<a<<' ';
				is[a] = true;
			}
			//cout<<'\n';
			bool bo = true;
			fore(i, 0, 32)
			{
				//cout<<is[i]<<' ';
				bo &= is[i];
			}
			cout<<(bo ? "yes\n" : "no\n");
		
	}
	return 0;
}
