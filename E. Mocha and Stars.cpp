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
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
const int tam = 100010;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	vii ar(n), er(n);
	fore(i, 0, n) cin>>ar[i].f>>ar[i].s;
	vi muls(m + 1);
	muls[1] = 1;
	fore(i, 1, m + 1)
	{
		forg(j, i + i, m + 1, i)
			muls[j] -= muls[i];
	}
	// fore(i, 0, m + 1)
	// 	cout<<i<<' '<<muls[i]<<'\n';
	ll res = 0;
	fore(i, 1, m + 1)
	{
		// cout<<"hola "<<i<<'\n';
		if(muls[i] != 0)
		{
			bool bo = true;
			fore(j, 0, n)
			{
				er[j].f = (ar[j].f + i - 1) / i;
				er[j].s = ar[j].s / i;
				if(er[j].f > er[j].s)
				{
					bo = false;
					break;
				}
			}
			// cout<<"bobo "<<bo<<'\n';
			if(bo)
			{
				vii nes = {{0, 1}};
				int l = m / i;
				for(ii x : er)
				{
					// cout<<x.f<<','<<x.s<<' ';
					vii nues(sz(nes) + x.s - x.f);
					if(nes[0].f + x.f > l)
					{
						nes = {{0, 0}};
						break;
					}
					ll su = 0;
					fore(i, 0, nes.size())
					{
						su = (su + nes[i].s) % MOD;
						nues[i].s = su;
					}
					fore(i, nes.size(), nues.size())
						nues[i].s = su;
					su = 0;
					fore(i, x.s - x.f + 1, nues.size())
					{
						su = (su + nes[i - (x.s - x.f + 1)].s) % MOD;
						nues[i].s = (nues[i].s + MOD - su) % MOD;
					}
					int ini = nes[0].f + x.f;
					fore(i, 0, nues.size())
						nues[i].f = ini++;
					while(nues.back().f > l) nues.pop_back();
					swap(nes, nues);
				}
				// cout<<'\n';
				for(ii x : nes)
					res += muls[i] * x.s;
				res = (res % MOD + MOD) % MOD;
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
