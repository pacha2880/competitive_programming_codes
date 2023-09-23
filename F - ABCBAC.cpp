#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
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
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC optimization ("O2")
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
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int pot (int b, int e, int MOD) {
    int res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
struct Hash
{
	int p = 997, m[2], in[2], n;
	vector<int> h[2], inv[2];
	Hash(string s)
	{
        n = sz(s);
		m[0] = 998244353, m[1] = 1000000009;
		fore(i, 0, 2)
		{
			in[i] = pot(p, m[i]-2, m[i]);
			h[i].resize(s.size() + 1);
			inv[i].resize(s.size() + 1);
			ll acu = 1;
			h[i][0] = 0, inv[i][0] = 1;
			fore(j, 0, s.size())
			{
				h[i][j + 1] = (h[i][j] + acu * s[j]) % m[i];
				inv[i][j + 1] = (1ll * inv[i][j] * in[i]) % m[i];
				acu = (acu * p) % m[i];
			}
		}
	}
	ll get(int e)
	{
		ll ha[2];
		fore(i, 0, 2)
			ha[i] = ((((h[i][n] - h[i][n / 2 + e]) * (ll)inv[i][n / 2]) % m[i] + h[i][e]) + m[i]) % m[i];
		return((ha[0] << 32) | ha[1]) ;
	}
    
	ll get(int b, int e)
	{
		ll ha[2];
		fore(i, 0, 2)
			ha[i] = ((((h[i][e] - h[i][b]) * (ll)inv[i][b]) % m[i]) + m[i]) % m[i];
        // cout<<ha[0]<<' '<<ha[1]<<'\n';
		return((ha[0] << 32) | ha[1]) ;
	}
};

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    string s;
    int n;
    cin>>n;
    cin>>s;
    // int n = sz(s) / 2;
    string sr = s;
    reverse(all(sr));
    Hash h1(s), h2(sr);
    // cout<<'a' + 0<<'\n';
    // cout<<(h1.get(0, 1)>>32)<<'\n';
    fore(i, 0, n + 1)
    {
        // cout<<i<<' '<<i<<' '<<i + n + 1<<'\n';
        int rev = n - i;
        // cout<<i<<' '<<rev<<' '<<rev + n<<'\n';
        // cout<<h1.get(i)<<' '<<h2.get(rev, rev + n)<<'\n';
        if(h1.get(i) == h2.get(rev, rev + n))
        {
            fore(j, 0, i) cout<<s[j];
            fore(j, i + n, 2 * n) cout<<s[j];
            cout<<'\n'<<i;
            return 0;
        }
    }
    cout<<-1<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
