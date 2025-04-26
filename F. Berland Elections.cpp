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
    int n, k, m, a;
    cin>>n>>k>>m>>a;
    vi fu(n), la(n);;
    fore(i, 0, a)
    {
        int x;
        cin>>x;
        la[x - 1] = i;
        fu[x-1]++;
    }
    vector<vi> frac(n);
    fore(i, 0, n) frac[i] = {fu[i], -la[i], i};
    sort(all(frac));
    // fore(i, 0, n) cout<<frac[i][0]<<' '<<frac[i][1]<<' '<<frac[i][2] + 1<<'\n';
    int su = 0;
    vi res(n);
    // cout<<m - a<<'\n';
    fore(i, 0, n)
    {
        // cout<<su<<'\n';
        // cout<<frac[i][2] + 1<<' '<<frac[i][0] + 1<<' '<<i - (n - k - 1)<<'\n';
        if(frac[i][0] > 0 && (n == k || n - k <= i && (frac[i][0] + 1) * (i - (n - k - 1)) - su > m - a))
            res[frac[i][2]] = 1;
        else if(n - k > i && frac[n - k][0] + 1 - frac[i][0] > m - a)
            res[frac[i][2]] = 3;
        else
            res[frac[i][2]] = 2;
        if(frac[i][0] == 0 && m == a)
            res[frac[i][2]] = 3;
        if(n - k - 1 <= i)
            su += frac[i][0];
    }
    fore(i, 0, n)
        cout<<res[i]<<' ';
    cout<<'\n';
	return 0;
}