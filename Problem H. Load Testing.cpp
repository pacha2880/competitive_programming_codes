#include<bits/stdc++.h>
#define int     long long
#define f 		first
#define s 		second
#define pb      push_back
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
    int n;
    cin>>n;
    vi ar(n);
    fore(i, 0, n) cin>>ar[i];
    vi mama(n), costus(n);
    mama[n - 1] = ar[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        costus[i] = costus[i + 1];
        if(ar[i] <= mama[i + 1])
            mama[i] = mama[i + 1] + 1, costus[i] += mama[i] - ar[i];
        else
            mama[i] = ar[i];
    }
    int res = costus[0];
    int mamei = ar[0], coses = 0;
    // cout<<res<<'\n';
    fore(i, 1, n)
    {
        if(ar[i] <= mamei)
        {
            mamei++;
            if(mama[i] <= mamei)
                res = min(res, coses + mamei - mama[i] + costus[i]);
            else
                res = min(res, coses + costus[i]);
            coses += mamei - ar[i];

        }
        else if(i < n - 1)
            res = min(res, coses + costus[i]);
        mamei = max(mamei, ar[i]);
    }
    // cout<<coses<<'\n';
    res = min(res, coses);
    cout<<res<<'\n';
	return 0;
}