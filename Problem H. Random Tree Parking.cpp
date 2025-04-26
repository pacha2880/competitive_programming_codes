#include <bits/stdc++.h>
#define f           first
#define s           second
#define pb          push_back
#define int         long long
#define all(v)      v.begin(), v.end()
#define sz(v)       (int)v.size()
#define fore(a, b, c)   for(int a = b; a < c; a++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int tam = 200010;
const int MOD = 998244353;
vector<vi> dp[tam];
vi g[tam];
int pro[tam];
int fac[tam], facin[tam];
int pot(int b, int e)
{
    int res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
int f(int node, int pos, int regalo)
{
    if(dp[node][pos][regalo] != -1) return dp[node][pos][regalo];
    if(pos == 0)
    {
        if(g[node].empty())
            return dp[node][pos][regalo] = facin[regalo + 1];
        else
        {
            int res = 0;
            fore(i, 0, regalo + 2)
                res = (res + facin[i] * f(node, pos + 1, regalo + 1 - i)) % MOD;
            return dp[node][pos][regalo] = res;
        }
    }
    else if(pos == sz(g[node]))
        return dp[node][pos][regalo] = f(g[node][pos - 1], 0, regalo);
    else
    {
        int res = 0;
        fore(i, 0, regalo + 1)
            res = (res + f(g[node][pos - 1], 0, i) * f(node, pos + 1, regalo - i)) % MOD;
        return dp[node][pos][regalo] = res;
    }
}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    fac[0] = facin[0] = 1;
    fore(i, 1, tam)
    {
        fac[i] = fac[i - 1] * i % MOD;
        facin[i] = pot(fac[i], MOD -2);
    }
    fore(i, 1, n)
    {
        int x;
        cin>>x;
        // cout<<i<<' '<<x<<'\n';
        x--;
        g[x].pb(i);
        pro[i] = pro[x] + 1;
    }
    // cout<<"asdf\n";
    fore(i, 0, n)
        // cout<<i<<' '<<pro[i] + 1<<'\n',
        dp[i].assign(sz(g[i]) + 1, vi(pro[i] + 2, -1));
    //     cout<<"fefe\n";
    // cout<<"asdfasdf\n";
    cout<<f(0, 0, 0) * fac[n] % MOD<<'\n';
    return 0;
}