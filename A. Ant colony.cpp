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
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_nodo_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct nodo
{
	int mi, count, g;
};
nodo join(nodo a, nodo b)
{
	nodo res;
	if(a.mi == b.mi)
	{
		res.mi = a.mi;
		res.count = a.count + b.count;
		res.g = __gcd(a.g, b.g);
	}
	else
	{
		if(a.mi > b.mi)
		{
			res.mi = b.mi;
			res.count = b.count;
		}
		else

		{
			res.mi = a.mi;
			res.count = a.count;	
		}
		res.g = __gcd(a.g, b.g);
	}
	return res;
}
int ar[100010];
nodo t[400040];
void init(int b, int  e, int node)
{
	if(b == e)
	{
		t[node].mi = ar[b];
		t[node].count = 1;
		t[node].g = ar[b];
		return;
	}
	int l = 2 * node + 1, r = l + 1, mid = (b + e) / 2;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
nodo query(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
		return t[node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		return query(mid + 1, e, r, i, j);
	else if(mid >= j)
		return query(b, mid, l, i , j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n)
		cin>>ar[i];
	int q, a, b;
	cin>>q;
	nodo res;
	init(0, n -1, 0);
	while(q--)
	{
		cin>>a>>b;
		res = query(0, n - 1, 0, a - 1, b - 1);
		//cout<<res.mi<<' '<<res.g<<' '<<res.count<<'\n';
		if(res.mi == res.g)
			cout<<b - a + 1 - res.count<<'\n';
		else
			cout<<b - a + 1<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	