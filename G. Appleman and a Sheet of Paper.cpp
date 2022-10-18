#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
// #define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct item{
    int key, pri, siz,su, lazy;
    item *l, *r;
    item() {}
    item(int key) : key(key), siz(1), pri(rng()), l(0), r(0), su(key), lazy(0) {}
};
typedef item* pitem;
int sz(pitem t)
{
    return (t?t->siz:0);
}
int su(pitem t)
{
	return (t?t->su:0);
}
void up_sz(pitem t)
{
    if(t) {
    	t->siz = sz(t->l) + 1 + sz(t->r);
    	t->su = su(t->l) + t->key + su(t->r);
    }
}
void push(pitem t)
{
	if(t && t->lazy)
	{
		swap(t->l, t->r);
		if(t->l) t->l->lazy ^= 1;
		if(t->r) t->r->lazy ^= 1;
		t->lazy = 0;
	}
}
void split(pitem t, pitem &l, pitem &r, int val)
{
	push(t);
    if(!t) r = l = NULL;
    else if(sz(t->l) < val) split(t->r, t->r, r, val - sz(t->l) - 1), l = t;
    else split(t->l, l, t->l, val), r = t;
    up_sz(t);
}
void merge(pitem &t, pitem l, pitem r)
{
	push(l); push(r);
    if(!l || !r) t=(l?l:r);
    else if(l->pri >= r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l),t=r;
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
void cut(pitem t, vi &v)
{
	push(t);
	if(t)
	{
		cut(t->l, v);
		v.pb(t->key);
		cut(t->r, v);
		delete t;
	}
}
void print(pitem t)
{
	push(t);
    if(t)
    {
        print(t->l);
        cout<<t->key<<' ';
        print(t->r);
    }
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, q, a, b, c;
	cin>>n>>q;
	pitem t = 0, t1 = 0, t2 = 0, t3 = 0;
	fore(i, 0, n)
		merge(t, t, new item(1));
	while(q--)
	{
		cin>>a>>b;
		if(a == 1)
		{
			if(b <= n / 2)
			{
				split(t, t, t1, b);
				split(t1, t1, t2, b);
				vi le, ri;
				cut(t, le);
				reverse(all(le));
				cut(t1, ri);
				t = 0;
				// print(t2);cout<<'\n';
				fore(i, 0, le.size())
				{
					merge(t, t, new item(le[i] + ri[i]));
				}
				// print(t);cout<<'\n';
				merge(t, t, t2);
				// print(t);cout<<'\n';
				n -= b;
			}
			else
			{
				// cout<<b<<' '<<n - b<<'\n';
				split(t, t, t1, b);
				split(t, t, t2, b - n + b);
				// cout<<"chacha\n";
				// print(t);cout<<'\n';
				// print(t2);cout<<'\n';
				// print(t1);cout<<'\n';
				vi le, ri;
				cut(t2, le);
				reverse(all(le));
				cut(t1, ri);
				t1 = 0;
				fore(i, 0, le.size())
				{
					merge(t1, t1, new item(le[i] + ri[i]));
				}
				t->lazy = 1;
				// print(t1); cout<<'\n';
				// print(t); cout<<'\n';
				merge(t, t1, t);
				n -= n - b;
			}
		}
		else
		{
			cin>>c;
			split(t, t, t1, c);
			split(t, t, t2, b);
			cout<<su(t2)<<'\n';
			merge(t, t, t2);
			merge(t, t, t1);
		}
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
