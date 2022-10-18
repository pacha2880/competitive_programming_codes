#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
//#define sz(a)			(int)a.size()
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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

struct item{
    ll key, pri, siz;
    ll su;
    item *l, *r;
    item() {}
    item(int key) : key(key), siz(1), pri(rand()), l(0), r(0), su(key) {}
};
typedef item* pitem;
int sz(pitem t)
{
    return (t?t->siz:0);
}
ll su(pitem t)
{
	return (t?t->su:0);
}
void up_sz(pitem t)
{
    if(t) 
    {
    	t->siz = sz(t->l) + 1 + sz(t->r);
    	t->su = su(t->l) + t->key + su(t->r);
    }
}
void split(pitem t, pitem &l, pitem &r, int val)
{
    if(!t) r = l = NULL;
    else if(t->key < val) split(t->r, t->r, r, val), l = t;
    else split(t->l, l, t->l, val), r = t;
    up_sz(t);
}
void merge(pitem &t, pitem l, pitem r)
{
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

void print(pitem t)
{
    if(t)
    {
        print(t->l);
        cout<<t->key<<' ';
        print(t->r);
    }
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int a;
	ll res = 0;
	pitem t = 0, t1 = 0, t2 = 0, t3 = 0;
	fore(i, 0, n)
	{
		//cout<<i<<'\n';
		if(i > 0) cout<<' ';
		cin>>a;
		//cout<<'w';
		split(t, t1, t2, a + 1);
		//cout<<i<<' ';
		res += su(t2);
		//cout<<'b';
		cout<<res;
		t3 = new item(a);
		//cout<<'c';
		merge(t2, t3, t2);
		//cout<<'d';
		merge(t, t1, t2);
		//cout<<'e';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	