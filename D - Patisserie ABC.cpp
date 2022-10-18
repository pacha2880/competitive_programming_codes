#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const ll MOD = 1e16;
const double EPS = 1e-9;

int n, m;
pair<ll,pair<ll,ll>> dp[1010][1010];
bool visited[1010][1010];
ll ar[3][1010];
int mod;
pair<ll, pair<ll,ll>> anti, ax1;
ll su1, su2;
pair<ll, pair<ll,ll>> f(int pos, int used)
{
	if(used == m) return mp(0, mp(0,0));
	if(pos == n) return anti;
	if(visited[pos][used]) return dp[pos][used];
	visited[pos][used] = 1;
	pair<ll, pair<ll,ll>> ax3 = f(pos + 1,  used), ax2 = f(pos + 1, used + 1);
	ax2.f += ar[0][pos], 
	ax2.s.f += ar[1][pos], 
	ax2.s.s += ar[2][pos];
	su1 = 0, su2 = 0;

	su1 += ((mod & 1)? 1:-1)*ax3.f;
	su1 += ((mod & 2)? 1:-1)*ax3.s.f;
	su1 += ((mod & 4)? 1:-1)*ax3.s.s;

	su2 += ((mod & 1)? 1:-1)*ax2.f;
	su2 += ((mod & 2)? 1:-1)*ax2.s.f;
	su2 += ((mod & 4)? 1:-1)*ax2.s.s;
	//cout<<"   "<<ax1.f<<' '<<ax1.s.f<<' '<<ax1.s.s<<'\n';
	//cout<<"   "<<ax2.f<<' '<<ax2.s.f<<' '<<ax2.s.s<<'\n';
	//cout<<"   "<<pos<<' '<<used<<' '<<su1<<' '<<su2<<'\n';
	if(su1 > su2)
		return dp[pos][used] = ax3;
	else
		return dp[pos][used] = ax2;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n>>m;
	fore(i, 0, n) fore(j, 0, 3) cin>>ar[j][i];
	ll res = 0;
	fore(i, 0, 8)
	{
		mem(visited, 0);
		mod = i;
		anti.f = ((mod & 1) ? -MOD:MOD);
		anti.s.f = ((mod & 2) ? -MOD:MOD);
		anti.s.s = ((mod & 4) ? -MOD:MOD);
		ax1 = f(0, 0);
		//cout<<i<<' '<<ax1.f<<' '<<ax1.s.f<<' '<<ax1.s.s<<'\n';
		res = max(res, abs(ax1.f) + abs(ax1.s.f) + abs(ax1.s.s));
	}

	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2