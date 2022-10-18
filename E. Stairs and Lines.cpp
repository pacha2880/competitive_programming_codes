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
const ll MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<vector<ll>> mat;
vector<vector<ll>> ans;
vector<vector<ll>> mats[7];
void gen()
{
	int tan, kua;
	bool bo;
	fore(z, 0, 7)
	{
		tan = z + 1;
		mats[z] = vector<vector<ll>>(1 << tan, vector<ll>(1 << tan, 0));
		fore(i, 0, 1 << tan)
		{
			fore(j, 0, 1 << tan)
			{
				fore(k, 0, 1 << (tan - 1))
				{
					kua = (k << 1) | 1 | (1 << tan);
					bo = true;
					fore(l, 0, tan)
					{
						if((kua & (1 << l)) && (i & (1 << l)) && (j & (1 << l)) && (kua & (1 << (l + 1))))
							bo = false;
					}
					mats[z][i][j] += bo;
				}
			}
		}
	}
}
void mult(vector<vector<ll>> m1, vector<vector<ll>> m2)
{
	ans.clear();
	ll answer = 0;
	fore(i, 0, m1.size())
	{
		vector<ll> fila;
		fore(j, 0, m2[0].size())
		{
			answer = 0;
			fore(k, 0, m2.size())
			{
				answer = (answer + m1[i][k] * m2[k][j]) % MOD;
			}
			fila.pb(answer);
		}
		ans.pb(fila);
	}
}
void pot(vector<vector<ll>> base, ll exp)
{
	int ta = base.size();
	vector<vector<ll>> res(ta,vector<ll>(ta,0));
	fore(i, 0, ta)
		res[i][i] = 1;
	while(exp)
	{
		if(exp & 1)
		{
			mult(res, base);
			res = ans;
		}
		mult(base, base);
		base = ans;
		exp /= 2;
	}
	ans = res;
}
int pis[7];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	vector<vector<ll>> ini(1, vector<ll>(2)), ax;
	ini[0][1] = 1;
	int tan, a;
	gen();
	fore(i, 0, 7)
	{
		cin>>a;
		tan = i + 2;
		pot(mats[i], a);
		mult(ini, ans);
		ini = ans;
		if(i < 6)
		{
			ax = vector<vector<ll>>(1, vector<ll>(1<<tan));
			fore(i, 0, 1 << (tan - 1))
				ax[0][(1 << (tan - 1)) + i] = ini[0][i];
			ini = ax;
		}
	}
	cout<<ini[0][(1 << 7) - 1]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	