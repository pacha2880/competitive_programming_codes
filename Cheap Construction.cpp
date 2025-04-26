#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int 			long long
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forev(i, e, b) for(int i = e; i > b; i--)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }
    return pi;
}

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent, rank;
};

int countConnectedComponents(const string& p, const string& s) {
    // cout<<p<<' '<<s<<'\n';
    string combined = p + '$' + s;
    vector<int> pi = kmp(combined);
    vector<int> match_positions(sz(s));

    int p_len = p.size();
    int combined_len = combined.size();

    // Collect all match positions in `s` where `p` is found
    for (int i = p_len + 1; i < combined_len; i++) {
        if (pi[i] == p_len) {
            match_positions[i - 2 * p_len] = 1; // Position in `s`
        }
    }

    // Edge case: If no matches found
    // fore(i, 0, sz(s))
    //     cout<<match_positions[i]<<' ';
    // cout<<'\n';

    // Use union-find to count connected components
    int n = sz(s);
    UnionFind uf(n);
    int last = -MOD;
    // Connect consecutive matches if they are adjacent
    for (int i = 0; i < n; i++) {
        if(last + p_len > i)
            uf.unite(i, i - 1);
        if (match_positions[i])
            last = i;
    }

    // Count distinct connected components
    int connectedComponents = 0;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) {
            connectedComponents++;
        }
    }

    return connectedComponents;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	string s;
    cin>>s;
    int n = sz(s);
    vi res(n, MOD);
    res[n - 1] = 1;
    fore(i, 0, n)
    {
        string sub;
        sub += s[i];
        fore(j, i+1, n)
        {
            sub += s[j];
            int asd = countConnectedComponents(sub, s);
            // cout<<i<<' '<<j<<' '<<asd<<'\n';
            res[asd - 1] = min(res[asd - 1], j + 1 - i);
        }
    }
    fore(i, 0, n)
        cout<<(res[i] == MOD ? 0 : res[i])<<' ';
    cout<<'\n';
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasándola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Si te caes 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad.
// Take a sad song and make it better.
// Ya que no se tiene información perfecta, tomar riesgos.
// Si se decide trabajar en un problema grande, empezar a hacerlo lo antes posible.
// La suerte siempre tiene su rol en las competencias y hay que vivir con eso.
