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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll cnt[4][4][4][10000];
ii ar[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, x, y, g;
	cin>>n;
	fore(i, 0, n)
	{
		cin>>ar[i].f>>ar[i].s;
		// fore(j, 0, i)
		// {
		// 	x = abs(ar[i].f - ar[j].f);
		// 	y = abs(ar[i].s - ar[j].s);
		// 	g = __gcd(x, y);
		// 	// cout<<x%4<<' '<<y%4<<' '<<g%4<<' '<<i<<'\n';
		// 	// cout<<x%4<<' '<<y%4<<' '<<g%4<<' '<<j<<'\n';
		// 	cnt[x % 4][y % 4][g % 4][i]++;
		// 	cnt[x % 4][y % 4][g % 4][j]++;
		// }
	}
	fore(i, 0, n)
	{
		fore(j, 0, n)
		{
			if(j != i)
			{
				x = ar[j].f - ar[i].f;
				y = ar[j].s - ar[i].s;
				g = abs(__gcd(x, y));
				cnt[(x % 4 + 4) % 4][(y % 4 + 4) % 4][g % 4][i]++;
			}
		}
	}
	ll e = 0, eo = 0;
	int b3, a, b;
	fore(i, 0, n)
	{
		fore(j, 0, 4)
		{
			fore(k, 0, 4)
			{
				fore(l, 0, 4)
				{
					fore(o, 0, 4)
					{
						if(j % 2 == l % 2 && k % 2 == o % 2)
						{
							a = ((j * o - k * l) % 4 + 4) % 4;
							if(j == l && k == o)
							{
								b3 = 0;
								fore(p, 0, 4)
								fore(q, 0, 4)
								{
									if(p % 2 == q % 2 && a == (p + q + b3) % 4)
									{
										if(p % 2 == 1)
										{
											if(p == q)
												eo += cnt[j][k][p][i] * (cnt[l][o][q][i] - 1);
											else
												eo += cnt[j][k][p][i] * cnt[l][o][q][i];
										}
										else
										{
											if(p == q)
												e += cnt[j][k][p][i] * (cnt[l][o][q][i] - 1);
											else
												e += cnt[j][k][p][i] * cnt[l][o][q][i];
										}
									}
								}
							}
							else
							{
								b3 = 2;
								fore(p, 0, 4)
								fore(q, 0, 4)
								{
									if(p % 2 == q % 2 && a == (p + q + b3) % 4)
									{
										if(p % 2 == 1)
											eo += cnt[j][k][p][i] * cnt[l][o][q][i];
										else
											e += cnt[j][k][p][i] * cnt[l][o][q][i];
									}
								}
							}
						}
					}
				}
			}
		}
		// cout<<eo<<' '<<e<<'\n';
	}
	// cout<<e<<' '<<eo<<'\n';
	cout<<(e / 3 + eo) / 2<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
