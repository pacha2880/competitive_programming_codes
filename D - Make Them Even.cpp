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
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	int ar[n][m];
	fore(i, 0, n)
		fore(j, 0, m)
			cin>>ar[i][j];
	string imp = "";
	int con = 0;
	vector<pair<pair<int,int>, pair<int, int>>> v;
	fore(i, 0, n)
		fore(j, 0, m)
		{
			if(ar[i][j]&1)
			{
				if(j == m-1)
				{
					if(i == n-1)
					{

					}
					else
					{
						ar[i+1][j]++;
						v.pb(mp(mp(i+1,j+1),mp(i+2,j+1)));
					}
				}
				else
				{
					ar[i][j+1]++;
					v.pb(mp(mp(i+1,j+1),mp(i+1,j+2)));
				}
			}
		}
		cout<<v.size()<<'\n';
		fore(i, 0, v.size()) cout<<v[i].f.f<<' '<<v[i].f.s<<' '<<v[i].s.f<<' '<<v[i].s.s<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2