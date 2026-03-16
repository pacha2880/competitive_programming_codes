#include <bits/stdc++.h>
#define int long long
#define ll long long
#define sz(x) (x).size()
#define forn(i,n) for(int i = 0; i < n; i++)
#define fore(i,a,n) for(int i = a; i < n; i++)
#define INF 2e18
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define fast_cin ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll mod = 998244353;

long long mult(long long x, long long y) {
    return (x*y)%mod;
}

struct Vertex{
    int l, r;   // indices
    ll sum;
    ll mul;
};

static const int MAXNODES = 4000000; // ajusta si hace falta
Vertex t[MAXNODES];
int cont = 0;

int new_node(int l, int r, ll sum, ll mul){
    ++cont;
    t[cont].l = l;
    t[cont].r = r;
    t[cont].sum = sum;
    t[cont].mul = mul;
    return cont;
}

int build(int tl, int tr){
    if(tl == tr){
        return new_node(0, 0, 0, 1); // (sum=0, mul=1)
    }
    int tm = (tl+tr)/2;
    int L = build(tl, tm);
    int R = build(tm+1, tr);
    ll s = t[L].sum + t[R].sum;
    ll m = (t[L].mul* t[R].mul) % mod;
    return new_node(L, R, s, m);
}

ll get_sum(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && tr == r) return t[v].sum;
    int tm = (tl+tr)/2;
    return get_sum(t[v].l, tl, tm, l, min(r, tm))
         + get_sum(t[v].r, tm+1, tr, max(l, tm+1), r);
}

ll get_mul(int v, int tl, int tr, int l, int r){
    if(l > r) return 1;
    if(l == tl && tr == r) return t[v].mul;
    int tm = (tl+tr)/2;
    return (
        get_mul(t[v].l, tl, tm, l, min(r, tm)) *
        get_mul(t[v].r, tm+1, tr, max(l, tm+1), r)
    ) % mod;
}

int update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        // sum = new_val - 1, mul = new_val
        return new_node(0, 0, new_val - 1, new_val);
    }
    int tm = (tl+tr)/2;
    int L = t[v].l;
    int R = t[v].r;
    if(pos <= tm) L = update(L, tl, tm, pos, new_val);
    else          R = update(R, tm+1, tr, pos, new_val);

    ll s = 0;
    ll m = 1;
    if(L){ s += t[L].sum; m = (m * t[L].mul) % mod; }
    if(R){ s += t[R].sum; m = (m* t[R].mul) % mod; }
    return new_node(L, R, s, m);
}

// wrappers (igual que antes)
int build(ll n){
    return build(0, n-1);
}
ll get_sum(int root, ll n, int l, int r){
    return get_sum(root, 0, n-1, l, r);
}
ll get_mul(int root, ll n, int l, int r){
    return get_mul(root, 0, n-1, l, r);
}
int update(int root, ll n, int pos, int newV){
    return update(root, 0, n-1, pos, newV);
}

ll pot(ll x, ll y) {
    if (y==0) return 1;
    ll ans = pot(x,y/2);
    ans = (ans *ans) % mod;
    if (y&1) ans = (ans*x)%mod;
    return ans;
}
ll inv(ll x) {
    return pot(x,mod-2);
}

signed main(){
    fast_cin;

    ll n, q; cin >> n >> q;

    vector<pair<ll,ll>> orden(n);
    vector<ll> nums(n);

    for (int i =0;i<n;i++) {
        cin >> nums[i];
        orden[i] = {nums[i],i};
    }

    sort(all(orden));

    vector<int> sumseg(n+6, 0);
    sumseg[0] = build(n);

    for (int i = 0;i<n;i++) {
        ll idx = orden[i].second;
        ll v = orden[i].first;
        sumseg[i+1] = update(sumseg[i], n, idx, v);
    }

    auto query = [&](ll l, ll r, ll k)->ll {
        ll left = 0;
        ll right = n;
        ll ans = 0;

        if (get_sum(sumseg[n], n, l, r) <= k) {
            left = right = n;
            ans = n;
        }
        if (get_sum(sumseg[1], n, l, r) > k) {
            left = right = 0;
            ans = 0;
        }
        while (left <= right) {
            ll mid = (left + right) >> 1;
            if (get_sum(sumseg[mid], n, l, r) <= k) {
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        ll extra = k - get_sum(sumseg[ans], n, l, r);

        ll mul = get_mul(sumseg[n], n, l, r);
        mul = (mul* inv(get_mul(sumseg[min(ans+1,n)], n, l, r))) % mod;

        if (ans < (ll)orden.size()) {
            mul = (mul * max(1ll, orden[ans].first - extra)) % mod;
        }
        return mul;
    };

    while (q--) {
        ll l, r, k; cin >> l >> r >> k;
        l--, r--;
        cout << query(l, r, k) << "\n";
    }

    return 0;
}
