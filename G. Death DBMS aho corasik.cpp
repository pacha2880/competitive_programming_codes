#include <bits/stdc++.h>
using namespace std; 

#define int long long
#define reze ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int INF = 1e18;
vector<int> RES(3e5 + 10, -1);

int N, M;
struct ST {
    int k;
    vector<int> t;
    vector<array<int,2>> rollbacks;
    ST (){}
    ST(int n) {
        k =1 ; while (k<n) k<<=1;
        t = vector<int>(2*k, -1);
    }

    void upd(int i, int j, int x) {
        i+=k, j+=k + 1;
        for (; i < j; i>>=1, j>>=1) {
            if (i&1) push(i), t[i] = max(x, t[i]), i++;
            if (j&1) j--, push(j), t[j] = max(t[j], x);
        }
    }
    void push(int id) {
        rollbacks.push_back({id, t[id]});
    }
    void roll() {
        int id = rollbacks.back()[0], x = rollbacks.back()[1];
        rollbacks.pop_back();
        t[id] = x;
    }

    int query(int i) {
        int res = -1;

        for (i+=k; i; i>>=1) res = max(res, t[i]);

        return res;
    }
};
vector<pair<int, int>> upds[300010];
struct node {
        int suf = 0, exit = 0, end = 0;
        int go[26];
        vector<int> queries;
        vector<int> terms;
        node() {
            memset(go, 0, sizeof go);
        }
        int& operator [] (int i) { return go[i]; }

    };
struct AHO {
    
    vector<node> trie;
    vector<vector<int>> grafo;
    ST t;

    AHO () {
        trie = vector<node>(1);
    }

    int add(string &s, int id) {
        int ac = 0; 
        for (auto &c: s) {
            int j = c-'a';
            if (!trie[ac].go[j]) trie[ac].go[j] = trie.size(), trie.push_back({});
            ac = trie[ac].go[j];
        }
        trie[ac].end = 1;
        upds[id].push_back({0,0});
        trie[ac].terms.push_back(id);
        // cout<<"insertando: "<<trie[ac].upds.size()<<endl;
        return ac;
    }

    void build_ac() {
        queue<int> q; q.push(0);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int c = 0; c < 26; ++c) {
                int v = trie[u][c];
                if (!v) trie[u][c] = trie[trie[u].suf][c];
                else q.push(v);
                if (!u || !v) continue;
                trie[v].suf = trie[trie[u].suf][c];
                trie[v].exit = trie[trie[v].suf].end ? trie[v].suf : trie[trie[v].suf].exit;
            }
        }
    }

    int goo(int node, int to){
    // cout<<'@'<<node<<' '<<to<<'\n';
        if(!trie[node].go[to]){
            if(node == 0)
                return trie[node].go[to] = 0;
            return trie[node].go[to] = goo(trie[node].suf, to);}
        return trie[node].go[to];
    }

    void marcar(string &s, int id) {
        int ac = 0;
        for (auto &c: s) {
            int i = c - 'a';
            // while (!trie[ac].go[i]) 
            ac = goo(ac, i);
            // cout<<'%'<<ac<<'\n';
            trie[ac].queries.push_back(id);
        }
    }

    void build_graph() {
        t = ST(M+1);
        grafo = vector<vector<int>>(trie.size());
        
        for(int i = 0; i < trie.size(); i++) {
            int a = i, b = trie[i].suf;
            if (a!=b)
            grafo[b].push_back(a);
        }

        // for (int i = 0; i<trie.size(); i++) {
        //     cout<<"viendO;"<<i<<endl;
        //     for (auto &to:grafo[i]) cout<<to<<' ';cout<<endl;
        // }
    }

    void dfs(int i, int p) {
        // cout<<"entrando: "<<i<<endl;
        int ops = t.rollbacks.size();
        int x = i; 
        while (x) {
            if (trie[x].end) {
                for (auto it: trie[x].terms)
                for (int j = upds[it].size()-1, ns = M; ~j; j--) {
                    // cout<<"udpate: "<<trie[x].upds.size()<<endl;
                    
                    int a = upds[it][j].first, b = ns, val = upds[it][j].second;
                    // cout<<"paso: "<<a<<' '<<b<<' ' << val<<endl;
                    t.upd(a, b, val);
                    // cout<<'f'<<endl;
                    ns = a;
                }
            }
            // x = trie[x].exit;
            x = 0;
        }

        for (auto &id: trie[i].queries) {
            RES[id] = max(RES[id], t.query(id));
            // if (id == 2) cout<<i<<"id: "<<id<<' '<<t.query(id)<<endl;
        }

        for (auto &to: grafo[i]) dfs(to, i);
            
        int ahora = t.rollbacks.size() - ops;
        while (ahora--) t.roll();
    }
};

void solve() {
    int n, q; cin>>n>>q;
    N = n, M = q; 
    vector<int> tos(n+1);
    AHO aho;
    // cout<<"empieza"<<endl;
    for (int i = 1; i<=n; i++) {
        string s; cin>>s;
        tos[i] = aho.add(s, i);
        // cout<<"agregado: "<<aho.trie.size()<<endl;
    }
        aho.build_ac();

    vector<int> fa;
    for (int i = 1; i<=q; i++) {
        int t; cin>>t;
        if (t & 1) {
            int id, x; cin>>id>>x;
            upds[id].push_back({i, x});
        } else {
            fa.push_back(i);
            string s; cin>>s;
            aho.marcar(s, i);
        }
    }
    aho.build_graph();
    
    aho.dfs(0,0);
    for (auto &i: fa) cout<<RES[i]<<endl;
}

signed main() {
    reze; 
    int T = 1; //cin>>T;
    while (T--) solve() ;
    return 0;
}