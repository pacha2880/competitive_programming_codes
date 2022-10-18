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
pair<int, int> l[200020], r[200020];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int cas;
	cin>>cas;
	int n;
	ll res = 0;
	int a, b, c;
	int le = 0, ri = 0;
	set<int> lef, rig;
	while(cas--)
	{
		//cout<<"xas "<<cas<<'\n';
		cin>>n;
		res = 0;
		le = 0, ri = 0;
		lef.clear();
		rig.clear();
		//cout<<"cha";
		fore(i, 0, n)
		{
			//cout<<i<<'\n';
			cin>>c>>a>>b;
			res += min(a, b);
			if(a > b)
			{
				l[le++] = {a - b, c - 1};
			}
			else
				r[ri++] = {b - a, n - c - 1};
		}
		fore(i, 0, le)
			lef.insert(i);
		fore(i, 0, ri)
			rig.insert(i);
		sort(l, l + le);
		reverse(l, l + le);
		sort(r, r + ri);
		reverse(r, r + ri);
		set<int>::iterator it;
		//cout<<le<<' '<<ri<<' '<<res<<'\n';
		fore(i, 0, le)
		{
			//cout<<i<<'\n';
			it = lef.lower_bound(l[i].s);
			if(it != lef.end() && *it == l[i].s)
			{
				res += l[i].f;
				lef.erase(it);
			}
			else
			{
				if(it == lef.begin())
				{
					it = lef.end();
					it--;
					lef.erase(it);
				}
				else
				{
					it--;
					res += l[i].f;
					lef.erase(it);
				}
			}
		}
		fore(i, 0, ri)
		{
			//cout<<i<<'\n';
			it = rig.lower_bound(r[i].s);
			if(it != rig.end() && *it == r[i].s)
			{
				res += r[i].f;
				rig.erase(it);
			}
			else
			{
				if(it == rig.begin())
				{
					it = rig.end();
					it--;
					rig.erase(it);
				}
				else
				{
					it--;
					res += r[i].f;
					rig.erase(it);
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	