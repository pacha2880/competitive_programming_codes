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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	string s;
	cin>>n;
	cin>>s;
	int lev = 0, maxle = 0;
	fore(i, 0, n)
	{
		if(s[i] == '[')
			lev++;
		else
			lev--;
		maxle = max(maxle, lev);
	}
	int siz = 3 + maxle * 2;
	string mod = "";
	fore(i, 0, siz)
	mod += ' ';
	vector<string> res;
	lev = 0;
	int antle = -1;
	string add;
	int cen = siz / 2;
	fore(i, 0, n)
	{
		add = mod;
		if(s[i] == '[')
			lev++;
		if(antle != -1)
		{
			add[cen + antle] = '-';
			add[cen - antle] = '-';
		}
		if(s[i] == ']')
		{
			if(antle == maxle - lev + 1)
			{
				res.pb(add);
				res.pb(mod);
				res.pb(add);
			}
			add = mod;
		}
		antle = maxle - lev + 1;
		//cout<<i<<' '<<antle<<'\n';
		add[cen + antle] = '+';
		add[cen - antle] = '+';
		fore(i, cen - antle + 1, cen + antle)
			add[i] = '|';
		res.pb(add);
		if(s[i] == ']')
		{
			res[res.size() - 2][cen + antle] = '-';
			res[res.size() - 2][cen - antle] = '-';
			antle = -1;
		}
		if(s[i] == ']')
			lev--;

	}
	string resa = "";
	fore(i, 1, siz - 1)
	{
		fore(j, 0, res.size())
			resa += res[j][i];
		resa += '\n';
	}
	cout<<resa;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	