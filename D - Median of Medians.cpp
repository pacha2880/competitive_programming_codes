#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
//#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
struct item
{
	int key, prior, sz;
	item *l, *r;
	item() {}
	item(int key) : key(key), prior(rand()), l(NULL), r(NULL) {}
};
typedef item * pitem;
int sz(pitem t)
{
	return t ? t -> sz : 0;
}
void up_sz(pitem t)
{
	if(t)
		t->sz = sz(t->l) + 1 + sz(t->r);
}
void merge(pitem &t, pitem l, pitem r)
{
	if(!l || !r) t = l ? l : r;
	else if(r -> prior > l->prior)
		merge(r->l, l, r->l) ,t = r;
	else
		merge(l->r, l->r, r), t = l;
	up_sz(t);
}
void split(pitem t, pitem &l, pitem &r, int val)
{
	if(!t) l = r = NULL;
	else if(val > t->key)
		split(t->r, t->r, r, val), l = t;
	else
		split(t->l, l, t->l, val), r = t; 
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
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	ll x;
	cin>>n;
	x = (ll)n * (n + 1) / 2;
	int ar[n];
	set<int> st;
	fore(i, 0, n)
	{
		cin>>ar[i];
		st.insert(ar[i]);
	}
	int mar[st.size()];
	int siz = st.size();
	int con = 0;
	for(set<int>::iterator it = st.begin(); it != st.end(); it++)
		mar[con] = *it, con++;
	int lo = 0, hi = siz -1;
	int mid, res = -1;
	pitem t = NULL, t1, t2, t3;
	while(lo <= hi)
	{
		//cout<<0<<'\n';
		erase(t);
		t = new item(0);
		mid = (lo + hi) / 2;
		//cout<<"     "<<lo<<' '<<hi<<'\n';
		int su = 0;
		ll sum = 0;
		fore(i, 0, n)
		{
			su += ar[i] >= mar[mid]? 1: -1;
			split(t, t1, t2, su+1);
			sum += sz(t1);
			//cout<<su<<','<<sum<<' '<<'\n';
			t3 = new item(su);
			merge(t1, t1, t3);
			merge(t, t1, t2);
		}
		//cout<<mid<<' '<<mar[mid]<<' '<<x<<' '<<sum<<'\n';
		if(sum >= x / 2 + (x&1))
			res = mid, lo = mid +1;
		else
			hi = mid -1;
		//cout<<res<<'\n';
	}
	//cout<<res<<'\n';
	cout<<mar[res];
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2