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
 
using ll = long long;
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

 
const ll INF = INT64_MAX;
const int inf = INT32_MAX;
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
    
}

void test_case() {
    ll n1,n2,m; cin >> n1 >>n2 >>m;
    vector<vector<ll>> adjL(n1), adjR(n2);
    for (int i =0;i<m;i++) {
        ll x, y;
        cin >> x >> y;x--,y--;
        adjL[x].pb(y);
        adjR[y].pb(x);
    }
    
    
    
    vector<ll> matchL(n1,-1), matchR(n2,-1);
    vector<ll> visL(n1), visR(n2);
    ll timer =1;
    ll f =0;
    auto try_kuhn = [&](ll x, auto &&try_kuhn)->bool {
        if (visR[x]==timer) return false;
        visR[x] = timer;
        for (auto y : adjR[x]) {
            if (matchL[y]==-1 || try_kuhn(matchL[y],try_kuhn)) {
                // if (matchR[x] != -1) {
                //     matchL[matchR[x]] = -1;
                // }
                matchL[y] = x;
                matchR[x] = y;
                return true;
            }
        }
        return false;
    };

    auto find = [&](ll x, ll limite, auto && find)->pair<ll,ll> {
        if (visL[x]==timer) return {1e18,false};
        visL[x] = timer;
        pair<ll,ll> fnd = {1e18,false};
        for (auto y : adjL[x]) {
            if (y < limite) continue;
            pair<ll,ll> nxt = {1e18,false};
            if (matchR[y] ==-1) {
                nxt = {y,true};
            } else  {
                nxt = find(matchR[y],limite,find);
            }
            fnd = min(fnd,nxt);
        }
        return fnd;
    };

    auto agumentar = [&](ll x, ll limite, ll objetivo, auto && agumentar)->bool {
        if (visL[x]==timer) return false;
        visL[x] = timer;
        for (auto y : adjL[x]) {
            if (y < limite) continue;
            if (y == objetivo || matchR[y] != -1 && agumentar(matchR[y], limite, objetivo, agumentar)) {
                matchL[x] = y;
                matchR[y] = x;
                return true;
            }
        }
        return false;
    };

    ll mod = 998244353;
    ll ans =0;
    auto mul = [&](ll x, ll y) {
        return (x*y)%mod;
    };

    auto add =[ &](ll x, ll y) {
        return (x+y)%mod;
    };

    vl cpmatchL, cpmatchR;
    ll cpf;

    // try approach upsolving without speedup with searching all augmeting paths
    vi pre(n2);
    for (int r = 0; r < n2; r++) {
        
        timer++;
        if(try_kuhn(r,try_kuhn)) f++;
        pre[r] = f;

    }
    vi sub(n2 + 1);
    vector<vi> subs(n2 + 1);
    for (int r = 0; r < n2 - 1;r++) {

        if (matchR[r] != -1) {
            int pareja = matchR[r];
            timer++;
            pair<ll, ll> hay = find(pareja,r+1,find);
            sub[r + 1]--;
            if(hay.S) {
                subs[r + 1].pb(hay.F);
                // sub[hay.F]++;
                // cout<<'#'<<r<<' '<<hay.F<<'\n';
                timer++;
                agumentar(pareja, r + 1, hay.F, agumentar);
            }
        }   

    }
    ans = 0;
    int au = 0;
    FOR(i, 0, n2){
        int val = pre[i];
        FOR(j, 0, i + 1){
            val += sub[j];
            for(int x : subs[j])
                if(i >= x)
                    val++;
            // cout<<i<<' '<<j<<' '<<val<<'\n';
            ans = add(ans,mul(mul(j+1,i+1),mul(((j+1)^(i+1))+1,val)));
        }
    }
    cout << ans << "\n";
}

