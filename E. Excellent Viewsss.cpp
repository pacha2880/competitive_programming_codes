#include <bits/stdc++.h>
#define ll long long
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define print(v) for(auto x : v){cout << x << " ";} cout << "\n"
#define all(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << "\n"
#define ii pair<ll,ll> 
using namespace std;

vector<ll> v;
ll n;

void solve(){
    cin>>n;
    v.resize(n);
    vector<ii>ord(n);
    for(ll i =0 ; i< n ; i ++){
        cin>>v[i];
        ord[i] = {v[i], i};
    }
    sort(all(ord));
    reverse(all(ord));
    vector<ll>ans(n,0);
    set<ll>st;
    st.insert(ord[0].second);
    // dbg(ord[0].second);
    repl(i,1,n){
        ll L =1e9, R = 1e9;
        auto ind = st.upper_bound(ord[i].second);
        ll LL = -1;
        ll RR = -1;
        if(ind != st.end()){
            R = abs(*ind - ord[i].second);
            RR = *ind;
        }
        if(ind != st.begin()){
            ind--;
            LL = *ind;
            L = abs(*ind - ord[i].second);
        }
        // dbg(LL);
        // dbg(RR);
        // cout << "-------"<<endl;
        if(R < L){
            ans[ord[i].second] =  ans[RR] + 1;
        }
        else if(L < R){
            ans[ord[i].second] =  ans[LL] + 1;
        }
        else{
            if(v[LL] > v[RR]){
                ans[ord[i].second] =  ans[LL] + 1;
            }
            else{
                ans[ord[i].second] =  ans[RR] + 1;
            }
        }
        st.insert(ord[i].second);
    }
    print(ans);
    
}

int main(){
    int t = 1;
    // cin >> t;
    repl(i,0,t){
        solve();
        // cout<<"\n";
    }
    return 0;
}