#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<pair<ll, ll>, ll> ar[20];
	ll res[100];
	ll cho[2][100010][100];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout)
	int n;
	cin>>n;
	fore(i, 1, n + 2)
	res[i] = MOD * 1ll * MOD;
	fore(i, 0, n)
	{
		cin>>ar[i].f.f>>ar[i].f.s>>ar[i].s;
		res[0] += min(abs(ar[i].f.s), abs(ar[i].f.f)) * ar[i].s;
	}
	int nu = 1 << n;
	vector<int> poses;
	int na;
	vector<int> ori, ver;
	ll par, cha;
	vector<int>:: iterator it, itt;
	int k;
	int tua, tue;
	fore(i, 0, nu)
	{
		fore(j, 0, n)
		{
			cho[0][i][j] = min(abs(ar[j].f.s), abs(ar[j].f.f)) * ar[j].s;
			fore(k, 0, n)
			{
				if((1 << k) & i)
					cho[0][i][j] = min(cho[0][i][j], abs(ar[k].f.s - ar[j].f.s) * ar[j].s);
			}
			cho[1][i][j] = min(abs(ar[j].f.s), abs(ar[j].f.f)) * ar[j].s;
			fore(k, 0, n)
			{
				if((1 << k) & i)
					cho[1][i][j] = min(cho[1][i][j], abs(ar[k].f.f - ar[j].f.f) * ar[j].s);
			}
		}
	}
	fore(i, 1, nu)
	{
		poses.clear();
		fore(j, 0, n)
		{
			if((1 << j) & i)
				poses.pb(j);
		}
		int siz = poses.size();
		na = 1 << siz;
		fore(j, 0, na)
		{
			par = 0;
			tua = 0;
			tue = 0;
			fore(i, 0, siz)
			{
				if((1<<i) & j)
					tua |= 1<<poses[i];
				else
					tue |= 1<<poses[i];
			}
			fore(i, 0, n)
			{
				par += min(cho[0][tua][i], cho[1][tue][i]);
			}
			res[siz] = min(res[siz], par);
		}
	}
	fore(i, 0, n + 1)
	{
		cout<<res[i]<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	