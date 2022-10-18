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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 

int parent[200020];
pair<int, int> ar[400020];
vector<pair<int, int>> ari;
set<int> su, ti;
set<pair<int, int>> nsu, nti;
int find(int n)
{
	if(parent[n] == -1) return n;
	return parent[n] = find(parent[n]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, a, b, pa, pb;
	cin>>n>>m;
	fore(i, 0, m)
	{
		cin>>ar[i].f>>ar[i].s;
	}
	int s, t, ds, dt;
	cin>>s>>t>>ds>>dt;
	mem(parent, -1);
	fore(i, 0, m)
	{
		a = ar[i].f, b = ar[i].s;
		if(a == s)
		{
			su.insert(b);
		}
		if(a == t)
		{
			ti.insert(b);
		}
		if(b == s)
		{
			su.insert(a);
		}
		if(b == t)
		{
			ti.insert(a);
		}
		if(a != s && a != t && b != s && b != t)
		{
			pa = find(a);
			pb = find(b);
			if(pa != pb)
			{
				parent[pa] = pb;
				ari.pb(mp(a, b));
			}
		}
	}
	//cout<<"a\n";
	for(auto a : su)
	{
		nsu.insert(mp(find(a), a));
	}
	//cout<<"aa\n";
	for(auto a : ti)
	{
		nti.insert(mp(find(a), a));
	}
	set<int> reg;
	fore(i, 1, n + 1)
	{
		if(i != s && i != t)
			reg.insert(find(i));
	}
	//cout<<"mis reg  ";
	/*for(auto a : reg)
	{
		//cout<<a<<' ';
	}*/
	//cout<<'\n';
	bool conec = false;
	set<pair<int, int>>::iterator it;

	//cout<<"b\n";
	for(auto pa : nsu)
	{
		it = nti.lower_bound(mp(pa.f, -1));
		if(it != nti.end() && (*it).f == pa.f)
		{
			//cout<<"coñac   "<<pa.s<<' '<<(*it).s<<'\n';
			ari.pb(mp(s, pa.s));
			ari.pb(mp(t, (*it).s));
			nsu.erase(pa);
			nti.erase(it);
			reg.erase(pa.f);
			ds--;
			dt--;
			conec = true;
			break;
		}
	}
	//cout<<"c\n";


	//cout<<"nsu:\n";
	for(auto pa : nsu)
	{
		//cout<<pa.f<<' '<<pa.s<<'\n';
		it = nti.lower_bound(mp(pa.f, -1));
		if(reg.count(pa.f) && (it == nti.end() || (*it).f != pa.f))
		{
			ds--;
			ari.pb(mp(s, pa.s));
			reg.erase(pa.f);
		}
	}
	//cout<<"d\n";
	//cout<<"nti\n";
	for(auto pa : nti)
	{
		//cout<<pa.f<<' '<<pa.s<<'\n';
		it = nsu.lower_bound(mp(pa.f, -1));
		if(reg.count(pa.f) && (it == nsu.end() || (*it).f != pa.f))
		{
			dt--;
			ari.pb(mp(t, pa.s));
			reg.erase(pa.f);
		}
	}
	//cout<<"regg\n";
	for(auto itt = reg.begin(); itt != reg.end();)
	{
		//cout<<(*itt)<<'\n';
		it = nsu.lower_bound(mp(*itt, -1));
		if(it != nsu.end() && (*it).f == *itt && ds > 0)
		{
			ari.pb(mp(s, (*it).s));
			itt = reg.erase(itt);
			ds--;
		}
		else 
		{
			it = nti.lower_bound(mp(*itt, -1));
			if(it != nsu.end() && (*it).f == *itt && dt > 0)
			{
				dt--;
				ari.pb(mp(t, (*it).s));
				itt = reg.erase(itt);
			}
			else
				itt++;
		}
	}

	//cout<<"g\n";
	if(!conec && su.count(t))
	{
		ds--; dt--;
		ari.pb(mp(s, t));
		conec = true;
	}
	//cout<<"h\n";
	if(conec && reg.size() == 0 && ds >= 0 && dt >= 0)
	{
		cout<<"Yes\n";
		for(auto pa : ari)
		{
			cout<<pa.f<<' '<<pa.s<<'\n';
		}
	}
	else
		cout<<"No\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	