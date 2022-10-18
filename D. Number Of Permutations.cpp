#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
ll fac[400000];
ll canti(vector<int> v)
{
	int fro = -1, com  = -1;
	ll res = 1;
	fore(i, 0, v.size())
	{
		if(v[i] != com)
		{
			res *= fac[i - fro]; 
			res %= MOD1;
			com = v[i];
			fro = i;
		}
	}
	return res * fac[v.size()-fro] % MOD1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	fac[0] = 1;
	fore(i, 1, 400000) fac[i] = (fac[i-1] * i) % MOD1;
	int n;
	cin>>n;
	vector<int> s1, s2;
	vector<pair<int,int>> pa;
	int a, b;
	fore(i, 0, n)
	{
		cin>>a>>b;
		s1.pb(a);
		s2.pb(b);
		pa.pb(mp(a, b));
	}
	sort(s1.begin(), s1.end());
	ll res = canti(s1);
	sort(s2.begin(), s2.end());
	res += canti(s2);
	res %= MOD1;
	//cout<<res<<'\n';
	sort(pa.begin(), pa.end());
	int ma = 0, ma1 = 0, beg = pa[0].f, po = 0, lapo = 0;
	ll meni = 1;
	bool pu = true;
	while(po < n)
	{
		beg = pa[po].f;
		while(po < n && pa[po].f == beg)
		{
			if(pa[po].s < ma)
			{
				pu = false;
				break;
			}
			ma1 = max(ma1, pa[po].s);
			po++;
		}
		if(!pu) break;
		ma = ma1;
		vector<int> pru;
		fore(i, lapo, po)
		{
			pru.pb(pa[i].s);
		}
		meni = meni * canti(pru) % MOD1;
		lapo = po;
	}
	if(pu)
		res = (res - meni + MOD1) % MOD1;
	cout<<(fac[n] - res + MOD1) % MOD1<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2