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
const int tam = 2000010;
const int MOD = 51123987;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct node
{
	int siz, tam;
	char ch;
	node *link;
	map<int, node*> child;
	node(int siz, char ch) : siz(siz), link(0), tam(0), ch(ch) {}
};
typedef node* pnode;
pnode nodes[tam], ce, meu, err[tam];
int posn;
ll pals;
void create(string s)
{
	meu = new node(-1, '#');
	ce = new node(0, '%');
	meu->link = ce->link = meu;
	pnode act = meu, suf;
	int po;
	pals = posn = 0;
	fore(i, 0, s.size())
	{
		while(act->siz == i || s[i - act->siz - 1] != s[i])
			act = act->link;
		po = s[i] - 'a';
		if(!act->child.count(po))
		{
			act->child[po] = new node(act->siz + 2, s[i]);
			err[posn++] = act->child[po];
			suf = act->link;
			act = act->child[po];
			while(s[i - suf->siz - 1] != s[i])
				suf = suf->link;
			act->link = act->siz == 1 ? ce : suf->child[po];
			act->tam = act->link->tam + 1;
		}
		else
			act = act->child[po];
		nodes[i] = act;
		pals += act->tam;
	}
}
ll sums[tam];
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	create(s);
	for(int i = n - 1; i > -1; i--)
		sums[i] = (sums[i + 1] + nodes[n - i - 1]->tam) % MOD;
	fore(i, 0, posn)
		delete err[i];
	reverse(all(s));
	create(s);
	__int128 pala = pals;
	pala = pala * (pala - 1) / 2 % MOD;
	pals = pala;
	//pals = pals * (pals - 1) / 2 % MOD;
	//cout<<pals<<'\n';
	fore(i, 0, n - 1)
		pals = ((pals - nodes[i]->tam * sums[i + 1] % MOD) % MOD + MOD) % MOD;
		cout<<pals;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	