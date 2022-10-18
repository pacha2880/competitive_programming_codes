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
string s[20000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int cas;
	cin>>cas;
		set<pair<pair<int, int>, int>> st;
	while(cas--)
	{
		int n, k;
		cin>>n>>k;
		string sa;
		int x;
		st.clear();
		fore(i, 0, n)
		{
			cin>>s[i]>>x;
			st.insert({{x, i}, x});
		}
		pair<pair<int, int>, int> pa;
		while(k--)
		{
			pa = *st.begin();
			st.erase(st.begin());
			cout<<pa.f.f<<' '<<s[pa.f.s]<<'\n';;
			st.insert({{pa.f.f + pa.s, pa.f.s}, pa.s});
		}
	}
	return 0;
}
