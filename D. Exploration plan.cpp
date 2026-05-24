#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back

struct Kuhn{
    Kuhn(){}
    Kuhn(int nLeft, int nRight){ init(nLeft, nRight); }
    void init(int nLeft, int nRight){
        L = nLeft, R = nRight;
        G.clear(), G.resize(L);
        mt.assign(R, -1);
        used.assign(L, 0);
        cc = 1;
    }
    int L, R, cc;
    vector<vi> G;
    vi mt, used;
    void addEdge(int u, int v){ G[u].pb(v); }
    bool dfs(int v){
        if(used[v] == cc) return 0;
        used[v] = cc;
        for(int to : G[v]) if(mt[to] == -1 || dfs(mt[to])) return mt[to] = v, 1;
        return 0;
    }
    int maxMatching(){
        mt.assign(R, -1);
        int match = 0;
        for(int v = 0; v < L; v++){
            ++cc;
            if(dfs(v)) match++;
        }
        return match;
    }
};

const int INF = 1e9;
int dist[605][605];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, N, K;
    cin >> V >> E >> N >> K;

    vector<int> start(N);
    for(int i = 0; i < N; i++){ cin >> start[i]; start[i]--; }

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for(int i = 0; i < E; i++){
        int a, b, t; cin >> a >> b >> t; a--; b--;
        dist[a][b] = min(dist[a][b], t);
        dist[b][a] = min(dist[b][a], t);
    }

    // Floyd-Warshall
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++) if(dist[i][k] < INF)
            for(int j = 0; j < V; j++) if(dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    auto check = [&](int T) -> bool {
        Kuhn kuhn(N, V);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < V; j++)
                if(dist[start[i]][j] <= T)
                    kuhn.addEdge(i, j);
        return kuhn.maxMatching() >= K;
    };


    int lo = 0, hi = 1731311, ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){ ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}