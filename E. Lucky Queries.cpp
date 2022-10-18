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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct nodo
{
	int cua, sie, inc, dec;
	nodo() {}
	nodo(int cua, int sie, int inc, int dec) :
		cua(cua), sie(sie), dec(dec), inc(inc) {}
};
nodo join(nodo a, nodo b)
{
	return {a.cua + b.cua, a.sie + b.sie, 
			max(a.cua + b.inc, a.inc + b.sie),
			max(a.sie + b.dec, a.dec + b.cua)};
}
int ar[tam], lazy[4 * tam];
nodo t[4 * tam];
void init(int node, int b, int e)
{
	if(b == e)
	{
		t[node] = {ar[b] == 4, ar[b] == 7, 1, 1};
		return;
	}
	index;
	init(l, b, mid);
	init(r, mid + 1, e);
	t[node] = join(t[l], t[r]);
}
void push(int node, int b, int e)
{
	if(lazy[node] != 0)
	{
		if(lazy[node] & 1)
		{
			swap(t[node].cua, t[node].sie);
			swap(t[node].inc, t[node].dec);
		}
		if(b < e)
		{
			lazy[node * 2 + 1] += lazy[node];
			lazy[node * 2 + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int b, int e, int i, int j)
{
	if(b > e) return;
	push(node, b, e);
	if(e < i || b > j) return;
	if(i <= b && j >= e)
	{
		lazy[node] ++;
		push(node, b, e);
		return;
	}
	index;
	update(l, b, mid, i, j);
	update(r, mid + 1, e, i, j);
	t[node] = join(t[l], t[r]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	fore(i, 0, n)
		ar[i] = s[i] - '0';
	init(0, 0, n - 1);
	while(m--)
	{
		cin>>s;
		if(s == "count")
			cout<<t[0].inc<<'\n';
		else
		{
			int a, b;
			cin>>a>>b;
			update(0, 0, n - 1, a - 1, b - 1);
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	