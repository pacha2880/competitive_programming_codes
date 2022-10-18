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
pair<int, int> pa[200020];
bitset<100000> bi;
vector<int> pri, pric;
void criba()
{
	bi.set();
	fore(i, 2, 100000)
	{
		if(bi[i])
		{
			forg(j, i, 100000, i)
				bi[j] = 0;
			pri.pb(i);
			pric.pb(i * i);
		}
	}
}
map<int, int> mano;
void desg(int n, int por)
{
	for(int i = 0; pric[i] <= n; i++)
	{
		while(n % pri[i] == 0)
		{
			mano[pri[i]] += por;
			n /= pri[i];
		}
	}
	if(n > 1)
		mano[n] += por;
}
void facto(ll n, ll m, int por)
{
	fore(i, 2, n+1)
		desg(i, por);
}
ll pot(ll b, ll e, ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		e /= 2;
		b = b * b % m;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	criba();
	cin>>n;
	int a;
	fore(i, 0, 2*n)
	{
		cin>>a;
		pa[i] = mp(a, i % n);
	}
	sort(pa, pa + 2 * n);
	multiset<int> st;
	map<int, int> ma;
	int cua = -1;
	ll re = 1;
	cin>>m;
	fore(i, 0, 2 * n)
	{
		if(pa[i].f != cua)
		{
			facto(st.size(), m, 1);
			for(auto pe : ma)
			{
				//cout<<pe.f<<' '<<pe.s<<' '<<pot(facto(pe.s, m), m - 2, m)<<'\n';
				facto(pe.s, m, -1);
			}
			//cout<<re<<'\n';
			st.clear();
			ma.clear();
			cua = pa[i].f;
		}
		st.insert(pa[i].s);
		ma[pa[i].s]++;
	}
			facto(st.size(), m, 1);
			for(auto pe : ma)
			{
				//cout<<pe.f<<' '<<pe.s<<' '<<pot(facto(pe.s, m), m - 2, m)<<'\n';
				facto(pe.s, m, -1);
			}

			for(auto pu: mano)
				re = re * pot(pu.f, pu.s, m) % m;
	cout<<re<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2