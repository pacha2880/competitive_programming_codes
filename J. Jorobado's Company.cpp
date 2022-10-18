#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
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
int n;
struct item{
    int siz;
    ll key, tot, lazy;
    bool lef;
    item *l, *r, *p;
    item() {}
    item(int key) : key(key), tot(key), lazy(0), siz(1), l(0), r(0), p(0) {}
};
typedef item* pitem;
int tot(pitem t)
{
    return (t?t->tot:0);
}
int siz(pitem t)
{
    return (t?t->siz:0);
}
void push(pitem t)
{
	if(t && t->lazy)
	{
		t->key = (t->key + t->lazy) % MOD;
		t->tot = (t->lazy * t->siz % MOD + t->tot) % MOD;
		if(t->l) t->l->lazy = (t->l->lazy + t->lazy) % MOD;
		if(t->r) t->r->lazy = (t->r->lazy + t->lazy) % MOD;
		t->lazy = 0;
	}
}
void up_sz(pitem t)
{
    if(t)
    {
    	push(t->l);
    	push(t->r);
    	t->siz = siz(t->l) + 1 + siz(t->r);
    	t->tot = (tot(t->l) + t->key + tot(t->r)) % MOD;
    }
}
void rotate(pitem t)
{
	push(t->p);
	push(t);
	if(t->lef)
	{
		t->p->l = t->r;
		if(t->r)
			t->r->p = t->p, t->r->lef = true;
		t->r = t->p;
	}
	else
	{
		t->p->r = t->l;
		if(t->l)
			t->l->p = t->p, t->l->lef = false;
		t->l = t->p;
	}
	swap(t->lef, t->p->lef);
	t->p->lef ^= 1;
	pitem ax = t->p->p;
	t->p->p = t;
	up_sz(t->p);
	up_sz(t);
	t->p = ax;
	if(ax)
		if(t->lef) ax->l = t;
		else ax->r = t;
}
void splay(pitem t)
{
	while(t->p)
	{
		if(t->p->p)
		{
			if(t->lef == t->p->lef)
				rotate(t->p);
			else
				rotate(t);
		}
		rotate(t);
	}
}
pitem search(pitem t, int val)
{
	push(t);
	if(val > t->key && t->r)
		return search(t->r, val);
	if(val < t->key && t->l)
		return search(t->l, val);
	splay(t);
	return t;
}
void merge(pitem &t, pitem l, pitem r)
{
	if(!l || !r) t = l ? l : r;
	else
	{
		t = search(l, MOD);
		r->p = t;
		r->lef = false;
		t->r = r;
	}
	up_sz(t);
}
void splitl(pitem &l, pitem &r)
{
	splay(l);
	r = l->r;
	l->r = 0;
	if(r) r->p = 0;
	up_sz(l);
	up_sz(r);
}
void splitr(pitem &l, pitem &r)
{
	splay(r);
	l = r->l;
	r->l = 0;
	if(l) l->p = 0;
	up_sz(r);
	up_sz(l);
}
pitem iz[200020];
pitem der[200020];
int ini[200020];
vector<int> g[200020];
void dfs(int node, pitem &t)
{
	//cout<<node<<'\n';
	iz[node] = new item(ini[node]);
	merge(t, t, iz[node]);
	fore(i, 0, g[node].size())
		dfs(g[node][i], t);
	der[node] = new item(ini[node]);
	merge(t, t, der[node]);
}
ll pot(ll b, ll e)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int q;
	cin>>n>>q;
	fore(i, 0, n)
		cin>>ini[i];
	int a, b, c;
	fore(i, 1, n)
	{
		cin>>a;
		g[a - 1].pb(i);
	}
	pitem t = 0, t1, t2, t3;
	dfs(0, t);
	ll dos = pot(2, MOD - 2);
	while(q--)
	{
		cin>>a>>b;
		if(a == 1)
		{
			cin>>c;
			b--;
			c--;
			splitr(t1, iz[b]);
			splitl(der[b], t2);
			merge(t1, t1, t2);
			splay(iz[c]);
			t3 = iz[c]->r;
			t3->p = 0;
			iz[c]->r = 0;
			up_sz(iz[c]);
			merge(t1, iz[c], der[b]);
			merge(t, t1, t3);
		}
		else if(a == 2)
		{
			cin>>c;
			c--;
			splitr(t1, iz[c]);
			splitl(der[c], t2);
			der[c]->lazy = (der[c]->lazy + b) % MOD;
			merge(t1, t1, der[c]);
			merge(t, t1, t2);
		}
		else
		{
			b--;
			splitr(t1, iz[b]);
			splitl(der[b], t2);
			cout<<der[b]->tot * dos % MOD<<'\n';
			merge(t1, t1, der[b]);
			merge(t, t1, t2);
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	