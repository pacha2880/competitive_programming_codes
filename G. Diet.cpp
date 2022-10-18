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
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)

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
const ll MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct nodo
{
	ll pre, mini, can;
	nodo() {}
	nodo(ll pre, ll mini, ll can) : pre(pre), mini(mini), can(can) {}
};
nodo join(nodo a, nodo b)
{
	a.mini = min(a.mini, a.pre + b.mini);
	a.pre += b.pre;
	a.can += b.can;
	return a;
}
nodo ar[tam], t[tam * 4];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = ar[b];
		//cout<<"mana "<<node<<' '<<t[node].pre<<' '<<t[node].mini<<'\n';
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
void update(int b, int e, int node, int pos, nodo val)
{
	if(b == e)
	{
		t[node] = val;
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid >= pos)
		update(b, mid, l, pos, val);
	else
		update(mid + 1, e, r, pos, val);
	t[node] = join(t[l], t[r]);
}
int cuan(int b, int e, int node, ll x)
{
	if(x >= t[node].pre)
		return 0;
	if(b == e) return t[node].can;
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(t[l].pre <= x)
		return cuan(mid + 1, e, r, x - t[l].pre);
	return t[r].can + cuan(b, mid, l, x);
}
vector<int> eli;
void vaca(int b, int e, int node, ll x)
{
	//cout<<"vaca "<<b<<' '<<e<<' '<<' '<<node<<' '<<t[node].mini<<' '<<t[node].pre<<' '<<x<<'\n';
	if(x <= t[node].mini)
		return;
	if(b == e)
	{
		eli.pb(b);
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	vaca(b, mid, l, x);
	vaca(mid + 1, e, r, x - t[l].pre);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	ll a, b, c, d;
	fore(i, 0, n)
	{
		cin>>a>>b;
		ar[i] = {a, a + b, 1};
	}
	init(0, n - 1, 0);
	int q;
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		if(a == 1)
		{
			c = cuan(0, n - 1, 0, b);
			eli.clear();
			vaca(0, n - 1, 0, b);
			cout<<eli.size()<<' '<<c<<'\n';
			fore(i, 0, eli.size())
			{
				update(0, n - 1, 0, eli[i], {0, (ll)(2e18 + 1), 0});
			}
		}
		else
		{
			cin>>c>>d;
			update(0, n - 1, 0, d - 1, {b, b + c, 1});
		}
	}
	return 0;	
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	