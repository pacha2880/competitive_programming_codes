#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sortt(x) sort(all(x))
#define sq(a) ((a) * (a))
 
#define each(x, xs)  for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be) - ((be) > (en)); i != (en) - ((be) > (en)); i += 1 - 2 * ((be) > (en)))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
 
using ll = int;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<long long, long long, long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvl = vector<vl>;
using vpl = vector<pl>;
template<class T> using pql = priority_queue<T,vector<T>,greater<T>>;
template<class T> using pqg = priority_queue<T>;
 
// >>>>>>>>>> debugging >>>>>>>>>>
#ifdef NICO_LOCAL
    // #include "debug.h"
    #define LINE cerr << "-------------------" << endl;
#else
    #define deb(x...)
    #define LINE
#endif
// <<<<<<<<<< debugging <<<<<<<<<<
 
void test_case();

 
// const ll INF = INT64_MAX;
// const int inf = INT32_MAX;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;
const int DX[4]{1,0,-1,0}, DY[4]{0,1,0,-1};
 
int testId;

void init();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    T = 1;
    cin >> T;
    rep (t, 0, T) { testId++; test_case(); }
 
    return 0;
}

void init() {
    cout << fixed<< setprecision(8);    
}

const int SQRT = 550;

ll best[200001];
void lis(vector<int> &nums, ll st, ll end, auto onlylst, vector<int> &range) {
    range.clear();
    int ini = 0;
    if (end < st) {
        range.pb(0);
        return;
    }
    // vector<int> best;
    for (int i = st; i <= end; i++) {
        int idx = lower_bound(best, best + ini, nums[i]) - best;
        if (idx == ini) {
            best[ini++] = nums[i];
        } else {
            best[idx] = min((ll)best[idx], nums[i]);
        }
        if (!onlylst) range.pb(ini);
    }
    if (onlylst) range.pb(ini);
    // return range;
}

const int inf = 1e9;
// >>>>>>>>> Implement
struct Node { int mn = inf, mx = -inf; };

Node e() { return Node(); } // op(a, e()) = a
 
Node op(const Node &a, const Node &b) { // asociative property
    Node c;
    c.mn = min(a.mn, b.mn);
    c.mx = max(a.mx, b.mx);
    return c;
}
// <<<<<<<
 
struct segtree { 
    vector<Node> t;
    int n;
 
    void init(int n) {
        t.assign(n * 2, e());
        this->n = n;
    }
 
    void init(vector<Node>& s) {
        n = s.size();
        t.assign(n * 2, e());
        for (int i = 0; i < n; i++) t[i+n] = s[i];
        build();
    }
 
    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = op(t[i*2], t[i*2+1]);
    }
 
    // set value at position p
    void update(int p, const Node& value) {
        for (t[p += n] = value; p >>= 1; ) t[p] = op(t[p*2], t[p*2+1]);
    }
 
    // sum on interval [l, r]
    Node query(int l, int r) {
        r++; // make this inclusive
        Node resl=e(), resr=e(); // null element
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) resl = op(resl, t[l++]);
            if (r&1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
 
    Node get(int i) {
        return t[i+n];
    }
    
    // Maximum r that satisfy g(op(t[l], t[l+1], ..., t[r-1])) = True
    // if there's no g() that returns true, then r = l
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if (l == n) return n;
        ll size = n;
        l += size;
        Node sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, t[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, t[l]))) {
                        sm = op(sm, t[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, t[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    // If g is monotone, this is the minimum l that satisfies 
    // g(op(a[l], a[l + 1], ..., a[r - 1])) = true.
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        ll size = n;
        r += size;
        Node sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(t[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(t[r], sm))) {
                        sm = op(t[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(t[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

vector<vector<int>> blocklist(500,vl());
void test_case() {
    ll n, q; cin >> n >> q;
    blocklist.clear();
    segtree tree;
    tree.init(n);
    
    vector<int> nums(n);
    for( int i =0;i<n;i++) cin>>nums[i], tree.update(i,{nums[i],nums[i]});
    vector<ll> block(n);
    
    for (int i =0;i*SQRT<n;i++) {
        ll st = i*SQRT;
        ll end = n-1;

        lis(nums, st, end, false, blocklist[i]);
        
        for (int j = st; j < min(st+SQRT,n); j++) {
            block[j] = i;
        }
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--,r--;
        if (r-l+1<=SQRT+5) {
        // if (false) {
            vector<int> aux;
            lis(nums,l,r,true,aux);
            cout << aux.back() << "\n";
        } else {
            // cerr << "======================="<<endl;
            // cerr << "range " << l << " " << r << endl;
            
            if (block[l]*SQRT==l) {
                cout << blocklist[block[l]][r-block[l]*SQRT] << "\n";
                continue;
            }
            ll b = block[l]+1;
            ll start_block = b*SQRT;
            ll y =0;
            // if (b < blocklist.size() && start_block <= r) {
                // cout <<"using block "<<endl;
                y = blocklist[b][r-start_block];
            // } 

            vector<int> aux;
            lis(nums,l,min(start_block-1,r),true,aux);
            ll x = aux.back();
            // cerr << "look range x " << l << " " << min(start_block-1,r) <<endl; 

            auto left = tree.query(l,start_block-1);
            auto right = tree.query(start_block,r);

            int a = left.mn < right.mx;

            ll ans  = max(x,y) + (min(x,y)/2);
            // if (ans > 2) ans--;
            // ll real = lis(nums,l,r).back();
            // cerr << "x y " << x << " " << y <<endl;
            // cerr << "ans " << ans << endl;
            // cerr << "real " << real << endl;
            // ld ratio = max((1.0*ans)/real, (1.0*real)/ans);
            // cerr << "ratio " << ratio << endl;
            // assert(ratio <= 1.51);
            
            cout << max(ans,1+a) << "\n";
        }
    }
}

