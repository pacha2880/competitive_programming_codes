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


pair<pair<ll, int>, pair<int, ll> > evs[1000010];
pair<pair<ll, ll>, ll> cir[1000010];
bool cho(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
	ll x = a.f.f - b.f.f;
	ll y = a.f.s - b.f.s;
	ll r = a.s + b.s;
	return x * x + y * y == r * r;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	set<pair<ll, int> > st;
	int n;
	cin>>n;
	int a, b, c;
	fore(i, 0, n)
	{
		cin>>cir[i].f.f>>cir[i].f.s>>cir[i].s;
		evs[2 * i] = mp(mp(cir[i].f.f - cir[i].s, -1), mp(i, cir[i].f.s));
		evs[2 * i + 1] = mp(mp(cir[i].f.f + cir[i].s, 1), mp(i, cir[i].f.s));
	}
	sort(evs, evs + 2 * n);
	set<pair<ll, int> >::iterator it, it1;
	pair<ll, int> mei;
	set<pair<int,int> > rus;
	bool bo;
	fore(i, 0, 2 * n)
	{
		mei = mp(evs[i].s.s, evs[i].s.f);
		bo = st.count(mei);
		if(bo)
			st.erase(mei);
		it = st.lower_bound(mei);
		if(it != st.end())
		{
			if(cho(cir[evs[i].s.f], cir[(*it).s]))
				rus.insert(mp(min(evs[i].s.f, (*it).s), max(evs[i].s.f, (*it).s)));
			if(it != st.begin() && bo)
			{
				it1 = it;
				it1--;
				if(cho(cir[(*it1).s], cir[(*it).s]))
					rus.insert(mp(min((*it1).s, (*it).s), max((*it1).s, (*it).s)));
			}
		}
		if(it != st.begin())
		{
			it--;
			if(cho(cir[evs[i].s.f], cir[(*it).s]))
				rus.insert(mp(min(evs[i].s.f, (*it).s), max(evs[i].s.f, (*it).s)));
		}
		if(!bo)
			st.insert(mei);
	}
	cout<<rus.size()<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2