#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
char tab[2020][2020];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int n, m, a, b;
    char ch;
    cin>>n>>m>>a>>ch>>b;
    cin>>ch;
    vector<string> ar(n);
    cin.ignore();
    fore(i, 0, n)
        getline(cin, ar[i]);
    vector<ii> cip(500);
    bool bus = false;
    string s;
    int i = 1, j = 1;
    while(m--)
    {
        getline(cin, s);
        for(char cha : s)
        {
            if(!bus)
            {
                if(cha == '<')
                    bus = true;
                else if(i <= a)
                {
                    tab[i - 1][j - 1] = cha;
                    if(ch == 'S')
                    {
                        if(cip[cha].f == 0)
                            cip[cha] = {i, j};
                        else
                            cip[cha] = min(cip[cha], {i, j});
                    }
                    else
                    {
                        if(cip[cha].f == 0)
                            cip[cha] = {i, j};
                        else
                            cip[cha] = max(cip[cha], {i, j});
                    }
                    j++;
                    if(j == b + 1)
                        j = 1, i++;
                }
            }
            else
                if(cha == '>')
                    bus = false;
        }
    }
    // fore(i, 0, a)
    // {
    //     fore(j, 0, b)
    //         cout<<tab[i][j];
    //     cout<<'\n';
    // }
    fore(i, 0, n)
    {
        s = ar[i];
        vi res;
        bool bo = true;
        for(char ch : s)
        {
            if(cip[ch].f == 0)
                bo = false;
            res.pb(cip[ch].f);
            res.pb(cip[ch].s);
        }
        if(bo)
        {
            fore(i, 0, sz(res))
            {
                if(i > 0) cout<<',';
                cout<<res[i];
            }
            cout<<'\n';
        }
        else
            cout<<"0\n";
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
