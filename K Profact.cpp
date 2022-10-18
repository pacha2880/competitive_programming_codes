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
//find_by_order kth largest  order_of_key <
const int tam = 370010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
ll fact[100];
int dp[tam];
bool okay;
bool prime[123];
bool f(ll numero)
{
	if (numero==1){
		okay=1;
		return 1;
	}
	if (numero<tam)
	{
		if (dp[numero]!=-1)
			return dp[numero];
	}
	bool ans=0;
	int pos=20;
	fore(i,2,20)
	{
		if (prime[i] && numero%i==0)
			pos=i;
	}
	fore(i,pos,20)
	{
		if(numero%fact[i]==0 && ans==0)
		ans|=f(numero/fact[i]);
		else
		break;
	}
	if (numero<tam)
		dp[numero]=ans;
	return ans;
}
int main()
{
	prime[3]=prime[2]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=1;
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	memset(dp,-1,sizeof dp);
	fact[1]=1;
	fore(i,2,20)
		fact[i]=fact[i-1]*i;
	fore(i,1,tam)
		f(i);
	int casos;
	cin>>casos;
	ll numero;
	while(casos--)
	{
		cin>>numero;
		if (numero==1)
		{
			cout<<"YES\n";
			continue;
		}
		okay=0;
		fore(i,2,20)
		{
			if (numero%i==0)
				okay=1;
		}
		if (!okay)
		{
			cout<<"NO\n";
			continue;
		}
		bool ans=f(numero);
		if (ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2