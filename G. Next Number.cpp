#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
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
int mini = -1, n, b;
int ar[400000];
int parent[400000][2];
int t[3000000][2];
void init(int be, int e, int node, int pa)
{
	if(be == e)
	{
		t[node][pa] = parent[node][pa];
		return;
	}
	int mid = (be + e) / 2, l = node * 2 + 1, r = l + 1;
	init(be, mid, l, pa);
	init(mid + 1, e, r, pa);
	t[node][pa] = 0;
}
void update(int be, int e, int node, int i, int j, int val, int pa)
{
	if(be >= i && e <= j)
	{
		t[node][pa] = val;
		return;
	}
	int mid = (be + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid < i)
		update(mid + 1, e, r, i, j, val, pa);
	else if(mid >= j)
		update(be, mid, l, i, j, val, pa);
	else
	{
		update(mid + 1, e, r, i, j, val, pa);
		update(be, mid, l, i, j, val, pa);
	}
}
int query(int be, int e, int node, int pos, int pa)
{
	if(be == e)
		return t[node][pa];
	if(t[node][pa])
		return t[node][pa];
	int mid = (be + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid >= pos)
		return query(mid + 1, e, r, pos, pa);
	else
		return query(be, mid, l, pos, pa);
}
int find(int x, int pa)
{
	int par = query(0, b, 0, x, pa);
	if(par == x) return x;
	int pur = find(par, pa);
	update(0, b, 0, x, x, pur, pa);
	return pur;
}
void su(int po)
{
	int pu = find(ar[po],0);
	if(pu == b)
	{
		mini = po;
		if(po == 0)
			return;
		int aba = find(ar[po],1);
		update(0, b, 0, aba, ar[po], ar[po], 0);
		update(0, b, 0, ar[po] + 1, b, ar[po] + 1, 1);
		su(po-1);
	}
	else
	{

	}
}
bool ex[400000];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	memset(parent, -1, sizeof(parent));
	cin>>n>>b;
	for(int i = 0; i <= b; i++)
		parent[i][0] = parent[i][1] = i;
	for(int i = 0; i < n; i++)
		cin>>ar[i];
	int ax, ax0;
	for(int i = 0; i < n; i++)
	{
		if(ex[ar[i]])
		{
			mini = i + 1;
			su(i);
			break;
		}
		ex[ar[i]] = 1;
		ax0 = find(ar[i] + 1, 0);
		update(0, b, 0, ar[i], ar[i], ax0, 0);
		if(ar[i] > 0 && ex[ar[i]-1])
		{
			ax = find(ar[i] - 1, 1);
			update(0, b, 0, ar[i], ax0, ax, 1);
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS