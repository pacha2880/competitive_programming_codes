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
int pos[400];
struct node
{
	int siz, dpt, dph;
	char ch;
	node *child[4], *link[20], *par;
	node(int siz, node *par, char ch) : ch(ch), siz(siz), par(par), dpt(-1), dph(0) 
	{
		mem(link, 0);
		mem(child, 0);
	}
};
typedef node* pnode;
pnode nodes[tam], meu, ce;
int posn;
void create(string s)
{
	meu = new node(-1, 0, '$');
	ce = new node(0, 0, '#');
	pnode act = meu, suf;
	fore(i, 0, 20)
		meu->link[i] = ce->link[i] = meu;
	ce->dpt = ce->dph = meu->dpt = meu->dph = 0;
	int po, i;
	posn = 0;
	fore(i, 0, s.size())
	{
		po = pos[s[i]];
		while(i == act->siz || s[i - act->siz - 1] != s[i])
			act = act->link[0];
		if(!act->child[po])
		{
			act->child[po] = new node(act->siz + 2, act, s[i]);
			nodes[posn++] = act->child[po];
			suf = act->link[0];
			act = act->child[po];
			while(s[i - suf->siz - 1] != s[i])
				suf = suf->link[0];
			act->link[0] = act->siz == 1 ? ce : suf->child[po];
			fore(i, 1, 20)
				act->link[i] = act->link[i-1]->link[i-1];
		}
		else
			act = act->child[po];
	}
}
string print1(pnode p);
pnode lift(pnode node, int x)
{
	for(int i = 19; i > -1; i--)
		if(node->link[i]->siz > x)
			node = node->link[i];
	node = node->link[0];
	return node;
}
void f(pnode p)
{
	if(p->dpt != -1) return;
	if(p->siz == 1)
	{
		p->dpt = 1;
		p->dph = 0;
		return;
	}
	f(p->link[0]);
	p->dpt = p->link[0]->dpt + p->siz - p->link[0]->siz;
	if(p->siz % 2 == 0)
	{
		f(p->par);
		pnode mit = lift(p, p->siz / 2);
		f(mit);
		p->dph = min(p->par->dph + 1, mit->dpt + p->siz / 2 - mit->siz);
		p->dpt = min(p->dpt, p->dph + 1);
	}

}
string print1(pnode p)
{
	string s = "";
	s += p->ch;
	if(p->siz <= 0) return "";
	if(p->siz == 1)
		return s;
	return s + print1(p->par) + s;
}
string print(pnode p)
{
	string res = "";
	while(p->siz > 0)
	{
		res += print1(p) + '\n';
		p = p->link[0];
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	pos['A'] = 0;
	pos['G'] = 1;
	pos['T'] = 2;
	pos['C'] = 3;
	int cas;
	cin>>cas;
	pnode ax;
	while(cas--)
	{
		string s;
		cin>>s;
		create(s);
		int n = s.size();
		int res = n;
		fore(i, 0, posn)
		{
			f(nodes[i]);
			res = min(res, n - nodes[i]->siz + nodes[i]->dpt);
		}
		fore(i, 0, posn)
		{
			delete nodes[i];
		}
			delete meu;
			delete ce;
		cout<<res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	