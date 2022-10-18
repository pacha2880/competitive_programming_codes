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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
ll k;
struct item
{
	int po, pol, por, nil, can, prior, sz, rep;
	item *l, *r;
	item(int po) : po(po) {pol = po, por = po, prior = rand(), rep = 1, nil = 0, can = 2 * k, l = NULL, r = NULL;}
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
		t->sz = sz(t->l) + 1 + sz(t->l);
		t->nil = 0;
		t->pol = t->po;
		t->por = t->po;
		if(t->l)
		{
			t->nil += t->l->nil + max(0ll, t->pol - t->l->por - 2 * k);
			t->pol = t->l->pol;
		}
		if(t->r)
		{
			t->nil += t->r->nil + max(0ll, t->r->pol - t->por - 2 * k);
			t->por = t->r->por;
		}
		t->can = t->por - t->pol - t->nil + 2 * k;
	}
}
void split(pitem t, pitem &l, pitem &r, int val)
{
	if(!t) r = l = NULL;
	else if(t->po <= val) split(t->r, t->r, r, val), l = t;
	else split(t->l, l, t->l, val), r = t;
	upd_sz(t);
}
void merge(pitem &t, pitem l, pitem r)
{
	if(!r || !l) t = l ? l : r;
	else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_sz(t);
}
void print(pitem t)
{
	if(t)
	{
		print(t->l);
		cout<<t->po<<' ';
		print(t->r);
	}
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
pair<int, pair<int, int>> aro[3000], pois[3000];
pair<pair<int,int>, pair<int,int>> ar[3000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas, n;
	cin>>cas;
	pitem t=NULL, t1, t2, t3;
	while(cas--)
	{
		cin>>n>>k;
		fore(i, 0, n)
		{
			cin>>ar[2 * i].f.f>>ar[2 * i].f.s>>ar[2 * i].s.f;
			pois[i].f = ar[2 * i].f.f;
			pois[i].s.f = ar[2 * i].f.s;
			pois[i].s.s = ar[2 * i].s.f;
			ar[2 * i].s.s = i;
			ar[2 * i + 1] = ar[2 * i];
			ar[2 * i].f.f += k;
			ar[2 * i + 1].f.f -= k;
		}
		sort(ar, ar + 2 * n);
		ll fro = ar[0].f.f, froi;
		ll vol = 0, area;
		bool used[n];
		bool usod[n];
		mem(used, 0);
		fore(i, 0, 2 * n)
		{
			int co = 0;
			//cout<<"\nlos usados: \n";
			fore(j, 0, n)
			{
				//cout<<(used[j]? 1:0)<<' ';
				if(used[j])
				{
					aro[2 * co] = mp(pois[j].s.f + k, mp(pois[j].s.s, co));
					aro[2 * co + 1] = mp(pois[j].s.f - k, mp(pois[j].s.s, co));
					co++;
				}
			}
			//cout<<'\n'<<co<<'\n';
			sort(aro, aro + 2 * co);
			area = 0;
			froi = aro[0].f;
			erase(t);
			mem(usod, 0);
			//cout<<"my love"<<ar[i].f.f<<'\n';
			fore(j, 0, 2 * co)
			{
				//cout<<aro[j].f<<' '<<aro[j].s.f<<' '<<aro[j].s.s<<'\n';
				//cout<<j<<" mit  ";
				//print(t);
				//cout<<'\n';
				if(t)
					area += (aro[j].f - froi) * t->can;
				froi = aro[j].f;
				split(t, t1, t2, aro[j].s.f);
				split(t1, t1, t3, aro[j].s.f - 1);
				if(usod[aro[j].s.s])
				{
					//cout<<"ocu "<<aro[j].s.s<<' ';
					//print(t3);cout<<'\n';
					if(t3->rep == 1)
					{
						merge(t, t1, t2);
					}
					else
					{
						t3->rep--;
						merge(t1, t1, t3);
						merge(t, t1, t2);
					}
				}
				else
				{
					//cout<<"usado "<<aro[j].f<<' ';
					usod[aro[j].s.s] = 1;
					if(t3)
						t3->rep++;
					else
						t3 = new item(aro[j].s.f);
					merge(t1, t1, t3);
					merge(t, t1, t2);
				}
				//cout<<area<<' ';
			}
			//cout<<"miare  "<<area<<' ';
			vol += (ar[i].f.f - fro) * area;

			fro = ar[i].f.f;
			//cout<<ar[i].s.s;
			if(used[ar[i].s.s])
				used[ar[i].s.s] = false;
			else
				used[ar[i].s.s] = true;
			//used[ar[i].s.s] = !used[ar[i].s.s];

		}
		cout<<vol<<'\n';
	}
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2