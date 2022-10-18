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
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
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
const int tam = 300010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int N = 1e5;  // limit for array size
int n;  // array size
struct node
{
    int maxa, maxb;
    node() {maxa = maxb = -MOD;}
    node(int val) {maxa = val, maxb = -MOD;}
};
node join(node a, node b)
{
    if(a.maxa < b.maxa)
        swap(a.maxa, b.maxa);
    a.maxb = max(a.maxb, max(b.maxa, b.maxb));
    return a;
}
int ar[100000];
struct st
{
  node val;
  st* left;
  st* right;
  st() {left = right = NULL;}
  st(node x) {val = x; left = right = NULL;}
};
typedef st* pst;
void init(pst nodo, int b, int e)
{
  if(b == e)
  {
    nodo->val = node(ar[b]);
    return;
  }
  int mid = (b + e) / 2;
  nodo->left = new st();
  nodo->right = new st();
  init(nodo->left, b, mid);
  init(nodo->right, mid + 1, e);
  nodo->val = join(nodo->left->val, nodo->right->val);
}
void update(pst nodo, int b, int e, int pos, int val)
{
  if(b == e)
  {
    nodo->val = node(val);
    return;
  }
  int mid = (b + e) / 2;
  if(mid >= pos)
    update(nodo->left, b, mid, pos, val);
  else
    update(nodo->right, mid + 1, e, pos, val);
  nodo->val = join(nodo->left->val, nodo->right->val);
}
node query(pst nodo, int b, int e, int i, int j)
{
  if(b >= i && e <= j)
    return nodo->val;
  int mid = (b + e) / 2;
  if(mid >= j)
    return query(nodo->left, b, mid, i, j);
  if(mid < i)
    return query(nodo->right, mid + 1, e, i, j);
  return join(query(nodo->left, b, mid, i, j), query(nodo->right, mid + 1, e, i, j));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int m, a, b, c;
	cin>>n;
	fore(i, 0, n) cin>>ar[i];
  cin>>m;
  char ch;
  pst t = new st();
  init(t, 0, n - 1);
  node ras;

	while(m--)
	{
		cin>>ch>>a>>b;
        if(ch == 'U')
        {
          update(t, 0, n - 1, a - 1, b);
        }
        else
        {
            ras = query(t, 0, n - 1, a - 1, b - 1);
            cout<<ras.maxa + ras.maxb<<'\n';
        }
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	