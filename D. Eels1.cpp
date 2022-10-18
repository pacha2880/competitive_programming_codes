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
	int key, pri, siz, mini, can, cant;
	ll sum;
	item *l, *r;
	item() {}
	item(int key) : key(key), siz(1), pri(rand()),
		mini(key), sum(key), can(1), cant(1) {l = r = NULL;}
};
typedef item*pitem;
int sz(pitem &t)
{
	return (t?t->siz:0);
}
void up_sz(pitem &t)
{
	if(t)
	{
		t->siz = sz(t->l) + 1 + sz(t->r);
		t->sum = 1ll * t->can * t->key;
		t->cant = t->can;
		if(t->l)
		{
			t->cant += t->l->cant;
			t->sum += t->l->sum;
			t->mini = t->l->mini;
		}
		else
		{
			t->mini = t->key;
		}
		if(t->r)
		{
			t->cant += t->r->cant;
			t->sum += t->r->sum;
		}
	}
}
void split(pitem t, pitem &l, pitem &r, ll val)
{
	if(!t) r = l = NULL;
	else if(t->key < val) split(t->r, t->r, r, val), l = t;
	else split(t->l, l, t->l, val), r = t;
	up_sz(t);
}
void merge(pitem &t, pitem l, pitem r)
{
	if(!l || !r) t = (l?l:r);
	else if(l->pri >= r->pri) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	up_sz(t);
}
void print(pitem t)
{
	if(t)
	{
		print(t->l);
		cout<<t->key<<','<<t->can<<' ';
		print(t->r);
	}
}
pitem t1, t2, t3;
int anal(pitem &t, ll su)
{
	pitem t1, t2;
	if(!t) return 0;
	int res;
	split(t, t1, t2, (t->mini + su) * 2 + 1);
	//if(!t1) {cout<<"chancho\n"; print(t2);exit(0);}
	if(t2 == NULL || (t1->sum + su) * 2 < t2->mini)
		res = t1->cant - 1 + anal(t2, t1->sum + su);
	else
		res = t1->cant + anal(t2, t1->sum + su);
	merge(t, t1, t2);
	return res;
}
void add(int x, pitem &t)
{
	//cout<<'a';
	split(t, t1, t2, x);
	//cout<<'b';
	split(t2, t2, t3, x + 1);
	//cout<<'c';
	if(t2 == NULL)
	{
		t2 = new item(x);
	}
	else
		t2->can++;
	merge(t2, t2, t3);
	//cout<<'e';
	merge(t, t1, t2);
	//cout<<'f';
	//cout<<'\n';
}
void kill(int x, pitem &t)
{
	split(t, t1, t2, x);
	split(t2, t2, t3, x + 1);
	t2->can--;
	if(t2->can == 0)
	{
		delete t2;
		merge(t, t1, t3);
	}
	else
	{
		merge(t2, t2, t3);
		merge(t, t1, t2);	
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	pitem t = NULL;
	int q;
	cin>>q;
	char ch;
	int x;
	fore(i, 0, q)
	{
		//cout<<"el "<<i<<'\n';
		cin>>ch>>x;
		//cout<<t<<'\n';
		//if(t == NULL) cout<<"chapare\n";
		if(ch == '+')
			add(x, t);
		else
			kill(x, t);
		//cout<<t<<'\n';
		//print(t);
		//cout<<"el "<<i<<' '<<ch<<' '<<x<<'\n';
		cout<<anal(t, 0)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	