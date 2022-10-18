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
const int tam = 100010;int ara[100010], arb[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int maxa = 0, maxa1 = 0, ina, maxb = 0, maxb1 = 0, inb, a;
	mem(ara, 0), mem(arb, 0);
	fore(i, 0, n)
	{
		cin>>a;
		if(i&1)
		{
			ara[a]++;
		}
		else
			arb[a]++;
	}
	fore(i, 0, 100010)
	{
		if(ara[i] > maxa)
		{
			maxa1 = maxa;
			maxa = ara[i];
			ina = i;
		}
		else
		{
			if(ara[i] > maxa1)
			{
				maxa1 = ara[i];
			}
		}
	}
	fore(i, 0, 100010)
	{
		if(arb[i] > maxb)
		{
			maxb1 = maxb;
			maxb = arb[i];
			inb = i;
		}
		else
		{
			if(arb[i] > maxb1)
				maxb1 = arb[i];
		}
	}
	//cout<<ina<<' '<<maxa<<' '<<maxa1<<' '<<inb<<' '<<maxb<<' '<<maxb1<<'\n';
	if(ina == inb)
	{
		if(maxa1 + maxb > maxa + maxb1)
			maxa = maxa1;
		else
			maxb = maxb1;
	}
	cout<<n - maxb - maxa<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2