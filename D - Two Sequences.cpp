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
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	int n;
	cin>>n;
	int ar[2][n];
	fore(i, 0, 2) fore(j, 0, n) cin>>ar[i][j];
	int ax[2][n];
	int t;
	int pl, pr, pll, prr;
	int res = 0;
	fore(i, 1, 30)
	{
		t = 1 << i;
		fore(i, 0, 2) fore(j, 0, n) ax[i][j] = ar[i][j] % t;
		fore(i, 0, 2) sort(ax[i], ax[i] + n);
		pl = pll = n-1;
		prr = pr = n-1;
		t /= 2;
		/*cout<<'\n';
		fore(i, 0, 2)
		{
			fore(j, 0, n) cout<<ax[i][j]<<' ';
			cout<<'\n';
		}cout<<'\n';*/
		fore(j, 0, n)
		{
			while(pl > -1 && ax[0][pl] + ax[1][j] >= t)
				pl--;
			while(pr > -1 && ax[0][pr] + ax[1][j] >= 2 * t)
				pr--;
			//pll = prr = pr;
			while(pll > -1 && ax[0][pll] + ax[1][j] >= 3 * t)
				pll--;
			while(prr > -1 && ax[0][prr] + ax[1][j] >= 4 * t)
				prr--;
			//cout<<pl<<' '<<pr<<' '<<pll<<' '<<prr<<'\n';
			//cout<<i<<' '<<j<<' '<<pr - pl + prr - pll - 2<<'\n';
			res ^= ((pr - pl + prr - pll) & 1) << (i-1);
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2