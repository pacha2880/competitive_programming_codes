#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long ans = 0;
    priority_queue<pair<int, int>> p;
    p.push(make_pair(0, 0));
    vector<bool> v(2005, false);
    while(!p.empty()){
        int summ = p.top().first;
        int in = p.top().second;
        p.pop();
        if(v[in]){
            continue;
        }
        v[in] = true;
        ans += summ;
        for(int i = 0; i < n; i++){
            if(v[i]){
                continue;
            }
            p.push(make_pair(arr[in] ^ arr[i], i));
        }
    }
    cout << ans << "\n";
    return 0;
}
