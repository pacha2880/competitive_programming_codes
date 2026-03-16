#include <bits/stdc++.h>
using namespace std; 

#define int long long
#define double long double
#define reze ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int INF = 1e18;

const int N = 40;
set<int> grafo[N];
vector<int> dp(N), vis(N);
void solve() {
    int n; cin>>n;
    int tapi = 0;
    auto f = [&](int i, auto &&f) -> int {
        if (vis[i]) return dp[i];
        int res = 1;
        vis[i] = 1;
        for (auto &x: grafo[i]) res += f(x,f);
		// cout<<"#"<<i<<' '<<res<<'\n';
        return dp[i] = res;
    };
    auto ask = [&](int k) {
        int n; vector<int> v;
        cout<<"? "<<k<<endl;
        n; cin>>n; 
        v = vector<int>(n);
        for (auto &x: v) cin>>x;
        if (!n) return vector<int>{};
        if (n == 1) return v;
        int x = v[0];
        for (int i = 1; i<n; i++) {
            if (grafo[x].count(v[i])) x = v[i];
            else {
                for (auto &to: grafo[x]) f(to,f);
            }
        }
        for (int i = 1;i <n; i++) grafo[v[i-1]].insert(v[i]);
        return v;
    };
	int asdf;
    int k = 2;
	int aska = 0;
	vector<int> v;
    for (int i = 1; i<=n; i++) {
        if (vis[i]) k+= f(i, f);
        else {

            while (1) {
				if(aska != i)
                	v = ask(k);
                if (!v.size() || v[0] != i) {if(!v.empty())aska = v[0]; break;}
				aska = 0;
                
                int suma = 0;
                for (auto &x: v) 
                if (vis[x]) {
                    suma += f(x, f)-1;
                    break;
                }
                k+=suma+1;
            }
            f(i,f);
        } 
    }
    int m = 0;
    for (int i= 1; i<=n;i ++) 
    m += grafo[i].size();

    cout<<"! "<<m<<endl;
    for (int i = 1; i<=n; i++) 
    for (auto &to: grafo[i]) cout<<i<<' '<<to<<endl;
    for (int i = 1; i<=n; i++) grafo[i].clear(), vis[i] = dp[i] = 0;
}

signed main() {
    reze; 
    int T = 1; cin>>T;
    while (T--) solve() ;
    return 0;
}