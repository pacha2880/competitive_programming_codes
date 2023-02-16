#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
#define ll                    long long
#define ld                    long double
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
#define all(x)                (x).begin(), (x).end()
#define sz(x)                 ((int)(x).size())
#define forn(i,n)             for(int i = 0; i < n; i++)
#define fore(i,b,e)           for(int i = b; i < e; i++)
#define forg(i,b,e,m)         for(int i = b; i < e; i+=m)
#define rforn(i,n)            for(int i = n; i >= 0; i--)
#define rfore(i,b,e)          for(int i = b; i >= e; i--)
#define rforg(i,b,e,m)        for(int i = s; i >= e; i-=m)
#define endl                  "\n"
#define MOD                   1000000007
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

const int N = 10005;
ll n,h;
vector<pair<ll, ll>> vec(N);
ll dp[N];

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin>>n>>h;
    forn(i,n) cin>>vec[i].fi>>vec[i].se;
    forn(i,N) dp[i] = 0;
    forn(i,n){
        ll fuerza = vec[i].fi, perdida = vec[i].se/2, valor = vec[i].se/2, ganancia = fuerza;
        vector<pair<ll, ll>> pares;
        while(valor>0){
            pares.pb({ganancia, perdida});
            fuerza *= 2;
            ganancia += fuerza;
            perdida = perdida+valor-valor/2;
            valor /= 2;
        }
        pares.pb({ganancia, perdida});
        //for(auto u: pares) cout<<u.fi<<" "<<u.se<<endl;
        for(int j = N-1; j >= 0; j--){
            for(auto par : pares){
                if(j+par.se < N){
                    dp[j+par.se] = max(dp[j+par.se], dp[j]+par.fi);
                }
            }
        }
    }
    ll ans = 0;
    bool bo = 1;
    forn(i,N){
        if(dp[i] >= h){
            ans = i;
            bo = 0;
            break;
        }
    }
    if(!bo) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}