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
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll pot(ll b, ll e, ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
ll A = 100001;
struct node
{
	int siz, from, to;
	ll tam, hs;
	node *child[26], *link, *par;
	vector<node*> g;
	char cha;
	node(int siz, int i, node *ax, int ch) : siz(siz), link(0), hs(0), from(0), to(0), tam(0), cha(ch), par(ax)
	{
		mem(child, 0);
		if(siz > 0)
		{
			from = i - siz + 1;
			to = i;
			if(siz == 1)
				hs = ch;
			else
				hs = ((ax -> hs * A % MOD) + ch + ch * pot(A, ax->siz + 1, MOD)) % MOD;
		}			
	}
};
typedef node* pnode;
string s;
pnode nodes[tam], ce, meu;
int posn;
void create(string s)
{
	ce = new node(0, 0, 0, 0);
	meu = new node(-1, 0, 0, 0);
	ce->link = meu->link = meu;
	pnode act = meu, suf, ax;
	int po;
	fore(i, 0, s.size())
	{
		po = s[i] - 'a';
		while(act->siz == i || s[i - act->siz - 1] != s[i])
			act = act->link;
		if(!act->child[po])
		{
			act->child[po] = new node(act->siz + 2, i, act, s[i]);
			nodes[posn++] = act->child[po];
			suf = act->link;
			act = act->child[po];
			while(s[i - suf->siz - 1] != s[i])
					suf = suf->link;
			act->link = act->siz == 1 ? ce : suf->child[po];
			act->link->g.pb(act);
		}
		else
			act = act->child[po];
		act->tam++;
	}
}
void f(pnode p)
{
	for(auto cat : p->g)
	{
		f(cat);
		p->tam += cat->tam;
	}
}
string asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
vector<vector<int>> table;
void sparceKMR(string &s)
{
	int n = s.size(), cc, ax;
	vector<int> sa(n), sa1(n), col(n), col1(n), head(n);
	fore(i, 0, n) sa[i] = i;
	asd = s;
	stable_sort(sa.begin(), sa.end(), cmp);
	head[0] = col[sa[0]] = cc = 0;
	fore(i, 1, n)
	{
		if(s[sa[i]] != s[sa[i-1]])
			cc++, head[cc] = i;
		col[sa[i]] = cc;
	}
	table.pb(col);
	for(int k = 1; k < n; k *= 2)
	{
		fore(i, 0, n)
		{
			ax = (sa[i] - k + n) % n;
			sa1[head[col[ax]]++] = ax;
		}
		swap(sa, sa1);
		col1[sa[0]] = head[0] = cc = 0;
		fore(i, 1, n)
		{
			if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
				cc++, head[cc] = i;
			col1[sa[i]] = cc;
		}
		col = col1;
		table.pb(col1);
	}
}
pair<int, int> query(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return mp(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
int lo , hi, mid ,res;
pair<int, int> le, ri;
bool comp(const pnode a, const pnode b)
{ 
	lo = 0,  hi = min(a->siz, b->siz) - 1, res = -1;
	le = query(a->from, a->from + hi), ri = query(b->from, b->from + hi);
	if(le == ri)
		return a->siz < b->siz;
	return le < ri;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, q;
	cin>>n>>q;
	cin>>s;
	create(s);
	f(ce);
	sparceKMR(s);
	sort(nodes, nodes + posn, comp);
	fore(i, 1, posn)
		nodes[i]->tam += nodes[i-1]->tam;
	ll a;
	while(q--)
	{
		cin>>a;
		lo = 0, hi = posn - 1, res = -1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(nodes[mid]->tam >= a)
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		if(res == -1)
			cout<<-1<<'\n';
		else
			cout<<nodes[res]->hs<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	