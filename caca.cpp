#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define PI                acos(-1)
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e)	  for (int i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
struct item
{	
	int key, prior, sz;
	bool isle;
	item * l, * r, * p;
	item(int key) : key(key) {prior = rand(), sz = 1, l = NULL, r = NULL, p = NULL, isle = 1;}
};
typedef item* pitem;
int sz(pitem t)
{
	return t ? t->sz : 0;
}
void upd_sz(pitem t)
{
	if(t)
	{
		t->sz = sz(t->l) + 1 + sz(t->r);
		if(t->l)
		{
			(t->l)->isle = true;
			(t->l)->p = t;
		}
		if(t->r)
		{
			(t->r)->isle = false;
			(t->r)->p = t;
		}
	}
}
void split(pitem t, pitem& l, pitem& r, int pos)
{
	if(!t) {r = l = NULL; return;}
	if(pos < sz(t->l))
	{
		split(t->l, l, t->l, pos), r = t;
	}
	else
	{
		split(t->r, t->r, r, pos - 1 - sz(t->l)), l = t;
	}
	upd_sz(r);
	upd_sz(l);
}
void merge(pitem& t, pitem l, pitem r)
{
	if(!r || !l) {t = l? l : r; upd_sz(t); return;}
	if((l->prior) > (r->prior))
	{
		merge(l->r, l->r, r), t = l;
	}
	else
	{
		merge(r->l, l, r->l), t = r;

	}
	upd_sz(t);
}
pitem root;
int getPopo(pitem t)
{
	int ans = sz(t->l) + 1;
	pitem p;
	while(t != root)
	{
		p = t->p;
		if(p->l != t)
			ans += 1 + sz(p->l);
		t = p;
	}
	return ans;
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
pitem ar[100010];
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    pitem t1, t2, t3;
    int pos = 0;
    int n;
    cin>>n;
    int pap;
    root = NULL;
    char ch;
    int can = 0;
    while(n--)
    {
    	cin>>ch;
    	if(ch == 'B')
    	{
    		ar[pos] = new item(pos);
    		if(can)
    			merge(root, root, ar[pos]);
    		else
    			root = ar[pos];
    		pos++;
    		can++;
    	}
    	if(ch == 'F')
    	{
    		ar[pos] = new item(pos);
    		if(can)
    			merge(root, ar[pos], root);
    		else
    			root = ar[pos];
    		pos++;
    		can++;
    	}
    	if(ch == 'O')
    	{
    		cin>>pap;
    		//cout<<ar[pap-1]->key<<'\n';
    		pap = getPopo(ar[pap-1]);
    		//cout<<pap<<' '<<can<<'\n';
    		split(root, t1, t2, pap-1);
    		split(t1, t1, t3, pap - 2);
    		//print(t2);cout<<'\n';
    		//print(t3);cout<<'\n';
    		merge(root, t2, t1);
    		cout<<min(pap - 1, can - pap)<<'\n';
    		can--;
    	}
    	//print(root);
    	//cout<<'\n';
    }
    return 0;
}
// PLUS ULTRA!