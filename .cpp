#include <bits/stdc++.h>
 //#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/extc++.h>
typedef long long ll;
//#define int               long long
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(a)(a).begin(), (a).end()
#define clr(a, h) memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
    #define forr(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
        #define deb(x) cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x)(int) x.size()
#define endl '\n'
int faster_in() {
    int r = 0, c;
    for (c = getchar(); c <= 32; c = getchar());
    if (c == '-') return -faster_in();
    for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar());
    return r;
}

using namespace std;
//using namespace __gnu_pbds;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < ll > vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = numeric_limits < int > ::max() / 4;

vector < pair < ii, int >> segs;

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n, m, p;
    cin >> n >> m >> p;
    vi vala(m), lengu(m), valu(m), leng(m);
    fore(i, 0, m) {
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;
        vala[i] = c;
        leng[i] = lengu[i] = r - l + 1;
        segs.pb({
            {
                l,
                r
            },
            c
        });
    }
    vi res(n, 0);
    int cur = 0;
    vi par(m, -1);
    auto len = [ & ](int idx) {
        return segs[idx].first.second - segs[idx].first.first + 1;
    };
    // check none
    fore(i, 0, m) {
        int l = segs[i].first.first;
        int r = segs[i].first.second;
        ll val = segs[i].second;
        ll sum = 0;
        cur++;
        vii ch;
        fore(j, 0, m) {
            if (i == j) continue;
            int a = segs[j].first.first;
            int b = segs[j].first.second;
            if (l <= a && b <= r) {
                ch.pb({
                    a,
                    b
                });
                sum += segs[j].second;
                if (len(i) == len(j)){if(i > j) par[j] = i;}
                else if (par[j] == -1) par[j] = i;
                else if (len(i) < len(par[j])) par[j] = i;
            }
        }
    }
    fore(i, 0, m)
    {
        if(par[i] != -1)
        {
            valu[par[i]] += vala[i];
            lengu[par[i]] -= leng[i];
        }
    }
    fore(i, 0, m)
    {
        // cout<<i<<' '<<lengu[i]<<' '<<valu[i]<<' '<<vala[i]<<' '<<par[i]<<'\n';
        if(!lengu[i] && (valu[i] % p != vala[i] % p))
        {
            cout << "None" << endl;
            return 0;
        }

    }
    // asumimos que nigun rango intersecta raro
    vi index;
    fore(i, 0, m) index.pb(i);
    // sort(all(segs), [&](pair<ii, int> a, pair<ii, int> b) {
    //   int A = a.first.second - a.first.first + 1;
    //   int B = b.first.second - b.first.first + 1;
    //   return A < B;
    // });
    sort(all(index), [ & ](int i, int j) {
        auto a = segs[i];
        auto b = segs[j];
        int A = a.first.second - a.first.first + 1;
        int B = b.first.second - b.first.first + 1;
        return A < B;
    });
    auto updatePar = [ & ](int v, int val) {
        while (v == -1) {
            segs[v].second = (segs[v].second - val + 2 * p) % p;
            v = par[v];
        }
    };
    fore(idx, 0, m) {
        int i = index[idx];
        if (segs[i].second == 0) continue;
        for (int pos = segs[i].first.second; pos >= segs[i].first.first; --pos) {
            if (res[pos] == 0) {
                res[pos] = segs[i].second;
                updatePar(i, segs[i].second);
                break;
            }
        }
    }
    fore(i, 0, n) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
// Dinosaurs