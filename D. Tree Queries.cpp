#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long power(long long a, long long b, long long mod) {
    long long res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
long long modinv(long long a, long long mod) { return power(a, mod - 2, mod); }

// ---- BIT ----
struct BIT {
    int n;
    vector<long long> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void update(int i, long long v) { // 1-indexed
        for (i++; i <= n; i += i & -i) t[i] = (t[i] + v) % MOD;
    }
    long long query(int i) { // prefix sum [0..i]
        long long s = 0;
        for (i++; i > 0; i -= i & -i) s = (s + t[i]) % MOD;
        return s;
    }
    long long range(int l, int r) { // [l..r]
        if (l > r) return 0;
        return (query(r) - (l ? query(l - 1) : 0) + MOD) % MOD;
    }
};

const int MAXN = 150005;
int n, q;
vector<int> adj[MAXN];
int sz[MAXN], par[MAXN], depth[MAXN], heavy[MAXN];
int pos_hld[MAXN], top_hld[MAXN], node_at[MAXN];
int timer_hld = 0;
long long D[MAXN]; // sum of d for queries at v
long long global_sum = 0;

void dfs_sz(int v, int p, int d) {
    par[v] = p; depth[v] = d; sz[v] = 1; heavy[v] = -1;
    int max_sz = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs_sz(u, v, d + 1);
        sz[v] += sz[u];
        if (sz[u] > max_sz) { max_sz = sz[u]; heavy[v] = u; }
    }
}

void dfs_hld(int v, int t) {
    top_hld[v] = t;
    pos_hld[v] = timer_hld;
    node_at[timer_hld] = v;
    timer_hld++;
    if (heavy[v] != -1) dfs_hld(heavy[v], t);
    for (int u : adj[v]) {
        if (u == par[v] || u == heavy[v]) continue;
        dfs_hld(u, u);
    }
}

long long path_sum_B(BIT& B, int w) {
    long long res = 0;
    while (w != -1) {
        int t = top_hld[w];
        res = (res + B.range(pos_hld[t], pos_hld[w])) % MOD;
        w = par[t];
    }
    return res;
}

long long path_T3(BIT& C, int w) {
    long long res = 0;
    while (w != -1) {
        int t = top_hld[w];
        // Heavy contributions in [t+1, w] positions
        if (pos_hld[t] + 1 <= pos_hld[w]) {
            res = (res + C.range(pos_hld[t] + 1, pos_hld[w])) % MOD;
        }
        // Light jump: t is light child of par[t]
        if (par[t] != -1) {
            long long contrib = (long long)(n - sz[t]) % MOD * D[par[t]] % MOD;
            res = (res + contrib) % MOD;
        }
        w = par[t];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Root at 1
    dfs_sz(1, -1, 0);
    dfs_hld(1, 1);
    
    long long inv_n = modinv(n, MOD);
    BIT B(n), C(n);
    
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int v; long long d; cin >> v >> d;
            global_sum = (global_sum + d % MOD * (sz[v] % MOD)) % MOD;
            D[v] = (D[v] + d) % MOD;
            B.update(pos_hld[v], d % MOD * (sz[v] % MOD) % MOD);
            if (heavy[v] != -1) {
                long long val = d % MOD * ((n - sz[heavy[v]]) % MOD) % MOD;
                C.update(pos_hld[heavy[v]], val);
            }
        } else {
            int w; cin >> w;
            long long T1 = global_sum % MOD * inv_n % MOD;
            long long T2 = (MOD - path_sum_B(B, w) % MOD * inv_n % MOD) % MOD;
            long long T3 = path_T3(C, w) % MOD * inv_n % MOD;
            long long T4 = D[w];
            long long ans = (T1 + T2 + T3 + T4) % MOD;
            cout << ans << "\n";
        }
    }
    return 0;
}