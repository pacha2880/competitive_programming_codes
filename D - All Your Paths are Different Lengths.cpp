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
	int n, tre[15], potre[16];
	potre[0] = 1;
	fore(i, 1, 16) potre[i] = potre[i-1] * 3;
	fore(i, 1, 15) tre[i] = potre[i] - 1;
	cin>>n;
	n--;
	int in = 1;
	int mul = 1;
	vector<pair<pair<int,int>, int>> ar;
	while(n >= potre[in]-1)
	{
		//cout<<potre[in]<<'\n';
		ar.pb(mp(mp(in-1, in), 0));
		ar.pb(mp(mp(in-1, in), mul));
		ar.pb(mp(mp(in-1, in), mul * 2));
		mul *= 3;
		in++;
	}
	/*fore(i, 0, ar.size())
		cout<<ar[i].f.f<<' '<<ar[i].f.s<<' '<<ar[i].s<<'\n';*/
	in--;
	n -= potre[in] - 1;
	int sus = potre[in] - 1;
	int ini;
	int an = in+1;
	ar.pb(mp(mp(in, an), 0));
	while(n > 0)
	{
		//cout<<n<<'\n';
		ini = 1;
		while(n > potre[ini] - 1)
			ini++;
		ini--;

		ar.pb(mp(mp(ini, an), sus + 1));
		n -= potre[ini];
		sus += potre[ini];
		if(n > potre[ini])
		{
			ar.pb(mp(mp(ini, an), sus + 1));
			sus += potre[ini];
			n -= potre[ini];
		}
	}
	cout<<an+1<<' '<<ar.size()<<'\n';;
	fore(i, 0, ar.size())
		cout<<ar[i].f.f+1<<' '<<ar[i].f.s+1<<' '<<ar[i].s<<'\n';
	return 0;
}