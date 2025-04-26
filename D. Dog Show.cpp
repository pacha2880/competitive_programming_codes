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
    int n, t;
    cin>>n>>t;
    int res = 0;
    multiset<int> bilbo;
    fore(i, 1, n + 1)
    {
        int x;
        cin>>x;
        bilbo.insert(x - i);
        while(!bilbo.empty() && *--bilbo.end() + i >= t)
            bilbo.erase(--bilbo.end());
        if(i < t)
        res = max(res, sz(bilbo));
    }
    cout<<res<<'\n';
	return 0;
}