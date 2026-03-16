#include <bits/stdc++.h>
#define int long long
#define ll long long
// #define sz(x) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first 
#define S second 
#define fast_cin ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

using namespace std; 

struct submit {
    string label;
    ll time;
    string timestring;
    ll position;
    string ver;
};

void solve(){
    ll p, n;
    cin >> p >> n;

    map<string,vector<submit>> f;

    auto gt = [&](auto &s, ll i) {
        return s[i]-'0';
    };

    set<string> teams;
    set<pair<string,string>> ac;
    for (int i =0;i<n;i++) {
        string team,label,timestring,ver;
        cin >> team >> label >> timestring >> ver;

        if (ac.count({team,label})) continue;
        if (ver=="OK") ac.insert({team,label});
        
        ll timenum =gt(timestring,0)*60+gt(timestring,2)*10+gt(timestring,3);
        teams.insert(team);

        submit sub;
        sub.label = label, sub.time = timenum, sub.timestring = timestring, sub.position = i, sub.ver = ver;
        f[team].pb(sub);
        // f[team].pb({label,timenum,time,i,ver});
    }


    auto getboard = [&](string awardedteam, ll position) {
        vector<tuple<ll,ll,ll,string>> board;
    
        
        for (auto& p : f) {
            auto team = p.first;
            auto& sub = p.second;
            map<string,ll> cnt;
    
            ll penalty = 0;
            ll solved = 0;
            ll lastsolved = 0;

            for (auto & submit : sub) {
                if (team == awardedteam && submit.position >= position) continue;

                if (submit.ver == "OK") {
                    solved++;
                    penalty += cnt[submit.label]*20 + submit.time;
                    lastsolved = max(lastsolved,submit.position);
                } else {
                    cnt[submit.label]++;
                }
            }
            board.pb({-solved,penalty,lastsolved,team});
        }
        sort(all(board));
        return board;
    };

    
    auto board = getboard("",0);
    set<string> awarded;
    string never_get_medal_team = get<3>(board[12]);
    for (int i =0;i<12;i++) {
        awarded.insert(get<3>(board[i]));
    }
    for (auto &team : teams) {
        if (!(awarded.count(team)||team==never_get_medal_team)) f.erase(team);
    }


    vector<tuple<ll,string,string>> ans;

    for (auto team : awarded) {

        ll left = 0;
        ll right = f[team].size()-1;
        ll ansid = -1;

        auto check  =[&](ll mid) {
            auto newboard = getboard(team,f[team][mid].position);
            for (int i = 0;i<12;i++) {
                if (get<3>(newboard[i])==team) return true;
            }
            return false;
        };

        while (left <= right) {
            ll mid = (left + right) >> 1;

            if (!check(mid)) {
                left =mid+1;
                ansid = mid;
            } else {
                right = mid-1;
            }
        }
        assert(ansid != -1);
        ans.pb({f[team][ansid].position,team,f[team][ansid].timestring});
    }
    sort(all(ans));
    for (auto &entry : ans) {
        auto &team = get<1>(entry);
        auto &time = get<2>(entry);
        cout << team << " " << time << "\n";
    }
}

signed main() {

    fast_cin; 
    ll t; cin >> t;
    while (t--) solve();
}