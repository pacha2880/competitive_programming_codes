#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
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
const int tam = 10000010;
ll primis[tam];
void criba()
{
	mem(primis, 0);
	primis[0] = primis[1] = 0;
	for(int i = 2; i < tam; i++)
	{
		if(primis[i] == 0)
		{
			for(int j = i; j < tam; j+= i)
				primis[j]++;
		}
	}
	ll mul;
	for(ll i = 2; i < tam; i++)
	{
		if(primis[i] == 1)
		{
			mul = i*i;
			for(ll j = i*i; j < tam; j+= mul)
				primis[j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd1.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	criba();
	ll n, res;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		res = 0;
		for(ll i = 2; i < tam && i*i <= n; i++)
		{
			if(primis[i] > 0)
				res += n / (i*i) * (primis[i]&1?1ll:-1ll);
			//cout<<res<<'\n';
		}
		cout<<n-res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2