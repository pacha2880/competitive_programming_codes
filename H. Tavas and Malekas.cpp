#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
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
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 2000010;
const int MOD = 1000000007;
const int MOD1 = 1000000009;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int mar[tam];
int ar[tam];
int z[tam];
int matches[tam];
void alz(string &s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = z[i-1];
        while (j > 0 && s[i] != s[j])
            j = z[j-1];
        if (s[i] == s[j])
            j++;
        z[i] = j;
    }
}

void asd(string &s, string &p)
{
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
    cin>>n>>m;
    string p;
    cin>>p;
    string s(n, 'A');
    int ind = 0, ac = 0;
    fore(i, 0, m)
    {
        int x;
        cin>>x;
        ar[i] = x - 1;
        mar[x - 1] = 1;
    }
    fore(i, 0, n)
    {
        if(ind == p.size())
            ind = 0, ac = 0;
        if(mar[i])
            ind = 0, ac = 1;
        if(ac == 1)
            s[i] = p[ind++];
    }
    
    string go = p + "#" + s;
    alz(go);
    int pm = p.size();
    // fore(i, 0, sz(s) + pm + 1)
    //     cout<<z[i]<<' ';
    fore(i, pm + 1, sz(s) + pm + 1)
        if(z[i] == pm)
            matches[i - pm - pm] = 1;
    // for(int x : matches) cout<<x<<'\n';
    bool bo = 1;
    fore(i, 0, m)
    {
        // cout<<ar[i]<<' ';
        bo &= matches[ar[i]];
    }
    // cout<<"\n-->"<<s<<' '<<bo<<'\n';
    if(bo)
    {
        ll res = 1;
        fore(i, 0, n)
            if(s[i] == 'A')
                res = res * 26 % MOD;
        cout<<res<<'\n';
    }
    else
        cout<<0<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
