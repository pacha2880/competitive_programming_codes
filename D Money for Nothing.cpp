#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
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
const int tam = 500010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int p1[tam], p2[tam], ven[tam], com[tam];
int N, M;
int cal(int i, int j)
{
    if(p2[j] <= p1[i] || com[j] <= ven[i]) return -1;
    return (p2[j] - p1[i]) * (com[j] - ven[i]);
}
int f(int b1, int e1, int b2, int e2)
{
    if(b1 > e1) return 0;
    while(b2 <= e2 && p2[b2] <= p1[b1]) b2++;
    while(b2 <= e2 && com[e2] <= ven[e1]) e2--;
    if(b2 > e2) return 0;
    int mid = (b1 + e1) / 2;
    int optimus_prime = b2;
    fore(i, b2 + 1, e2 + 1)
        if(cal(mid, i) > cal(mid, optimus_prime))
            optimus_prime = i;
    if(cal(mid, optimus_prime) == -1)
        return max(f(b1, mid - 1, b2, e2), f(mid + 1, e1, b2, e2));
    return max({cal(mid, optimus_prime), f(b1, mid - 1, b2, optimus_prime), f(mid + 1, e1, optimus_prime, e2)});
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    vii ar(n), br(m);
    fore(i, 0, n) cin>>ar[i].s>>ar[i].f;
    fore(i, 0, m) cin>>br[i].s>>br[i].f;
    sort(all(ar)); sort(all(br));
    int las = MOD;
    fore(i, 0, n)
    {
        if(las > ar[i].s)
        {
            p1[N] = ar[i].f;
            ven[N] = ar[i].s;
            N++;
            las = ar[i].s;
        }
    }
    las = 0;
    reverse(all(br));
    fore(i, 0, m)
    {
        if(las < br[i].s)
        {
            p2[M] = br[i].f;
            com[M] = br[i].s;
            M++;
            las = br[i].s;
        }
    }
    reverse(p2, p2 + M);
    reverse(com, com + M);
    cout<<f(0, N - 1, 0, M - 1);
	return 0;
}
