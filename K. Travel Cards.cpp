#include<bits/stdc++.h>
#define int     long long
#define f 		first
#define s 		second
#define pb      push_back
#define all(v)  v.begin(), v.end()
#define index   int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define sz(v) 	(int)v.size()
#define fore(i, b, e)   for(int i = b; i < e; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int tam = 200010;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b, k, f;
    cin>>n>>a>>b>>k>>f;
	string lalo = "1233\n";
	map<pair<string, string>, int> ma;
	int res = 0;
	fore(i, 0, n)
	{
		string sa, sb;
		cin>>sa>>sb;
        string ax = sb;
		if(sa == lalo)
		{
			if(sa > sb)
				swap(sa, sb);
			ma[{sa, sb}] += b;
            res += b;
		}
		else
		{
			if(sa > sb)
				swap(sa, sb);
			ma[{sa, sb}] += a;
            res += a;
		}
        lalo = ax;
	}
    // cout<<res<<'\n';
	vi cucu;
	for(auto cat : ma)
		cucu.pb(cat.s);
	sort(all(cucu), greater<>());
	fore(i, 0, min(k, sz(cucu)))
	{
        // cout<<cucu[i]<<' '<<f<<'\n';
		if(cucu[i] > f)
			res -= cucu[i] - f;
	}
	cout<<res<<'\n';
	return 0;
}