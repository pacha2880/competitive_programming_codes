#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll dp[2][33][33][33][33];
ll per[33][33][33];
ll par[33][33][33];
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, h;
	cin>>n>>h;
	fore(i, 1, 33)
	{
		fore(j, i, 33)
		{
			fore(k, j, 33)
			{
				map<int, int> ma;
				ma[i]++;
				ma[j]++;
				ma[k]++;
				per[i][j][k] = 6;
				for(auto pa : ma)
				{
					int divi = 1, con = 1;
					while(pa.s--)
					{
						divi *= con;
						con++;
					}
					per[i][j][k] /= divi;
				}
				ma[h + 1]++;
				par[i][j][k] = 24;
				for(auto pa : ma)
				{
					int divi = 1, con = 1;
					while(pa.s--)
					{
						divi *= con;
						con++;
					}
					par[i][j][k] /= divi;
				}
			}
		}
	}
	int now, last, hcon, dis, i, j, k, l, ip, jp, kp, lp, ucon, perm;
	dp[0][1][1][1][1] = 1;
	vector<int> ava(4);
		set<pair<pair<int, int>, pair<int, int>>> st;
		vector<pair<pair<int, int>, pair<int, int>>> cas, casp;
		fore(i, 1, h + 2)
		{
			ip = min(h + 1, i + 1);
			fore(j, 1, h + 2)
			{
				jp = min(h + 1, j + 1);
				fore(k, 1, h + 2)
				{
					kp = min(h + 1, k + 1);
					hcon = (i == h + 1) + (j == h + 1) + (k == h + 1);
					ucon = (i == 1) + (j == 1) + (k == 1);
					fore(l, 1, h + 2)
					{
						if(hcon == 3 && l == h + 1) break;
						lp = min(h + 1, l + 1);
						vector<int> casu;
						casu.pb(i);
						casu.pb(j);
						casu.pb(k);
						casu.pb(l);
						sort(all(casu));
						st.insert(mp(mp(casu[0], casu[1]), mp(casu[2], casu[3])));
						if(ucon == 0 && hcon == 0 && l == 1) l = h;
					}
				}
			}
		}
		//cout<<st.size()<<'\n';
		//return 0;

		for(auto a : st)
		{
			cas.pb(a);
			casp.pb(mp(mp(min(h + 1, a.f.f + 1), min(h + 1, a.f.s + 1)), mp(min(h + 1, a.s.f + 1), min(h + 1, a.s.s + 1))));
		}
	fore(x, 1, n + 1)
	{
		now = x % 2;
		last = abs(now - 1);
		fore(i, 0, cas.size())
			dp[now][cas[i].f.f][cas[i].f.s][cas[i].s.f][cas[i].s.s] = 0;
		//cout<<x<<'\n';
		fore(z, 0, cas.size())
		{
			i = cas[z].f.f, j = cas[z].f.s, k = cas[z].s.f, l = cas[z].s.s;
			ip = casp[z].f.f, jp = casp[z].f.s, kp = casp[z].s.f, lp = casp[z].s.s;
			if(i != h + 1)
				dp[now][1][jp][kp][lp] += dp[last][i][j][k][l];
			else
				dp[now][ip][jp][kp][lp] += dp[last][i][j][k][l];
			if(j != h + 1)
				dp[now][1][ip][kp][lp] += dp[last][i][j][k][l]; 
			else
				dp[now][ip][jp][kp][lp] += dp[last][i][j][k][l]; 
			if(k != h + 1)
				dp[now][1][ip][jp][lp] += dp[last][i][j][k][l];
			else
				dp[now][ip][jp][kp][lp] += dp[last][i][j][k][l];
			if(l != h + 1)
				dp[now][1][ip][jp][kp] += dp[last][i][j][k][l];
			else
				dp[now][ip][jp][kp][lp] += dp[last][i][j][k][l];
		}
		fore(i, 0, cas.size())
			dp[now][cas[i].f.f][cas[i].f.s][cas[i].s.f][cas[i].s.s] %= MOD;
		

	}
	ll res = 0;
	fore(i, 0, cas.size())
		res = (res + dp[now][cas[i].f.f][cas[i].f.s][cas[i].s.f][cas[i].s.s]) % MOD;
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	