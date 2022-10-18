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
	int n, x;
	cin>>x;
	int  su;
	while(x--)
	{
		cin>>n;
		su = 1;
		for(int i = 2; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				su += i;
				if(i * i != n)
					su += n / i;
			}
		}
		if(su < n)
			cout<<"deficient\n";
		else
			if(su == n)
				cout<<"perfect\n";
			else
				cout<<"abundant\n";
	}
	return 0;
}
