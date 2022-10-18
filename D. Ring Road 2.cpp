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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> g[200];
int cols[200];
bool chech(int n, int col)
{
	bool res = true;
	cols[n] = abs(col - 1);
	for(int i = 0; i < g[n].size(); i++)
	{
		if(cols[g[n][i]] == -1)
			res &= chech(g[n][i], cols[n]);
		else
			if(cols[g[n][i]] != col)
				return false;

	}
	return res;
}
pair<int, int> cra[200];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	pair<bool, bool> x, y;
	int a, b;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--; b--;
		if(a > b) swap(a, b);
		fore(j, 0, i)
		{
			if(a < cra[j].f)
			{
				if(cra[j].f < b && cra[j].f > a && cra[j].s > b)
				{
					g[i].pb(j);
					g[j].pb(i);
				}
			}
			else
			{
				if(cra[j].s > a && cra[j].f < a && cra[j].s < b)
				{
					g[i].pb(j);
					g[j].pb(i);	
				}
			}
		}
		cra[i] = mp(a, b);
	}
	mem(cols, -1);
	bool res = true;
	fore(i, 0, m)
	{
		if(cols[i] == -1)
			res &= chech(i, 0);
	}
	if(res)
	{
		fore(i, 0, m)
			cout<<(cols[i] ? 'i' : 'o');
		cout<<'\n';
	}
	else
		cout<<"Impossible\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	