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
struct node
{
	char ch;
	int val, sz;
	node *l, *r;
	node(char ch) : ch(ch) {val = rand(), l = NULL, r = NULL, sz = 1;}
};
typedef node* pnode;
int sz(pnode t)
{
	return t? t->sz : 0;
}
void upd_sz(pnode t)
{
	if(t)
	{
		t->sz = sz(t->l) + 1 + sz(t->r);
	}
}
void split(pnode t, pnode &l, pnode &r, int pos, int izq = 0)
{
	if(!t) {l = r = NULL; return;}
	int posi = izq + sz(t->l);
	if(pos > posi)
		split(t->r, t->r, r, pos, posi + 1), l = t;
	else
		split(t->l, l, t->l, pos, izq), r = t;
	upd_sz(t);
}
void merge(pnode &t, pnode l, pnode r)
{
	if(!l || !r) 
	{
		t = l ? l : r;
		return;
	}
	if(l->val > r->val)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	upd_sz(t);
}
void print(pnode t)
{
	if(t)
	{
		print(t->l);
		cout<<t->ch;
		print(t->r);
	}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	string s;
	pnode t, t1, t2, t3;
	while(n--)
	{
		cin>>s;
		int pos = 0, tam = 0;
		t = t1 = t2 = t3 = NULL;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '<')
				pos = max(0, pos - 1);
			else if(s[i] == '>')
				pos = min(pos + 1, tam);
			else if(s[i] == '-')
			{
				if(pos > 0)
				{
					pos--;
					split(t, t1, t2, pos);
					split(t2, t3, t2, 1);
					merge(t, t1, t2);	
					tam--;
				}
			}
			else
			{
				//cout<<0;
				split(t, t1, t2, pos);
				//cout<<1;
				t3 = new node(s[i]);
				//cout<<2;
				merge(t1, t1, t3);
				//cout<<3;
				merge(t, t1, t2);
				//cout<<4<<'\n';
				pos++;
				tam++;
			}
		}
		print(t);
		cout<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS