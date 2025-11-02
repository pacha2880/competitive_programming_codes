#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define readlin(input) string input;getline(cin, input)
#define clr(a,h) memset(a, (h), sizeof(a))
#define fr(a,b) for(int i = a; i < b; i++)
#define frl(a,b) for(long long i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++) 
#define repl(i,a,b) for(long long i = a; i < b; i++) 
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define readi(x) int x; cin >> x
#define readl(x) long long x; cin >> x
#define reads(x) string x; cin >> x
#define papucasos(x) long long x; cin >> x; while(x--)
#define papu(x) cout<<x<<endl
#define mamu(x) cout<<x
using namespace std;
const long long MOD=1e9+7;
vector<long long> dp;
 
void solve(){
   ll n;
   cin>>n;
   if(n % 2 == 0 && __builtin_popcountl(n) > 1){
        int po = __builtin_ctzl(n) - 1;
        cout<<n + (1<<po)<<' '<<n / 2<<' '<<n / 2 - (1<<po)<<'\n';
   }
   else
   
    cout<<"-1\n";
}

int main() {
    fast_io;
   // readl(t);
   int t=1;
   cin>>t;
   while(t--){
      solve();
   }

    return 0;
}                                                                                                       