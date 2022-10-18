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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

int ar[200020], t[800080], lazy[800080];
pair<int, int> pars[100010];
void update(int b, int e, int node, int i, int j, int val)
{
	//cout<<b<<' '<<e<<'\n';
	if(j < b || i > e) return;
	if(i <= b && j >= e)
	{
		t[node] += val;
		lazy[node] += val;
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	t[l] += lazy[node];
	lazy[l] += lazy[node];
	t[r] += lazy[node];
	lazy[r] += lazy[node];
	lazy[node] = 0;
	if(mid >= j)
		update(b, mid, l, i, j, val);
	else if(mid < i)
		update(mid + 1, e, r, i, j, val);
	else
	{
		update(b, mid, l, i, j, val);
		update(mid + 1, e, r, i, j, val);
	}
	t[node] = max(t[l], t[r]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	int a, b, c, d;
	vector<pair<int, pair<int, int>>> sweep;
	fore(i, 0, n)
	{
		cin>>a>>b>>c>>d;
		sweep.pb(mp(b, mp(1, i)));
		sweep.pb(mp(d, mp(0, i)));
	}
	sort(all(sweep));
	int con = 0;
	fore(i, 0, 2 * n)
	{
		//cout<<i<<'\n';
		if(sweep[i].s.f == 0)
		{
			con++;
			update(0, 2 * n - 1, 0, i, i, con);
			//cout<<con<<' ';
			pars[sweep[i].s.s].f = i;
		}
		else
		{
			update(0, 2 * n - 1, 0, i, i, con);
			//cout<<con<<' ';
			con--;
			pars[sweep[i].s.s].s = i;	
		}
	}
	//cout<<'\n';
	int res = 0; con = 0;
	fore(i, 0, 2 * n)
	{
		//cout<<i<<'\n';
		//cout<<sweep[i].f<<' '<<sweep[i].s.f<<' '<<sweep[i].s.s<<"   -     "<<pars[sweep[i].s.s].f<<' '<< pars[sweep[i].s.s].s<<'\n';
		if(sweep[i].s.f == 0)
		{
			con++;
			update(0, 2 * n - 1, 0, pars[sweep[i].s.s].f, pars[sweep[i].s.s].s, -1);
			//cout<<t[0]<<' '<<con<<'\n';
			res = max(res, t[0] + con);
		}
		else
		{
			res = max(res,t[0] + con);
			//cout<<t[0]<<' '<<con<<'\n';
			con--;
		}
	}
    cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	 