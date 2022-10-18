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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
const ll MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<ll> pri, pric;
bitset<10000010> bi;
void criba()
{
	bi.set();
	fore(i, 2, 10000010)
	{
		if(bi[i])
		{
			forg(j, i, 10000010, i)
				bi[j] = 0;
			pri.pb(i);
			pric.pb(1ll * i * i);
		}
	}
}
pair<pair<int, int>, pair<int, int>> divi[10000010];
vector<pair<int, int>> divs;
int an, posu;
//int div;
void llans(int pos, int pas, int num)
{
	if(pos == divs.size())
	{
		int div = num;
		if(divi[div].f.f > an)
		{
			divi[div].s = divi[div].f;
			divi[div].f = mp(an, posu);
		}
		else if(divi[div].s.f > an)
			divi[div].s = mp(an, posu);
		return;
	}
	llans(pos + 1, 0, num);
	if(pas < divs[pos].s)
		llans(pos, pas + 1, num * divs[pos].f);
}
void llen(int n)
{
	int con;
	bool bo;
	divs.clear();
	for(int i = 0; pric[i] <= n; i++)
	{
		con = 0;
		bo = false;
		while(n % pri[i] == 0)
		{
			bo = true;
			n /= pri[i];
			con++;
		}
		if(bo)
		divs.pb(mp(pri[i], con));
	}	
	if(n > 1) divs.pb(mp(n, 1));
	llans(0, 0, 1);
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	fore(i, 0, 10000010) divi[i] = mp(mp(MOD, 0), mp(MOD, 0));
	int a;
	criba();
	double TLE = 3.9;
	double t = clock();
	fore(i, 0, n)
	{
		scanf("%d", &a);
		an = a;
		posu = i + 1;
		llen(a);
	}
	ll res = 1e16, ax;
	pair<int, int> re(-1, -1);
	fore(i, 0, 10000010)
	{
		if(divi[i].f.f != MOD && divi[i].s.f != MOD)
		{
			ax = 1ll * divi[i].f.f * divi[i].s.f / i;
			if(res > ax)
			{
				res = ax;
				re = mp(divi[i].f.s, divi[i].s.s);
				if(re.f > re.s)
					swap(re.f, re.s);
			}
		}
	}
	printf("%d %d\n", re.f, re.s);
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	