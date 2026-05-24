#include <bits/stdc++.h>
#define int ll
#define pb push_back
#define fore(i,b,e) for(int i=b;i<e;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MOD = 1e9+7;
const int tam = 100010;

vi g[tam];
int n;
int dp[tam];
int res[tam];

int pw(int a, int b){ int r=1; a%=MOD; while(b>0){if(b&1)r=r*a%MOD;a=a*a%MOD;b>>=1;} return r; }
int inv(int a){ return pw(a, MOD-2); }

void dfs(int u, int pa = -1){
    dp[u] = 1;
    bool hoja = true;
    for(int x : g[u]) if(x != pa){
        dfs(x, u);
        hoja = false;
        dp[u] = dp[u] * dp[x] % MOD;
    }
    if(hoja) return;
    dp[u] = dp[u] * 2 % MOD;
}

void dfs2(int u, int pa = -1, int extra = 1){
    int tot = extra;
    for(int x : g[u]) if(x != pa){
        tot = tot * dp[x] % MOD;
    }
    res[u] = tot * 2 % MOD;
    for(int x : g[u]) if(x != pa){
        dfs2(x, u, pa == -1  && g[u].size() == 1 ? 1 : tot * inv(dp[x]) * 2 % MOD);
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(n == 1) {
        cout<<1<<'\n';
        return 0;
    }
    fore(i, 0, n-1){
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0);
    dfs2(0);
    int ans = 0;
    fore(i, 0, n) ans = (ans + res[i]) % MOD;
    cout << ans << '\n';
}