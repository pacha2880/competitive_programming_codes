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
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll pot(ll b, ll e, ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
ll conta(ll x, ll i)
{
	ll res = 0;
	while(x > 0)
	{
		res += x / i;
		x /= i;
	}
	return res;
}
ll fac[2000010], inv[1000010], cont[1000010];
ll f(ll x, ll i, ll ba)
{
	if(x <= 1) return 1;
	//cout<<x<<' '<<i<<' '<<i * ba<<" choclo\n";
	//cout<<"!"<<pot(fac[i-1], x / (i * ba), i)<<' '<<fac[x % (i * ba)]<<' '<<f(x / (i * ba), i, ba)<<'\n';
	//cout<<'@';
	return pot(fac[i-1], x / i, i) * fac[x % i] % i * f(x / ba, i, ba) % i;
}
ll f1(ll x, ll i, ll ba)
{
	ll para = f(x, i, ba);
	ll inv = 1;
	while(para * inv % i != 1)
		inv++;
	return inv;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	while(1){
	ll n, k, m, sav, paca, poro, mo = 0, mul = 1;
	cin>>n>>k>>m;
	sav = m;
	fore(i, 2, m + 1)
	{
		if(m % i == 0)
		{
			paca = 1;
			while(m % i == 0)
			{
				paca *= i;
				m /= i;
			}
			fac[0] = 1;
			ll co, dan;
			fore(j, 1, 2000000)
			{
				co = 0;
				dan = j;
				if(j % i == 0)
				{
					dan = 1;	
				}
				fac[j] = fac[j-1] * dan % paca;
			}

			poro = f(n, paca, i) * f1(k, paca, i) % paca * f1(n - k, paca, i) % paca *
					pot(i, conta(n, i) - conta(k, i) - conta(n - k, i), paca) % paca;
					//cout<<"adf";
			//cout<<f(n, paca, i)<<' '<< f1(k, paca, i) <<' '<<f1(n - k, paca, i)<<' '<<conta(n, i) - conta(k, i) - conta(n - k, i)<<'\n';
			ll multa = 0;
			//cout<<"asdas";
			while((mo + (sav / paca) * multa) % paca != poro)
				multa++;
			mo = (mo + (sav / paca) * multa) % sav;
		}
	}
	cout<<mo<<'\n';

	if(10) return 0;}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2