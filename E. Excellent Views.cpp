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
vector<ll> brute(vector<int> &v){
	int n = v.size();
	vector<ll> ans(n);
	vector<pair<int, int>> cucu(n);
	repl(i, 0, n) cucu[i] = {v[i], i};
	sort(all(cucu));
	reverse(all(cucu));
	repl(i, 0, n){
		int mini = 1e9;
		repl(j, 0, n){
			if(cucu[j].first <= v[i]) break;
			if(abs(i - cucu[j].second) < mini){
				ans[i]++;
				mini = abs(i - cucu[j].second);
			}
		}
	}
	return ans;
}

void solve(){
	vector<int> per({1, 2, 3, 4, 5, 6});
	do{
		auto v = per;
		int n = 6;
		vector<ii>ord(n);
		for(ll i =0 ; i< n ; i ++){
			ord[i] = {v[i], i};
		}
		sort(all(ord));
		reverse(all(ord));
		vector<ll>ans(n,0);
		set<ll>st;
		st.insert(ord[0].second);
		// dbg(ord[0].second);
		repl(i,1,n){
			ll L =2e9, R = 2e9;
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
		if(ans != brute(v)){
			
			for(int x : per)
				cout<<x<<' ';
			cout<<'\n';		
			for(int x : ans)
				cout<<x<<' ';
			cout<<'\n';		
			for(int x : brute(v))
				cout<<x<<' ';
			cout<<'\n';		
			cout<<'\n';
			cout<<'\n';
		}	
	}
	while(next_permutation(all(per)));
    
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