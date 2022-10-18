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
struct item{
    int key, siz;
    bool lef;
    item *l, *r, *p;
    item() {}
    item(int key) : key(key), siz(1), l(0), r(0), p(0) {}
};
typedef item* pitem;
int sz(pitem t)
{
    return (t?t->siz:0);
}
void up_sz(pitem t)
{
    if(t) t->siz = sz(t->l) + 1 + sz(t->r);
}
void rotate(pitem t)
{
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
	if(val > t->key && t->r)
		return search(t->r, val);
	if(val < t->key && t->l)
		return search(t->l, val);
	splay(t);
	return t;
}
void split(pitem t, pitem &l, pitem &r, int val)
{
	if(!t) {l = r = 0; return;}
	t = search(t, val);
	if(t->key >= val)
	{
		l = t->l;
		t->l = 0;
		r = t;
		if(l) l->p = 0;
	}
	else
	{
		r = t->r;
		t->r = 0;
		l = t;	
		if(r) r->p = 0;
	}
	up_sz(l);
	up_sz(r);
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
void erase(pitem t)
{
    if(t)
    {
        erase(t->l);
        erase(t->r);
        delete t;
    }
}
void print(pitem t)
{
    if(t)
    {
    	cout<<'(';
        print(t->l);
        cout<<t->key<<' ';
        print(t->r);
        cout<<')';
    }
}
int ar[200020];
map<int, pitem> ma;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, q;
	cin>>n>>q;
	pitem t1, t2, t3, t4;
	fore(i, 0, n)
	{
		cin>>ar[i];
		if(!ma.count(ar[i]))
		{
			ma[ar[i]] = new item(i);
		}
		else
		{
			t1 = ma[ar[i]];
			split(t1, t2, t3, i);
			t4 = new item(i);
			merge(t1, t2, t4);
			merge(t1, t1, t3);
			ma[ar[i]] = t1;
		}
	}
	int a, b;
	while(q--)
	{
		cin>>a>>b;
		t1 = ma[ar[a]];
		split(t1, t1, t2, a);
		split(t2, t2, t3, a + 1);
		delete t2;
		merge(t1, t1, t3);
		ma[ar[a]] = t1;
		ar[a] = b;
		t1 = ma[ar[a]];
		split(t1, t2, t3, a);
		cout<<sz(t2)<<'\n';
		t4 = new item(a);
		merge(t1, t2, t4);
		merge(t1, t1, t3);
		ma[ar[a]] = t1;
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	