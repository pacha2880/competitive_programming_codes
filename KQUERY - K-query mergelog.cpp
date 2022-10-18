#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
int ar[tam];
vector<pair<int, pair<int, int>>> t[4 * tam];
void merg(vector<pair<int, pair<int, int>>> &l, vector<pair<int, pair<int, int>>> &r, vector<pair<int, pair<int, int>>> &t)
{
	int il = 0, ir = 0;
	while(il < l.size() || ir < r.size())
	{
		if(il < l.size() && ir < r.size())
		{
			if(l[il].f < r[ir].f)
			{
				t.pb({l[il].f, {il, ir}});
				il++;
			}
			else
			{
				t.pb({r[ir].f, {il, ir}});
				ir++;	
			}
		}
		else if(il < l.size())
		{
			t.pb({l[il].f, {il, MOD}});
			il++;
		}
		else
		{
			t.pb({r[ir].f, {MOD, ir}});
			ir++;
		}
	}
}
void init(int node, int b, int e)
{
	if(b == e)
	{
		t[node].assign(1, {ar[b], {MOD, MOD}});
		return;
	}
	index;
	init(l, b, mid);
	init(r, mid + 1, e);
	merg(t[l], t[r], t[node]);
}

int query(int node, int b, int e, int i, int j, int val, bool bo)
{
	if(val == MOD) return 0;
	if(bo)
	{
		vector<pair<int, pair<int, int>>>::iterator it;
		it = upper_bound(t[node].begin(), t[node].end(), mp(val, mp(MOD, MOD)));
		if(it == t[node].end()) return 0;
		index;
		if(mid >= j)
			return query(l, b, mid, i, j, it->s.f, false);
		if(mid < i)
			return query(r, mid + 1, e, i, j, it->s.s, false);
		return query(l, b, mid, i, j, it->s.f, false) + query(r, mid + 1, e, i, j, it->s.s, false);
	}
	if(b >= i && e <= j)
		return (int)t[node].size() - val;
	index;
	if(mid >= j)
		return query(l, b, mid, i, j, t[node][val].s.f, false);
	if(mid < i)
		return query(r, mid + 1, e, i, j, t[node][val].s.s, false);
	return query(l, b, mid, i, j, t[node][val].s.f, false) + query(r, mid + 1, e, i, j, t[node][val].s.s, false);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n) cin>>ar[i];
	init(0, 0, n - 1);
	int a, b, c;
	int m;
	cin>>m;
	while(m--)
	{
		cin>>a>>b>>c;
		cout<<query(0, 0, n - 1, a - 1, b - 1, c, true)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	