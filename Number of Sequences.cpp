#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
int rem[tam];
bitset<tam> bi;
vector<int> pri, pric;
void criba()
{
	bi.set();
	fore(i, 2, tam)
	{
		if(bi[i])
		{
			forg(j, i, tam, i)
			bi[j] = 0;
			pric.pb(i*i);
			pri.pb(i);
		}
	}
	mem(rem, -1);
}
bool fac(int n, int a)
{
	if(a == -1) return 1;
	int ax = n;
	int mul;
	for(int i = 0; pric[i] <= ax; i++)
	{
		if(ax % pri[i] == 0)
		{
			mul = pri[i];
			while(ax % pri[i] == 0)
			{
				if(rem[mul] == -1)
					rem[mul] = a % mul;
				else
					if(rem[mul] != a % mul)
						return 0;
				ax /= pri[i];
				mul *= pri[i];
			}
		}
	}
	if(ax > 1)
	{
		if(rem[ax] == -1)
					rem[ax] = a % ax;
				else
					if(rem[ax] != a % ax)
						return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int a;
	criba();
	fore(i, 1, n+1)
	{
		cin>>a;
		//cout<<i<<' '<<a<<'\n';
		if(!fac(i, a))
		{
			//fore(i, 0, 176) cout<<i<<' '<<rem[i]<<'\n';
			cout<<"0\n";
			return 0;
		}
	}
	int  b;
	ll ax;
	ll res = 1;
	//fore(i, 0, 10) cout<<rem[i]<<'\n';
	for(int i = 0; pri[i] <= n; i++)
	{
		a = b = 0;
		ax = pri[i];
		//cout<<pri[i]<<'\n';
		while(ax <= n)
		{
			b++;
			if(rem[ax] != -1) a = b; 
			ax *= pri[i];
		}
		//cout<<a<<' '<<b<<'\n';
		fore(j, a, b)
		res = res * pri[i] % MOD;
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2