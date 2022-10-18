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
const int tam = 100010;
ll dp[100][200000];
int can[100], mul[100];
int n, nus;
vector<int> pri, pric;
bitset<100000> bi;
void criba()
{
	bi.set();
	fore(i, 2, 100000)
	{
		if(bi[i])
		{
			forg(j, i+i, 100000, i)
				bi[j] = 0;
			pri.pb(i);
			pric.pb(i * i);
		}
	}
}
void fac(int ax)
{
	int i  = 0, pos = 0;
	mem(can, 0);
	while(pric[i] <= ax)
	{
		if(ax % pri[i] == 0)
		{
			while(ax % pri[i] == 0)
			{
				ax /= pri[i];
				can[pos]++;
			}
			pos++;
		}
		i++;
	}
	if(ax > 1)
	{
		can[pos]++;
		pos++;
	}
	nus = pos;
}
ll f(int a, int b)
{
	if(a == 1) return b;
	if(b == 0) return 0;
	if(b % 100 == 0)
		cout<<a<<' '<<b<<'\n';
	if(dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = (f(a - 1, b) + f(a, b-1))%MOD;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int m;
	cin>>n>>m;
	criba();
	fac(m);
	ll res = 1;
	mem(dp, -1);
	fore(i, 0, n+1)
		dp[1][i] = i;
	fore(i, 0, 100)
		dp[i][0] = 0;
	fore(i, 2, 100)
	{
		fore(j, 1, n+1)
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
	}
	fore(i, 0, nus)
	{
		//cout<<can[i]<<' ';cout<<f(can[i], n)<<'\n';
		res = (res * dp[can[i]][n]) % MOD;
	}
	//cout<<'\n';
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2