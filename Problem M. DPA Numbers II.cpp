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
const int tam = 1000010;
vector<int> pri;
vector<ll> pric;
bitset<tam> bi;
void criba()
{
	bi.set();
	fore(i, 2, tam)
	{
		if(bi[i])
		{
			forg(j, i, tam, i)
				bi[j] = 0;
			pri.pb(i);
			pric.pb(1ll * i * i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	criba();
	int n;
	ll x;
	ll res;
	ll tu;
	cin>>n;
	ll back;
	while(n--)
	{
		cin>>x;
		back = x;
		res = 1;
		for(int i = 0; pric[i] <= x; i++)
		{
			if(x % pri[i] == 0)
			{
				tu = pri[i];
				while(x % pri[i] == 0)
				{
					x /= pri[i];
					tu *= pri[i];
				}
				//cout<<pri[i]<<','<<tu<<' ';
				tu--;
				tu /= pri[i] - 1;
				res *= tu;
			}
		}
		//cout<<res<<','<<x<<' ';
		if(x > 1) res = res * (x + 1);
		res -= back;
		ll su = res;
		//cout<<res<<' ';
		if(su < back)
			cout<<"deficient\n";
		else
			if(su == back)
				cout<<"perfect\n";
			else
				cout<<"abundant\n";
	}
	return 0;
}
