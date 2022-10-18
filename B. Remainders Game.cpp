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

//typedef long long 		;
typedef unsigned long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 10000;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
vector<int> pri, pric;
bitset<10000> bi;

void criba()
{
	bi.set();
	fore(i, 2, 10000)
	{
		if(bi[i])
		{
			forg(j, i+i, 10000, i)
			bi[j] = 0;
			pri.pb(i);
			pric.pb(i * i);
		}
	}
}

int fac[2000000];

void fact(int n)
{
	int co;
	for(int i = 0; pric[i] <= n; i++)
	{
		if(n % pri[i] == 0)
		{
			co = 0;
			while(n % pri[i] == 0)
			{
				n /= pri[i];
				co++;
			}
			fac[pri[i]] = max(fac[pri[i]], co);
		}
	}
	if(n > 1)
		fac[n] = max(fac[n], 1);
}
bool facto(int n)
{
	int co;
	for(int i = 0; pric[i] <= n; i++)
	{
		if(n % pri[i] == 0)
		{
			co = 0;
			while(n % pri[i] == 0)
			{
				n /= pri[i];
				co++;
			}
			if(fac[pri[i]] < co)
				return 0;
		}
	}
	if(n > 1)
	{
		if(fac[n] == 0)
		return 0;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, k;
	cin>>n>>k;;
	int a;
	criba();
	while(n--)
	{
		cin>>a;
		fact(a);
	}
	cout<<(facto(k) ? "Yes" : "No")<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2