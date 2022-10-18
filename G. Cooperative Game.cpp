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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int floid(int t, int c)
{
    vi g(t + c);
    fore(i, 0, t + c - 1)
        g[i] = i + 1;
    g[t + c - 1] = t;
    // fore(i, 0, t + c)
    //     cout<<i<<"->"<<g[i]<<'\n';
    int can = 0;
    int a = 0, b = 0;
    int cont = 0;
    do
    {
        a = g[a];
        if(a == t)
            cont++;
        b = g[b];
        // cout<<a<<' '<<b<<" -> ";
        b = g[b];
        cout<<a<<' '<<b<<'\n';
        can++;
    } while(a != b); 
    cout<<cont<<'\n';
    if(cont > 1)return -10000000;
    cout<<"cana"<<' '<<t<<' '<<c<<' '<<can<<'\n';
    return can;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int can = 0;
    int k;
    string s;
	do
    {
        cout<<"pis\n";
        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        cin>>k;
        fore(i, 0, k) cin>>s;
        cout<<"next 0"<<endl;
        cin>>k;
        fore(i, 0, k) cin>>s;
        can++;
        // cout<<"caca\n";

    } while (k > 1);
    // cout<<"pasas\n";
    int cicl = 0;
	do
    {
        cout<<"next 0"<<endl;
        cin>>k;
        fore(i, 0, k) cin>>s;
        cicl++;

    } while (k > 1);
    int equis = -1, te = -1;
    for(int t = 1; t < 5; t++)
    {
        if(floid(t, cicl) == can)
        {
            equis = can - t;
            te = t;
            break;
        }
    }
    // cout<<equis<<' '<<te<<' '<<cicl<<' '<<can<<'\n';
    fore(i, 0, cicl - equis)
    {
        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        cin>>k;
        fore(i, 0, k) cin>>s;
    }

    cout<<"done"<<endl;
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
