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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll ar[tam], t[4 * tam], lazy[4 * tam];
void init(int node, int b, int e)
{
	if(b == e)
	{
		t[node] = ar[b];
		return;
	}
	index;
	init(l, b, mid);
	init(r, mid + 1, e);
	t[node] = min(t[l], t[r]);
}
void push(int node, int b, int e)
{
	if(lazy[node] != 0)
	{
		t[node] += lazy[node];
		if(b < e)
		{
			lazy[node * 2 + 1] += lazy[node];
			lazy[node * 2 + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int b, int e, int i, int j, int val)
{
	if(b > e) return;
	push(node, b, e);
	if(e < i || b > j) return;
	if(i <= b && j >= e)
	{
		lazy[node] += val;
		push(node, b, e);
		return;
	}
	index;
	update(l, b, mid, i, j, val);
	update(r, mid + 1, e, i, j, val);
	t[node] = min(t[l], t[r]);
}
ll query(int node, int b, int e, int i, int j)
{
	push(node, b, e);
	if(b >= i && e <= j)
		return t[node];
	index;
	if(mid >= j)
		return query(l, b, mid, i, j);
	if(mid < i)
		return query(r, mid + 1, e, i, j);
	return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
int in[10];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, a, b, c;
	cin>>n;
	fore(i, 0, n) cin>>ar[i];
	init(0, 0, n - 1);
	cin>>m;
		cin.ignore();
	fore(i, 0, m)
	{
		string s;
		stringstream sc;
		getline(cin, s);
		sc << s;
		int ta = 0;
		while(sc >> in[ta++]);
		ta--;
		// cout<<ta<<'\n';
		// cout<<in[i]<<'-';
		// cout<<"cas "<<i<<'\n';
		if(ta == 2)
		{
			if(in[0] > in[1])
				cout<<min(query(0, 0, n - 1, in[0], n - 1), query(0, 0, n - 1, 0, in[1]))<<'\n';
			else
				cout<<query(0, 0, n - 1, in[0], in[1])<<'\n';
		}
		else
		{
			if(in[0] > in[1])
			{
				update(0, 0, n - 1, in[0], n - 1, in[2]);
				update(0, 0, n - 1, 0, in[1], in[2]);
			}
			else
				update(0, 0, n - 1, in[0], in[1], in[2]);
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	