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
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int o, n;
	cin>>o>>n;
	ll can[n]; pair<ll, pair<int, ll>> ev[2 * n];
	ll res = 0;
	int a, b;
	mem(can, -1);
	fore(i, 0, n)
	{
		cin>>a>>b;
		ev[2 * i] = mp(a, mp(0, i));
		ev[2 * i + 1] = mp(b, mp(1, i));
	}
	sort(ev, ev + 2 * n);
	reverse(ev, ev + 2 * n);
	if(ev[0].f < o || ev[2 * n - 1].f > 0)
	{
		cout<<0;
		return 0;
	}
	ll su = 1, ausu = 0, pre = ev[0].f;
	can[ev[0].s.s] = 1;
	fore(i, 1, 2 * n)
	{
		//cout<<su<<' '<<ev[i].f<<' '<<ev[i].s.f<<' '<<ev[i].s.s<<'\n';
		if(ev[i].s.f == 0)
		{
			if(ev[i].f == 0)
				res = mod(res + can[ev[i].s.s]);
			su = mod(su - can[ev[i].s.s]);
			if(su == 0 && ausu == 0 && ev[i].f > 0)
			{
				cout<<0;
				return 0;
			}
		}
		else
		{
			if(ev[i].f < pre)
			{
				pre = ev[i].f;
				su = mod(su + ausu);
				ausu = 0;
			}
			can[ev[i].s.s] = su;
			ausu = mod(ausu + su);
		}
	}
	//fore(i, 0, n) cout<<can[i]<<'\n';
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	